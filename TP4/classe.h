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
        Classe(const double, const double);
        Classe(const double, const double, const double);

        // Accesseurs
        const double & getBorneInf() const;
        const double & getBorneSup() const;
        const unsigned int & getQuantite() const;
        void setBorneInf(const double &);
        void setBorneSup(const double &);
        void setQuantite(const unsigned int &);
        void ajouter();

        const bool operator< (const Classe &) const;
        const bool operator> (const Classe &) const;
};


template <typename> class ComparateurQuantite{
    //static_assert(false, "Not implemented");
};

template <>
class ComparateurQuantite<Classe> {
    public:
        bool operator()(const Classe &, const Classe &) const;
};

#endif