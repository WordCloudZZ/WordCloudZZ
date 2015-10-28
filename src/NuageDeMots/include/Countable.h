#ifndef COUNTABLE_H
#define COUNTABLE_H


class Countable {
    protected:
        /** Number of occurences **/
        unsigned long long int          m_number;

    public:
        /** Default constructor */
        Countable(const int & = 0);
        /** Default destructor */
        virtual ~Countable();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Countable(const Countable &);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Countable& operator=(const Countable &);
        /** Get the number of occurences
         *  \param None
         *  \return An integer representing th number of occurences
         */
        int number() const;
        /** Set a value to m_number
         *  \param p_number Number to assign
         *  \return None
         */
        void setNumber(const int &);
        /** Increment operator
         *  \param None
         *  \return A reference to this
         */
        Countable & operator++();
        /** Increment operator
         *  \param None
         *  \return A copy of this
         */
        Countable operator++(int);
        /** Decrement operator
         *  \param None
         *  \return A reference to this
         */
        Countable & operator--();
        /** Decrement operator
         *  \param None
         *  \return A copy of this
         */
        Countable operator--(int);
};

#endif // COUNTABLE_H
