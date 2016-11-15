#include "displaydatawidget.h"

DisplayDataWidget::DisplayDataWidget(QWidget *parent)
     : QWidget(parent)
{
    createAreas();
}

DisplayDataWidget::~DisplayDataWidget() { }

void DisplayDataWidget::createAreas() {

    // Creation Layout
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setVerticalSpacing(50);

    // Creations widgets valeurs
    m_valueList = new QTextEdit("Coucou", this);
    m_valueList->setFixedHeight(200);

    m_nbValues = new QLabel("0", this);
    m_average = new QLabel("0", this);
    m_standDev = new QLabel("0", this);

    // Ajout des widgets au layout
    m_gridLayout->addWidget(new QLabel("Nombre de valeurs", this), 0, 0, 1, 1);
    m_gridLayout->addWidget(new QLabel("Moyenne", this), 0, 1, 1, 1);
    m_gridLayout->addWidget(new QLabel("Ecart-type", this), 0, 2, 1, 1);
    m_gridLayout->addWidget(m_nbValues, 2, 0, 1, 1);
    m_gridLayout->addWidget(m_average, 2, 1, 1, 1);
    m_gridLayout->addWidget(m_standDev, 2, 2, 1, 1);

    m_gridLayout->addWidget(m_valueList, 4, 0, 1, 3);

    // Mise en place du layout
    setLayout(m_gridLayout);
}

/*
void DisplayDataWidget::setEchantillon(const Echantillon & e) {
    m_echantillon = e;
}
*/
