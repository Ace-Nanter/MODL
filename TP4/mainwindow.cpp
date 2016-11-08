#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    this->resize(800, 600);

    createActions();
    createMenus();

    m_displayWidget = new DisplayDataWidget;
    setCentralWidget(m_displayWidget);
}

MainWindow::~MainWindow()
{ }

void MainWindow::createActions() {
    m_actionQuitter = new QAction("Quitter", this);
    m_actionQuitter->setShortcut(QKeySequence::Close);

    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus() {
    m_menuBar = new QMenuBar();

    m_menuFichier = m_menuBar->addMenu("Fichier");
    m_menuFichier->addAction(m_actionQuitter);

    this->setMenuBar(m_menuBar);
}
