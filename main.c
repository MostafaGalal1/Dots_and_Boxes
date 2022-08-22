#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include "menu.h"
#include "game.h"
#include "Save.h"
#include "Leaderboard.h"

int main(int argc, char *argv[])
{
    /*hiding console window*/
    ShowWindow(GetConsoleWindow(),SW_HIDE);

    /*setting the required surfaces and textures*/
    int a = 1;

    SDL_Event event;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;

    SDL_Surface* title_surface = NULL;
    SDL_Texture* title_texture = NULL;

    SDL_Surface* newgame_surface = NULL;
    SDL_Texture* newgame_texture = NULL;

    SDL_Surface* loadgame_surface = NULL;
    SDL_Texture* loadgame_texture = NULL;

    SDL_Surface* ranking_surface = NULL;
    SDL_Texture* ranking_texture = NULL;

    SDL_Surface* exit_surface = NULL;
    SDL_Texture* exit_texture = NULL;

    SDL_Surface* savlos = NULL;
    SDL_Texture* savlot = NULL;

    SDL_Surface* fileloads = NULL;
    SDL_Texture* fileloadt = NULL;
    SDL_Surface* confirms = NULL;
    SDL_Texture* confirmt = NULL;
    SDL_Surface* cancels = NULL;
    SDL_Texture* cancelt = NULL;

    SDL_Surface* b1 = NULL;
    SDL_Texture* b1t = NULL;
    SDL_Surface* b2 = NULL;
    SDL_Texture* b2t = NULL;
    SDL_Surface* b3 = NULL;
    SDL_Texture* b3t = NULL;
    SDL_Surface* b4 = NULL;
    SDL_Texture* b4t = NULL;
    SDL_Surface* b5 = NULL;
    SDL_Texture* b5t = NULL;

    SDL_Rect savlorect;
    savlorect.x = 133;
    savlorect.y = 125;
    savlorect.w = 450;
    savlorect.h = 200;

    SDL_Rect b1rect;
    b1rect.x = 160;
    b1rect.y = 180;
    b1rect.w = 60;
    b1rect.h = 60;

    SDL_Rect b2rect;
    b2rect.x = 245;
    b2rect.y = 180;
    b2rect.w = 60;
    b2rect.h = 60;

    SDL_Rect b3rect;
    b3rect.x = 330;
    b3rect.y = 180;
    b3rect.w = 60;
    b3rect.h = 60;

    SDL_Rect b4rect;
    b4rect.x = 415;
    b4rect.y = 180;
    b4rect.w = 60;
    b4rect.h = 60;

    SDL_Rect b5rect;
    b5rect.x = 500;
    b5rect.y = 180;
    b5rect.w = 60;
    b5rect.h = 60;

    SDL_Rect button1;
    button1.x = 280;
    button1.y = 130;
    button1.w = 150;
    button1.h = 46;

    SDL_Rect button2;
    button2.x = 280;
    button2.y = 180;
    button2.w = 150;
    button2.h = 44;

    SDL_Rect button3;
    button3.x = 280;
    button3.y = 230;
    button3.w = 150;
    button3.h = 44;


    SDL_Rect button4;
    button4.x = 280;
    button4.y = 280;
    button4.w = 150;
    button4.h = 44;

    SDL_Rect bac;
    bac.x = 0;
    bac.y = 0;
    bac.w = 715;
    bac.h = 384;

    SDL_Rect titlep;
    titlep.x = 155;
    titlep.y = 10;
    titlep.w = 415;
    titlep.h = 90;

    SDL_Rect filrect;
    filrect.x = 143;
    filrect.y = 115;
    filrect.w = 430;
    filrect.h = 90;

    SDL_Rect confirmrect;
    confirmrect.x = 135;
    confirmrect.y = 260;
    confirmrect.w = 140;
    confirmrect.h = 50;

    SDL_Rect cancelrect;
    cancelrect.x = 450;
    cancelrect.y = 260;
    cancelrect.w = 140;
    cancelrect.h = 50;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(
                 "Dots & Boxes",
                 SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED,
                 715,
                 384,
                 SDL_WINDOW_SHOWN
             );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    background_surface = IMG_Load("background1.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    title_surface = IMG_Load("title.png");
    title_texture = SDL_CreateTextureFromSurface(renderer, title_surface);

    newgame_surface = IMG_Load("newgame.png");
    newgame_texture = SDL_CreateTextureFromSurface(renderer, newgame_surface);

    savlos = IMG_Load("savlo.png");
    savlot = SDL_CreateTextureFromSurface(renderer, savlos);

    loadgame_surface = IMG_Load("loadgame.png");
    loadgame_texture = SDL_CreateTextureFromSurface(renderer, loadgame_surface);

    ranking_surface = IMG_Load("ranking.png");
    ranking_texture = SDL_CreateTextureFromSurface(renderer, ranking_surface);

    exit_surface = IMG_Load("exit.png");
    exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surface);

    confirms = IMG_Load("confirm.png");
    confirmt = SDL_CreateTextureFromSurface(renderer, confirms);

    cancels = IMG_Load("cancell.png");
    cancelt = SDL_CreateTextureFromSurface(renderer, cancels);

    fileloads = IMG_Load("fileload.png");
    fileloadt = SDL_CreateTextureFromSurface(renderer, fileloads);

    b1 = IMG_Load("1.png");
    b1t = SDL_CreateTextureFromSurface(renderer, b1);
    b2 = IMG_Load("2.png");
    b2t = SDL_CreateTextureFromSurface(renderer, b2);
    b3 = IMG_Load("3.png");
    b3t = SDL_CreateTextureFromSurface(renderer, b3);
    b4 = IMG_Load("4.png");
    b4t = SDL_CreateTextureFromSurface(renderer, b4);
    b5 = IMG_Load("5.png");
    b5t = SDL_CreateTextureFromSurface(renderer, b5);

    char name[11] = {'D','o','t','s','_',' ','.','b','i','n'};
    int gametype = 0, grid = 0;
    char P2Name[30], P1Name[30];
    int x1, y1, x3, y3;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    int e = 1, enableee = 0;

    while(a)
    {
        SDL_PollEvent(&event);
        /*rendering the needed textures*/
        if (e)
        {
            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, background_texture, NULL, &bac);
            SDL_RenderCopy(renderer, title_texture, NULL, &titlep);

            SDL_RenderCopy(renderer, newgame_texture, NULL, &button1);
            SDL_RenderCopy(renderer, loadgame_texture, NULL, &button2);
            SDL_RenderCopy(renderer, ranking_texture, NULL, &button3);
            SDL_RenderCopy(renderer, exit_texture, NULL, &button4);

            if (enableee)
            {
                SDL_RenderCopy(renderer, savlot, NULL, &savlorect);
                SDL_RenderCopy(renderer, fileloadt, NULL, &filrect);
                SDL_RenderCopy(renderer, b1t, NULL, &b1rect);
                SDL_RenderCopy(renderer, b2t, NULL, &b2rect);
                SDL_RenderCopy(renderer, b3t, NULL, &b3rect);
                SDL_RenderCopy(renderer, b4t, NULL, &b4rect);
                SDL_RenderCopy(renderer, b5t, NULL, &b5rect);
                SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
                SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
                SDL_RenderPresent(renderer);
            }

            SDL_RenderPresent(renderer);
            e=0;
        }

        /*handling courser actions*/
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x1,&y1);
            if (y1 > 130 && y1 < 166 && x1 > 300 && x1 < 405 && !enableee)
            {
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(title_surface);
                SDL_FreeSurface(newgame_surface);
                SDL_FreeSurface(loadgame_surface);
                SDL_FreeSurface(ranking_surface);
                SDL_FreeSurface(exit_surface);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(title_texture);
                SDL_DestroyTexture(newgame_texture);
                SDL_DestroyTexture(loadgame_texture);
                SDL_DestroyTexture(ranking_texture);
                SDL_DestroyTexture(exit_texture);
                SDL_RenderClear(renderer);
                if (menu(event, window, renderer) == 0)
                {
                    return 0;
                }
                e =1;
                background_surface = IMG_Load("background1.png");
                background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

                title_surface = IMG_Load("title.png");
                title_texture = SDL_CreateTextureFromSurface(renderer, title_surface);

                newgame_surface = IMG_Load("newgame.png");
                newgame_texture = SDL_CreateTextureFromSurface(renderer, newgame_surface);

                loadgame_surface = IMG_Load("loadgame.png");
                loadgame_texture = SDL_CreateTextureFromSurface(renderer, loadgame_surface);

                ranking_surface = IMG_Load("ranking.png");
                ranking_texture = SDL_CreateTextureFromSurface(renderer, ranking_surface);

                exit_surface = IMG_Load("exit.png");
                exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surface);
            }
            else if (y1 > 180 && y1 < 216 && x1 > 280 && x1 < 410 && !enableee)
            {
                enableee = 1;
            }
            else if (y3 > 260 && y3 < 310 && x3 > 130 && x3 < 270 && enableee)
            {
                enableee = 0;
                FILE *lfile;
                if (name[5] == ' ')
                {
                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);
                    b1 = IMG_Load("1.png");
                    b1t = SDL_CreateTextureFromSurface(renderer, b1);
                    b2 = IMG_Load("2.png");
                    b2t = SDL_CreateTextureFromSurface(renderer, b2);
                    b3 = IMG_Load("3.png");
                    b3t = SDL_CreateTextureFromSurface(renderer, b3);
                    b4 = IMG_Load("4.png");
                    b4t = SDL_CreateTextureFromSurface(renderer, b4);
                    b5 = IMG_Load("5.png");
                    b5t = SDL_CreateTextureFromSurface(renderer, b5);
                }

                else if ((lfile = fopen(name, "rb")) == NULL)
                {
                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);
                    b1 = IMG_Load("1.png");
                    b1t = SDL_CreateTextureFromSurface(renderer, b1);
                    b2 = IMG_Load("2.png");
                    b2t = SDL_CreateTextureFromSurface(renderer, b2);
                    b3 = IMG_Load("3.png");
                    b3t = SDL_CreateTextureFromSurface(renderer, b3);
                    b4 = IMG_Load("4.png");
                    b4t = SDL_CreateTextureFromSurface(renderer, b4);
                    b5 = IMG_Load("5.png");
                    b5t = SDL_CreateTextureFromSurface(renderer, b5);
                }
                else
                {
                    fread(&gametype, sizeof(int), 1, lfile);
                    fread(&P1Name, sizeof(char), 30, lfile);
                    fread(&P2Name, sizeof(char), 30, lfile);
                    fread(&grid, sizeof(int), 1, lfile);
                    if (grid == 5)
                    {
                        grid = 1;
                    }
                    else
                    {
                        grid = 0;
                    }
                    fclose(lfile);
                    game(gametype, P1Name, P2Name, grid, event, window, renderer, name);
                }
            }
            else if (y3 > 260 && y3 < 310 && x3 > 450 && x3 < 590 && enableee)
            {
                enableee = 0;
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }
            else if (y1 > 230 && y1 < 266 && x1 > 280 && x1 < 410 && !enableee)
            {
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(title_surface);
                SDL_FreeSurface(newgame_surface);
                SDL_FreeSurface(loadgame_surface);
                SDL_FreeSurface(ranking_surface);
                SDL_FreeSurface(exit_surface);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(title_texture);
                SDL_DestroyTexture(newgame_texture);
                SDL_DestroyTexture(loadgame_texture);
                SDL_DestroyTexture(ranking_texture);
                SDL_DestroyTexture(exit_texture);
                SDL_RenderClear(renderer);
                if (leaderboard(event, window, renderer) == 0)
                {
                    return 0;
                }
                e =1;
                background_surface = IMG_Load("background1.png");
                background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

                title_surface = IMG_Load("title.png");
                title_texture = SDL_CreateTextureFromSurface(renderer, title_surface);

                newgame_surface = IMG_Load("newgame.png");
                newgame_texture = SDL_CreateTextureFromSurface(renderer, newgame_surface);

                loadgame_surface = IMG_Load("loadgame.png");
                loadgame_texture = SDL_CreateTextureFromSurface(renderer, loadgame_surface);

                ranking_surface = IMG_Load("ranking.png");
                ranking_texture = SDL_CreateTextureFromSurface(renderer, ranking_surface);

                exit_surface = IMG_Load("exit.png");
                exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surface);

            }
            else if (y1 > 280 && y1 < 316 && x1 > 325 && x1 < 380 && !enableee)
            {
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(title_texture);
                SDL_DestroyTexture(newgame_texture);
                SDL_DestroyTexture(loadgame_texture);
                SDL_DestroyTexture(ranking_texture);
                SDL_DestroyTexture(exit_texture);

                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);

                SDL_Quit();
                return 0;
            }
            else if (y1 > 180 && y1 < 245 && x1 > 160 && x1 < 225 && enableee)
            {
                name[5] = '1';
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1g.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }
            else if (y1 > 180 && y1 < 245 && x1 > 245 && x1 < 310 && enableee)
            {
                name[5] = '2';
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2g.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }
            else if (y1 > 180 && y1 < 245 && x1 > 330 && x1 < 395 && enableee)
            {
                name[5] = '3';
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3g.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }
            else if (y1 > 180 && y1 < 245 && x1 > 415 && x1 < 480 && enableee)
            {
                name[5] = '4';
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4g.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }
            else if (y1 > 180 && y1 < 245 && x1 > 500 && x1 < 565 && enableee)
            {
                name[5] = '5';
                SDL_FreeSurface(b1);
                SDL_DestroyTexture(b1t);
                SDL_FreeSurface(b2);
                SDL_DestroyTexture(b2t);
                SDL_FreeSurface(b3);
                SDL_DestroyTexture(b3t);
                SDL_FreeSurface(b4);
                SDL_DestroyTexture(b4t);
                SDL_FreeSurface(b5);
                SDL_DestroyTexture(b5t);
                b1 = IMG_Load("1.png");
                b1t = SDL_CreateTextureFromSurface(renderer, b1);
                b2 = IMG_Load("2.png");
                b2t = SDL_CreateTextureFromSurface(renderer, b2);
                b3 = IMG_Load("3.png");
                b3t = SDL_CreateTextureFromSurface(renderer, b3);
                b4 = IMG_Load("4.png");
                b4t = SDL_CreateTextureFromSurface(renderer, b4);
                b5 = IMG_Load("5g.png");
                b5t = SDL_CreateTextureFromSurface(renderer, b5);
            }

        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x3,&y3);
            if (y3 > 130 && y3 < 166 && x3 > 300 && x3 < 405 && !enableee)
            {
                e = 1;
                button1.y = 125;
                button1.h = 52;
                SDL_FreeSurface(newgame_surface);
                newgame_surface = IMG_Load("newgameg.png");
                SDL_DestroyTexture(newgame_texture);
                newgame_texture = SDL_CreateTextureFromSurface(renderer, newgame_surface);
                SDL_RenderCopy(renderer, newgame_texture, NULL, &button1);
            }
            else if (y3 > 180 && y3 < 216 && x3 > 280 && x3 < 410 && !enableee)
            {
                e = 1;
                button2.y = 175;
                button2.h = 50;
                SDL_FreeSurface(loadgame_surface);
                SDL_DestroyTexture(loadgame_texture);
                loadgame_surface = IMG_Load("loadgameg.png");
                loadgame_texture = SDL_CreateTextureFromSurface(renderer, loadgame_surface);
                SDL_RenderCopy(renderer, loadgame_texture, NULL, &button2);
            }
            else if (y3 > 230 && y3 < 266 && x3 > 280 && x3 < 410 && !enableee)
            {
                e = 1;
                button3.y = 225;
                button3.h = 50;
                SDL_FreeSurface(ranking_surface);
                SDL_DestroyTexture(ranking_texture);
                ranking_surface = IMG_Load("rankingg.png");
                ranking_texture = SDL_CreateTextureFromSurface(renderer, ranking_surface);
                SDL_RenderCopy(renderer, ranking_texture, NULL, &button3);
            }
            else if (y3 > 280 && y3 < 316 && x3 > 325 && x3 < 380 && !enableee)
            {
                e = 1;
                button4.y = 275;
                button4.h = 50;
                SDL_FreeSurface(exit_surface);
                SDL_DestroyTexture(exit_texture);
                exit_surface = IMG_Load("exitg.png");
                exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surface);
                SDL_RenderCopy(renderer, exit_texture, NULL, &button4);
            }
            else if (y3 > 260 && y3 < 310 && x3 > 130 && x3 < 270 && enableee)
            {
                e = 1;
                SDL_FreeSurface(confirms);
                SDL_DestroyTexture(confirmt);
                confirms = IMG_Load("confirmg.png");
                confirmt = SDL_CreateTextureFromSurface(renderer, confirms);
                SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
            }
            else if (y3 > 260 && y3 < 310 && x3 > 450 && x3 < 590 && enableee)
            {
                e = 1;
                SDL_FreeSurface(cancels);
                SDL_DestroyTexture(cancelt);
                cancels = IMG_Load("cancellg.png");
                cancelt = SDL_CreateTextureFromSurface(renderer, cancels);
                SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
            }
            else
            {
                e = 1;
                button1.y = 130;
                button2.y = 180;
                button3.y = 230;
                button4.y = 280;
                button1.h = 46;
                button2.h = 44;
                button3.h = 44;
                button4.h = 44;
                SDL_FreeSurface(cancels);
                SDL_DestroyTexture(cancelt);
                SDL_FreeSurface(confirms);
                SDL_DestroyTexture(confirmt);
                SDL_FreeSurface(newgame_surface);
                SDL_FreeSurface(loadgame_surface);
                SDL_FreeSurface(ranking_surface);
                SDL_FreeSurface(exit_surface);
                SDL_DestroyTexture(newgame_texture);
                SDL_DestroyTexture(loadgame_texture);
                SDL_DestroyTexture(ranking_texture);
                SDL_DestroyTexture(exit_texture);
                newgame_surface = IMG_Load("newgame.png");
                newgame_texture = SDL_CreateTextureFromSurface(renderer, newgame_surface);
                loadgame_surface = IMG_Load("loadgame.png");
                loadgame_texture = SDL_CreateTextureFromSurface(renderer, loadgame_surface);
                ranking_surface = IMG_Load("ranking.png");
                ranking_texture = SDL_CreateTextureFromSurface(renderer, ranking_surface);
                exit_surface = IMG_Load("exit.png");
                exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surface);
                confirms = IMG_Load("confirm.png");
                confirmt = SDL_CreateTextureFromSurface(renderer, confirms);
                cancels = IMG_Load("cancell.png");
                cancelt = SDL_CreateTextureFromSurface(renderer, cancels);
                SDL_RenderCopy(renderer, title_texture, NULL, &titlep);
                SDL_RenderCopy(renderer, newgame_texture, NULL, &button1);
                SDL_RenderCopy(renderer, loadgame_texture, NULL, &button2);
                SDL_RenderCopy(renderer, ranking_texture, NULL, &button3);
                SDL_RenderCopy(renderer, exit_texture, NULL, &button4);
                SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
                SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
            }

            break;
        }
        SDL_Delay(1000/100);
        if(event.type == SDL_QUIT)
        {
            a = 0;
            SDL_DestroyTexture(background_texture);
            SDL_DestroyTexture(title_texture);
            SDL_DestroyTexture(newgame_texture);
            SDL_DestroyTexture(loadgame_texture);
            SDL_DestroyTexture(ranking_texture);
            SDL_DestroyTexture(exit_texture);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);

            SDL_Quit();
        }
    }

    /*destroying the textures*/
    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(title_texture);
    SDL_DestroyTexture(newgame_texture);
    SDL_DestroyTexture(loadgame_texture);
    SDL_DestroyTexture(ranking_texture);
    SDL_DestroyTexture(exit_texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}
