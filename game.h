#ifndef GAME_H
#define GAME_H
#include "Save.h"
#include "Rank.h"
#include "AI.h"
#include <SDL_ttf.h>

int game(int gametype, char P1Name[30], char P2Name[30], int grid, SDL_Event event, SDL_Window* window, SDL_Renderer* renderer, char name[11])
{

    /*setting the required surfaces and textures*/
    TTF_Init();

    int a = 1, sec;
    int di = 0;
    clock_t dif, before = clock();
    char namestring[50], scorestring[50], movestring[50], availablestring[50], timestring[50];
    char stringg[11][75] = {{' '}};

    struct
    {
        char name[30];
        int moves;
        int score;
        int color;
    } P1 = {" ", 0,0,0}, P2 = {" ", 0, 0, 1};

    for (int i = 0; i < 30; i++)
    {
        P1.name[i] = P1Name[i];
        P2.name[i] = P2Name[i];
    }

    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;
    SDL_Surface* savlos = NULL;
    SDL_Texture* savlot = NULL;
    SDL_Surface* button_surface = NULL;
    SDL_Texture* button_texture = NULL;
    SDL_Surface* undo_surf = NULL;
    SDL_Texture* undo_texture = NULL;
    SDL_Surface* redo_surf = NULL;
    SDL_Texture* redo_texture = NULL;
    SDL_Surface* save_surf = NULL;
    SDL_Texture* save_texture = NULL;
    SDL_Surface* exit_surf = NULL;
    SDL_Texture* exit_texture = NULL;
    SDL_Surface* sub_surf = NULL;
    SDL_Texture* sub_texture = NULL;
    SDL_Surface* exit_s = NULL;
    SDL_Texture* exit_t = NULL;
    SDL_Surface* home_s = NULL;
    SDL_Texture* home_t = NULL;
    SDL_Surface* lmainmenus = NULL;
    SDL_Texture* lmainmenut = NULL;
    SDL_Surface* lexits = NULL;
    SDL_Texture* lexitt = NULL;
    SDL_Surface* mmenu_s = NULL;
    SDL_Texture* mmenu_t = NULL;
    SDL_Surface* suspend_surface = NULL;
    SDL_Texture* suspend_texture = NULL;
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
    SDL_Surface* filesaves = NULL;
    SDL_Texture* filesavet = NULL;
    SDL_Surface* b5 = NULL;
    SDL_Texture* b5t = NULL;

    SDL_Surface* game_states = NULL;
    SDL_Texture* game_statet = NULL;

    TTF_Font* textfont1 = TTF_OpenFont("ocrr.ttf", 17);
    TTF_SetFontStyle(textfont1, TTF_STYLE_BOLD);

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

    SDL_Rect buttonu_pos;
    buttonu_pos.w = 45;
    buttonu_pos.h = 45;
    buttonu_pos.x = 410;
    buttonu_pos.y = 30;

    SDL_Rect savlorect;
    savlorect.x = 133;
    savlorect.y = 125;
    savlorect.w = 450;
    savlorect.h = 200;

    SDL_Rect filrect;
    filrect.x = 143;
    filrect.y = 115;
    filrect.w = 430;
    filrect.h = 90;

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


    SDL_Rect buttonr_pos;
    buttonr_pos.w = 45;
    buttonr_pos.h = 45;
    buttonr_pos.x = 469;
    buttonr_pos.y = 30;

    SDL_Rect buttonsave_pos;
    buttonsave_pos.w = 45;
    buttonsave_pos.h = 45;
    buttonsave_pos.x = 528;
    buttonsave_pos.y = 30;

    SDL_Rect buttonhome_pos;
    buttonhome_pos.w = 45;
    buttonhome_pos.h = 45;
    buttonhome_pos.x = 587;
    buttonhome_pos.y = 30;

    SDL_Rect buttonexit_pos;
    buttonexit_pos.w = 45;
    buttonexit_pos.h = 45;
    buttonexit_pos.x = 646;
    buttonexit_pos.y = 30;

    SDL_Rect buttonu;
    buttonu.w = 45;
    buttonu.h = 45;
    buttonu.x = 400;
    buttonu.y = 30;

    SDL_Rect buttonr;
    buttonr.w = 45;
    buttonr.h = 45;
    buttonr.x = 461;
    buttonr.y = 30;

    SDL_Rect buttonsave;
    buttonsave.w = 45;
    buttonsave.h = 45;
    buttonsave.x = 522;
    buttonsave.y = 30;

    SDL_Rect buttonhome;
    buttonhome.w = 45;
    buttonhome.h = 45;
    buttonhome.x = 583;
    buttonhome.y = 30;

    SDL_Rect buttonexit;
    buttonexit.w = 45;
    buttonexit.h = 45;
    buttonexit.x = 644;
    buttonexit.y = 30;

    SDL_Surface* textbars = NULL;
    SDL_Texture* textbart = NULL;

    SDL_Rect nullity;
    nullity.w = 0;
    nullity.h = 0;
    nullity.x = 0;
    nullity.y = 0;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    background_surface = IMG_Load("background.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    suspend_surface = IMG_Load("suspend.png");
    suspend_texture = SDL_CreateTextureFromSurface(renderer, suspend_surface);

    lmainmenus = IMG_Load("lmainmenu.png");
    lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);

    lexits = IMG_Load("lexit.png");
    lexitt = SDL_CreateTextureFromSurface(renderer, lexits);


    savlos = IMG_Load("savlo.png");
    savlot = SDL_CreateTextureFromSurface(renderer, savlos);

    /*defining needed variables*/
    int x, y;

    if (grid)
    {
        x = 5, y = 5;
        button_surface = IMG_Load("5x5grid.png");
    }
    else
    {
        x = 2, y = 2;
        button_surface = IMG_Load("2x2grid.png");
    }
    button_texture = SDL_CreateTextureFromSurface(renderer, button_surface);

    home_s = IMG_Load("home.png");
    home_t = SDL_CreateTextureFromSurface(renderer, home_s);

    confirms = IMG_Load("confirm.png");
    confirmt = SDL_CreateTextureFromSurface(renderer, confirms);

    cancels = IMG_Load("cancell.png");
    cancelt = SDL_CreateTextureFromSurface(renderer, cancels);

    filesaves = IMG_Load("filesave.png");
    filesavet = SDL_CreateTextureFromSurface(renderer, filesaves);

    undo_surf = IMG_Load("undo.png");
    undo_texture = SDL_CreateTextureFromSurface(renderer, undo_surf);

    redo_surf = IMG_Load("redo.png");
    redo_texture = SDL_CreateTextureFromSurface(renderer, redo_surf);

    exit_surf = IMG_Load("exitt.png");
    exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surf);

    save_surf = IMG_Load("save.png");
    save_texture = SDL_CreateTextureFromSurface(renderer, save_surf);

    sub_surf = IMG_Load("subsurf.png");
    sub_texture = SDL_CreateTextureFromSurface(renderer, sub_surf);


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

    SDL_Rect backg;
    backg.x = 0;
    backg.y = 0;
    backg.w = 384;
    backg.h = 384;

    SDL_Rect bac;
    bac.x = 0;
    bac.y = 0;
    bac.w = 715;
    bac.h = 384;


    SDL_Rect mainrect;
    mainrect.x = 45;
    mainrect.y = 305;
    mainrect.w = 150;
    mainrect.h = 52;

    SDL_Rect exitrect;
    exitrect.x = 550;
    exitrect.y = 305;
    exitrect.w = 150;
    exitrect.h = 52;

    SDL_Rect winnerpos;
    winnerpos.x = 83;
    winnerpos.y = 25;
    winnerpos.w = 550;
    winnerpos.h = 170;

    SDL_Rect subrect;
    subrect.x = 396;
    subrect.y = 10;
    subrect.w = 311;
    subrect.h = 364;

    SDL_Rect textbarrect;
    textbarrect.x = 410;
    textbarrect.y = 86;
    textbarrect.w = 0;
    textbarrect.h = 0;

    int found, gamet = gametype;
    int player = 0, aloop = 1;
    int history_len = x*(x+1)*2;
    int moves_history[history_len][3];

    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    r.w = 0;
    r.h = 0;

    SDL_Rect box;
    box.x = 0;
    box.y = 0;
    box.w = 0;
    box.h = 0;

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int pressing = 0, stay = 1, fileno = 0;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_Rect Darr[x*(x+1)*2], Darr_redo[x*(x+1)*2];
    int process = 0, ended = 0;
    int column, row;

    for (int i = 0; i < x*(x+1)*2; i++)
    {
        Darr[i] = nullity;
    }

    int ind = 0, tick = 1;
    int boxes[x*x];
    char lines[2*x+1][2*x+1], emptystr[30];;

    int x3, y3, seconds = 0, emptyint;
    int available_moves = x * (x+1) * 2;
    int redo_counter = 0, counter = 0, x_coor, y_coor, moves_redo[x * (x + 1) * 2][3];

    for (int i = 0; i < history_len; i++)
    {
        moves_history[i][0] = 0;
        moves_history[i][1] = 0;
        moves_history[i][2] = 0;
        moves_redo[i][0] = 0;
        moves_redo[i][1] = 0;
        moves_redo[i][2] = 0;
    }

    for (int i = 0; i < x+x+1; i+=2)
    {
        for (int j = 0; j < y+y+1; j+=2)
        {
            lines[i][j] = 254;
        }
    }

    for (int i = 1; i < 2*x; i+=2)
    {
        for (int j = 1; j < 2*y; j+=2)
        {
            boxes[ind] = i*10+j;
            ind++;
        }
    }

    /*check if it is loaded game*/
    if (gamet > 2)
    {
        FILE *sfile;
        if ((sfile = fopen(name,"rb")) == NULL)
        {
            exit(1);
        }
        fread(&emptyint, sizeof(int), 1, sfile);
        fread(&emptystr, sizeof(char), 30, sfile);
        fread(&emptystr, sizeof(char), 30, sfile);
        fread(&emptyint, sizeof(int), 1, sfile);
        fread(&counter, sizeof(int), 1, sfile);
        fread(&P1.score, sizeof(int), 1, sfile);
        fread(&P2.score, sizeof(int), 1, sfile);
        fread(&P1.moves, sizeof(int), 1, sfile);
        fread(&P2.moves, sizeof(int), 1, sfile);
        fread(&available_moves, sizeof(int), 1, sfile);
        fread(&seconds, sizeof(int), 1, sfile);
        fread(&lines, sizeof(char), (x+x+1) * (x+x+1), sfile);
        fread(&player, sizeof(int), 1, sfile);
        fread(&boxes, sizeof(int), x*x, sfile);
        fread(&history_len, sizeof(int), 1, sfile);
        fread(&moves_history, sizeof(int), history_len * 3, sfile);
        fread(&Darr, sizeof(SDL_Rect), x*(x+1)*2, sfile);
        fread(&Darr_redo, sizeof(SDL_Rect), x*(x+1)*2, sfile);
        fclose(sfile);
    }


    gamet %= 10;
    int enableee = 0;
    SDL_Color textcolor;
    int enable = 1, movecheck = -1;
    FILE *GLog;
    GLog = fopen("GLog.txt", "w");

    while(a)
    {

        SDL_PollEvent(&event);

        int inloop = 0;
        /*rendering needed textures*/
        if (1)
        {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, background_texture, NULL, &bac);
            SDL_RenderCopy(renderer, sub_texture, NULL, &subrect);
            /*get game ticks*/
            if (tick)
            {
                dif = clock() - before;
                sec = seconds + dif / CLOCKS_PER_SEC;
            }
            /*printing information to the screen*/
            char intstr[2];
            if (gamet == 0)
            {
                if (player)
                {
                    memcpy(namestring, "   - Player two turn -", 30);
                    memcpy(stringg[0], namestring, 50);
                }
                else
                {
                    memcpy(namestring, "   - Player one turn -", 30);
                    memcpy(stringg[0], namestring, 50);
                }
            }
            else
            {
                memcpy(namestring, "   - Player one turn -", 30);
                memcpy(stringg[0], namestring, 50);
            }
            memcpy(namestring, "Player one name:", 30);
            memcpy(stringg[1], namestring, 50);
            memcpy(namestring, P1.name, 30);
            memcpy(stringg[2], namestring, 50);
            memcpy(scorestring, "Player one score: ", 30);
            sprintf(intstr, "%d", P1.score);
            strcat(scorestring, intstr);
            memcpy(stringg[3], scorestring, 50);
            memcpy(movestring, "Player one moves: ", 30);
            sprintf(intstr, "%d", P1.moves);
            strcat(movestring, intstr);
            memcpy(stringg[4], movestring, 50);
            memcpy(namestring, "Player two name:", 30);
            memcpy(stringg[5], namestring, 50);
            memcpy(namestring, P2.name, 30);
            memcpy(stringg[6], namestring, 50);
            memcpy(scorestring, "Player two score: ", 30);
            sprintf(intstr, "%d", P2.score);
            strcat(scorestring, intstr);
            memcpy(stringg[7], scorestring, 50);
            memcpy(movestring, "Player two moves: ", 30);
            sprintf(intstr, "%d", P2.moves);
            strcat(movestring, intstr);
            memcpy(stringg[8], movestring, 50);
            memcpy(availablestring, "No of available moves: ", 30);
            sprintf(intstr, "%d", available_moves);
            strcat(availablestring, intstr);
            memcpy(stringg[9], availablestring, 50);
            memcpy(timestring, "Time passed: ", 30);
            if (sec < 60)
            {
                strcat(timestring, "00:");
                if (sec%60 < 10)
                {
                    strcat(timestring, "0");
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
                else
                {
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
            }
            else if (sec < 600)
            {
                strcat(timestring, "0");
                sprintf(intstr, "%d", sec/60);
                strcat(timestring, intstr);
                strcat(timestring, ":");
                if (sec%60 < 10)
                {
                    strcat(timestring, "0");
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
                else
                {
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
            }
            else
            {
                sprintf(intstr, "%d", sec/60);
                strcat(timestring, intstr);
                strcat(timestring, ":");
                if (sec%60 < 10)
                {
                    strcat(timestring, "0");
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
                else
                {
                    sprintf(intstr, "%d", sec%60);
                    strcat(timestring, intstr);
                }
            }
            memcpy(stringg[10], timestring, 50);

            /*handling the color and position of printed text*/
            for (int i = 0; i < 11; i++)
            {
                textbarrect.y = 90 + i * (textbarrect.h + 5);
                SDL_FreeSurface(textbars);
                SDL_DestroyTexture(textbart);
                if (i == 0)
                {
                    if (gamet == 0)
                    {
                        if (player)
                        {
                            textcolor.r = 255;
                            textcolor.g = 0;
                            textcolor.b = 0;
                            textcolor.a = 210;
                        }
                        else
                        {
                            textcolor.r = 0;
                            textcolor.g = 0;
                            textcolor.b = 255;
                            textcolor.a = 210;
                        }
                    }
                    else
                    {
                        textcolor.r = 0;
                        textcolor.g = 0;
                        textcolor.b = 255;
                        textcolor.a = 210;
                    }
                }
                else if (i < 5)
                {
                    textcolor.r = 0;
                    textcolor.g = 0;
                    textcolor.b = 255;
                    textcolor.a = 210;
                }
                else if (i < 9)
                {
                    textbarrect.y += 10;
                    textcolor.r = 255;
                    textcolor.g = 0;
                    textcolor.b = 0;
                    textcolor.a = 210;
                }
                else
                {
                    textbarrect.y += 20;
                    textcolor.r = 255;
                    textcolor.g = 0;
                    textcolor.b = 255;
                    textcolor.a = 210;
                }
                textbars = TTF_RenderText_Blended(textfont1, stringg[i], textcolor);
                textbart = SDL_CreateTextureFromSurface(renderer, textbars);
                TTF_SizeText(textfont1, stringg[i], &textbarrect.w, &textbarrect.h);
                if (textbarrect.w > 295)
                {
                    textbarrect.w /= (1 + (0.005) * (textbarrect.w - 295));
                }
                SDL_RenderCopy(renderer, textbart, NULL, &textbarrect);
            }

            /*rendering completed boxes*/
            for (int k = 0; k < x * x; k++)
            {
                if (grid)
                {
                    box.w = 42;
                    box.h = 42;
                    if (boxes[k]/100)
                    {
                        box.x = 43 + 64 * (((boxes[k]/10)%10)-1)/2;
                        box.y = 43 + 64 * ((boxes[k]/100)-1)/2;
                        if (boxes[k]%10)
                        {
                            SDL_SetRenderDrawColor(renderer, 255, 10, 50, 200);
                        }
                        else
                        {
                            SDL_SetRenderDrawColor(renderer, 10, 50, 255, 200);
                        }
                        SDL_RenderFillRect(renderer, &box);
                    }
                }
                else
                {
                    box.w = 90;
                    box.h = 89;
                    if (boxes[k]/100)
                    {
                        box.x = 83 + 128 * (((boxes[k]/10)%10)-1)/2;
                        box.y = 83 + 128 * ((boxes[k]/100)-1)/2;
                        if (boxes[k]%10)
                        {
                            SDL_SetRenderDrawColor(renderer, 255, 10, 50, 200);
                        }
                        else
                        {
                            SDL_SetRenderDrawColor(renderer, 10, 50, 255, 200);
                        }
                        SDL_RenderFillRect(renderer, &box);
                    }
                }
            }

            /*rendering moves*/
            for (int j = 0; j < counter; j++)
            {
                if (moves_history[j][2])
                {
                    SDL_SetRenderDrawColor(renderer, 255, 10, 50, 200);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 10, 50, 255, 200);
                }
                SDL_RenderFillRect(renderer, &Darr[j]);
            }

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderCopy(renderer, button_texture, NULL, &backg);
            SDL_RenderCopy(renderer, undo_texture, NULL, &buttonu_pos);
            SDL_RenderCopy(renderer, redo_texture, NULL, &buttonr_pos);
            SDL_RenderCopy(renderer, save_texture, NULL, &buttonsave_pos);
            SDL_RenderCopy(renderer, home_t, NULL, &buttonhome_pos);
            SDL_RenderCopy(renderer, exit_texture, NULL, &buttonexit_pos);
            /*rendering save menu*/
            if (enableee)
            {
                pressing = 0;
                SDL_RenderCopy(renderer, savlot, NULL, &savlorect);
                SDL_RenderCopy(renderer, filesavet, NULL, &filrect);
                SDL_RenderCopy(renderer, b1t, NULL, &b1rect);
                SDL_RenderCopy(renderer, b2t, NULL, &b2rect);
                SDL_RenderCopy(renderer, b3t, NULL, &b3rect);
                SDL_RenderCopy(renderer, b4t, NULL, &b4rect);
                SDL_RenderCopy(renderer, b5t, NULL, &b5rect);
                SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
                SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
                SDL_RenderPresent(renderer);
            }
            /*rendering endgame screen*/
            if (ended)
            {
                SDL_RenderCopy(renderer, suspend_texture, NULL, &bac);
                SDL_RenderCopy(renderer, game_statet, NULL, &winnerpos);
                SDL_RenderCopy(renderer, lmainmenut, NULL, &mainrect);
                SDL_RenderCopy(renderer, lexitt, NULL, &exitrect);
                SDL_RenderPresent(renderer);
            }
            SDL_RenderPresent(renderer);
            found = 0, stay = 1;

        }
        /*check if the game ended*/
        if (available_moves <= 0)
        {
            if (!ended)
            {
                tick = 0;
                if (P1.score == P2.score)
                {
                    game_states = IMG_Load("tie.png");
                }
                else if (P1.score > P2.score)
                {
                    game_states = IMG_Load("playeronewins.png");
                    if (gamet == 0 && aloop == 1)
                    {
                        Rank(P1.name, P1.score);
                    }
                }
                else
                {
                    if (gamet == 0)
                    {
                        game_states = IMG_Load("playertwowins.png");
                    }
                    else
                    {
                        game_states = IMG_Load("computerwins.png");
                    }
                    if (gamet == 0 && aloop == 1)
                    {
                        Rank(P2.name, P2.score);
                    }
                }

                game_statet = SDL_CreateTextureFromSurface(renderer,  game_states);
                ended = 1;
            }
        }

        if (enable)
        {
            /*writing moves to the log file*/
            if (movecheck != counter)
            {
                movecheck = counter;
                GLog = fopen("GLog.txt", "a+");
                if(GLog != NULL)
                {
                    if (counter == 0)
                    {
                        fprintf(GLog, "Gametype: %d\n", gametype);
                        fprintf(GLog, "P1Name: %s\n", P1.name);
                        fprintf(GLog, "P2Name: %s\n", P2.name);
                        fprintf(GLog, "Grid: %d\n\n", x);
                    }
                    fprintf(GLog, "counter: %d\n", counter);
                    fprintf(GLog, "P1.score: %d\n", P1.score);
                    fprintf(GLog, "P2.score: %d\n", P2.score);
                    fprintf(GLog, "P1.moves: %d\n", P1.moves);
                    fprintf(GLog, "P2.moves: %d\n", P2.moves);
                    fprintf(GLog, "available_moves: %d\n", available_moves);
                    fprintf(GLog, "seconds: %d\n", seconds);
                    fprintf(GLog, "player: %d\n\n", player);
                    fclose(GLog);
                }
            }
            /*handling courser actions*/
            switch (event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                pressing = 1;
                SDL_GetMouseState(&x1,&y1);
                /*redo button*/
                if (y1 > 30 && y1 < 75 && x1 > 469 && x1 < 514 && redo_counter > 0 && !enableee && !ended)
                {
                    while(stay)
                    {
                        stay = 0;
                        available_moves--;
                        redo_counter--;
                        x_coor = moves_redo[redo_counter][0];
                        y_coor = moves_redo[redo_counter][1];
                        moves_history[counter][0] = x_coor;
                        moves_history[counter][1] = y_coor;
                        moves_history[counter][2] = moves_redo[redo_counter][2];
                        Darr[counter] = Darr_redo[redo_counter];
                        Darr_redo[redo_counter] = nullity;
                        counter++;
                        x_coor--;
                        y_coor--;
                        if (x_coor % 2 == 0 && y_coor % 2 == 1)
                        {
                            lines[x_coor][y_coor] = 205;
                        }
                        else if(x_coor % 2 == 1 && y_coor % 2 == 0)
                        {
                            lines[x_coor][y_coor] = 186;
                        }
                        moves_redo[redo_counter][0] = 0;
                        moves_redo[redo_counter][1] = 0;
                        moves_redo[redo_counter][2] = 0;
                        player ^= 1;
                        P1.moves = 0;
                        P2.moves = 0;
                        for (int i = 0; i < counter; i++)
                        {
                            if(moves_history[i][2])
                            {
                                P2.moves++;
                            }
                            else
                            {
                                P1.moves++;
                            }
                        }
                        inloop = 0;
                        for (int i = 1; i < x+x+1; i+=2)
                        {
                            for (int j = 1; j < y+y+1; j+=2)
                            {
                                for (int k = 0; k < x*x; k++)
                                {
                                    if (i*10 + j == boxes[k])
                                    {
                                        if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                                        {
                                            if (inloop == 0)
                                            {
                                                player ^= 1;
                                            }
                                            lines[i][j] = 219;
                                            boxes[k] = boxes[k] * 10 + player;
                                            if (player)
                                            {
                                                P2.score++;
                                            }
                                            else
                                            {
                                                P1.score++;
                                            }
                                            inloop = 1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        if (gamet != 0 && player == 1)
                        {
                            stay = 1;
                        }
                    }
                    /*undo button*/
                }
                else if (y1 > 30 && y1 < 75 && x1 > 410 && x1 < 455 && counter > 0 && !enableee && !ended)
                {
                    while(stay)
                    {
                        stay = 0;
                        available_moves++;
                        counter--;
                        x_coor = moves_history[counter][0];
                        y_coor = moves_history[counter][1];
                        moves_redo[redo_counter][0] = x_coor;
                        moves_redo[redo_counter][1] = y_coor;
                        moves_redo[redo_counter][2] = moves_history[counter][2];
                        Darr_redo[redo_counter] = Darr[counter];
                        Darr[counter] = nullity;
                        redo_counter++;
                        lines[x_coor-1][y_coor-1] = ' ';
                        moves_history[counter][0] = 0;
                        moves_history[counter][1] = 0;
                        moves_history[counter][2] = 0;

                        player ^= 1;
                        P1.moves = 0;
                        P2.moves = 0;
                        for (int i = 0; i < counter; i++)
                        {
                            if(moves_history[i][2])
                            {
                                P2.moves++;
                            }
                            else
                            {
                                P1.moves++;
                            }
                        }
                        inloop = 0;
                        for (int i = 1; i < x+x+1; i+=2)
                        {
                            for (int j = 1; j < y+y+1; j+=2)
                            {
                                for (int k = 0; k < x * x; k++)
                                {
                                    if (i*10 + j == boxes[k]/10)
                                    {
                                        if (!(lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51))
                                        {
                                            if (inloop == 0)
                                            {
                                                player ^= 1;
                                            }
                                            lines[i][j] = ' ';
                                            boxes[k] /= 10;
                                            if (player)
                                            {
                                                P2.score--;
                                            }
                                            else
                                            {
                                                P1.score--;
                                            }
                                            inloop = 1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        if (gamet != 0 && player == 1)
                        {
                            stay = 1;
                        }
                    }
                    /*save button*/
                }
                else if (y3 > 30 && y3 < 75 && x3 > 520 && x3 < 565 && !enableee && !ended)
                {
                    enableee = 1;
                    tick = 0;
                    /*main menu buutton*/
                }
                else if (y3 > 30 && y3 < 75 && x3 > 587 && x3 < 632 && !enableee && !ended)
                {

                    SDL_FreeSurface(background_surface);
                    SDL_DestroyTexture(background_texture);
                    SDL_FreeSurface(savlos);
                    SDL_DestroyTexture(savlot);
                    SDL_FreeSurface(button_surface);
                    SDL_DestroyTexture(button_texture);
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    SDL_FreeSurface(sub_surf);
                    SDL_DestroyTexture(sub_texture);
                    SDL_FreeSurface(exit_s);
                    SDL_DestroyTexture(exit_t);
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);
                    SDL_FreeSurface(mmenu_s);
                    SDL_DestroyTexture(mmenu_t);
                    SDL_FreeSurface(suspend_surface);
                    SDL_DestroyTexture(suspend_texture);
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);

                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(filesaves);
                    SDL_DestroyTexture(filesavet);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);

                    SDL_FreeSurface(game_states);
                    SDL_DestroyTexture(game_statet);
                    TTF_Quit();
                    return 1;
                    /*exit button*/
                }
                else if (y3 > 30 && y3 < 75 && x3 > 646 && x3 < 691 && !enableee && !ended)
                {

                    SDL_FreeSurface(background_surface);
                    SDL_DestroyTexture(background_texture);
                    SDL_FreeSurface(savlos);
                    SDL_DestroyTexture(savlot);
                    SDL_FreeSurface(button_surface);
                    SDL_DestroyTexture(button_texture);
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    SDL_FreeSurface(sub_surf);
                    SDL_DestroyTexture(sub_texture);
                    SDL_FreeSurface(exit_s);
                    SDL_DestroyTexture(exit_t);
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);
                    SDL_FreeSurface(mmenu_s);
                    SDL_DestroyTexture(mmenu_t);
                    SDL_FreeSurface(suspend_surface);
                    SDL_DestroyTexture(suspend_texture);
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);

                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(filesaves);
                    SDL_DestroyTexture(filesavet);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);

                    SDL_FreeSurface(game_states);
                    SDL_DestroyTexture(game_statet);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    TTF_Quit();
                    SDL_Quit();
                    return 0;
                }
                else if (y1 > 180 && y1 < 245 && x1 > 160 && x1 < 225 && enableee && !ended)
                {
                    fileno = 1;
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
                else if (y1 > 180 && y1 < 245 && x1 > 245 && x1 < 310 && enableee && !ended)
                {
                    fileno = 2;
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
                else if (y1 > 180 && y1 < 245 && x1 > 330 && x1 < 395 && enableee && !ended)
                {
                    fileno = 3;
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
                else if (y1 > 180 && y1 < 245 && x1 > 415 && x1 < 480 && enableee && !ended)
                {
                    fileno = 4;
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
                else if (y1 > 180 && y1 < 245 && x1 > 500 && x1 < 565 && enableee && !ended)
                {
                    fileno = 5;
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
                else if (y1 > 260 && y1 < 310 && x1 > 130 && x1 < 270 && enableee && !ended)
                {
                    enableee = 0;
                    tick = 1;
                    if (fileno == 0)
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
                        Save((10 + gamet), P1.name, P2.name, x, counter, P1.score, P2.score, P1.moves, P2.moves, available_moves, sec, lines, player, boxes, history_len, moves_history, fileno, Darr, Darr_redo);
                    }
                }
                else if (y1 > 260 && y1 < 310 && x1 > 450 && x1 < 590 && enableee && !ended)
                {
                    enableee = 0;
                    tick = 1;
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
                else if (y1 > 305 && y1 < 357 && x1 > 45 && x1 < 195 && !enableee && ended)
                {
                    SDL_FreeSurface(background_surface);
                    SDL_DestroyTexture(background_texture);
                    SDL_FreeSurface(savlos);
                    SDL_DestroyTexture(savlot);
                    SDL_FreeSurface(button_surface);
                    SDL_DestroyTexture(button_texture);
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    SDL_FreeSurface(sub_surf);
                    SDL_DestroyTexture(sub_texture);
                    SDL_FreeSurface(exit_s);
                    SDL_DestroyTexture(exit_t);
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);
                    SDL_FreeSurface(mmenu_s);
                    SDL_DestroyTexture(mmenu_t);
                    SDL_FreeSurface(suspend_surface);
                    SDL_DestroyTexture(suspend_texture);
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);

                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(filesaves);
                    SDL_DestroyTexture(filesavet);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);

                    SDL_FreeSurface(game_states);
                    SDL_DestroyTexture(game_statet);
                    TTF_Quit();
                    return 1;

                }
                else if (y1 > 305 && y1 < 357 && x1 > 550 && x1 < 700 && !enableee && ended)
                {

                    SDL_FreeSurface(background_surface);
                    SDL_DestroyTexture(background_texture);
                    SDL_FreeSurface(savlos);
                    SDL_DestroyTexture(savlot);
                    SDL_FreeSurface(button_surface);
                    SDL_DestroyTexture(button_texture);
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    SDL_FreeSurface(sub_surf);
                    SDL_DestroyTexture(sub_texture);
                    SDL_FreeSurface(exit_s);
                    SDL_DestroyTexture(exit_t);
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);
                    SDL_FreeSurface(mmenu_s);
                    SDL_DestroyTexture(mmenu_t);
                    SDL_FreeSurface(suspend_surface);
                    SDL_DestroyTexture(suspend_texture);
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);

                    SDL_FreeSurface(b1);
                    SDL_DestroyTexture(b1t);
                    SDL_FreeSurface(b2);
                    SDL_DestroyTexture(b2t);
                    SDL_FreeSurface(b3);
                    SDL_DestroyTexture(b3t);
                    SDL_FreeSurface(b4);
                    SDL_DestroyTexture(b4t);
                    SDL_FreeSurface(filesaves);
                    SDL_DestroyTexture(filesavet);
                    SDL_FreeSurface(b5);
                    SDL_DestroyTexture(b5t);

                    SDL_FreeSurface(game_states);
                    SDL_DestroyTexture(game_statet);
                    TTF_Quit();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
                /*transforming coordinates to indices*/
                x2 = x1;
                y2 = y1;

                if (grid)
                {
                    for (int i = 0 ; i < 6; i++)
                    {
                        if (x1 > 25 + 64 * i && x1 < 39 + 64 * i)
                        {
                            x1 = i;
                        }
                    }

                    for (int i = 0 ; i < 6; i++)
                    {
                        if (y1 > 25 + 64 * i && y1 < 39 + 64 * i)
                        {
                            y1 = i;
                        }
                    }
                }
                else
                {
                    for (int i = 0 ; i < 3; i++)
                    {
                        if (x1 > 48 + 128 * i && x1 < 78 + 128 * i)
                        {
                            x1 = i;
                        }
                    }

                    for (int i = 0 ; i < 3; i++)
                    {
                        if (y1 > 48 + 128 * i && y1 < 78 + 128 * i)
                        {
                            y1 = i;
                        }
                    }
                }

                break;


            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&x3,&y3);
                if (pressing == 1)
                {
                    SDL_GetMouseState(&x2,&y2);
                }
                else if (y3 > 30 && y3 < 75 && x3 > 469 && x3 < 514 && !enableee && !ended)
                {
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    redo_surf = IMG_Load("redog.png");
                    redo_texture = SDL_CreateTextureFromSurface(renderer, redo_surf);
                    SDL_RenderCopy(renderer, redo_texture, NULL, &buttonr);
                }
                else if (y3 > 30 && y3 < 75 && x3 > 410 && x3 < 455 && !enableee && !ended)
                {
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    undo_surf = IMG_Load("undog.png");
                    undo_texture = SDL_CreateTextureFromSurface(renderer, undo_surf);
                    SDL_RenderCopy(renderer, undo_texture, NULL, &buttonu);
                }
                else if (y3 > 30 && y3 < 75 && x3 > 528 && x3 < 573 && !enableee && !ended)
                {
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    save_surf = IMG_Load("saveg.png");
                    save_texture = SDL_CreateTextureFromSurface(renderer, save_surf);
                    SDL_RenderCopy(renderer, save_texture, NULL, &buttonsave);
                }
                else if (y3 > 30 && y3 < 75 && x3 > 587 && x3 < 632 && !enableee && !ended)
                {
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    home_s = IMG_Load("homeg.png");
                    home_t = SDL_CreateTextureFromSurface(renderer, home_s);
                    SDL_RenderCopy(renderer, home_t, NULL, &buttonhome);
                }
                else if (y3 > 30 && y3 < 75 && x3 > 646 && x3 < 691 && !enableee && !ended)
                {
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    exit_surf = IMG_Load("exittg.png");
                    exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surf);
                    SDL_RenderCopy(renderer, exit_texture, NULL, &buttonexit);
                }
                else if (y3 > 260 && y3 < 310 && x3 > 130 && x3 < 270 && enableee && !ended)
                {
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    confirms = IMG_Load("confirmg.png");
                    confirmt = SDL_CreateTextureFromSurface(renderer, confirms);
                    SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
                }
                else if (y3 > 260 && y3 < 310 && x3 > 450 && x3 < 590 && enableee && !ended)
                {
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);
                    cancels = IMG_Load("cancellg.png");
                    cancelt = SDL_CreateTextureFromSurface(renderer, cancels);
                    SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
                }
                else if (y3 > 305 && y3 < 357 && x3 > 550 && x3 < 700 && !enableee && ended)
                {
                    ended = 1;
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);
                    lexits = IMG_Load("lexitg.png");
                    lexitt = SDL_CreateTextureFromSurface(renderer, lexits);
                }
                else if (y3 > 305 && y3 < 357 && x3 > 45 && x3 < 195 && !enableee && ended)
                {
                    ended = 1;
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    lmainmenus = IMG_Load("lmainmenug.png");
                    lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);
                }
                else
                {
                    SDL_FreeSurface(cancels);
                    SDL_DestroyTexture(cancelt);
                    SDL_FreeSurface(confirms);
                    SDL_DestroyTexture(confirmt);
                    SDL_FreeSurface(redo_surf);
                    SDL_DestroyTexture(redo_texture);
                    SDL_FreeSurface(undo_surf);
                    SDL_DestroyTexture(undo_texture);
                    SDL_FreeSurface(save_surf);
                    SDL_DestroyTexture(save_texture);
                    SDL_FreeSurface(home_s);
                    SDL_DestroyTexture(home_t);
                    SDL_FreeSurface(exit_surf);
                    SDL_DestroyTexture(exit_texture);
                    SDL_FreeSurface(lmainmenus);
                    SDL_DestroyTexture(lmainmenut);
                    SDL_FreeSurface(lexits);
                    SDL_DestroyTexture(lexitt);

                    redo_surf = IMG_Load("redo.png");
                    redo_texture = SDL_CreateTextureFromSurface(renderer, redo_surf);
                    undo_surf = IMG_Load("undo.png");
                    undo_texture = SDL_CreateTextureFromSurface(renderer, undo_surf);
                    save_surf = IMG_Load("save.png");
                    save_texture = SDL_CreateTextureFromSurface(renderer, save_surf);
                    home_s = IMG_Load("home.png");
                    home_t = SDL_CreateTextureFromSurface(renderer, home_s);
                    exit_surf = IMG_Load("exitt.png");
                    exit_texture = SDL_CreateTextureFromSurface(renderer, exit_surf);
                    confirms = IMG_Load("confirm.png");
                    confirmt = SDL_CreateTextureFromSurface(renderer, confirms);
                    cancels = IMG_Load("cancell.png");
                    cancelt = SDL_CreateTextureFromSurface(renderer, cancels);
                    lmainmenus = IMG_Load("lmainmenu.png");
                    lexits = IMG_Load("lexit.png");
                    lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);
                    lexitt = SDL_CreateTextureFromSurface(renderer, lexits);
                    SDL_RenderCopy(renderer, undo_texture, NULL, &buttonu_pos);
                    SDL_RenderCopy(renderer, redo_texture, NULL, &buttonr_pos);
                    SDL_RenderCopy(renderer, save_texture, NULL, &buttonsave_pos);
                    SDL_RenderCopy(renderer, home_t, NULL, &buttonhome_pos);
                    SDL_RenderCopy(renderer, exit_texture, NULL, &buttonexit_pos);
                    SDL_RenderCopy(renderer, confirmt, NULL, &confirmrect);
                    SDL_RenderCopy(renderer, cancelt, NULL, &cancelrect);
                }


                break;

            case SDL_MOUSEBUTTONUP:
                if (!enableee)
                {
                    pressing = 0;
                    if (grid)
                    {

                        for (int i = 0 ; i < 6; i++)
                        {
                            if (x2 > 25 + 64 * i && x2 < 39 + 64 * i)
                            {
                                x2 = i;
                            }
                        }

                        for (int i = 0 ; i < 6; i++)
                        {
                            if (y2 > 25 + 64 * i && y2 < 39 + 64 * i)
                            {
                                y2 = i;
                            }
                        }

                        if (x1 == x2 && (y1 == y2 - 1 || y1 == y2 + 1))
                        {
                            r.x = 32 + 64 * x1 - 7;
                            r.y = 32 + 64 * y1;
                            r.w = 14;
                            r.h = y1<y2? 64:-64;
                            process = 1;

                        }
                        else if ((x1 == x2 - 1 || x1 == x2 + 1)&& y1 == y2)
                        {
                            r.x = 32 + 64 * x1;
                            r.y = 32 + 64 * y1 - 7;
                            r.w = x1<x2? 64:-64;
                            r.h = 14;
                            process = 1;
                        }
                    }
                    else
                    {
                        for (int i = 0 ; i < 3; i++)
                        {
                            if (x2 > 48 + 128 * i && x2 < 78 + 128 * i)
                            {
                                x2 = i;
                            }
                        }

                        for (int i = 0 ; i < 3; i++)
                        {
                            if (y2 > 48 + 128 * i && y2 < 78 + 128 * i)
                            {
                                y2 = i;
                            }
                        }

                        if (x1 == x2 && (y1 == y2 - 1 || y1 == y2 + 1))
                        {
                            r.x = 64 + 128 * x1 - (12 + x1 % 2);
                            r.y = 64 + 128 * y1;
                            r.w = 25;
                            r.h = y1<y2? 128:-128;
                            process = 1;

                        }
                        else if ((x1 == x2 - 1 || x1 == x2 + 1)&& y1 == y2)
                        {
                            r.x = 64 + 128 * x1;
                            r.y = 64 + 128 * y1 - (12 + y1 % 2);
                            r.w = x1<x2? 128:-128;
                            r.h = 25;
                            process = 1;
                        }
                    }
                    /*making move*/
                    if (process && x1 < 12 && x2 < 12 && y1 < 12 && y2 < 12)
                    {
                        column = x1 + x2;
                        row = y1 + y2;
                        /*check move validity*/
                        if ((column % 2 ==0 && row % 2 == 0) || (column % 2 ==1 && row % 2 == 1))
                        {
                            found = 1;
                            break;
                        }
                        for (int i = 0; i < counter; i++)
                        {
                            if((row + 1 == moves_history[i][0]) && (column + 1 == moves_history[i][1]))
                            {
                                found = 1;
                                break;
                            }
                        }
                        if (found)
                        {
                            break;
                        }
                        /*storing move in 2d array*/

                        Darr[counter] = r;

                        for (int i = 0; i < redo_counter; i++)
                        {
                            moves_redo[i][0] = 0;
                            moves_redo[i][1] = 0;
                            moves_redo[i][2] = 0;
                            Darr_redo[i] = nullity;
                        }
                        redo_counter = 0;

                        moves_history[counter][0] = row + 1;
                        moves_history[counter][1] = column + 1;
                        moves_history[counter][2] = player;
                        if (row % 2 == 0 && column % 2 == 1)
                        {
                            lines[row][column] = 205;
                        }
                        else if(row % 2 == 1 && column % 2 == 0)
                        {
                            lines[row][column] = 186;
                        }
                        if (player)
                        {
                            P2.moves++;
                        }
                        else
                        {
                            P1.moves++;
                        }
                        available_moves--;
                        counter++;
                        player ^= 1;
                        process = 0;

                        for (int i = 1; i < x+x+1; i+=2)
                        {
                            for (int j = 1; j < y+y+1; j+=2)
                            {
                                for (int k = 0; k < x*x; k++)
                                {
                                    if (i*10 + j == boxes[k])
                                    {
                                        if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                                        {
                                            if (inloop == 0)
                                            {
                                                player ^= 1;
                                            }
                                            lines[i][j] = 219;
                                            boxes[k] = boxes[k] * 10 + player;
                                            if (player)
                                            {
                                                P2.score++;
                                            }
                                            else
                                            {
                                                P1.score++;
                                            }
                                            inloop = 1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }

                    }

                    break;
                }
            }
            /*AI functionality*/
            if (gamet != 0 && player == 1 && !enableee && !ended)
            {
                int foun = 1;
                while(foun)
                {
                    foun = 0;
                    di = AI(x, y, lines, moves_history, counter, row, column, gamet);
                    row = di / 100;
                    column = di % 100;
                    for (int i = 0; i < counter; i++)
                    {
                        if((row + 1 == moves_history[i][0]) && (column + 1 == moves_history[i][1]))
                        {
                            foun = 1;
                            break;
                        }
                    }
                    if (foun)
                    {
                        continue;
                    }
                    if (row % 2 == 0 && column %2 == 1)
                    {
                        x1 = (column-1) / 2;
                        y1 = row / 2;
                        x2 = (column+1) / 2;
                        y2 = row / 2;
                    }
                    else if (row % 2 == 1 && column %2 == 0)
                    {
                        x1 = column / 2;
                        y1 = (row-1)/2;
                        x2 = column / 2;
                        y2 = (row+1)/2;
                    }
                    if (grid)
                    {
                        if (x1 == x2 && (y1 == y2 - 1 || y1 == y2 + 1))
                        {
                            r.x = 32 + 64 * x1 - 7;
                            r.y = 32 + 64 * y1;
                            r.w = 14;
                            r.h = y1<y2? 64:-64;
                            process = 1;

                        }
                        else if ((x1 == x2 - 1 || x1 == x2 + 1)&& y1 == y2)
                        {
                            r.x = 32 + 64 * x1;
                            r.y = 32 + 64 * y1 - 7;
                            r.w = x1<x2? 64:-64;
                            r.h = 14;
                            process = 1;
                        }
                    }
                    else
                    {
                        if (x1 == x2 && (y1 == y2 - 1 || y1 == y2 + 1))
                        {
                            r.x = 64 + 128 * x1 - (12 + x1 % 2);
                            r.y = 64 + 128 * y1;
                            r.w = 25;
                            r.h = y1<y2? 128:-128;
                            process = 1;

                        }
                        else if ((x1 == x2 - 1 || x1 == x2 + 1)&& y1 == y2)
                        {
                            r.x = 64 + 128 * x1;
                            r.y = 64 + 128 * y1 - (12 + y1 % 2);
                            r.w = x1<x2? 128:-128;
                            r.h = 25;
                            process = 1;
                        }
                    }
                    Darr[counter] = r;

                    for (int i = 0; i < redo_counter; i++)
                    {
                        moves_redo[i][0] = 0;
                        moves_redo[i][1] = 0;
                        moves_redo[i][2] = 0;
                        Darr_redo[i] = nullity;
                    }
                    redo_counter = 0;

                    moves_history[counter][0] = row + 1;
                    moves_history[counter][1] = column + 1;
                    moves_history[counter][2] = player;
                    if (row % 2 == 0 && column % 2 == 1)
                    {
                        lines[row][column] = 205;
                    }
                    else if(row % 2 == 1 && column % 2 == 0)
                    {
                        lines[row][column] = 186;
                    }
                    if (player)
                    {
                        P2.moves++;
                    }
                    else
                    {
                        P1.moves++;
                    }
                    available_moves--;
                    counter++;
                    player ^= 1;
                    process = 0;

                    for (int i = 1; i < x+x+1; i+=2)
                    {
                        for (int j = 1; j < y+y+1; j+=2)
                        {
                            for (int k = 0; k < x*x; k++)
                            {
                                if (i*10 + j == boxes[k])
                                {
                                    if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                                    {
                                        if (inloop == 0)
                                        {
                                            player ^= 1;
                                        }
                                        lines[i][j] = 219;
                                        boxes[k] = boxes[k] * 10 + player;
                                        if (player)
                                        {
                                            P2.score++;
                                        }
                                        else
                                        {
                                            P1.score++;
                                        }
                                        inloop = 1;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }


            }
        }

        SDL_Delay(1000/100);
        if(event.type == SDL_QUIT)
        {
            a = 0;

            SDL_FreeSurface(background_surface);
            SDL_DestroyTexture(background_texture);
            SDL_FreeSurface(savlos);
            SDL_DestroyTexture(savlot);
            SDL_FreeSurface(button_surface);
            SDL_DestroyTexture(button_texture);
            SDL_FreeSurface(undo_surf);
            SDL_DestroyTexture(undo_texture);
            SDL_FreeSurface(redo_surf);
            SDL_DestroyTexture(redo_texture);
            SDL_FreeSurface(save_surf);
            SDL_DestroyTexture(save_texture);
            SDL_FreeSurface(exit_surf);
            SDL_DestroyTexture(exit_texture);
            SDL_FreeSurface(sub_surf);
            SDL_DestroyTexture(sub_texture);
            SDL_FreeSurface(exit_s);
            SDL_DestroyTexture(exit_t);
            SDL_FreeSurface(home_s);
            SDL_DestroyTexture(home_t);
            SDL_FreeSurface(lmainmenus);
            SDL_DestroyTexture(lmainmenut);
            SDL_FreeSurface(lexits);
            SDL_DestroyTexture(lexitt);
            SDL_FreeSurface(mmenu_s);
            SDL_DestroyTexture(mmenu_t);
            SDL_FreeSurface(suspend_surface);
            SDL_DestroyTexture(suspend_texture);
            SDL_FreeSurface(confirms);
            SDL_DestroyTexture(confirmt);
            SDL_FreeSurface(cancels);
            SDL_DestroyTexture(cancelt);

            SDL_FreeSurface(b1);
            SDL_DestroyTexture(b1t);
            SDL_FreeSurface(b2);
            SDL_DestroyTexture(b2t);
            SDL_FreeSurface(b3);
            SDL_DestroyTexture(b3t);
            SDL_FreeSurface(b4);
            SDL_DestroyTexture(b4t);
            SDL_FreeSurface(filesaves);
            SDL_DestroyTexture(filesavet);
            SDL_FreeSurface(b5);
            SDL_DestroyTexture(b5t);

            SDL_FreeSurface(game_states);
            SDL_DestroyTexture(game_statet);
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
    SDL_FreeSurface(savlos);
    SDL_DestroyTexture(savlot);
    SDL_FreeSurface(button_surface);
    SDL_DestroyTexture(button_texture);
    SDL_FreeSurface(undo_surf);
    SDL_DestroyTexture(undo_texture);
    SDL_FreeSurface(redo_surf);
    SDL_DestroyTexture(redo_texture);
    SDL_FreeSurface(save_surf);
    SDL_DestroyTexture(save_texture);
    SDL_FreeSurface(exit_surf);
    SDL_DestroyTexture(exit_texture);
    SDL_FreeSurface(sub_surf);
    SDL_DestroyTexture(sub_texture);
    SDL_FreeSurface(exit_s);
    SDL_DestroyTexture(exit_t);
    SDL_FreeSurface(home_s);
    SDL_DestroyTexture(home_t);
    SDL_FreeSurface(lmainmenus);
    SDL_DestroyTexture(lmainmenut);
    SDL_FreeSurface(lexits);
    SDL_DestroyTexture(lexitt);
    SDL_FreeSurface(mmenu_s);
    SDL_DestroyTexture(mmenu_t);
    SDL_FreeSurface(suspend_surface);
    SDL_DestroyTexture(suspend_texture);
    SDL_FreeSurface(confirms);
    SDL_DestroyTexture(confirmt);
    SDL_FreeSurface(cancels);
    SDL_DestroyTexture(cancelt);

    SDL_FreeSurface(b1);
    SDL_DestroyTexture(b1t);
    SDL_FreeSurface(b2);
    SDL_DestroyTexture(b2t);
    SDL_FreeSurface(b3);
    SDL_DestroyTexture(b3t);
    SDL_FreeSurface(b4);
    SDL_DestroyTexture(b4t);
    SDL_FreeSurface(filesaves);
    SDL_DestroyTexture(filesavet);
    SDL_FreeSurface(b5);
    SDL_DestroyTexture(b5t);

    SDL_FreeSurface(game_states);
    SDL_DestroyTexture(game_statet);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
#endif // GAME_H
