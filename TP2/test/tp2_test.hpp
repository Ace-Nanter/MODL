// Gardien //---------------------------------------------------------------------------------------
#ifndef _TP2_TEST_HPP_
#define _TP2_TEST_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <cmath>

//#include <cosinus.hpp>
//#include <exponentielle.hpp>
#include <point.h>
#include <cartesien.h>
#include <polaire.h>
#include <nuage.h>
#include <factorielle.h>
#include <puissance.h>
#include <exponentielle.h>
#include <cosinus.h>
#include <sinus.h>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST ( TP2_Nuage, Ajout ) {
 Nuage<Cartesien> n;

 EXPECT_EQ( n.size(), 0u );

 n.ajouter(Cartesien(12,34));
 n.ajouter(Cartesien(56,78));
 n.ajouter(Cartesien(90,12));
 n.ajouter(Cartesien(34,56));

 EXPECT_EQ ( n.size(), 4u );
}

//------------------------------------------------------------------------------------------------ 2
TEST ( TP2_Nuage, Iterateurs ) {
 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Nuage<Polaire> n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire t[4];
 unsigned i = 0;
 Nuage<Polaire>::const_iterator it = n.begin();

 while (it!=n.end()) t[i++]=*(it++);

 EXPECT_DOUBLE_EQ ( t[0].getAngle(), p1.getAngle() );
 EXPECT_DOUBLE_EQ ( t[0].getDistance(), p1.getDistance() );
 EXPECT_DOUBLE_EQ ( t[1].getAngle(), p2.getAngle() );
 EXPECT_DOUBLE_EQ ( t[1].getDistance(), p2.getDistance() );
 EXPECT_DOUBLE_EQ ( t[2].getAngle(), p3.getAngle() );
 EXPECT_DOUBLE_EQ ( t[2].getDistance(), p3.getDistance() );
 EXPECT_DOUBLE_EQ ( t[3].getAngle(), p4.getAngle() );
 EXPECT_DOUBLE_EQ ( t[3].getDistance(), p4.getDistance() );
}

//------------------------------------------------------------------------------------------------ 3
/*TEST ( TP2_Nuage, BarycentreCartesien_V1 ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b1.getX(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getY(), 0.0 );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b2.getX(), p1.getX() );
 EXPECT_DOUBLE_EQ ( b2.getY(), p1.getY() );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b3.getX(), (p1.getX()+p2.getX()+p3.getX()+p4.getX())/4 );
 EXPECT_DOUBLE_EQ ( b3.getY(), (p1.getY()+p2.getY()+p3.getY()+p4.getY())/4 );
}*/

//----------------------------------------------------------------------------------------------- 4a
/*TEST ( TP2_Nuage, BarycentrePolaire_V1 ) {
 Nuage<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b1.getAngle(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getDistance(), 0.0 );

 n.ajouter(p1);

 Polaire b2 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b2.getAngle(), p1.getAngle() );
 EXPECT_DOUBLE_EQ ( b2.getDistance(), p1.getDistance() );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire b3 = barycentre_v1(n);

 EXPECT_NEAR ( b3.getAngle(), 43.017260, 1e-3 );
 EXPECT_NEAR ( b3.getDistance(), 42.159772, 1e-3 );
}*/

//----------------------------------------------------------------------------------------------- 4b
/*TEST ( TP2_Nuage, BarycentrePolaire_V1 ) {
 Nuage<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b1.getAngle(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getDistance(), 0.0 );

 n.ajouter(p1);

 Polaire b2 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b2.getAngle(), p1.getAngle() );
 EXPECT_DOUBLE_EQ ( b2.getDistance(), p1.getDistance() );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire b3 = barycentre_v1(n);

 EXPECT_DOUBLE_EQ ( b3.getAngle(), (p1.getAngle()+p2.getAngle()
                                    +p3.getAngle()+p4.getAngle())/4 );

 EXPECT_DOUBLE_EQ ( b3.getDistance(), (p1.getDistance()+p2.getDistance()
                                       +p3.getDistance()+p4.getDistance())/4 );
}*/

