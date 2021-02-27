#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_
#include <QDebug>
#include <QString>
#include <QMainWindow>
#include <QColor>
#include <QPalette>
#include <QPainter>
#include <QTimer>
#include <QFont>
#include <QSoundEffect>
#include <QTime>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "pala.h"
#include "bola.h"

class MainWindow : public QMainWindow{

Q_OBJECT

public:
	MainWindow(QWidget *parent = NULL);
    	Pala *PalaJugador1;
    	Pala *PalaJugador2;
    	Bola *Bola1;
	QAction * accionReset;
	QMenu *menuGame;
    	int puntos1;
    	int puntos2;
    	QSoundEffect sonido_rebote;
    	QTimer *temporizador;
    	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void iniciarMenus();
public slots:
	void slotRepintar();
	void slotReset();
signals:
	
private:
    


};


#endif
