// Gardien //---------------------------------------------------------------------------------------
#ifndef _TP3_TEST_HPP_
#define _TP3_TEST_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <cmath>

#include <valeur.h>
#include <echantillon.h>
//#include <histogramme.hpp>
//#include <comparateur_quantite.hpp>

//typedef Histogramme Histo;
//typedef Histogramme<> Histo;

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST ( TP3_Valeur, Constructeur ) {
 const double a = 12.0;

 Valeur v(a);

 EXPECT_DOUBLE_EQ ( v.getNombre(), a );
}

//------------------------------------------------------------------------------------------------ 2
TEST ( TP3_Valeur, ConstructeurDefaut ) {
 Valeur v;

 EXPECT_DOUBLE_EQ ( v.getNombre(), 0.0 );
}

//------------------------------------------------------------------------------------------------ 3
TEST ( TP3_Valeur, Accesseurs ) {
 const double a = 12.0;

 Valeur v(13.0);

 v.setNombre(a);

 EXPECT_DOUBLE_EQ ( v.getNombre(), a );
}

//------------------------------------------------------------------------------------------------ 4
TEST ( TP3_Valeur, AccesseursConstants ) {
 const Valeur v;

 EXPECT_DOUBLE_EQ ( v.getNombre(), 0.0 );
}

//------------------------------------------------------------------------------------------------ 5
TEST ( TP3_Echantillon, Constructeur ) {
 Echantillon e;

 EXPECT_EQ ( e.getTaille(), 0u );
}

//------------------------------------------------------------------------------------------------ 6
TEST ( TP3_Echantillon, Ajout ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };

 for (unsigned i = 0; i<4; ++i) e.ajouter(v[i]);

 EXPECT_EQ ( e.getTaille(), 4u );
}

//------------------------------------------------------------------------------------------------ 7
TEST ( TP3_Echantillon, MinMax ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };
 double min = v[0];
 double max = v[0];

 for (unsigned i = 0; i<4; ++i) {
  e.ajouter(v[i]);
  if (v[i]<min) min=v[i];
  if (v[i]>max) max=v[i];
 }

 EXPECT_DOUBLE_EQ ( e.getMinimum().getNombre(), min );
 EXPECT_DOUBLE_EQ ( e.getMaximum().getNombre(), max );
}

//------------------------------------------------------------------------------------------------ 8
/*TEST ( TP3_Echantillon, MinMaxException ) {
 Echantillon e;

 int error = 0;

 try { e.getMinimum().getNombre(); }

 catch (const std::domain_error & e) { error=2; }
 catch (...) { error=1; }

 EXPECT_EQ ( error, 2 );

 error=0;

 try { e.getMaximum().getNombre(); }

 catch (const std::domain_error & e) { error=2; }
 catch (...) { error=1; }

 EXPECT_EQ ( error, 2 );
}*/

//------------------------------------------------------------------------------------------------ 9
/*TEST ( TP3_Echantillon, Indice ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };

 for (unsigned i = 0; i<4; ++i) e.ajouter(v[i]);

 int error = 0;

 try {
  for (unsigned i = 0; i<4; ++i)
   EXPECT_DOUBLE_EQ ( e.getValeur(i).getNombre(), v[i] );
 }

 catch (...) { error=1; }

 EXPECT_EQ( error, 0 );

 try { e.getValeur(e.getTaille()); }

 catch (const std::out_of_range & e) { error=2; }
 catch (...) { error=1; }

 EXPECT_EQ( error, 2 );
}*/

//----------------------------------------------------------------------------------------------- 10
/*TEST ( TP3_Classe, Constructeur ) {
 const double a = 12.0;
 const double b = 24.0;

 Classe c(a,b);

 EXPECT_DOUBLE_EQ ( c.getBorneInf(), a );
 EXPECT_DOUBLE_EQ ( c.getBorneSup(), b );
 EXPECT_EQ ( c.getQuantite(), 0u );
}*/

