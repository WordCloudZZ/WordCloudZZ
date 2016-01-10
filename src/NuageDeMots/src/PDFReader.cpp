#include "PDFReader.h"
#include "pdf.h"

using namespace std;

#define oldchar 15

PDFReader::PDFReader(string filename) {
	m_open = false;
	m_filename = "";
    if(!open(filename)) {
        cerr << "PDFReader error: cannot open the pdf file " << filename << endl;
    }
}

PDFReader::~PDFReader() {
    if(isOpen() && !close())
        cerr << "PDFReader error: cannot close the pdf file " << m_filename << endl;
}

bool PDFReader::open(string filename) {
    if(!isOpen() && (m_pdf = fopen(filename.c_str(), "rb"))) {
        m_filename = filename;
    	m_open = true;
        process();
    }
    return isOpen();
}

bool PDFReader::close() {
    if(isOpen()) {
        m_open = fclose(m_pdf);
        if(!isOpen())
            m_lines.clear();
    }
    return !isOpen();
}

bool PDFReader::isOpen() const {
    return m_open;
}

vector<string> PDFReader::getLines() const {
    vector<string> result;

    if(isOpen())
        result = m_lines;
    else {
        cerr << "PDFReader error: no pdf file opened" << endl;
    }

    return result;
}

bool PDFReader::process() {
	if(isOpen()) {
		//Get the file length:
		int fseekres = fseek(m_pdf,0, SEEK_END);   //fseek==0 if ok
		long filelen = ftell(m_pdf);
		fseekres = fseek(m_pdf,0, SEEK_SET);

		//Read ethe ntire file into memory (!):
		char* buffer = new char [filelen]; benzero(buffer, filelen);//ZeroMemory(buffer, filelen);
		size_t actualread = fread(buffer, filelen, 1 ,m_pdf);  //must return 1

		bool morestreams = true;

		//Now search the buffer repeated for streams of data:
		while(morestreams) {
			//Search for stream, endstream. We ought to first check the filter
			//of the object to make sure it if FlateDecode, but skip that for now!
			size_t streamstart = FindStringInBuffer (buffer, "stream", filelen);
			size_t streamend   = FindStringInBuffer (buffer, "endstream", filelen);
			if (streamstart>0 && streamend>streamstart)
			{
				//Skip to beginning and end of the data stream:
				streamstart += 6;

				if (buffer[streamstart]==0x0d && buffer[streamstart+1]==0x0a) streamstart+=2;
				else if (buffer[streamstart]==0x0a) streamstart++;

				if (buffer[streamend-2]==0x0d && buffer[streamend-1]==0x0a) streamend-=2;
				else if (buffer[streamend-1]==0x0a) streamend--;

				//Assume output will fit into 10 times input buffer:
				size_t outsize = (streamend - streamstart)*10;
				char* output = new char [outsize]; benzero(output, outsize);//ZeroMemory(output, outsize);

				//Now use zlib to inflate:
				z_stream zstrm; benzero(&zstrm, sizeof(zstrm));//ZeroMemory(&zstrm, sizeof(zstrm));

				zstrm.avail_in = streamend - streamstart + 1;
				zstrm.avail_out = outsize;
				zstrm.next_in = (Bytef*)(buffer + streamstart);
				zstrm.next_out = (Bytef*)output;

				int rsti = inflateInit(&zstrm);
				if (rsti == Z_OK) {
					int rst2 = inflate(&zstrm, Z_FINISH);
					if (rst2 >= 0) {
						//Ok, got something, extract the text:
						size_t totout = zstrm.total_out;
						subProcess(output, totout);
					}
				}
				delete[] output; output=0;
				buffer+= streamend + 7;
				filelen = filelen - (streamend+7);
			}
			else {
				morestreams = false;
			}
		}
	} else {
	    cerr << "PDFReader error : processing impossible: file not opened" << endl;
    }

	return isOpen();
}

void PDFReader::subProcess(char* output, size_t len) {
    //Are we currently inside a text object?
	bool intextobject = false;

	//Is the next character literal (e.g. \\ to get a \ character or \( to get ( ):
	bool nextliteral = false;

	//() Bracket nesting level. Text appears inside ()
	int rbdepth = 0;

	// ligne en lecture
	string str;

	//Keep previous chars to get extract numbers etc.:
	char oc[oldchar];
	int j=0;
	for (j=0; j<oldchar; j++) oc[j]=' ';

	for(size_t i=0; i<len; i++) {
		char c = output[i];
		if(intextobject) {
			if(rbdepth==0 && seen2("TD", oc)) {
				//Positioning.
				//See if a new line has to start or just a tab:
				float num = ExtractNumber(oc,oldchar-5);
				if(num>1.0) {
					str.push_back(0x0d);
					str.push_back(0x0a);
				}
				if(num<1.0) {
					str.push_back('\t');
				}
			}
			if(rbdepth==0 && seen2("ET", oc)) {
				//End of a text object, also go to a new line.
				intextobject = false;
				str.push_back(0x0d);
				str.push_back(0x0a);
			} else if(c=='(' && rbdepth==0 && !nextliteral) {
				//Start outputting text!
				rbdepth=1;
				//See if a space or tab (>1000) is called for by looking
				//at the number in front of (
				int num = ExtractNumber(oc,oldchar-1);
				if(num>0) {
					if(num>1000.0) {
						str.push_back('\t');
					} else if(num>100.0) {
						str.push_back(' ');
					}
				}
			}
			else if(c==')' && rbdepth==1 && !nextliteral) {
				//Stop outputting text
				rbdepth=0;
			} else if(rbdepth==1) {
				//Just a normal text character:
				if(c=='\\' && !nextliteral) {
					//Only print out next character no matter what. Do not interpret.
					nextliteral = true;
				} else {
					nextliteral = false;
					if( ((c>=' ') && (c<='~')) || ((c>=128) && (c<255)) ) {
						str.push_back(c);
					}
				}
			}
		}
		//Store the recent characters for when we have to go back for a number:
		for(j=0; j<oldchar-1; j++) oc[j]=oc[j+1];
		oc[oldchar-1]=c;
		if(!intextobject) {
			if(seen2("BT", oc)) {
				//Start of a text object:
				intextobject = true;
			}
		}
	}

	m_lines.push_back(str);
}
