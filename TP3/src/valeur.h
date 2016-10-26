#ifndef __VALEUR_H__
#define __VALEUR_H__

#include <string>

class Valeur {
    protected:
        double m_value;
        std::string m_nom; 


    public:
        // Constructeur / Destructeurs
        Valeur();
        Valeur(const double);
        Valeur(const double, const std::string &);
        ~Valeur();

        // Accesseurs
        const double getNombre() const;
        const double getNote() const;
        const std::string getEtudiant() const;
        void setNombre(const double);
        void setNote(const double);
        void setEtudiant(const std::string &);
};

class ValeurComparaison {
    public:
        const bool operator()(const Valeur & v1, const Valeur & v2) const {
            return (v1.getNombre() < v2.getNombre());
        }
};

#endif