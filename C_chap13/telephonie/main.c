/**
 * \file main.c
 * \brief contient le main du programme.
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * Super programme permettant au gérant d'une boutique de téléphonie
 * de saisir les clients du jour
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "abo_fixe.h"
#include "abo_mobile.h"
#include "client.h"
#include "gestion_client.h"

char save[] = "save.csv";

int main(int argc, char *argv[])
{
	menu_gestionnaire();
	return 0;
}
