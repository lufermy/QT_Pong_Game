#ifndef _BOLA_H_
#define _BOLA_H_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <cstdlib>
#include <QImage>
#include <QStringList>
#include "pala.h"
#include <QDebug>
#include <QStatusBar>
#include <QPainter>
#include <math.h>
#include <QBrush>
#include <QSoundEffect>
#include <QStringList>
#include <QRandomGenerator>
class Bola {

public:
	Bola(float psX, float psY,bool side);
	static const int DIAMETRO = 25;
	int colision;
	int colisionParedes;
	float psX;
	float psY;
	float velX;
	float velY;
   	QSoundEffect sonido_rebote;
	QColor color;
	void mueve(int, int); //anchura y altura del area de juego
	void pinta(QPainter & pintor);
	bool choca(Pala * pala);
	void upSpeed();
};


#endif
