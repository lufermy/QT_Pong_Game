#include "bola.h"

Bola::Bola(float psX, float psY,bool side){
    this->psX = psX/2;
    this->psY = psY/2;
    QRandomGenerator generator;
    if (side){
    	this->velX = 2;
    	this->velY = 2;
    }else{
    	this->velX = -2;
    	this->velY = -2;
    }
    
    this->colision = 0;
    this->colisionParedes = 0;
    color=QColor(0,0,0);
    sonido_rebote.setSource(QUrl::fromLocalFile("sounds/boing.wav"));// source: https://freesound.org/people/NoiseCollector/sounds/4359/
}

void Bola::mueve(int ancho, int alto){

    if(psX>=ancho-DIAMETRO){
        velX= -fabs(velX);
        colisionParedes++;

    }

    if(psX <=0){
        velX= fabs(velX);
        colisionParedes++;
        
    }

    if(psY>=alto -DIAMETRO){
        velY= -fabs(velY);
        colisionParedes++;
        sonido_rebote.play();
    }

    if(psY <=20){
        velY= fabs(velY);
        colisionParedes++;
        sonido_rebote.play();
    }


    psY=psY+velY;
    psX=psX+velX;
}

void Bola::pinta(QPainter &pintor){

    QBrush brush(color);
    pintor.setBrush(brush);
    pintor.drawEllipse(psX,psY, Bola::DIAMETRO, Bola::DIAMETRO);
}
bool Bola::choca(Pala *pala){
    bool choca=false;
    if((Bola::psY+DIAMETRO/2 > pala->psY)&&(Bola::psY-DIAMETRO/2 < pala->psY+100)){
    	if(pala->jugador==1){
    		if((Bola::psX+DIAMETRO/2 == pala->psX+10)&&(Bola::psX-DIAMETRO/2 <=pala->psX)){
    		choca=true;
    		}
    	}else{
    	if((Bola::psX+DIAMETRO/2 == pala->psX-10)&&(Bola::psX-DIAMETRO/2 <=pala->psX)){
    		choca=true;
    		}
    	}
    }
    return choca;

}

void Bola::upSpeed(){
	if(this->velX<0){
		this->velX=this->velX-0.05;
	}else{
		this->velX=this->velX+0.05;
	}
	
	if(this->velY<0){
		this->velY=this->velY-0.05;
	}else{
		this->velY=this->velY+0.05;
	}
}
