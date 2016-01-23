#ifndef STUDENT_H
#define STUDENT_H

class Student {
    protected:
        double    * values_,    // Valeurs de 1 a 30
                    // Valeurs pour le reste
                    coeff_40_30_,
                    off_40_30,
                    coeff_80_40_,
                    off_80_40,
                    coeff_120_80_,
                    off_120_80,
                    infty_;     // Valeurs a l'infini

    public:
        Student();
        ~Student();

        double getQuantile(int);
};

#endif // STUDENT_H
