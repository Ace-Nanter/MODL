template <class T>
Histogramme<T>::Histogramme(const double & borneInf, const double & borneSup, const unsigned int & quantite) {
    const double intervalle = (borneSup - borneInf) / quantite;
    for(unsigned int i = 0 ; i < quantite ; i++) {
        const double & inf = borneInf + i * intervalle;
        const double & sup = borneSup - (quantite - (i + 1)) * intervalle;
        m_container.insert(Classe(inf, sup));
    }
 }

template <class T>
const std::set<Classe, T> & Histogramme<T>::getClasses() const {
    return m_container;
}

template <class T>
void Histogramme<T>::ajouter(const Echantillon & e) {
    for(unsigned int i = 0 ; i < e.getTaille() ; i++) {
        typename Histogramme<T>::classes_t::iterator it = m_container.begin();
        while(it != m_container.end()) {
            if(e.getValeur(i).getNombre() >= it->getBorneInf() 
                && e.getValeur(i).getNombre() < it->getBorneSup()) {
                    const_cast<Classe&>(*it).ajouter();

                break;
            }
            it++;
        }
    }
}