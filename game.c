#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include "game.h"

int main()
{

	int x = 1;
         
	int a = 0, b = 0, c = 0, d = 0, e = 0, m = 0, t = 1, u = 0, vol = 120, z = 0,w=0, r=0,l=0,s=0,k=0,Running,FRAME,volume,i=0;
         char ch[40] ; 
        char* Frame_Path[10];
  Uint32 Time  ; 
         SDL_Surface *Frame[30],*textereste5,*ecran,*textecm=NULL;
	SDL_Surface *background[30];
	SDL_Rect position[30],positionreste5,postextecm;
	SDL_Event event;
	Mix_Music *music[2];
     

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable :%s\n", SDL_GetError());
	}



background[0] = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("erreur:%s\n", Mix_GetError());
	}

	load(background);
	initialise(position);
//// ttf
        postextecm.x=70;
	postextecm.y=0;
	TTF_Init();
	TTF_Font *police=NULL;
	SDL_Color couleurgris={172,169,169};
	SDL_WM_SetCaption("GAME	",NULL);
	police=TTF_OpenFont("angelina.ttf",40);

	textecm=TTF_RenderText_Blended(police,"SPACE INVADERS",couleurgris);
	SDL_BlitSurface(textecm,NULL,background[0],&postextecm);
	SDL_Flip(background[0]);

	TTF_CloseFont(police);
	TTF_Quit;


//  animationbackground (background, position)  ;

  
////////ttf 
	/*	TTF_Font *police = NULL;
police = TTF_OpenFont("angelina.ttf",40);
SDL_Color couleurrouge = {255, 0, 0};

textereste5 = TTF_RenderText_Blended(police, "SPACE F5", couleurrouge);
        positionreste5.x =0;
        positionreste5.y =0;
        SDL_BlitSurface(textereste5, NULL, ecran, &positionreste5);  
        SDL_Flip(ecran);
TTF_CloseFont(police);
	TTF_Quit();	
*/

/*

police=TTF_OpenFont("angelina.ttf",40);
	// ecriture du texte dans la sdl surface texte en mode blended/
	text=TTf_BenderText_Blended(police,"Gestion du texte avec sdl ttf",couleurNoire);
	while(continuer)
	{
		SDL_FillRect(screen , NULL, SDL_MapRGB(ecran->format,255,255,255));
	position.x=0;
	position.y=0;
	SDL_BlitSurface(background,NULL,screen,*position);
	
	position.x=60;
	position.y=370;
	SDL_BlitSurface(text ,NULL,screen,*position); //blit du text
	
	
	SDL_Flip(screen);
	}
	TTF_CloseFont(Police);
	TTF_Quit();
	SDL_Quit();
	
	
}
*/
//////
//......................................
	load_music(music);
	play_music(music);
//......................................


	while (x == 1)
	{

	if (t == 1)
		{

			switch (m)
			{
			case 0:
				normal_back(background, position);
				break;
			case 1:
				play(background, position);
				break;
			case 2:
				settings(background, position);
				break;
                        case 3 : 
                                   stats(background, position) ;
                                     break ; 
			case 4:
				exite(background, position);
				break;
                     
                          case 5 : 
                           mute1(background, position) ; 
                             break ; 
                              case 6 : 
                           mute2(background, position) ; 
                             break ; 
                         
			default:
				normal_back(background, position);
				break;

			}

			


			SDL_PollEvent(&event);


			switch (event.type)
			{
			case SDL_QUIT:
				x = 0;
				break;
			
				switch (event.key.keysym.sym)
				{
				
		  case SDLK_UP:
            	        
				if((m==1) || (m==0))
				m=4;
				
				else
            			m--;
              		break;
              		
			case SDLK_DOWN:
				if(m==4)
				m=1; 
				else 
				m++;
		 	break;

				}//switch2
				

			case SDL_MOUSEMOTION:
				a = event.motion.x;
				b = event.motion.y;

                            


				if (a > 35 && a < 380  && b > 220 && b < 285 )
				{
					m = 1;
                                        

                                    
                                 sound_effect("buttonsound.wav",-1);
                             
                               
                                          
                                         
				}
				else  if (a > 35 && a < 380 && b > 317 && b < 385)
				{       

                                     
					m = 2;
                                          sound_effect("buttonsound.wav",-1);
                              
				}
				else if (a > 35 && a < 380 && b > 425 && b < 488)
				{
					m = 3;
                                  sound_effect("buttonsound.wav",-1);

				}
                               else if (a > 35 && a < 380 && b > 524 && b < 595 ) 
				{
					m = 4;
                                              sound_effect("buttonsound.wav",-1);

				}

				else
				{
					m = 0;

				}
				break;
                                
                            case SDL_MOUSEBUTTONUP : 


                      a=event.motion.x;
                       b=event.motion.y;

                         if(m==2)//options
                                  {  
                                     
                                     option(background, position);
                                  
                                   }
                             break ; 
                                case SDL_MOUSEBUTTONDOWN:
                              
                              a = event.motion.x;
				b = event.motion.y;
				
				
				if(a > 302 && a < 366 && b > 632 && b < 683)
				{Mix_PauseMusic();}
				
				if(a > 86 && a < 151 && b > 632 && b < 683)
				{Mix_ResumeMusic();}
				break; 
 	

                          



			}//switch1



		}//if1


	

if (t == 3)
{
SDL_PollEvent(&event);

switch (event.type)
{
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE: 
   Mix_VolumeMusic(0);
  break ;


 case SDL_MOUSEBUTTONUP : 


                      a=event.motion.x;
                       b=event.motion.y;

                         if(a > 35 && a < 380 && b > 317 && b < 385)//options
                                  {  
                                     
                                     option(background, position);
                                  
                                   }
                             break ; 
					

break;

}
break;












//if3




	}//while

	 // free_back(background);

	return 0;
}



}
/*
Frame_Path[1]="img1.png" ; 
Frame_Path[2]="img2.png" ;
Frame_Path[3]="img3.png" ;
Frame_Path[4]="img4.png" ;
Frame_Path[5]="img5.png" ;
Frame_Path[6]="img6.png" ;
Frame_Path[7]="img7.png" ;
Frame_Path[8]="img8.png" ;
Frame_Path[9]="img9.png" ;
Frame_Path[10]="img10.png" ;

 Time=SDL_GetTicks(); //GET TIME ELAPSED
        
        SDL_FreeSurface(Frame[FRAME]);
        FRAME++;
        if(FRAME==10)
            FRAME=0;

        Frame[FRAME]=IMG_Load(Frame_Path[FRAME]);

        SDL_BlitSurface(Frame[FRAME], NULL, background[1], &position);

*/
}

