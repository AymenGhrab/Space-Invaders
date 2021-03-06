#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ennemi.h"

/***********-------------- ENNEMI 1------------------**************/


void initialiser_ennemi1(ennemi *en1)
{
en1->position_entite.x=2500;
en1->position_entite.y=200;
en1->position_entite.w=448;
en1->position_entite.h=373;
en1->direction=0;
	char entites[10];
	int i;
  for ( i = 0; i < 10; i++)
  {
      sprintf(entites,"ennemi/en1/%d.png",i);
    en1->affichage_secondaire[i]=IMG_Load(entites); /*imgLoad file for use as an image in a new surface*/
    /*affichage secondaire est un pointeur de sdl surface */
  }
en1->Frame=0;
en1->speed=35;
}

void initialiser_ennemi2(ennemi *en2)
{
en2->position_entite.x=3325;
en2->position_entite.y=50;
en2->position_entite.w=448;
en2->position_entite.h=373;
  char entites[10];
  int i;
  for ( i = 0; i < 10; i++)
  {
      sprintf(entites,"ennemi/en2/%d.png",i);
    en2->affichage_secondaire[i]=IMG_Load(entites);
  }
en2->Frame=0; en2->speed=35;
}

void afficher_ennemi1(ennemi en1, SDL_Surface *ecran)
{
SDL_BlitSurface(en1.affichage_secondaire[en1.Frame],NULL,ecran ,&(en1.position_entite));
/*SDL_BlitSurface(surface, &source_rect=position, temp_surface=ecran, NULL);*/
}


void afficher_ennemi2(ennemi en2, SDL_Surface *ecran)
{
SDL_BlitSurface(en2.affichage_secondaire[en2.Frame],NULL,ecran ,&(en2.position_entite));
}


/*-- animation gauche/droite -- */

void animation_droite (ennemi *en1)
{
	if(en1->Frame<=0 || en1->Frame>=9)
	{
	//printf("hello!");
	en1->Frame=1;
	}
	en1->Frame++;
	}

/*--SCROLL--*/

/*
void scroll_ennemi(int clic, ennemi *en1)
{


if(clic==2)//walk droite
	{

		en1->position_entite.x-=en1->speed;

	}
	else if ((clic==1)&&(en1->position_entite.x<6500))//walk gauche
	{
		en1->position_entite.x+=en1->speed;

	}
if(clic==5)//walk droite
	{

		en1->position_entite.x-=en1->speed+2;

	}
	else if ((clic==6)&&(en1->position_entite.x<6500))//walk gauche
	{
		en1->position_entite.x+=en1->speed+2;

	}

if(clic==3)
	{

		en1->position_entite.x-=en1->speed;

	}

} */
// je laisse le scrolling en commentaire car on aura besoin de lui pour la collision



