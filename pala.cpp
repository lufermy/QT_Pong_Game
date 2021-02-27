#include "pala.h"
#include <QDebug>
#include <QStatusBar>
#include <QPainter>
#include <math.h>
#include <QBrush>
#include <QStringList>
#include <QRandomGenerator>
Pala::Pala(int jugador,int psY,int tamanoventana){
        color=QColor(0,0,0);
	if(jugador==1){
	this->psX= 10;
	}else{
	this->psX=tamanoventana-20;
	}
	this->jugador=jugador;
	this->psY=psY;
}

void Pala::pinta(QPainter &pintor,int ancho, int alto){
    QBrush brush(color);
    pintor.setBrush(brush);
    pintor.drawRect(this->psX,this->psY,ancho,alto);    
}

void Pala::updateJugador2(int anchoVentana){
	this->psX=anchoVentana-20;
}
