template <class T>
template <class U>
Histogramme<T>::Histogramme(const Histogramme<U> & h) {
    typename Histogramme<T>::classes_t::iterator it = h.getClasses().begin();
    while(it != h.getClasses().end()) {
        m_container.insert(*it);
        it++;
    }   
}

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
const std::multimap<Classe, Valeur> & Histogramme<T>::getValeurs() const {
    return m_values;
}

template <class T>
std::pair<typename Histogramme<T>::it_valeurs_t, typename Histogramme<T>::it_valeurs_t> Histogramme<T>::getValeurs(const Classe & c) const {
    return m_values.equal_range(c);
}

template <class T>
void Histogramme<T>::ajouter(const double d) {

    typename Histogramme<T>::classes_t::iterator it = m_container.begin();
	while(it != m_container.end())
	{
		if(d >= it->getBorneInf() && d < it->getBorneSup()) {

            // Suppression puis ajout après incrémentation dans l'ensemble
			Classe tmp(*it);
			tmp.ajouter();
			m_container.erase(it);
			m_container.insert(tmp);

            // Insertion dans la map
            m_values.insert(std::pair<Classe, Valeur>(*it, Valeur(d)));

			break;
		}
		else
			++it;
	}
}

template <class T>
void Histogramme<T>::ajouter(const Echantillon & e) {
    for(unsigned int i = 0 ; i < e.getTaille() ; i++) {
        ajouter(e.getValeur(i).getNombre());
    }
}