//----------------------------------------------------------------------------------------------- 11
/*TEST ( TP3_Classe, Accesseurs ) {
 const double   a = 12.0;
 const double   b = 24.0;
 const unsigned n = 7;

 Classe c(13.0,25.0);

 c.setBorneInf(a);
 c.setBorneSup(b);
 c.setQuantite(n);

 EXPECT_DOUBLE_EQ ( c.getBorneInf(), a );
 EXPECT_DOUBLE_EQ ( c.getBorneSup(), b );
 EXPECT_EQ ( c.getQuantite(), n );

 c.ajouter();

 EXPECT_EQ ( c.getQuantite(), n+1 );
}*/

//----------------------------------------------------------------------------------------------- 12
/*TEST ( TP3_Histogramme, Constructeur ) {
 Histo h(5.0,15.0,5);

 EXPECT_EQ ( h.getClasses().size(), 5u );

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 Histo::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                         i  = 0;

 while (it!=h.getClasses().end()) {
  EXPECT_DOUBLE_EQ ( it->getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( it->getBorneSup(), bornesSup[i] );
  EXPECT_EQ ( it->getQuantite(), 0u );
  ++it;
  ++i;
 }
}*/

//----------------------------------------------------------------------------------------------- 13
/*TEST ( TP3_Histogramme, Echantillon ) {
 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };
 double n[] = { 3, 2, 2, 0, 3 };

 Echantillon e;

 for (unsigned i = 0; i<10; ++i) e.ajouter(v[i]);

 Histo h(5.0,15.0,5);

 h.ajouter(e);

 Histo::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                         i  = 0;

 while (it!=h.getClasses().end()) {
  EXPECT_DOUBLE_EQ ( it->getQuantite(), n[i] );
  ++it;
  ++i;
 }
}*/

//----------------------------------------------------------------------------------------------- 14
/*TEST ( TP3_Histogramme, Generique ) {
 typedef Histogramme<> histo_t;

 histo_t h(5.0,15.0,5);

 EXPECT_EQ ( h.getClasses().size(), 5u );

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 histo_t::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                           i  = 0;

 while (it!=h.getClasses().end()) {
  EXPECT_DOUBLE_EQ ( it->getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( it->getBorneSup(), bornesSup[i] );
  EXPECT_EQ ( it->getQuantite(), 0u );
  ++it;
  ++i;
 }
}*/

//----------------------------------------------------------------------------------------------- 15
/*TEST ( TP3_Histogramme, FoncteurGreater ) {
 typedef Histogramme< std::greater<Classe> > histo_t;

 histo_t h(5.0,15.0,5);

 EXPECT_EQ ( h.getClasses().size(), 5u );

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 histo_t::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                           i  = 5;

 while (it!=h.getClasses().end()) {
  --i;
  EXPECT_DOUBLE_EQ ( it->getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( it->getBorneSup(), bornesSup[i] );
  EXPECT_EQ ( it->getQuantite(), 0u );
  ++it;
 }
}*/

//----------------------------------------------------------------------------------------------- 16
/*TEST ( TP3_Histogramme, ComparateurQuantite ) {
 typedef Histogramme< ComparateurQuantite<Classe> > histo_t;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 EXPECT_EQ ( h.getClasses().size(), 5u );

 double   bornesInf[] = { 5.0, 13.0, 7.0,  9.0, 11.0 };
 double   bornesSup[] = { 7.0, 15.0, 9.0, 11.0, 13.0 };
 unsigned quantites[] = {   3,    3,   2,    2,    0 };

 histo_t::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                           i  = 0;

 while (it!=h.getClasses().end()) {
  EXPECT_DOUBLE_EQ ( it->getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( it->getBorneSup(), bornesSup[i] );
  EXPECT_EQ ( it->getQuantite(), quantites[i] );
  ++it;
  ++i;
 }
}*/

//------------------------------------------------------------------------------------------------17
/*TEST ( TP3_Histogramme, Conversion ) {
 typedef Histogramme< std::greater<Classe> >        histo1_t;
 typedef Histogramme< ComparateurQuantite<Classe> > histo2_t;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo1_t h1(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h1.ajouter(v[i]);

 histo2_t h2(h1);

 double   bornesInf[] = { 5.0, 13.0, 7.0,  9.0, 11.0 };
 double   bornesSup[] = { 7.0, 15.0, 9.0, 11.0, 13.0 };
 unsigned quantites[] = {   3,    3,   2,    2,    0 };

 histo2_t::classes_t::const_iterator it = h2.getClasses().begin();
 unsigned i = 0;

 while (it!=h2.getClasses().end()) {
  EXPECT_DOUBLE_EQ ( it->getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( it->getBorneSup(), bornesSup[i] );
  EXPECT_EQ ( it->getQuantite(), quantites[i] );
  ++it;
  ++i;
 }
}*/

