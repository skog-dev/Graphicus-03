/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <iostream>
#include <sstream>
#include "mainInterface.h"

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
	return true;
}

bool MainInterface::sauvegarderFichier(const char* nom)
{
	// TODO : Implement
	return true;
}



void MainInterface::coucheAjouter()
{
	// TODO : Implement
}

void MainInterface::coucheRetirer()
{
	// TODO : Implement
}

void MainInterface::coucheTranslater(int deltaX, int deltaY)
{
	// TODO : Implement
}

void MainInterface::ajouterCercle(int x, int y, int rayon)
{
	// TODO : Implement
}

void MainInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	// TODO : Implement
}

void MainInterface::ajouterCarre(int x, int y, int cote)
{
	// TODO : Implement
}

void MainInterface::retirerForme()
{
	// TODO : Implement
}

void MainInterface::modePileChange(bool mode)
{
	// TODO : Implement
}



void MainInterface::couchePremiere()
{
	// TODO : Implement
}

void MainInterface::couchePrecedente()
{
	// TODO : Implement
}

void MainInterface::coucheSuivante()
{
	// TODO : Implement
}

void MainInterface::coucheDerniere()
{
	// TODO : Implement
}

void MainInterface::formePremiere()
{
	// TODO : Implement
}

void MainInterface::formePrecedente()
{
	// TODO : Implement
}

void MainInterface::formeSuivante()
{
	// TODO : Implement
}

void MainInterface::formeDerniere()
{
	// TODO : Implement
}



