#ifndef DISPLAYDATAWIDGET_H
#define DISPLAYDATAWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>

//#include "echantillon.h"

class DisplayDataWidget : public QWidget
{
    Q_OBJECT

    private:

        // Widgets
        QTextEdit * m_valueList;

        // Valeurs
        QLabel * m_nbValues;
        QLabel * m_average;
        QLabel * m_standDev;

        // Layout
        QGridLayout * m_gridLayout;

        // Données
        //Echantillon & m_echantillon;

        // Méthodes
        void createAreas();

    public:
        explicit DisplayDataWidget(QWidget *parent = 0);
        ~DisplayDataWidget();

        //void setEchantillon(const Echantillon &);
};

#endif // DISPLAYDATAWIDGET_H