//----------------------------------------------------------------------------------------------- 18
/*TEST ( TP3_Etudiant, Constructeur ) {
 const double a = 12.0;
 const char * n = "Machin";

 Valeur v(a,n);

 EXPECT_DOUBLE_EQ ( v.getNombre(), a );
 EXPECT_DOUBLE_EQ ( v.getNote(), a );
 EXPECT_STREQ ( v.getEtudiant().c_str(), n );
}*/

//----------------------------------------------------------------------------------------------- 19
/*TEST ( TP3_Etudiant, ConstructeurDefaut ) {
 Valeur v;

 EXPECT_DOUBLE_EQ ( v.getNombre(), 0.0 );
 EXPECT_DOUBLE_EQ ( v.getNote(), 0.0 );
 EXPECT_STREQ ( v.getEtudiant().c_str(), "inconnu" );
}*/

//----------------------------------------------------------------------------------------------- 20
/*TEST ( TP3_Etudiant, Accesseurs ) {
 const double a = 12.0;
 const char * n = "Machin";

 Valeur v(13.0,"Truc");

 v.setNote(a);
 v.setEtudiant(n);

 EXPECT_DOUBLE_EQ ( v.getNombre(), a );
 EXPECT_DOUBLE_EQ ( v.getNote(), a );
 EXPECT_STREQ ( v.getEtudiant().c_str(), n );
}*/

//----------------------------------------------------------------------------------------------- 21
/*TEST ( TP3_Etudiant, AccesseursConstants ) {
 const Valeur v;

 EXPECT_DOUBLE_EQ ( v.getNombre(), 0.0 );
 EXPECT_DOUBLE_EQ ( v.getNote(), 0.0 );
 EXPECT_STREQ ( v.getEtudiant().c_str(), "inconnu" );
}*/

//----------------------------------------------------------------------------------------------- 22
/*TEST ( TP3_Valeurs, Association ) {
 typedef Histogramme<> histo_t;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 EXPECT_EQ ( h.getValeurs().size(), 10u );

 double bornesInf[] = {5.0, 5.0, 5.0, 7.0, 7.0,  9.0,  9.0, 13.0, 13.0, 13.0 };
 double bornesSup[] = {7.0, 7.0, 7.0, 9.0, 9.0, 11.0, 11.0, 15.0, 15.0, 15.0 };
 double notes[]     = {5.0, 6.0, 5.5, 7.0, 8.0,  9.0, 10.0, 14.0, 13.0, 13.5 };

 histo_t::valeurs_t::const_iterator it = h.getValeurs().begin();
 unsigned                           i  = 0;

 while (it!=h.getValeurs().end()) {
  const Classe & c = it->first;
  const Valeur & v = it->second;

  EXPECT_DOUBLE_EQ ( c.getBorneInf(), bornesInf[i] );
  EXPECT_DOUBLE_EQ ( c.getBorneSup(), bornesSup[i] );
  EXPECT_DOUBLE_EQ ( v.getNote(), notes[i] );

  ++it;
  ++i;
 }
}*/

//----------------------------------------------------------------------------------------------- 23
/*TEST ( TP3_Valeurs, Intervalle ) {
 typedef Histogramme<> histo_t;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 EXPECT_EQ ( h.getValeurs().size(), 10u );

 double notes[] = { 5.0, 6.0, 5.5 };

 typedef std::pair<histo_t::it_valeurs_t,histo_t::it_valeurs_t> interval_t;

 interval_t            interval = h.getValeurs(*h.getClasses().begin());
 histo_t::it_valeurs_t it       = interval.first;
 int                   i        = 0;

 while (it!=interval.second) {
  EXPECT_DOUBLE_EQ ( it->second.getNote(), notes[i] );
  ++i;
  ++it;
 }
}*/

// Fin //-------------------------------------------------------------------------------------------
#endif
