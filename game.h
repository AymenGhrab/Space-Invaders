#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


void load(SDL_Surface *background[]);
void initialise(SDL_Rect position[]);
void load_music(Mix_Music *music[]);
void play_music(Mix_Music *music[]);
int normal_screen(SDL_Surface *backgound[]);
void normal_back(SDL_Surface *background[],SDL_Rect position[]);






void play(SDL_Surface *background[],SDL_Rect position[]);
void stats(SDL_Surface *background[], SDL_Rect position[]) ;
void settings(SDL_Surface *background[],SDL_Rect position[]);
void exite(SDL_Surface *background[],SDL_Rect position[]);
void option(SDL_Surface *background[], SDL_Rect position[]) ; 
void mute1(SDL_Surface *background[], SDL_Rect position[]) ; 
void mute2(SDL_Surface *background[], SDL_Rect position[]) ;
// void animationbackground (SDL_Surface *background[], SDL_Rect position[]) ; 


 // void free_back(SDL_Surface *background[]);


#endif
