// Gardien //---------------------------------------------------------------------------------------
#ifndef _TP1_TEST_HPP_
#define _TP1_TEST_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <sstream>
#include <typeinfo>

#include <point.h>
#include <cartesien.h>
#include <polaire.h>
#include <nuage.h>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST ( TP1_Polaire, Constructeur ) {
 const double a = 12.0;
 const double d = 24.0;

 Polaire p(a,d);

 EXPECT_DOUBLE_EQ ( p.getAngle(), a );
 EXPECT_DOUBLE_EQ ( p.getDistance(), d );
}

//------------------------------------------------------------------------------------------------ 2
TEST ( TP1_Polaire, ConstructeurDefaut ) {
 Polaire p;

 EXPECT_DOUBLE_EQ ( p.getAngle(), 0.0 );
 EXPECT_DOUBLE_EQ ( p.getDistance(), 0.0 );
}

//------------------------------------------------------------------------------------------------ 3
TEST ( TP1_Polaire, Accesseurs ) {
 const double a = 12.0;
 const double d = 24.0;

 Polaire p(13.0,25.0);

 p.setAngle(a);
 p.setDistance(d);

 EXPECT_DOUBLE_EQ ( p.getAngle(), a );
 EXPECT_DOUBLE_EQ ( p.getDistance(), d );
}

//------------------------------------------------------------------------------------------------ 4
TEST ( TP1_Polaire, AccesseursConstants ) {
 const Polaire p;

 EXPECT_DOUBLE_EQ ( p.getAngle(), 0.0 );
 EXPECT_DOUBLE_EQ ( p.getDistance(), 0.0 );
}

//------------------------------------------------------------------------------------------------ 5
TEST ( TP1_Polaire, Affichage ) {
 Polaire p(12.0,24.0);
 std::stringstream flux;

 p.afficher(flux);

 EXPECT_EQ ( flux.str(), "(a=12;d=24)" );
}

//------------------------------------------------------------------------------------------------ 6
TEST ( TP1_Cartesien, Constructeur ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesien c(x,y);

 EXPECT_DOUBLE_EQ ( c.getX(), x );
 EXPECT_DOUBLE_EQ ( c.getY(), y );
}

//------------------------------------------------------------------------------------------------ 7
TEST ( TP1_Cartesien, ConstructeurDefaut ) {
 Cartesien c;

 EXPECT_DOUBLE_EQ ( c.getX(), 0.0 );
 EXPECT_DOUBLE_EQ ( c.getY(), 0.0 );
}

//------------------------------------------------------------------------------------------------ 8
TEST ( TP1_Cartesien, Accesseurs ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesien c(13.0,25.0);

 c.setX(x);
 c.setY(y);

 EXPECT_DOUBLE_EQ ( c.getX(), x );
 EXPECT_DOUBLE_EQ ( c.getY(), y );
}

//------------------------------------------------------------------------------------------------ 9
TEST ( TP1_Cartesien, AccesseursConstants ) {
 const Cartesien c;

 EXPECT_DOUBLE_EQ ( c.getX(), 0.0 );
 EXPECT_DOUBLE_EQ ( c.getY(), 0.0 );
}

//----------------------------------------------------------------------------------------------- 10
TEST ( TP1_Cartesien, Affichage ) {
 Cartesien c(12.0,24.0);
 std::stringstream flux;

 c.afficher(flux);

 EXPECT_EQ ( flux.str(), "(x=12;y=24)" );
}

