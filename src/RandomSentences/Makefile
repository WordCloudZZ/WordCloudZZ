# compilateur 
CC = g++

# options de compilation 
CCFLAGS = -Wall -Wextra -ansi -pedantic -g -O2 -std=c++11 -Iinclude/

# options de l'edition des liens
LDFLAGS = -lm

# liste des fichiers objets 
OBJ = main.o WordsGenerator.o Mersenne.o
BUILD_PATH = ../../bin/
EXE = RandomSentences

VPATH = src/ include/

# regle finale pour la creation de l'executable
$(EXE):$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

deploy: $(EXE)
	cp $(EXE) $(BUILD_PATH)

# compiler tous les .cpp en .o
.cpp.o:
	$(CC) $(CCFLAGS) -c $<
       
# creation automatique des dependances
# attention : on liste tous les fichiers cpp du repertoire mais on peut affiner ;-)
dep:
	$(CC) -MM *.cpp src/*.cpp -Iinclude/ > makefile.dep
          
clean:
	rm -rf $(OBJ) core *.h.gch
             
include makefile.dep
