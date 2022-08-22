#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "game.h"


int playermenu(SDL_Event event, SDL_Window* window, SDL_Renderer* renderer, int mode, int grid)
{

    /*setting the required surfaces and textures*/
    int a = 1;
    char P1Name[30] = {' '};
    char P2Name[30] = {' '};
    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;

    SDL_Surface* nexts = NULL;
    SDL_Texture* nextt = NULL;

    SDL_Surface* backs = NULL;
    SDL_Texture* backt = NULL;

    SDL_Surface* tdifficultys = NULL;
    SDL_Texture* tdifficultyt = NULL;

    SDL_Surface* gdifficultys = NULL;
    SDL_Texture* gdifficultyt = NULL;

    SDL_Surface* rightsu = NULL;
    SDL_Texture* righttu = NULL;

    SDL_Surface* leftsu = NULL;
    SDL_Texture* lefttu = NULL;

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

    SDL_Rect title;
    title.x = 250;
    title.y = 0;
    title.w = 214;
    title.h = 60;

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

    rightsu = IMG_Load("right.png");
    righttu = SDL_CreateTextureFromSurface(renderer, rightsu);

    leftsu = IMG_Load("left.png");
    lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);

    gdifficultys = IMG_Load("easy.png");
    gdifficultyt = SDL_CreateTextureFromSurface(renderer, gdifficultys);

    tdifficultys = IMG_Load("gamedifficulty.png");
    tdifficultyt = SDL_CreateTextureFromSurface(renderer, tdifficultys);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    background_surface = IMG_Load("background.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    TTF_Init();
    SDL_StopTextInput();

    char inputText1[30] = "Enter player's one name";
    char inputText2[30] = "Enter player's two name";

    TTF_Font* textfont1 = TTF_OpenFont("ocrr.ttf", 17);
    TTF_Font* textfont2 = TTF_OpenFont("ocrr.ttf", 17);
    TTF_SetFontStyle(textfont1, TTF_STYLE_BOLD);
    TTF_SetFontStyle(textfont2, TTF_STYLE_BOLD);

    SDL_Color textcolor = {150, 150, 150, 150};

    SDL_Rect Message_rect1;
    Message_rect1.x = 275;
    Message_rect1.y = 180;
    Message_rect1.w = 300;
    Message_rect1.h = 17;

    SDL_Rect Message_rect2;
    Message_rect2.x = 275;
    Message_rect2.y = 180;
    Message_rect2.w = 300;
    Message_rect2.h = 17;

    SDL_Rect text_rect1;
    text_rect1.x = 265;
    text_rect1.y = 175;
    text_rect1.w = 350;
    text_rect1.h = 30;

    SDL_Rect text_rect2;
    text_rect2.x = 265;
    text_rect2.y = 175;
    text_rect2.w = 350;
    text_rect2.h = 30;

    SDL_Rect pname;
    pname.x = 73;
    pname.y = 160;
    pname.w = 197;
    pname.h = 65;

    SDL_Surface* surfaceMessage = TTF_RenderText_Blended(textfont1, inputText1, textcolor);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Surface* surfaceMessag = TTF_RenderText_Blended(textfont2, inputText2, textcolor);
    SDL_Texture* Messag = SDL_CreateTextureFromSurface(renderer, surfaceMessag);

    SDL_Surface* textbox1s = IMG_Load("textboxn.png");
    SDL_Texture* textbox1t = SDL_CreateTextureFromSurface(renderer, textbox1s);

    SDL_Surface* textbox2s = IMG_Load("textboxn.png");
    SDL_Texture* textbox2t = SDL_CreateTextureFromSurface(renderer, textbox2s);

    SDL_Surface* p1ns = IMG_Load("playeronename.png");
    SDL_Texture* p1nt = SDL_CreateTextureFromSurface(renderer, p1ns);

    SDL_Surface* p2ns = IMG_Load("playertwoname.png");
    SDL_Texture* p2nt = SDL_CreateTextureFromSurface(renderer, p2ns);

    nexts = IMG_Load("next.png");
    nextt = SDL_CreateTextureFromSurface(renderer, nexts);

    backs = IMG_Load("back.png");
    backt = SDL_CreateTextureFromSurface(renderer, backs);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int x3, y3, x1, y1;
    int difficulty = 0;
    int rendertext1 = 0, rendertext2 = 0;
    TTF_SizeText(textfont1, inputText1, &Message_rect1.w, &Message_rect1.h);
    TTF_SizeText(textfont2, inputText2, &Message_rect2.w, &Message_rect2.h);
    while(a)
    {
        SDL_PollEvent(&event);
        /*rendering the needed textures*/
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background_texture, NULL, &bac);
        SDL_RenderCopy(renderer, backt, NULL, &backb);
        SDL_RenderCopy(renderer, nextt, NULL, &nextb);
        if (mode)
        {
            title.y = 45;
            SDL_RenderCopy(renderer, tdifficultyt, NULL, &title);

            buttonr.y = 100;
            SDL_RenderCopy(renderer, righttu, NULL, &buttonr);

            buttonl.y = 100;
            SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);

            buttonp.y = 99;
            SDL_RenderCopy(renderer, gdifficultyt, NULL, &buttonp);
            pname.y = 160;
            text_rect1.y = 175;

            Message_rect1.y = 180;


        }
        else
        {
            SDL_Color textcolor = {250, 0, 15, 0};

            SDL_FreeSurface(surfaceMessag);

            SDL_DestroyTexture(Messag);
            surfaceMessag = TTF_RenderText_Blended(textfont2, inputText2, textcolor);

            Messag = SDL_CreateTextureFromSurface(renderer, surfaceMessag);
            text_rect2.y = 175;
            SDL_RenderCopy(renderer, textbox2t, NULL, &text_rect2);
            Message_rect2.y = 180;
            SDL_RenderCopy(renderer, Messag, NULL, &Message_rect2);
            pname.y = 160;
            SDL_RenderCopy(renderer, p2nt, NULL, &pname);
            pname.y = 80;
            text_rect1.y = 95;
            Message_rect1.y = 100;
        }
        SDL_Color textcolor = {15, 0, 250, 0};

        SDL_FreeSurface(surfaceMessage);

        SDL_DestroyTexture(Message);
        surfaceMessage = TTF_RenderText_Blended(textfont1, inputText1, textcolor);
        Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_RenderCopy(renderer, p1nt, NULL, &pname);

        SDL_RenderCopy(renderer, textbox1t, NULL, &text_rect1);

        SDL_RenderCopy(renderer, Message, NULL, &Message_rect1);
        SDL_RenderPresent(renderer);

        /*handling courser actions*/
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x1,&y1);
            if (y1 > 100 && y1 < 136 && ((x1 > 252 && x1 < 288) || (x1 > 428 && x1 < 464)) && mode == 1)
            {
                difficulty ^= 1;
                SDL_FreeSurface(gdifficultys);
                SDL_DestroyTexture(gdifficultyt);
                if (difficulty)
                {
                    gdifficultys = IMG_Load("hard.png");
                    gdifficultyt = SDL_CreateTextureFromSurface(renderer, gdifficultys);
                }
                else
                {
                    gdifficultys = IMG_Load("easy.png");
                    gdifficultyt = SDL_CreateTextureFromSurface(renderer, gdifficultys);
                }
                buttonp.y = 99;
                SDL_RenderCopy(renderer, gdifficultyt, NULL, &buttonp);
            }
            else if (y1 > 305 && y1 < 357 && x1 > 505 && x1 < 565)
            {
                if (mode)
                {
                    if (strcmp(inputText1, "Enter player's one name") && strcmp(inputText1, ""))
                    {
                        strcpy(P1Name, inputText1);
                        SDL_FreeSurface(background_surface);
                        SDL_DestroyTexture(background_texture);

                        SDL_FreeSurface(nexts);
                        SDL_DestroyTexture(nextt);

                        SDL_FreeSurface(backs);
                        SDL_DestroyTexture(backt);

                        SDL_FreeSurface(tdifficultys);
                        SDL_DestroyTexture(tdifficultyt);

                        SDL_FreeSurface(gdifficultys);
                        SDL_DestroyTexture(gdifficultyt);

                        SDL_FreeSurface(rightsu);
                        SDL_DestroyTexture(righttu);

                        SDL_FreeSurface(leftsu);
                        SDL_DestroyTexture(lefttu);

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
                        SDL_FreeSurface(textbox1s);
                        SDL_DestroyTexture(textbox1t);
                        SDL_FreeSurface(textbox2s);
                        SDL_DestroyTexture(textbox2t);
                        SDL_FreeSurface(surfaceMessage);
                        SDL_DestroyTexture(Message);
                        SDL_FreeSurface(surfaceMessag);
                        SDL_DestroyTexture(Messag);
                        SDL_FreeSurface(p1ns);
                        SDL_DestroyTexture(p1nt);
                        SDL_FreeSurface(p2ns);
                        SDL_DestroyTexture(p2nt);
                        TTF_Quit();
                        strcpy(P2Name, "Computer");
                        return game(mode + (difficulty ^ 1), P1Name, P2Name, grid, event, window, renderer, " ");
                    }
                }
                else
                {
                    if (strcmp(inputText1, "Enter player's one name") && strcmp(inputText1, "") && strcmp(inputText2, "Enter player's two name") && strcmp(inputText2, ""))
                    {
                        strcpy(P1Name, inputText1);
                        SDL_FreeSurface(background_surface);
                        SDL_DestroyTexture(background_texture);

                        SDL_FreeSurface(nexts);
                        SDL_DestroyTexture(nextt);

                        SDL_FreeSurface(backs);
                        SDL_DestroyTexture(backt);

                        SDL_FreeSurface(tdifficultys);
                        SDL_DestroyTexture(tdifficultyt);

                        SDL_FreeSurface(gdifficultys);
                        SDL_DestroyTexture(gdifficultyt);

                        SDL_FreeSurface(rightsu);
                        SDL_DestroyTexture(righttu);

                        SDL_FreeSurface(leftsu);
                        SDL_DestroyTexture(lefttu);

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
                        SDL_FreeSurface(textbox1s);
                        SDL_DestroyTexture(textbox1t);
                        SDL_FreeSurface(textbox2s);
                        SDL_DestroyTexture(textbox2t);
                        SDL_FreeSurface(surfaceMessage);
                        SDL_DestroyTexture(Message);
                        SDL_FreeSurface(surfaceMessag);
                        SDL_DestroyTexture(Messag);
                        SDL_FreeSurface(p1ns);
                        SDL_DestroyTexture(p1nt);
                        SDL_FreeSurface(p2ns);
                        SDL_DestroyTexture(p2nt);
                        TTF_Quit();
                        strcpy(P2Name, inputText2);
                        return game(mode, P1Name, P2Name, grid, event, window, renderer, " ");
                    }
                }
            }
            else if (y1 > 95 && y1 < 125 && x1 > 265 && x1 < 570 && mode == 0)
            {
                SDL_FreeSurface(textbox1s);
                SDL_DestroyTexture(textbox1t);
                SDL_FreeSurface(textbox2s);
                SDL_DestroyTexture(textbox2t);
                textbox1s = IMG_Load("textbox1.png");
                textbox1t = SDL_CreateTextureFromSurface(renderer, textbox1s);
                textbox2s = IMG_Load("textboxn.png");
                textbox2t = SDL_CreateTextureFromSurface(renderer, textbox2s);
                rendertext1 = 1;
                rendertext2 = 0;
                SDL_StartTextInput();
            }
            else if (y1 > 175 && y1 < 205 && x1 > 265 && x1 < 570)
            {
                if (mode)
                {
                    SDL_FreeSurface(textbox1s);
                    SDL_DestroyTexture(textbox1t);
                    textbox1s = IMG_Load("textbox1.png");
                    textbox1t = SDL_CreateTextureFromSurface(renderer, textbox1s);
                    rendertext1 = 1;
                    rendertext2 = 0;
                }
                else
                {
                    SDL_FreeSurface(textbox1s);
                    SDL_DestroyTexture(textbox1t);
                    SDL_FreeSurface(textbox2s);
                    SDL_DestroyTexture(textbox2t);
                    textbox1s = IMG_Load("textboxn.png");
                    textbox1t = SDL_CreateTextureFromSurface(renderer, textbox1s);
                    textbox2s = IMG_Load("textbox2.png");
                    textbox2t = SDL_CreateTextureFromSurface(renderer, textbox2s);
                    rendertext1 = 0;
                    rendertext2 = 1;
                }
                SDL_StartTextInput();
            }
            else if (y1 > 305 && y1 < 357 && x1 > 145 && x1 < 205)
            {
                SDL_FreeSurface(background_surface);
                SDL_DestroyTexture(background_texture);

                SDL_FreeSurface(nexts);
                SDL_DestroyTexture(nextt);

                SDL_FreeSurface(backs);
                SDL_DestroyTexture(backt);

                SDL_FreeSurface(tdifficultys);
                SDL_DestroyTexture(tdifficultyt);

                SDL_FreeSurface(gdifficultys);
                SDL_DestroyTexture(gdifficultyt);

                SDL_FreeSurface(rightsu);
                SDL_DestroyTexture(righttu);

                SDL_FreeSurface(leftsu);
                SDL_DestroyTexture(lefttu);

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

                SDL_FreeSurface(textbox1s);
                SDL_DestroyTexture(textbox1t);
                SDL_FreeSurface(textbox2s);
                SDL_DestroyTexture(textbox2t);
                SDL_FreeSurface(surfaceMessage);
                SDL_DestroyTexture(Message);
                SDL_FreeSurface(surfaceMessag);
                SDL_DestroyTexture(Messag);
                SDL_FreeSurface(p1ns);
                SDL_DestroyTexture(p1nt);
                SDL_FreeSurface(p2ns);
                SDL_DestroyTexture(p2nt);
                TTF_Quit();
                return 2;
            }
            else
            {
                rendertext1 = 0;
                rendertext2 = 0;
                SDL_FreeSurface(textbox1s);
                SDL_DestroyTexture(textbox1t);
                SDL_FreeSurface(textbox2s);
                SDL_DestroyTexture(textbox2t);
                textbox1s = IMG_Load("textboxn.png");
                textbox1t = SDL_CreateTextureFromSurface(renderer, textbox1s);
                textbox2s = IMG_Load("textboxn.png");
                textbox2t = SDL_CreateTextureFromSurface(renderer, textbox2s);
                SDL_StopTextInput();
            }
            break;

        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x3,&y3);
            if (y3 > 100 && y3 < 136 && x3 > 252 && x3 < 288)
            {
                SDL_FreeSurface(leftsu);
                SDL_DestroyTexture(lefttu);
                leftsu = IMG_Load("leftg.png");
                lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);
                SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);
            }
            else if (y3 > 100 && y3 < 136 && x3 > 428 && x3 < 464)
            {
                SDL_FreeSurface(rightsu);
                SDL_DestroyTexture(righttu);
                rightsu = IMG_Load("rightg.png");
                righttu = SDL_CreateTextureFromSurface(renderer, rightsu);
                SDL_RenderCopy(renderer, righttu, NULL, &buttonr);
            }
            else if (y3 > 305 && y3 < 357 && x3 > 145 && x3 < 205)
            {
                SDL_FreeSurface(backs);
                SDL_DestroyTexture(backt);
                backs = IMG_Load("backg.png");
                backt = SDL_CreateTextureFromSurface(renderer, backs);
            }
            else if (y3 > 305 && y3 < 357 && x3 > 505 && x3 < 565)
            {
                SDL_FreeSurface(nexts);
                SDL_DestroyTexture(nextt);
                nexts = IMG_Load("nextg.png");
                nextt = SDL_CreateTextureFromSurface(renderer, nexts);
            }
            else
            {
                SDL_FreeSurface(backs);
                SDL_DestroyTexture(backt);
                SDL_FreeSurface(nexts);
                SDL_DestroyTexture(nextt);
                SDL_FreeSurface(leftsu);
                SDL_DestroyTexture(lefttu);
                SDL_FreeSurface(rightsu);
                SDL_DestroyTexture(righttu);
                backs = IMG_Load("back.png");
                backt = SDL_CreateTextureFromSurface(renderer, backs);
                nexts = IMG_Load("next.png");
                nextt = SDL_CreateTextureFromSurface(renderer, nexts);
                rightsu = IMG_Load("right.png");
                righttu = SDL_CreateTextureFromSurface(renderer, rightsu);
                leftsu = IMG_Load("left.png");
                lefttu = SDL_CreateTextureFromSurface(renderer, leftsu);

                SDL_RenderCopy(renderer, righttu, NULL, &buttonr);
                SDL_RenderCopy(renderer, lefttu, NULL, &buttonl);
            }
            break;
        case (SDL_KEYDOWN):
            if (rendertext1)
            {
                if( event.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText1) > 0)
                {
                    inputText1[strlen(inputText1) - 1] = '\0';
                    TTF_SizeText(textfont1, inputText1, &Message_rect1.w, &Message_rect1.h);
                }
                else if( event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                {
                    SDL_SetClipboardText( inputText1 );
                    TTF_SizeText(textfont1, inputText1, &Message_rect1.w, &Message_rect1.h);
                }
                else if( event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                {
                    if (strlen(inputText1) + strlen(SDL_GetClipboardText()) > 30)
                    {
                        printf("\a");
                    }
                    strncat(inputText1, SDL_GetClipboardText(), 30 - strlen(inputText1));
                    TTF_SizeText(textfont1, inputText1, &Message_rect1.w, &Message_rect1.h);
                }
            }
            else if (rendertext2)
            {
                if( event.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText2) > 0)
                {
                    inputText2[strlen(inputText2) - 1] = '\0';
                    TTF_SizeText(textfont2, inputText2, &Message_rect2.w, &Message_rect2.h);
                }
                else if( event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                {
                    SDL_SetClipboardText(inputText2);
                    TTF_SizeText(textfont2, inputText2, &Message_rect2.w, &Message_rect2.h);
                }
                else if( event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                {
                    if (strlen(inputText2) + strlen(SDL_GetClipboardText()) > 30)
                    {
                        printf("\a");
                    }
                    strncat(inputText2, SDL_GetClipboardText(), 30 - strlen(inputText2));
                    TTF_SizeText(textfont2, inputText2, &Message_rect2.w, &Message_rect2.h);
                }
            }
            break;

        case(SDL_TEXTINPUT):
            if (rendertext1)
            {
                if( !( SDL_GetModState() & KMOD_CTRL && ( event.text.text[ 0 ] == 'c' || event.text.text[ 0 ] == 'C' || event.text.text[ 0 ] == 'v' || event.text.text[ 0 ] == 'V' ) ) )
                {
                    textcolor.r = 15;
                    textcolor.g = 0;
                    textcolor.b = 250;
                    textcolor.a = 0;
                    if (!(strcmp(inputText1, "Enter player's one name")))
                    {
                        inputText1[0] = '\0';
                    }
                    if (strlen(inputText1) <= 29)
                    {
                        strcat(inputText1, event.text.text);
                        TTF_SizeText(textfont1, inputText1, &Message_rect1.w, &Message_rect1.h);
                    }
                    else
                    {
                        printf("\a");
                    }
                }
            }
            else if (rendertext2)
            {
                if( !( SDL_GetModState() & KMOD_CTRL && ( event.text.text[ 0 ] == 'c' || event.text.text[ 0 ] == 'C' || event.text.text[ 0 ] == 'v' || event.text.text[ 0 ] == 'V' ) ) )
                {
                    textcolor.r = 250;
                    textcolor.g = 0;
                    textcolor.b = 15;
                    textcolor.a = 0;
                    if (!(strcmp(inputText2, "Enter player's two name")))
                    {
                        inputText2[0] = '\0';
                    }
                    if (strlen(inputText2) <= 29)
                    {
                        strcat(inputText2, event.text.text);
                        TTF_SizeText(textfont2, inputText2, &Message_rect2.w, &Message_rect2.h);
                    }
                    else
                    {
                        printf("\a");
                    }
                }
            }
            break;
        }
        SDL_Delay(1000/100);
        if(event.type == SDL_QUIT)
        {
            a = 0;
            SDL_FreeSurface(background_surface);
            SDL_DestroyTexture(background_texture);

            SDL_FreeSurface(nexts);
            SDL_DestroyTexture(nextt);

            SDL_FreeSurface(backs);
            SDL_DestroyTexture(backt);

            SDL_FreeSurface(tdifficultys);
            SDL_DestroyTexture(tdifficultyt);

            SDL_FreeSurface(gdifficultys);
            SDL_DestroyTexture(gdifficultyt);

            SDL_FreeSurface(rightsu);
            SDL_DestroyTexture(righttu);

            SDL_FreeSurface(leftsu);
            SDL_DestroyTexture(lefttu);

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

            SDL_FreeSurface(textbox1s);
            SDL_DestroyTexture(textbox1t);
            SDL_FreeSurface(textbox2s);
            SDL_DestroyTexture(textbox2t);
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(Message);
            SDL_FreeSurface(surfaceMessag);
            SDL_DestroyTexture(Messag);
            SDL_FreeSurface(p1ns);
            SDL_DestroyTexture(p1nt);
            SDL_FreeSurface(p2ns);
            SDL_DestroyTexture(p2nt);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            TTF_Quit();
            SDL_Quit();
            return 0;
        }
    }

    /*destroying the textures*/
    SDL_FreeSurface(background_surface);
    SDL_DestroyTexture(background_texture);

    SDL_FreeSurface(nexts);
    SDL_DestroyTexture(nextt);

    SDL_FreeSurface(backs);
    SDL_DestroyTexture(backt);

    SDL_FreeSurface(tdifficultys);
    SDL_DestroyTexture(tdifficultyt);

    SDL_FreeSurface(gdifficultys);
    SDL_DestroyTexture(gdifficultyt);

    SDL_FreeSurface(rightsu);
    SDL_DestroyTexture(righttu);

    SDL_FreeSurface(leftsu);
    SDL_DestroyTexture(lefttu);

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
    SDL_FreeSurface(textbox1s);
    SDL_DestroyTexture(textbox1t);
    SDL_FreeSurface(textbox2s);
    SDL_DestroyTexture(textbox2t);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessag);
    SDL_DestroyTexture(Messag);
    SDL_FreeSurface(p1ns);
    SDL_DestroyTexture(p1nt);
    SDL_FreeSurface(p2ns);
    SDL_DestroyTexture(p2nt);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
