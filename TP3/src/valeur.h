#ifndef __VALEUR_H__
#define __VALEUR_H__

class Valeur {
    protected:
        double m_value;


    public:
        // Constructeur / Destructeurs
        Valeur();
        Valeur(const double & a);
        ~Valeur();

        // Accesseurs
        const double & getNombre() const;
        void setNombre(const double &);
};

class ValeurComparaison {
    public:
        const bool operator()(const Valeur & v1, const Valeur & v2) const {
            return (v1.getNombre() < v2.getNombre());
        }
};

#endif