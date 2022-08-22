#include "playermenu.h"
int menu(SDL_Event event, SDL_Window* window, SDL_Renderer* renderer)
{

    /*setting the required surfaces and textures*/
    int a = 1;
    int returnValue;

    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;

    SDL_Surface* rightsu = NULL;
    SDL_Texture* righttu = NULL;

    SDL_Surface* leftsu = NULL;
    SDL_Texture* lefttu = NULL;

    SDL_Surface* rightsd = NULL;
    SDL_Texture* righttd = NULL;

    SDL_Surface* leftsd = NULL;
    SDL_Texture* lefttd = NULL;

    SDL_Surface* tmodes = NULL;
    SDL_Texture* tmodet = NULL;

    SDL_Surface* gmodes = NULL;
    SDL_Texture* gmodet = NULL;

    SDL_Surface* ggrids = NULL;
    SDL_Texture* ggridt = NULL;

    SDL_Surface* tgrids = NULL;
    SDL_Texture* tgridt = NULL;

    SDL_Surface* nexts = NULL;
    SDL_Texture* nextt = NULL;

    SDL_Surface* backs = NULL;
    SDL_Texture* backt = NULL;

    SDL_Rect title;
    title.x = 265;
    title.y = 2;
    title.w = 184;
    title.h = 55;

    SDL_Rect buttonl;
    buttonl.x = 252;
    buttonl.y = 0;
    buttonl.w = 36;
    buttonl.h = 36;

    SDL_Rect buttonr;
    buttonr.x = 428;
    buttonr.y = 0;
    buttonr.w = 36;
    buttonr.h = 36;

    SDL_Rect buttonp;
    buttonp.x = 293;
    buttonp.y = 0;
    buttonp.w = 130;
    buttonp.h = 43;

    SDL_Rect bac;
    bac.x = 0;
    bac.y = 0;
    bac.w = 715;
    bac.h = 384;

    SDL_Rect backb;
    backb.x = 100;
    backb.y = 305;
    backb.w = 150;
    backb.h = 52;

    SDL_Rect nextb;
    nextb.x = 460;
    nextb.y = 305;
    nextb.w = 150;
    nextb.h = 52;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    background_surface = IMG_Load("background.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    nexts = IMG_Load("next.png");
    nextt = SDL_CreateTextureFromSurface(renderer, nexts);

    backs = IMG_Load("back.png");
    backt = SDL_CreateTextureFromSurface(renderer, backs);

    rightsd = IMG_Load("right.png");
    righttd = SDL_CreateTextureFromSurface(renderer, rightsd);

    leftsd = IMG_Load("left.png");
    lefttd = SDL_CreateTextureFromSurface(renderer, leftsd);

    rightsu = IMG_Load("right.png");
    righttu = SDL_CreateTextureFromSurface(renderer, rightsu);

    leftsu = IMG_Load("left.png");
    lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);

    gmodes = IMG_Load("oneplayer.png");
    gmodet = SDL_CreateTextureFromSurface(renderer, gmodes);

    ggrids = IMG_Load("2x2.png");
    ggridt = SDL_CreateTextureFromSurface(renderer, ggrids);

    tmodes = IMG_Load("gamemode.png");
    tmodet = SDL_CreateTextureFromSurface(renderer, tmodes);

    tgrids = IMG_Load("gamegrid.png");
    tgridt = SDL_CreateTextureFromSurface(renderer, tgrids);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int x3, y3, x1, y1;
    int grid = 0, mode = 0;
    int e = 1;

    while(a)
    {
        SDL_PollEvent(&event);
        /*rendering the needed textures*/
        if (e)
        {
            e = 0;
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, background_texture, NULL, &bac);

            SDL_RenderCopy(renderer, backt, NULL, &backb);
            SDL_RenderCopy(renderer, nextt, NULL, &nextb);

            title.y = 45;
            SDL_RenderCopy(renderer, tmodet, NULL, &title);
            title.y = 165;
            SDL_RenderCopy(renderer, tgridt, NULL, &title);

            buttonr.y = 100;
            SDL_RenderCopy(renderer, righttu, NULL, &buttonr);
            buttonl.y = 100;
            SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);

            buttonr.y = 220;
            SDL_RenderCopy(renderer, righttd, NULL, &buttonr);
            buttonl.y = 220;
            SDL_RenderCopy(renderer, lefttd, NULL, &buttonl);

            buttonp.y = 99;
            SDL_RenderCopy(renderer, gmodet, NULL, &buttonp);
            buttonp.y = 219;
            SDL_RenderCopy(renderer, ggridt, NULL, &buttonp);

            SDL_RenderPresent(renderer);
        }

        /*handling courser actions*/
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x1,&y1);
            if (y1 > 100 && y1 < 136 && ((x1 > 252 && x1 < 288) || (x1 > 428 && x1 < 464)))
            {
                e = 1;
                SDL_FreeSurface(gmodes);
                SDL_DestroyTexture(gmodet);
                mode ^= 1;
                if (mode)
                {
                    gmodes = IMG_Load("twoplayer.png");
                    gmodet = SDL_CreateTextureFromSurface(renderer, gmodes);
                }
                else
                {
                    gmodes = IMG_Load("oneplayer.png");
                    gmodet = SDL_CreateTextureFromSurface(renderer, gmodes);
                }
                buttonp.y = 99;
                SDL_RenderCopy(renderer, gmodet, NULL, &buttonp);
            }
            else if (y1 > 220 && y1 < 256 && ((x1 > 252 && x1 < 288) || (x1 > 428 && x1 < 464)))
            {
                e = 1;
                grid ^= 1;
                SDL_FreeSurface(ggrids);
                SDL_DestroyTexture(ggridt);
                if (grid)
                {
                    ggrids = IMG_Load("5x5.png");
                    ggridt = SDL_CreateTextureFromSurface(renderer, ggrids);
                }
                else
                {
                    ggrids = IMG_Load("2x2.png");
                    ggridt = SDL_CreateTextureFromSurface(renderer, ggrids);
                }
                buttonp.y = 219;
                SDL_RenderCopy(renderer, gmodet, NULL, &buttonp);
            }
            else if (y1 > 305 && y1 < 357 && x1 > 505 && x1 < 565)
            {
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(rightsu);
                SDL_FreeSurface(rightsd);
                SDL_FreeSurface(leftsu);
                SDL_FreeSurface(leftsd);
                SDL_FreeSurface(nexts);
                SDL_FreeSurface(backs);
                SDL_FreeSurface(tmodes);
                SDL_FreeSurface(tgrids);
                SDL_FreeSurface(gmodes);
                SDL_FreeSurface(ggrids);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(righttu);
                SDL_DestroyTexture(righttd);
                SDL_DestroyTexture(lefttu);
                SDL_DestroyTexture(lefttd);
                SDL_DestroyTexture(nextt);
                SDL_DestroyTexture(backt);
                SDL_DestroyTexture(tmodet);
                SDL_DestroyTexture(tgridt);
                SDL_DestroyTexture(gmodet);
                SDL_DestroyTexture(ggridt);
                returnValue = playermenu(event, window, renderer, mode ^ 1, grid);
                if (returnValue == 0 || returnValue == 1)
                {
                    return returnValue;
                }
                mode = 0;
                grid = 0;
                e = 1;
                background_surface = IMG_Load("background.png");
                background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

                nexts = IMG_Load("next.png");
                nextt = SDL_CreateTextureFromSurface(renderer, nexts);

                backs = IMG_Load("back.png");
                backt = SDL_CreateTextureFromSurface(renderer, backs);

                rightsd = IMG_Load("right.png");
                righttd = SDL_CreateTextureFromSurface(renderer, rightsd);

                leftsd = IMG_Load("left.png");
                lefttd = SDL_CreateTextureFromSurface(renderer, leftsd);

                rightsu = IMG_Load("right.png");
                righttu = SDL_CreateTextureFromSurface(renderer, rightsu);

                leftsu = IMG_Load("left.png");
                lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);

                gmodes = IMG_Load("oneplayer.png");
                gmodet = SDL_CreateTextureFromSurface(renderer, gmodes);

                ggrids = IMG_Load("2x2.png");
                ggridt = SDL_CreateTextureFromSurface(renderer, ggrids);

                tmodes = IMG_Load("gamemode.png");
                tmodet = SDL_CreateTextureFromSurface(renderer, tmodes);

                tgrids = IMG_Load("gamegrid.png");
                tgridt = SDL_CreateTextureFromSurface(renderer, tgrids);
            }
            else if (y1 > 305 && y1 < 357 && x1 > 145 && x1 < 205)
            {
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(rightsu);
                SDL_FreeSurface(rightsd);
                SDL_FreeSurface(leftsu);
                SDL_FreeSurface(leftsd);
                SDL_FreeSurface(nexts);
                SDL_FreeSurface(backs);
                SDL_FreeSurface(tmodes);
                SDL_FreeSurface(tgrids);
                SDL_FreeSurface(gmodes);
                SDL_FreeSurface(ggrids);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(righttu);
                SDL_DestroyTexture(righttd);
                SDL_DestroyTexture(lefttu);
                SDL_DestroyTexture(lefttd);
                SDL_DestroyTexture(nextt);
                SDL_DestroyTexture(backt);
                SDL_DestroyTexture(tmodet);
                SDL_DestroyTexture(tgridt);
                SDL_DestroyTexture(gmodet);
                SDL_DestroyTexture(ggridt);
                return 1;
            }
            break;

        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x3,&y3);
            if (y3 > 100 && y3 < 136 && x3 > 252 && x3 < 288)
            {
                e = 1;
                SDL_FreeSurface(leftsu);
                SDL_DestroyTexture(lefttu);
                leftsu = IMG_Load("leftg.png");
                lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);
                SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);
            }
            else if (y3 > 220 && y3 < 256 && x3 > 252 && x3 < 288)
            {
                e = 1;
                SDL_FreeSurface(leftsd);
                SDL_DestroyTexture(lefttd);
                leftsd = IMG_Load("leftg.png");
                lefttd = SDL_CreateTextureFromSurface(renderer, leftsd);
                SDL_RenderCopy(renderer, lefttd, NULL, &buttonl);
            }
            else if (y3 > 100 && y3 < 136 && x3 > 428 && x3 < 464)
            {
                e = 1;
                SDL_FreeSurface(rightsu);
                SDL_DestroyTexture(righttu);
                rightsu = IMG_Load("rightg.png");
                righttu = SDL_CreateTextureFromSurface(renderer, rightsu);
                SDL_RenderCopy(renderer, righttu, NULL, &buttonr);
            }
            else if (y3 > 220 && y3 < 256 && x3 > 428 && x3 < 464)
            {
                e = 1;
                SDL_FreeSurface(rightsd);
                SDL_DestroyTexture(righttd);
                rightsd = IMG_Load("rightg.png");
                righttd = SDL_CreateTextureFromSurface(renderer, rightsd);
                SDL_RenderCopy(renderer, righttd, NULL, &buttonr);
            }
            else if (y3 > 305 && y3 < 357 && x3 > 145 && x3 < 205)
            {
                e = 1;
                SDL_FreeSurface(backs);
                SDL_DestroyTexture(backt);
                backs = IMG_Load("backg.png");
                backt = SDL_CreateTextureFromSurface(renderer, backs);
            }
            else if (y3 > 305 && y3 < 357 && x3 > 505 && x3 < 565)
            {
                e = 1;
                SDL_FreeSurface(nexts);
                SDL_DestroyTexture(nextt);
                nexts = IMG_Load("nextg.png");
                nextt = SDL_CreateTextureFromSurface(renderer, nexts);
            }
            else
            {
                e = 1;
                SDL_FreeSurface(rightsu);
                SDL_FreeSurface(rightsd);
                SDL_FreeSurface(leftsu);
                SDL_FreeSurface(leftsd);
                SDL_FreeSurface(nexts);
                SDL_FreeSurface(backs);
                SDL_DestroyTexture(righttu);
                SDL_DestroyTexture(righttd);
                SDL_DestroyTexture(lefttu);
                SDL_DestroyTexture(lefttd);
                SDL_DestroyTexture(nextt);
                SDL_DestroyTexture(backt);
                backs = IMG_Load("back.png");
                backt = SDL_CreateTextureFromSurface(renderer, backs);
                nexts = IMG_Load("next.png");
                nextt = SDL_CreateTextureFromSurface(renderer, nexts);
                rightsu = IMG_Load("right.png");
                righttu = SDL_CreateTextureFromSurface(renderer, rightsu);
                leftsu = IMG_Load("left.png");
                lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);
                rightsd = IMG_Load("right.png");
                righttd = SDL_CreateTextureFromSurface(renderer, rightsd);
                leftsd = IMG_Load("left.png");
                lefttd = SDL_CreateTextureFromSurface(renderer, leftsd);
                SDL_RenderCopy(renderer, righttu, NULL, &buttonr);
                SDL_RenderCopy(renderer, righttd, NULL, &buttonr);
                SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);
                SDL_RenderCopy(renderer, lefttd, NULL, &buttonl);
            }
            break;
        }

        SDL_Delay(1000/100);
        if(event.type == SDL_QUIT)
        {
            a = 0;
            SDL_DestroyTexture(background_texture);
            SDL_DestroyTexture(righttu);
            SDL_DestroyTexture(righttd);
            SDL_DestroyTexture(lefttu);
            SDL_DestroyTexture(lefttd);
            SDL_DestroyTexture(nextt);
            SDL_DestroyTexture(backt);
            SDL_DestroyTexture(tmodet);
            SDL_DestroyTexture(tgridt);
            SDL_DestroyTexture(gmodet);
            SDL_DestroyTexture(ggridt);
            SDL_Quit();
            return 0;
        }
    }

    /*destroying the textures*/
    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(righttu);
    SDL_DestroyTexture(righttd);
    SDL_DestroyTexture(lefttu);
    SDL_DestroyTexture(lefttd);
    SDL_DestroyTexture(nextt);
    SDL_DestroyTexture(backt);
    SDL_DestroyTexture(tmodet);
    SDL_DestroyTexture(tgridt);
    SDL_DestroyTexture(gmodet);
    SDL_DestroyTexture(ggridt);
    SDL_Quit();
    return 0;
}