//------------------------------------------------------------------------------------------------ 5
TEST ( TP2_Nuage, BarycentreCartesien_V2 ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b1.getX(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getY(), 0.0 );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b2.getX(), p1.getX() );
 EXPECT_DOUBLE_EQ ( b2.getY(), p1.getY() );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b3.getX(), (p1.getX()+p2.getX()+p3.getX()+p4.getX())/4 );
 EXPECT_DOUBLE_EQ ( b3.getY(), (p1.getY()+p2.getY()+p3.getY()+p4.getY())/4 );
}

//------------------------------------------------------------------------------------------------ 6
TEST ( TP2_Nuage, BarycentreCartesienVecteur ) {
 std::vector<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b1.getX(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getY(), 0.0 );

 n.push_back(p1);

 Cartesien b2 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b2.getX(), p1.getX() );
 EXPECT_DOUBLE_EQ ( b2.getY(), p1.getY() );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Cartesien b3 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b3.getX(), (p1.getX()+p2.getX()+p3.getX()+p4.getX())/4 );
 EXPECT_DOUBLE_EQ ( b3.getY(), (p1.getY()+p2.getY()+p3.getY()+p4.getY())/4 );
}

//------------------------------------------------------------------------------------------------ 7
TEST ( TP2_Nuage, BarycentrePolaire_V2 ) {
 std::vector<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b1.getAngle(), 0.0 );
 EXPECT_DOUBLE_EQ ( b1.getDistance(), 0.0 );

 n.push_back(p1);

 Polaire b2 = barycentre_v2(n);

 EXPECT_DOUBLE_EQ ( b2.getAngle(), p1.getAngle() );
 EXPECT_DOUBLE_EQ ( b2.getDistance(), p1.getDistance() );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Polaire b3 = barycentre_v2(n);

 EXPECT_NEAR ( b3.getAngle(), 43.017260, 1e-3 );
 EXPECT_NEAR ( b3.getDistance(), 42.159772, 1e-3 );
}

//------------------------------------------------------------------------------------------------ 8
TEST ( TP2_Metaprog, Factorielle ) {
 unsigned long f1 = Factorielle<1>::valeur;
 unsigned long f5 = Factorielle<5>::valeur;

 EXPECT_EQ ( f1, 1u );
 EXPECT_EQ ( f5, 5u*4u*3u*2u );
}

//------------------------------------------------------------------------------------------------ 9
TEST ( TP2_Metaprog, Puissance ) {
 EXPECT_DOUBLE_EQ ( Puissance<0>::valeur(3.0), 1.0 );
 EXPECT_DOUBLE_EQ ( Puissance<1>::valeur(3.0), 3.0 );
 EXPECT_DOUBLE_EQ ( Puissance<4>::valeur(3.0), 3.0*3.0*3.0*3.0 );
}

//----------------------------------------------------------------------------------------------- 10
TEST ( TP2_Metaprog, Exponentielle ) {
 EXPECT_NEAR ( Exponentielle<4>::valeur(0.0), std::exp(0.0), 1e-3 );
 EXPECT_NEAR ( Exponentielle<10>::valeur(-2.5), std::exp(-2.5), 1e-3 );
 EXPECT_NEAR ( Exponentielle<7>::valeur(1.4), std::exp(1.4), 1e-3 );
}

//----------------------------------------------------------------------------------------------- 11
TEST ( TP2_Metaprog, Cosinus ) {
 EXPECT_NEAR ( Cosinus<1>::valeur(0.0), std::cos(0.0), 1e-3 );
 EXPECT_NEAR ( Cosinus<4>::valeur(-2.0), std::cos(-2.0), 1e-3 );
 EXPECT_NEAR ( Cosinus<3>::valeur(1.0), std::cos(1.0), 1e-3 );
}

//----------------------------------------------------------------------------------------------- 12
TEST ( TP2_Metaprog, Sinus ) {
 EXPECT_NEAR ( Sinus<3>::valeur(0.0), std::sin(0.0), 1e-3 );
 EXPECT_NEAR ( Sinus<5>::valeur(-2.0), std::sin(-2.0), 1e-3 );
 EXPECT_NEAR ( Sinus<4>::valeur(1.0), std::sin(1.0), 1e-3 );
}

// Fin //-------------------------------------------------------------------------------------------
#endif
