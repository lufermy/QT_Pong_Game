#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){

    resize(800,600);// Default window size
    PalaJugador1=new Pala(1,1,width());//Pala Jugador 1
    PalaJugador2=new Pala(2,1,width());//Pala Jugador 2
    Bola1=new Bola(width(),height(),true);// La Bola
    // Frecuencia  de actualización
    temporizador=new QTimer();
    temporizador->setInterval(10);
    temporizador->setSingleShot(false);
    temporizador->start();
    connect(temporizador, SIGNAL(timeout()), this, SLOT(slotRepintar()));
    //
    // Inicio de la puntuacion
    puntos1=0;
    puntos2=0;
    //
    sonido_rebote.setSource(QUrl::fromLocalFile("sounds/boing.wav"));// source: https://freesound.org/people/NoiseCollector/sounds/4359/
    iniciarMenus();
}

void MainWindow::iniciarMenus(){
    menuGame = menuBar()->addMenu("Game");    
    accionReset = new QAction("Reset Score", this);
    accionReset->setStatusTip("Reset Score");
    accionReset->setToolTip("Reset Score");

    menuGame->addAction(accionReset);

    connect(accionReset, SIGNAL(triggered()), this, SLOT(slotReset()));

}


void MainWindow::paintEvent(QPaintEvent *event){
    QPainter pintor(this);
    PalaJugador1->pinta(pintor,10,100);
    PalaJugador2->pinta(pintor,10,100);
    Bola1->pinta(pintor);
    
    // Aqui  se pinta la puntuacion
    QFont fuente;
    fuente.setPixelSize(25);
    pintor.setFont(fuente);
    QColor color=QColor(0,0,0);
    QBrush brush(color);
    pintor.setBrush(brush);
    pintor.drawText(width()/2,40,(QString::number(puntos1)+" - "+QString::number(puntos2))); 

}
void MainWindow::keyPressEvent(QKeyEvent *event){
	//Controles de jugador 1
    if(event->text() == "w"){
        if(PalaJugador1->psY > 0){
        PalaJugador1->psY = PalaJugador1->psY - (height()/20);
        }
    }
    
    if(event->text() == "s"){
    if(PalaJugador1->psY < height()){
        PalaJugador1->psY = PalaJugador1->psY + (height()/20);
    }
    }
	//Controles de jugador 2
    if(event->key() == Qt::Key_Up){
        PalaJugador2->psY = PalaJugador2->psY - (height()/20);
    }

    if(event->key() == Qt::Key_Down){
        PalaJugador2->psY = PalaJugador2->psY + (height()/20);
 }
 }
 void MainWindow::slotRepintar(){
    // pedir al motor Qt que repinte la ventana
    Bola1->mueve(width(),height());
    PalaJugador2->updateJugador2(width());
    if((Bola1->choca(PalaJugador1))||(Bola1->choca(PalaJugador2))){
    	Bola1->velX=-(Bola1->velX);
	sonido_rebote.play();
	//Bola1->upSpeed();
    };
    if(Bola1->psX== 0){
    	Bola1=NULL;
    	Bola1=new Bola(width(),height(),false);
    	puntos2++;
    }else if(Bola1->psX+Bola1->DIAMETRO>=width()){
    	Bola1=NULL;
    	Bola1=new Bola(width(),height(),true);
    	puntos1++;
    }
    update();

}

void MainWindow::slotReset(){
	puntos1=0;
	puntos2=0;
	Bola1=NULL;
    	Bola1=new Bola(width(),height(),true);
}
    
