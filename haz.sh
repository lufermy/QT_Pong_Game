#!/bin/bash
make clean
rm *.pro
qmake -project
fichero=$( ls *.pro )
#echo "QT += widgets multimedia multimediawidgets" >> $fichero
echo "CONFIG += warn_off" >>$fichero
echo "QT += widgets charts" >> $fichero
echo "QT += multimedia" >> $fichero
qmake
make

