/********
* Fichier: testGraphicusGUI.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Ce programme teste l'interface usager GraphicusGUI.
* Modifié par Arthur-Olivier Fortin & Martin Le Gallic
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <QApplication>
#include "mainInterface.h"

int main( int argc, char ** argv )
{
	QApplication app(argc, argv);
	MainInterface gui("Graphicus-03");
	return app.exec();
}
