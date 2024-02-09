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
#include <stdio.h>

#include "mainInterface.h"

#include "headers/circle.h"
#include "headers/square.h"

using namespace std;

MainInterface::MainInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	coucheAjouter();
}

void MainInterface::reinitialiserCanevas()
{
	effacerInformations();

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

	setInformations(infos);

	updateCaneva();
}

bool MainInterface::ouvrirFichier(const char* nom)
{
	ifstream file(nom);

	std::string in;
	char first;

	reinitialiserCanevas();

	while (file)
	{
		first = ' ';
		file >> first;

		cout << "first char is " << first << endl;

		switch (first)
		{

		case 'L':
			coucheAjouter();
			break;

		case 'K':
		{
			int x, y, s;
			file >> x >> y >> s;
			ajouterCarre(x, y, s);
		}
			break;

		case 'R':
		{
			int x, y, w, h;
			file >> x >> y >> w >> h;
			ajouterRectangle(x, y, w, h);
		}
			break;

		case 'C':
		{
			int x, y, r;
			file >> x >> y >> r;
			ajouterCercle(x, y, r);
		}
			break;

		default:
			break;
		}
	}

	setInformations(infos);
	updateCaneva();

	return true;
}

bool MainInterface::sauvegarderFichier(const char* nom)
{
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
	if (infos.coucheActive >= 0) { layers[infos.coucheActive]->changeState(INACTIVE); }

	Layer *new_layer = new Layer();
	new_layer->changeState(ACTIVE);

	layers += new_layer;

	infos.nbCouches += 1;
	infos.coucheActive = layers.getSize() - 1;

	message("Une nouvelle couche a été ajoutée et sélectionnée");

	layers[infos.coucheActive]->getStateStr(infos.etatCouche);
	setInformations(infos);
}

void MainInterface::coucheRetirer()
{
	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active à supprimer");
		return;
	}

	delete layers.removeElement(infos.coucheActive);

	infos.nbCouches -= 1;
	infos.coucheActive = -1;

	strcpy(infos.etatCouche, "");
	setInformations(infos);

	updateCaneva();
}

void MainInterface::coucheTranslater(int deltaX, int deltaY)
{
	layers[infos.coucheActive]->translate(deltaX, deltaY);

	updateLayerInfo(layers[infos.coucheActive]);
	updateShapeInfo(layers[infos.coucheActive]->getElement(infos.formeActive));
	setInformations(infos);

	updateCaneva();
}

void MainInterface::ajouterCercle(int x, int y, int rayon)
{
	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active pour l'ajout");
		return;
	}

	Shape* circle = new Circle(x, y, rayon);
	layers[infos.coucheActive]->addElement(circle);

	infos.nbFormesCanevas += 1;
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;
	
	updateShapeInfo(circle);
	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);

	updateCaneva();
}

void MainInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active pour l'ajout");
		return;
	}

	Shape* rectangle = new Rectangle(x, y, largeur, longueur);
	layers[infos.coucheActive]->addElement(rectangle);

	infos.nbFormesCanevas += 1;
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;

	updateShapeInfo(rectangle);
	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);

	updateCaneva();
}

void MainInterface::ajouterCarre(int x, int y, int cote)
{
	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active pour l'ajout");
		return;
	}

	Shape* square = new Square(x, y, cote);
	layers[infos.coucheActive]->addElement(square); 

	infos.nbFormesCanevas += 1;
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;
	
	updateShapeInfo(square);
	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);

	updateCaneva();
}

void MainInterface::retirerForme()
{
	if (infos.formeActive < 0)
	{
		messageErreur("Aucune forme active a retirer");
		return;
	}

	if (infos.coucheActive < 0)
	{
		messageErreur("Aucune couche active pour retirer");
		return;
	}

	cout << "Deleting selected shape [" << infos.formeActive << "] on layer [" << infos.coucheActive << "]" << endl;

	delete layers[infos.coucheActive]->removeElement(infos.formeActive);
	infos.formeActive = -1;

	setInformations(infos);

	updateCaneva();
}

void MainInterface::modePileChange(bool mode)
{
	if (mode) message("Le mode pile a ete desactive");
	else message("Le mode pile a ete active");
	isPile = mode;

	updateCaneva();
}


void MainInterface::couchePremiere()
{
	if (isPile)
	infos.coucheActive = 0;
	
	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);
}

void MainInterface::couchePrecedente()
{
	if (infos.coucheActive > 0) { infos.coucheActive--; }

	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);
}

void MainInterface::coucheSuivante()
{
	if (infos.coucheActive < layers.getSize() - 1) { infos.coucheActive++; }

	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);
}

void MainInterface::coucheDerniere()
{
	infos.coucheActive = layers.getSize() - 1;

	updateLayerInfo(layers[infos.coucheActive]);
	setInformations(infos);
}

void MainInterface::formePremiere()
{
	infos.formeActive = 0;

	updateShapeInfo(layers[infos.coucheActive]->getElement(infos.formeActive));
	setInformations(infos);
}

void MainInterface::formePrecedente()
{
	if (infos.formeActive > 0) { infos.formeActive--; }

	updateShapeInfo(layers[infos.coucheActive]->getElement(infos.formeActive));
	setInformations(infos);
}

void MainInterface::formeSuivante()
{
	if (infos.formeActive < layers[infos.coucheActive]->getSize() - 1) { infos.formeActive++; }

	updateShapeInfo(layers[infos.coucheActive]->getElement(infos.formeActive));
	setInformations(infos);
}

void MainInterface::formeDerniere()
{
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;

	updateShapeInfo(layers[infos.coucheActive]->getElement(infos.formeActive));
	setInformations(infos);
}

void MainInterface::updateCaneva()
{
	effacer();

	ostringstream os;

	if (!isPile)
	{
		for (int i = 0; i < infos.nbCouches; i++)
		{
			os << layers[i]->toString() << endl;
		}
	}
	else
	{
		for (int i = infos.nbCouches - 1; i >= 0; i--)
		{
			os << layers[i]->toString() << endl;
		}
	}


	cout << os.str() << endl;

	dessiner(os.str().c_str());
}

void MainInterface::updateShapeInfo(Shape *shape)
{
	infos.coordX = shape->getAncrage().x;
	infos.coordY = shape->getAncrage().y;

	infos.aireForme = shape->area();
	shape->stateString(infos.informationForme);
}

void MainInterface::updateLayerInfo(Layer* layer)
{
	infos.nbFormesCouche = layer->getSize();
	layer->getStateStr(infos.etatCouche);

}

