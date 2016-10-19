#ifndef __CLASSE_H__
#define __CLASSE_H__


class Classe {

    protected:
        double m_borneInf;
        double m_borneSup;
        unsigned int m_quantite;
    
    public:

        // Constructeurs/Destructeur
        Classe();
        Classe(const double &, const double &);
        ~Classe();

        // Accesseurs
        const double & getBorneInf() const;
        const double & getBorneSup() const;
        const unsigned int & getQuantite() const;
        void setBorneInf(const double &);
        void setBorneSup(const double &);
        void setQuantite(const unsigned int &);
        void ajouter();
};


#endif