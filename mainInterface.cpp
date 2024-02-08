/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
* Modifié par Arthur-Olivier Fortin & Martin Le Gallic
* 
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <iostream>
#include <fstream>
#include <sstream>

#include "mainInterface.h"

#include "headers/circle.h"
#include "headers/square.h"

using namespace std;

MainInterface::MainInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	effacerInformations();
}

void MainInterface::reinitialiserCanevas()
{

	layers.purge();

	infos.nbCouches = 0;
	infos.nbFormesCanevas = 0;
	infos.coucheActive = -1;
	infos.aireCanevas = 0;
	infos.nbFormesCouche = 0;

	infos.aireCouche = 0;
	infos.formeActive = -1;
	
	infos.coordX = 0;
	infos.coordY = 0;
	infos.aireForme = 0;

	coucheAjouter();

	setInformations(infos);
}

bool MainInterface::ouvrirFichier(const char* nom)
{
	// TODO : Implement


	return true;
}

bool MainInterface::sauvegarderFichier(const char* nom)
{
	// TODO : Implement
	ofstream file(nom);

	for (int i = 0; i < layers.getSize(); i++)
	{
		file << layers[i]->toString();
	}

	file.close();

	return true;
}



void MainInterface::coucheAjouter()
{
	// TODO : Implement & Test
	if (infos.coucheActive >= 0) { layers[infos.coucheActive]->changeState(INACTIVE); }

	Layer *new_layer = new Layer();
	new_layer->changeState(ACTIVE);

	layers += new_layer;

	infos.nbCouches += 1;
	infos.coucheActive = layers.getSize() - 1;

	message("Une nouvelle couche a été ajoutée et sélectionnée");

	setInformations(infos);
}

void MainInterface::coucheRetirer()
{
	// TODO : Implement & Test
	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active à supprimer");
		return;
	}

	delete layers.removeElement(infos.coucheActive);

	infos.nbCouches -= 1;
	infos.coucheActive = -1;

	setInformations(infos);

	updateCaneva();
}

void MainInterface::coucheTranslater(int deltaX, int deltaY)
{
	// TODO : Implement
	layers[infos.coucheActive]->translate(deltaX, deltaY);

	updateCaneva();
}

void MainInterface::ajouterCercle(int x, int y, int rayon)
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE) { layers[i]->addElement(new Circle(x, y, rayon)); }
		infos.formeActive = layers[i]->getSize() - 1;
	}
	setInformations(infos);

	updateCaneva();

}

void MainInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE) { layers[i]->addElement(new Rectangle(x, y, largeur, longueur)); }
		infos.formeActive = layers[i]->getSize() - 1;
	}
	setInformations(infos);

	updateCaneva();
}

void MainInterface::ajouterCarre(int x, int y, int cote)
{
	// TODO : Implement

	layers[infos.coucheActive]->addElement(new Square(x, y, cote)); 
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;

	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);

	updateCaneva();
}

void MainInterface::retirerForme()
{
	// TODO : Implement

	cout << "Deleting selected shape [" << infos.formeActive << "] on layer [" << infos.coucheActive << "]" << endl;

	delete layers[infos.coucheActive]->removeElement(infos.formeActive);
	infos.formeActive = -1;

	strcpy(infos.etatCouche, "");
	setInformations(infos);

	updateCaneva();
}

void MainInterface::modePileChange(bool mode)
{
	// TODO : Implement
}



void MainInterface::couchePremiere()
{
	// TODO : Implement
	infos.coucheActive = 0;
	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);
}

void MainInterface::couchePrecedente()
{
	// TODO : Implement
	if (infos.coucheActive > 0) { infos.coucheActive--; }
	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);
}

void MainInterface::coucheSuivante()
{
	// TODO : Implement
	if (infos.coucheActive < layers.getSize() - 1) { infos.coucheActive++; }
	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);
}

void MainInterface::coucheDerniere()
{
	// TODO : Implement
	infos.coucheActive = layers.getSize() - 1;
	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);
}

void MainInterface::formePremiere()
{
	// TODO : Implement
	infos.formeActive = 0;
	setInformations(infos);
}

void MainInterface::formePrecedente()
{
	// TODO : Implement
	if (infos.formeActive > 0) { infos.formeActive--; }
	setInformations(infos);
}

void MainInterface::formeSuivante()
{
	// TODO : Implement
	if (infos.formeActive < layers[infos.coucheActive]->getSize() - 1) { infos.formeActive++; }
	setInformations(infos);
}

void MainInterface::formeDerniere()
{
	// TODO : Implement
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;
	setInformations(infos);
}

void MainInterface::updateCaneva()
{
	effacer();

	ostringstream os;
	for (int i = 0; i < infos.nbCouches; i++)
	{
		os << layers[i]->toString() << endl;
	}

	cout << os.str() << endl;

	dessiner(os.str().c_str());
}



