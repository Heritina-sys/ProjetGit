
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <math.h>
//#include <SDL/SDL_ttf.h>
#define LONGUER 800
#define LARGEUR 600
#define MAX_X 760
#define MIN_C 70
#define MAX_Y 550
#define ESPACE 30
#define ACCE 300
#define VITESSE 30

/*
gcc icone.c -o prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
gcc icone.c $(sdl2-config --cflags --libs) -o prog
*/
void SDL_error(const char *message);
void remplis_tab(int *tab,int taille);
//void creat_score(int nombre);
//int best_score(int score);
int main(int argc,char **argv){
	int ombre = 0;
//	creat_score(ombre);
	int tailleX = 22;
	int tailleY = 15;
	int *tabX;
	tabX = malloc(sizeof(int) * tailleX);
	remplis_tab(tabX,tailleX);
	int *tabY;
	tabY = malloc(sizeof(int) * tailleY);
	remplis_tab(tabY,tailleY);

/*
	int minX = rand() % 22;
	int minY = rand() % 15; 
	int initX = tabX[minX];
	int initY = tabY[minY];
*/
	ombre = 2;
	int posx = 0;
	int posy = 0;

//	int nb = cord_aleo(tabX);
//	printf("%d\n",nb);
	srand(time(NULL));
	SDL_Window *window = NULL;
	SDL_Renderer *render = NULL;
	SDL_Rect rectangle;
	rectangle.w = 25;
	rectangle.h = 25;
	rectangle.x = 100;
	rectangle.y = 100;
	printf("%d.%d\n",rectangle.x,rectangle.y );
//	rectangle.x = initX;
//	rectangle.y = initY;
	SDL_Rect rect[100000];
//	rect = (SDL_Rect*)malloc(sizeof(SDL_Rect) * ombre);
	for(int i=0;i < 100000;i++){
		rect[i].x = rectangle.x - (ESPACE * (1+i));
		rect[i].y = rectangle.y;
		rect[i].w=rectangle.w;
		rect[i].h=rectangle.h;
	}
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_error("L'initialisation du SDL");	
	window = SDL_CreateWindow("Snack Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LONGUER,LARGEUR,0);
	if(window == 0)
		SDL_error("Erreur lors de la creation de fenetre");
	render = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
	if(render== 0)
		SDL_error("Erreur lors de la creation de rendu");
//	TTF_Init();
//	TTF_Font *font = TTF_OpenFont("snack/Black Mortal TTF Personal.ttf",28);
		
//-----------------------------------------------------------------------------------------------------------------------------------------//	
	SDL_Surface *surface = SDL_LoadBMP("quiz/image.bmp");
		SDL_Texture *image = SDL_CreateTextureFromSurface(render,surface);
		SDL_Surface *ic_ombre[100000];
//		ic_ombre =(SDL_Surface**) malloc(sizeof(SDL_Surface*) * ombre);
		SDL_Texture *place[100000];
//		place = malloc(sizeof(SDL_Texture*) * ombre);
		for(int i = 0;i <= ombre;i++){
			ic_ombre[i] = SDL_LoadBMP("quiz/image.bmp");
			place[i] = SDL_CreateTextureFromSurface(render,ic_ombre[i]);
		}

	srand(time(NULL));
	SDL_Rect rect_cible;
	rect_cible.w = 25;
	rect_cible.h = 25;
	rect_cible.x = tabX[rand() % tailleX];
	rect_cible.y = tabY[rand() % tailleY];		
	SDL_Surface *surface_cible = SDL_LoadBMP("quiz/image.bmp");
	SDL_Texture *image_cible = SDL_CreateTextureFromSurface(render,surface_cible);	
//	SDL_RenderCopy(render,image_cible,NULL,&rect_cible);
	SDL_Rect rect_deco;
	rect_deco.x = MIN_C;
	rect_deco.y = MIN_C;
	rect_deco.w = 760 - MIN_C;
	rect_deco.h = 550 - MIN_C;
	SDL_bool tmp = SDL_TRUE;
	SDL_Rect lettreS;
	lettreS.w = 100;
	lettreS.h = 100;
	lettreS.x= 50;
	lettreS.y= 200;
	SDL_Surface *lS = SDL_LoadBMP("quiz/s.bmp");
	SDL_Texture *iS = SDL_CreateTextureFromSurface(render,lS);
	SDL_RenderCopy(render,iS,NULL,&lettreS);
	SDL_Rect lettreN;
	lettreN.w = 100;
	lettreN.h = 100;
	lettreN.x= 170;
	lettreN.y= 200;
	SDL_Surface *lN = SDL_LoadBMP("quiz/n.bmp");
	SDL_Texture *iN = SDL_CreateTextureFromSurface(render,lN);
	SDL_RenderCopy(render,iN,NULL,&lettreN);
	SDL_Rect lettreA;
	lettreA.w = 100;
	lettreA.h = 100;
	lettreA.x= 280;
	lettreA.y= 200;
	SDL_Surface *lA = SDL_LoadBMP("quiz/a.bmp");
	SDL_Texture *iA = SDL_CreateTextureFromSurface(render,lA);
	SDL_RenderCopy(render,iA,NULL,&lettreA);
	SDL_Rect lettreC;
	lettreC.w = 100;
	lettreC.h = 100;
	lettreC.x= 390;
	lettreC.y= 200;
	SDL_Surface *lC = SDL_LoadBMP("quiz/c.bmp");
	SDL_Texture *iC = SDL_CreateTextureFromSurface(render,lC);
	SDL_RenderCopy(render,iC,NULL,&lettreC);
	SDL_Rect lettreK;
	lettreK.w = 100;
	lettreK.h = 100;
	lettreK.x= 550;
	lettreK.y= 200;
	SDL_Surface *lK = SDL_LoadBMP("quiz/k.bmp");
	SDL_Texture *iK = SDL_CreateTextureFromSurface(render,lK);
	SDL_RenderCopy(render,iK,NULL,&lettreK);
	SDL_RenderPresent(render);
	
//-------------------------------------------------------------------//
	SDL_Rect game_over;
	game_over.w = 400;
	game_over.h = 400;
	game_over.x= 100;
	game_over.y= 100;
	SDL_Surface *game_overS = SDL_LoadBMP("snack/game_over.bmp");
	SDL_Texture *game_overL = SDL_CreateTextureFromSurface(render,game_overS);
//--------------------------------------------------------------------//
	SDL_Delay(5000);
	int etat = 0;
	while(tmp){
		SDL_SetRenderDrawColor(render,163,73,164,SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRect(render,&rect_deco);
		SDL_SetRenderDrawColor(render,0,0,0,SDL_ALPHA_OPAQUE);	
		SDL_RenderCopy(render,image_cible,NULL,&rect_cible);
		posx = rectangle.x;
		posy = rectangle.y;
		SDL_Event event;
/*
		SDL_Color color = { 255, 255, 255 };
		char isa[10];
		sprintf(isa,"%d",ombre - 2);
		SDL_Surface *tsurface = TTF_RenderText_Solid(font,isa,color);
		SDL_Texture *ttexture = SDL_CreateTextureFromSurface(render,tsurface);
		SDL_Rect destRect = {700,10,50,50};
		SDL_RenderCopy(render,ttexture,NULL,&destRect);
*/
		while(SDL_PollEvent(&event)){			
			switch(event.type){
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_UP :
							if(etat == 3){
								etat = 3;	
							}
							else{
								etat = 1;
								posx = rectangle.x;
								posy = rectangle.y;
							}
							continue;
						case SDLK_RIGHT :
							if(etat == 4){
								etat = 4;	
							}
							else{
								etat = 2;
								posx = rectangle.x;
								posy = rectangle.y;
							}
							continue;	
						case SDLK_DOWN :
							if(etat == 1){
								etat = 1;	
							}
							else{
								etat = 3;
								posx = rectangle.x;
								posy = rectangle.y;
							}
							continue;
						case SDLK_LEFT : 
							if(etat == 2 || etat == 0){
								etat = 0;	
							}
							else{
								etat = 4;
								posx = rectangle.x;
								posy = rectangle.y;
							}
							continue;		
						default:
							etat = 0;
							posx = rectangle.x;
							posy = rectangle.y;
							continue;
				}
			case SDL_QUIT:
				tmp = SDL_FALSE;
				break;
			default:
				continue;
			}
		}
		int tmp1 = etat;	
		switch(tmp1){
			case 1:
				rectangle.y = rectangle.y - VITESSE;
				for(int i = 0;i<ombre;i++){
						if(rectangle.x == rect[i].x && rectangle.y == rect[i].y){
							SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
						}
				}
				if(rectangle.y < MIN_C){
					SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
				}
				else{	
					if(rectangle.x == rect_cible.x && rectangle.y == rect_cible.y){
					srand(time(NULL));
						rect_cible.x = tabX[rand() % tailleX];
						rect_cible.y = tabY[rand() % tailleY];
						ombre = ombre + 1;				
					}
					for(int i = 0;i<ombre;i++){
						int tempX = rect[i].x;
						int tempY = rect[i].y;
						rect[i].x = posx;
						rect[i].y = posy;
						posx = tempX;
						posy = tempY;
						SDL_RenderCopy(render,image,NULL,&rect[i]);
						SDL_RenderCopy(render,image,NULL,&rectangle);
						//	SDL_Delay(ACCE);
						//	SDL_RenderClear(render);
					}
					SDL_RenderPresent(render);		
					SDL_Delay(ACCE);	
					SDL_RenderClear(render);			
				}
				continue;		
			case 2:
				rectangle.x = rectangle.x + VITESSE;
				for(int i = 0;i<ombre;i++){
						if(rectangle.x == rect[i].x && rectangle.y == rect[i].y){
							SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
						}
				}
				if(rectangle.x >= MAX_X){
					SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
				}
				else{	
					if(rectangle.x == rect_cible.x && rectangle.y == rect_cible.y){
					srand(time(NULL));
						rect_cible.x = tabX[rand() % tailleX];
						rect_cible.y = tabY[rand() % tailleY];
						ombre = ombre + 1;				
					}
					for(int i = 0;i<ombre;i++){
						int tempX = rect[i].x;
						int tempY = rect[i].y;
						rect[i].x = posx;
						rect[i].y = posy;
						posx = tempX;
						posy = tempY;
						SDL_RenderCopy(render,image,NULL,&rect[i]);
						SDL_RenderCopy(render,image,NULL,&rectangle);
						//	SDL_Delay(ACCE);
						//	SDL_RenderClear(render);
					}
					SDL_RenderPresent(render);		
					SDL_Delay(ACCE);	
					SDL_RenderClear(render);			
				}		
				continue;	
			case 3:
				rectangle.y = rectangle.y + VITESSE;
				for(int i = 0;i<ombre;i++){
						if(rectangle.x == rect[i].x && rectangle.y == rect[i].y){
							SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
						}
				}
				if(rectangle.y >= MAX_Y){
					SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
				}
				else{	
					if(rectangle.x == rect_cible.x && rectangle.y == rect_cible.y){
					srand(time(NULL));
						rect_cible.x = tabX[rand() % tailleX];
						rect_cible.y = tabY[rand() % tailleY];
						ombre = ombre + 1;
					}
					for(int i = 0;i<ombre;i++){
						int tempX = rect[i].x;
						int tempY = rect[i].y;
						rect[i].x = posx;
						rect[i].y = posy;
						posx = tempX;
						posy = tempY;
						SDL_RenderCopy(render,image,NULL,&rect[i]);
						SDL_RenderCopy(render,image,NULL,&rectangle);
					
						//	SDL_Delay(ACCE);
						//	SDL_RenderClear(render);
					}
						SDL_RenderPresent(render);					
						SDL_Delay(ACCE);
						SDL_RenderClear(render);			
				}
				continue;		
			case 4:
				rectangle.x = rectangle.x - VITESSE;
				for(int i = 0;i<ombre;i++){
						if(rectangle.x == rect[i].x && rectangle.y == rect[i].y){
							SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
						}
				}
				if(rectangle.x < MIN_C){
					SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
				}	
				else{
					if(rectangle.x == rect_cible.x && rectangle.y == rect_cible.y){
					srand(time(NULL));
						rect_cible.x = tabX[rand() % tailleX];
						rect_cible.y = tabY[rand() % tailleY];
						ombre = ombre + 1;
						}	
					for(int i = 0;i<ombre;i++){
						int tempX = rect[i].x;
						int tempY = rect[i].y;
						rect[i].x = posx;
						rect[i].y = posy;
						posx = tempX;
						posy = tempY;
						SDL_RenderCopy(render,image,NULL,&rect[i]);						
						SDL_RenderCopy(render,image,NULL,&rectangle);						
						//	SDL_Delay(ACCE);
						//	SDL_RenderClear(render);
						}
					SDL_RenderPresent(render);	
					SDL_Delay(ACCE);
					SDL_RenderClear(render);				
				}
				continue;	
			default :
				rectangle.x = rectangle.x + VITESSE;
				for(int i = 0;i<ombre;i++){
						if(rectangle.x == rect[i].x && rectangle.y == rect[i].y){
							SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
						}
				}
				if(rectangle.x >= MAX_X ){
					SDL_RenderClear(render);
					SDL_RenderCopy(render,game_overL,NULL,&game_over);
					SDL_RenderPresent(render);
					SDL_Delay(5000);
					tmp = SDL_FALSE;
				}	
				else{
					if(rectangle.x == rect_cible.x && rectangle.y == rect_cible.y){
					srand(time(NULL));
						rect_cible.x = tabX[rand() % tailleX];
						rect_cible.y = tabY[rand() % tailleY];
						ombre = ombre + 1;
					}
					for(int i = 0;i<ombre;i++){
						int tempX = rect[i].x;
						int tempY = rect[i].y;
						rect[i].x = posx;
						rect[i].y = posy;
						posx = tempX;
						posy = tempY;							
						SDL_RenderCopy(render,image,NULL,&rect[i]);	
						SDL_RenderCopy(render,image,NULL,&rectangle);
			//			SDL_Delay(ACCE);
			//			SDL_RenderClear(render);
					}
					SDL_RenderPresent(render);		
					SDL_Delay(ACCE);
					SDL_RenderClear(render);
				}
				continue;				
		}

	//	printf("Teste\n");
	}

//	SDL_Delay(3000);
//-----------------------------------------------------------------------------------------------------------------------------------------//
//	free(ic_ombre);
//	free(place);
//	free(rect);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
//	printf("score : %d\n",ombre - 2);
//	int B_score = best_score(ombre - 2);
//	printf("Meilleure score : %d\n",B_score);
	return EXIT_SUCCESS;
}
void SDL_error(const char *message){
	SDL_Log("%s : %s\n",message,SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
void remplis_tab(int *tab,int taille){
	for(int i = 0;i<taille;i++){
		tab[i] = 100 + (i * 30);
	}
}/*
void creat_score(int nombre){
	char valeur[10];
	sprintf(valeur,"%s",getenv("SNACK_SCORE"));
	if(valeur == NULL){
	char num[10000];
	sprintf(num,"%d",nombre);
	setenv("SNACK_SCORE",num,1);
	}
}
int best_score(int score){
	char valeur[10];
	sprintf(valeur,"%s",getenv("SNACK_SCORE"));
	int score_Env = atoi(valeur);
	if(score > score_Env){
		return score;
	}
	else{
		return score_Env;
	}	
}
*/
