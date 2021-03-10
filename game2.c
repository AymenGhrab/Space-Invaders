#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "game.h"



void load(SDL_Surface *background[])
{


	background[1] = IMG_Load("star1.png");
	background[2] = IMG_Load("play.png"); 
	background[3] = IMG_Load("stats.png");
	background[4] = IMG_Load("options.png");
        background[5] = IMG_Load("exit.png");
        background[6] = IMG_Load("settings.png");
        background[7] = IMG_Load("pngegg.png"); 
        background[8] = IMG_Load("pngegg2.png"); 
 
	

	




	

}

void initialise(SDL_Rect position[])
{

	position[1].x = 0;
	position[1].y = 0;

	position[2].x = 34;
	position[2].y = 210;

	position[3].x = 34;
	position[3].y = 420;

	position[4].x = 28;
	position[4].y = 300;

        position[5].x = 34;
	position[5].y = 520;

        position[7].x = 34;
	position[7].y = 550;
        
        position[8].x = 50;
	position[8].y = 550;


	

}
void load_music(Mix_Music *music[])
{



	music[0] = Mix_LoadMUS("space.mp3");
      
}


void play_music(Mix_Music *music[])
{
	Mix_PlayMusic(music[0], -1);
       

}





int normal_screen(SDL_Surface *background[])
{

	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	background[0] = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);
	return 1;

}


void normal_back(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	
	
	
	SDL_Flip(background[0]);
}



void play(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[2], NULL, background[0], &position[2]);
	
	

	SDL_Flip(background[0]);
}
void stats(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[3], NULL, background[0], &position[3]);
	
	

	SDL_Flip(background[0]);
}
void settings(SDL_Surface *background[], SDL_Rect position[])
{
	SDL_BlitSurface(background[4], NULL, background[0], &position[4]);
	
	SDL_Flip(background[0]);

}
void exite(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	

	SDL_Flip(background[0]);
}

void option(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[6], NULL, background[0], &position[6]);
	

	SDL_Flip(background[0]);
}
void mute1(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[7], NULL, background[0], &position[7]);
	

	SDL_Flip(background[0]);
}
void mute2(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[8], NULL, background[0], &position[8]);
	

	SDL_Flip(background[0]);
}

/*void animationbackground (SDL_Surface *background[], SDL_Rect position[])
{
      
    SDL_Surface *Frame[30] ;  
         Uint32 Time  ; 
   int FRAME ;   

        background[7] = IMG_Load("img1.png");
        background[8] = IMG_Load("img2.png");
        background[9] = IMG_Load("img3.png");
        background[10] = IMG_Load("img4.png");
        background[11] = IMG_Load("img5.png");
        background[12] = IMG_Load("img6.png");
        background[13] = IMG_Load("img7.png");
        background[14] = IMG_Load("img8.png");
        background[15] = IMG_Load("img9.png");
        background[16] = IMG_Load("img10.png");

 Time=SDL_GetTicks(); //GET TIME ELAPSED
        
        SDL_FreeSurface(Frame[FRAME]);
        FRAME++;
        if(FRAME==10)
            FRAME=0;

        Frame[FRAME]=IMG_Load(background[FRAME]);

        SDL_BlitSurface(background[FRAME], NULL, background[0], &position);

}
*/


void sound_effect(char ch[40],int volume)
{
Mix_Chunk* sound=NULL;
Mix_FreeChunk(sound);
sound = Mix_LoadWAV(ch);
Mix_AllocateChannels(16);
Mix_VolumeChunk(sound,volume);
Mix_PlayChannel(1,sound,0);
}







