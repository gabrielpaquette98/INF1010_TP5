/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteurs: Ryan Hardie, 1899088 et 1894061
*******************************************/

#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

#pragma once

#include "./Foncteur.h"

//T: donnees (produit ou usager);
//C: conteneur (multimap, set, etc);
//A: type des foncteurs d'ajout
//S: type des foncteurs de suppression
template<typename T, typename C, typename A, typename S>

class GestionnaireGenerique {

public:

	C obtenirConteneur() {
		return conteneur_;
	}

	void ajouter(T* element) {

		switch (typeid(T)) {

		case typeid(Usager) :
			AjouterUsager foncteurAjoutUsager(conteneur_);
			const Usager* usager = dynamic_cast<Usager*>(element);
			foncteurAjoutUsager(usager);
			break;

		case typeid(Produit) :
			AjouterProduit foncteurAjoutProduit(conteneur_);
			const Produit* produit* = dynamic_cast<Produit*>(element);
			foncteurAjoutProduit(produit);
			break;

		default:
			break;

		}

	}

	void supprimer(T* element) {

		switch (typeid(T)) {

		case typeid(Usager) :
			SupprimerUsager foncteurSupprUsager(conteneur_);
			const Usager* usager = dynamic_cast<Usager*>(element);
			foncteurSupprUsager(usager);
			break;

		case typeid(Produit) :
			SupprimerProduit foncteurSupprProduit(conteneur_);
			const Produit* produit = dynamic_cast<Produit*>(element);
			foncteurSupprProduit(produit);
			break;

		default:
			break;

		}

	}

	// TODO verifier
	template<typename Predicate>
	void pourChaqueElement(Predicate foncteur) {

		for_each(conteneur_.begin(), conteneur_.end(), foncteur);

	}

protected:
	C conteneur_;

};

#endif // !GESTIONNAIREGENERIQUE_H