//----------------------------------------------------------------------------------------------- 11
TEST ( TP1_Point, AffichageVirtuel ) {
 Polaire p(12.0,24.0);
 Cartesien c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 p1.afficher(flux1);
 p2.afficher(flux2);

 EXPECT_EQ ( flux1.str(), "(a=12;d=24)" );
 EXPECT_EQ ( flux2.str(), "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 12
TEST ( TP1_Point, OperateurFlux ) {
 Polaire p(12.0,24.0);
 Cartesien c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 flux1 << p1;
 flux2 << p2;

 EXPECT_EQ ( flux1.str(), "(a=12;d=24)" );
 EXPECT_EQ ( flux2.str(), "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 13
TEST ( TP1_Point, ConversionVersPolaire_V1 ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 const Cartesien c(x,y);
 Polaire p;

 c.convertir(p);

 EXPECT_NEAR ( p.getAngle(), a, 1e-3 );
 EXPECT_NEAR ( p.getDistance(), d, 1e-3 );
}

//----------------------------------------------------------------------------------------------- 14
TEST ( TP1_Point, ConversionVersCartesien_V1 ) {
 const double a = 12.0;
 const double d = 24.0;
 const double x = 23.475542;
 const double y = 4.9898805;

 const Polaire p(a,d);
 Cartesien c;

 p.convertir(c);

 EXPECT_NEAR ( c.getX(), x, 1e-3 );
 EXPECT_NEAR ( c.getY(), y, 1e-3 );
}

//----------------------------------------------------------------------------------------------- 15
TEST ( TP1_Point, ConversionVirtuel ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesien c(x,y);
 Polaire p(a,d);

 const Point * x1 = &c;
 const Point * x2 = &p;

 Cartesien c1;
 Cartesien c2;
 Polaire p1;
 Polaire p2;

 x1->convertir(c1);
 x1->convertir(p1);
 x2->convertir(c2);
 x2->convertir(p2);

 EXPECT_NEAR ( c1.getX(), x, 1e-3 );
 EXPECT_NEAR ( c1.getY(), y, 1e-3 );
 EXPECT_NEAR ( c2.getX(), x, 1e-3 );
 EXPECT_NEAR ( c2.getY(), y, 1e-3 );

 EXPECT_NEAR ( p1.getAngle(), a, 1e-3 );
 EXPECT_NEAR ( p1.getDistance(), d, 1e-3 );
 EXPECT_NEAR ( p2.getAngle(), a, 1e-3 );
 EXPECT_NEAR ( p2.getDistance(), d, 1e-3 );
}

//----------------------------------------------------------------------------------------------- 16
TEST ( TP1_Point, ConversionVersPolaire_V2 ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesien c(x,y);
 Polaire p(c);

 EXPECT_NEAR ( p.getAngle(), a, 1e-3 );
 EXPECT_NEAR ( p.getDistance(), d, 1e-3 );
}

//----------------------------------------------------------------------------------------------- 17
TEST ( TP1_Point, ConversionVersCartesien_V2 ) {
 const double a = 12.0;
 const double d = 24.0;
 const double x = 23.475542;
 const double y = 4.9898805;

 Polaire p(a,d);
 Cartesien c(p);

 EXPECT_NEAR ( c.getX(), x, 1e-3 );
 EXPECT_NEAR ( c.getY(), y, 1e-3 );
}

//----------------------------------------------------------------------------------------------- 18
TEST ( TP1_Nuage, Ajout ) {
 Cartesien p1(12.0,24.0);
 Polaire p2(13.0,25.0);
 Polaire p3(p1);
 Cartesien p4(p2);

 Nuage n;

 EXPECT_EQ( n.size(), 0u );

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 EXPECT_EQ ( n.size(), 4u );
}

//----------------------------------------------------------------------------------------------- 19
TEST ( TP1_Nuage, Iterateurs ) {
 Cartesien p1(12.0,24.0);
 Polaire p2(13.0,25.0);
 Polaire p3(p1);
 Cartesien p4(p2);

 Nuage n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Point * t[4];
 unsigned i = 0;
 Nuage::const_iterator it = n.begin();

 while (it!=n.end()) t[i++]=*(it++);

 EXPECT_EQ ( typeid(*(t[0])), typeid(Cartesien) );
 EXPECT_EQ ( typeid(*(t[1])), typeid(Polaire) );
 EXPECT_EQ ( typeid(*(t[2])), typeid(Polaire) );
 EXPECT_EQ ( typeid(*(t[3])), typeid(Cartesien) );

 Cartesien & p5 = *static_cast<Cartesien *>(t[0]);
 Polaire & p6 = *static_cast<Polaire *>(t[1]);
 Polaire & p7 = *static_cast<Polaire *>(t[2]);
 Cartesien & p8 = *static_cast<Cartesien *>(t[3]);

 EXPECT_DOUBLE_EQ ( p5.getX(), 12.0 );
 EXPECT_DOUBLE_EQ ( p5.getY(), 24.0 );
 EXPECT_DOUBLE_EQ ( p6.getAngle(), 13.0 );
 EXPECT_DOUBLE_EQ ( p6.getDistance(), 25.0 );

 EXPECT_NEAR ( p7.getAngle(), 63.434948, 1e-3 );
 EXPECT_NEAR ( p7.getDistance(), 26.832815, 1e-3 );
 EXPECT_NEAR ( p8.getX(), 24.359251, 1e-3 );
 EXPECT_NEAR ( p8.getY(), 5.623776, 1e-3 );
}

//--------------------------------------------------------------------------------------Commun 20-22
double x[] = { 3,7,13,27 };
double y[] = { 4,8,16,32 };

Cartesien p1(x[0],y[0]);
Cartesien p2(x[1],y[1]);
Cartesien p3(x[2],y[2]);
Cartesien p4(x[3],y[3]);

Nuage n;

//----------------------------------------------------------------------------------------------- 20
TEST ( TP1_Nuage, Barycentre ) {
 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b = barycentre(n);

 EXPECT_DOUBLE_EQ ( b.getX(), (x[0]+x[1]+x[2]+x[3])/4 );
 EXPECT_DOUBLE_EQ ( b.getY(), (y[0]+y[1]+y[2]+y[3])/4 );
}

//----------------------------------------------------------------------------------------------- 21
TEST ( TP1_Nuage, BarycentreCartesien ) {
 Cartesien b = BarycentreCartesien()(n);

 EXPECT_DOUBLE_EQ ( b.getX(), (x[0]+x[1]+x[2]+x[3])/4 );
 EXPECT_DOUBLE_EQ ( b.getY(), (y[0]+y[1]+y[2]+y[3])/4 );
}

//----------------------------------------------------------------------------------------------- 22
TEST ( TP1_Nuage, BarycentrePolaire ) {
 Polaire p(Cartesien((x[0]+x[1]+x[2]+x[3])/4,(y[0]+y[1]+y[2]+y[3])/4));
 Polaire b = BarycentrePolaire()(n);

 EXPECT_DOUBLE_EQ ( b.getAngle(), p.getAngle() );
 EXPECT_DOUBLE_EQ ( b.getDistance(), p.getDistance() );
}

// Fin //-------------------------------------------------------------------------------------------
#endif