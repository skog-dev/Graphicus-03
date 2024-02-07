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
	ostringstream os;

	os << "L a" << endl;
	os << "R -50 -50 120 60" << endl;
	os << "K 40 120 60" << endl;
	os << "C 120 40 60" << endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());
}

bool MainInterface::ouvrirFichier(const char* nom)
{
	// TODO : Implement
	// The full  path is contained in the nom variable
	FILE* file = fopen(nom, "r");



	return true;
}

bool MainInterface::sauvegarderFichier(const char* nom)
{
	// TODO : Implement
	// The full  path is contained in the nom variable
	ofstream file(nom);

	for (int i = 0; i < layers.getSize(); i++)
	{
		file << "L ";

		switch (layers[i]->getState()) 
		{
			case 0:
				file << "x" << endl;
				break;

			case 1:
				file << "a" << endl;
				break;
			
			default:
				file << "i" << endl;
				break;
		}

		for (int j = 0; j < layers[i]->getSize(); j++)
		{
			layers[i]->getElement(j)->printTo(file);
		}

	}

	file.close();

	return true;
}



void MainInterface::coucheAjouter()
{
	// TODO : Implement & Test
	layers += new Layer();
	infos.nbCouches += 1;
	infos.coucheActive = layers.getSize() - 1;
}

void MainInterface::coucheRetirer()
{
	// TODO : Implement & Test
	if (layers.isEmpty())
	{
		messageErreur("Aucune couche à supprimer");
		return;
	}
	delete layers.removeElement(layers.getSize() - 1);
	infos.nbCouches -= 1;
}

void MainInterface::coucheTranslater(int deltaX, int deltaY)
{
	// TODO : Implement
}

void MainInterface::ajouterCercle(int x, int y, int rayon)
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE) { layers[i]->addElement(new Circle(x, y, rayon)); }
		infos.formeActive = layers[i]->getSize();
	}

}

void MainInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE) { layers[i]->addElement(new Rectangle(x, y, largeur, longueur)); }
		infos.formeActive = layers[i]->getSize();
	}
}

void MainInterface::ajouterCarre(int x, int y, int cote)
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE) { layers[i]->addElement(new Square(x, y, cote)); }
		infos.formeActive = layers[i]->getSize();
	}
}

void MainInterface::retirerForme()
{
	// TODO : Implement
	for (int i = 0; i < layers.getSize(); i++)
	{
		if (layers[i]->getState() == ACTIVE)
		{
			layers[i]->removeElement(infos.formeActive);
			infos.formeActive = -1;
		}

	}
}

void MainInterface::modePileChange(bool mode)
{
	// TODO : Implement
}



void MainInterface::couchePremiere()
{
	// TODO : Implement
	infos.coucheActive = 0;
}

void MainInterface::couchePrecedente()
{
	// TODO : Implement
	if (infos.coucheActive > 0) { infos.coucheActive--; }
}

void MainInterface::coucheSuivante()
{
	// TODO : Implement
	if (infos.coucheActive > layers.getSize() - 1) { infos.coucheActive++; }
}

void MainInterface::coucheDerniere()
{
	// TODO : Implement
	infos.coucheActive = layers.getSize() - 1;
}

void MainInterface::formePremiere()
{
	// TODO : Implement
	infos.formeActive = 0;
}

void MainInterface::formePrecedente()
{
	// TODO : Implement
	if (infos.formeActive > 0) { infos.formeActive--; }
}

void MainInterface::formeSuivante()
{
	// TODO : Implement
	if (infos.formeActive > layers[infos.coucheActive]->getSize() - 1) { infos.formeActive++; }
}

void MainInterface::formeDerniere()
{
	// TODO : Implement
	infos.formeActive = layers[infos.coucheActive]->getSize() - 1;
}



