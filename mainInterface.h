/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
* Modifié par Arthur-Olivier Fortin & Martin Le Gallic
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include "graphicusGUI.h"
#include "headers/layer.h"


class MainInterface : public GraphicusGUI
{
public:
	MainInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();

	// File actions

	bool ouvrirFichier(const char* nom);
	bool sauvegarderFichier(const char* nom);
	

	// Caneva, layer and shape actions

	void coucheAjouter();
	void coucheRetirer();
	void coucheTranslater(int deltaX, int deltaY);
	
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	
	void retirerForme();
	void modePileChange(bool mode);


	// Navigation actions

	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();

	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();

private:
	Informations infos;
	Vector<Layer> layers;

};

#endif