#ifndef _PALA_H_
#define _PALA_H_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <cstdlib>
#include <QImage>
#include <QStringList>
class Pala {

public:
	Pala(int,int,int);
	// Variables

	int psY;
	int psX;
	int jugador;// Jugador1 o Jugador2
	QColor color;
	void pinta(QPainter & pintor,int ancho,int alto);
	void updateJugador2(int anchoVentana);

};


#endif
