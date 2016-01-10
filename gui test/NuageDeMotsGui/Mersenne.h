			/**********************************************************/
			/* BARBESANGE Benjamin & GARCON Benoit               2015 */
            /*--------------------------------------------------------*/
            /*                      Mersenne.h   	                  */
            /*        Generateur de nombres pseudo-aleatoires  	      */
            /*                   FICHIER EN-TETE                      */
            /**********************************************************/

#ifndef MERSENNE_H
#define MERSENNE_H

class Mersenne {
    protected:
        static const unsigned long  N =             624;
        const unsigned long         M =             397;
        const unsigned long         MATRIX_A =      0x9908b0dfUL;   /* constant vector a */
        const unsigned long         UPPER_MASK =    0x80000000UL; /* most significant w-r bits */
        const unsigned long         LOWER_MASK =    0x7fffffffUL; /* least significant r bits */
        unsigned long               mt[N];          /* the array for the state vector  */
        int                         mti =           N+1; /* mti==N+1 means mt[N] is not initialized */

    public:
        Mersenne();
        Mersenne(const Mersenne &);
        virtual ~Mersenne();
        Mersenne & operator=(const Mersenne &);

        long long rand(long long int a, long long int b); /// draw a random integer in [a,b]
        /* initializes mt[N] with a seed */
        void init_genrand(unsigned long s);

        /* initialize by an array with array-length */
        /* init_key is the array for initializing keys */
        /* key_length is its length */
        /* slight change for C++, 2004/2/26 */
        void init_by_array(unsigned long init_key[], int key_length);

        unsigned long genrand_int32(void);

        /* generates a random number on [0,0x7fffffff]-interval */
        long genrand_int31(void);

        /* generates a random number on [0,1]-real-interval */
        double genrand_real1(void);

        /* generates a random number on [0,1)-real-interval */
        double genrand_real2(void);

        /* generates a random number on (0,1)-real-interval */
        double genrand_real3(void);

        /* generates a random number on [0,1) with 53-bit resolution*/
        double genrand_res53(void);
        /* These real versions are due to Isaku Wada, 2002/01/09 added */
};

#endif // MERSENNE_H
