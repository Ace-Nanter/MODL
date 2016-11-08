#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>

#include "displaydatawidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    // Menu
    QMenuBar * m_menuBar;
    QMenu * m_menuFichier;

    // Actions
    QAction * m_actionQuitter;

    // Widgets personnalisés
    DisplayDataWidget * m_displayWidget;

    // Méthodes
    void createActions();
    void createMenus();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
