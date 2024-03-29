// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vecteur03.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {

    Vecteur v1;
    Vecteur v2;

    complexe_t::stats();

    unsigned i = 0;
    for (auto & e : v1) {
        e = complexe_t(10 * i, i * i);
        i++;
    }

    // for (unsigned i = 0; i<v1.getTaille(); ++i) v1[i]=complexe_t(10*i,i*i);



    i = 0;
    for (auto & e : v2) {
        e = complexe_t(i, i + 1);
        i++;
    }

    // for (unsigned i = 0; i<v2.getTaille(); ++i) v2[i]=complexe_t(i,i+1);

    std::cout << std::endl << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    complexe_t::stats();

    Vecteur v3 = v1;

    std::cout << std::endl << "v3 = " << v3 << std::endl;
    complexe_t::stats();

    Vecteur v4;

    v4=v1+v2;

    std::cout << std::endl << "v4 = " << v4 << std::endl;
    complexe_t::stats();

    Vecteur v5;

    v5=v1*v2;

    std::cout << std::endl << "v5 = " << v5 << std::endl;
    complexe_t::stats();

    std::deque<complexe_t> liste;

    for (auto e : v5) {
        liste.push_back(e);
    }

    // for (unsigned i = 0; i<v5.getTaille(); ++i) liste.push_back(v5[i]);

    std::cout << std::endl << "liste = v5" << std::endl;
    complexe_t::stats();

    // Definition lambda
    auto comparateur = [] (const complexe_t & c1, const complexe_t & c2)
    {
        return (c1.reel < c2.reel || (c1.reel==c2.reel && c1.imaginaire < c2.imaginaire));
    };

    // std::sort(liste.begin(), liste.end(), ComparateurComplexe());
    std::sort(liste.begin(),liste.end(), comparateur);

    std::cout << std::endl;

    for(auto & e : liste) {
        std::cout << e << " ";
    }

    //for (unsigned i = 0; i<liste.size(); ++i) std::cout << liste[i] << " ";

    std::cout << std::endl;
    
    complexe_t::stats();
}

// Fin //-------------------------------------------------------------------------------------------
