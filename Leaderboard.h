int leaderboard(SDL_Event event, SDL_Window* window, SDL_Renderer* renderer)
{

    /*setting the required surfaces and textures*/
    TTF_Init();
    SDL_StartTextInput();
    int a = 1;
    int HvsHno, PlayerScore;
    char PlayerName[30];
    char stringg[10][75] = {{' '}};
    char namestring[30];
    char scorestring[13];

    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;

    SDL_Surface* leaderboards = NULL;
    SDL_Texture* leaderboardt = NULL;

    SDL_Surface* subranks = NULL;
    SDL_Texture* subrankt = NULL;

    SDL_Surface* lmainmenus = NULL;
    SDL_Texture* lmainmenut = NULL;

    SDL_Surface* lexits = NULL;
    SDL_Texture* lexitt = NULL;

    TTF_Font* textfont1 = TTF_OpenFont("ocrr.ttf", 17);
    TTF_SetFontStyle(textfont1, TTF_STYLE_BOLD);

    SDL_Color textcolor = {250, 0, 0, 0};

    SDL_Surface* surfaceMessage = NULL;
    SDL_Texture* Message = NULL;


    SDL_Rect bac;
    bac.x = 0;
    bac.y = 0;
    bac.w = 715;
    bac.h = 384;

    SDL_Rect text_rect1;
    text_rect1.x = 52;
    text_rect1.y = 48;
    text_rect1.w = 350;
    text_rect1.h = 20;

    SDL_Rect title;
    title.x = 233;
    title.y = 5;
    title.w = 250;
    title.h = 70;

    SDL_Rect subrect;
    subrect.x = 10;
    subrect.y = 10;
    subrect.w = 695;
    subrect.h = 364;

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

    background_surface = IMG_Load("background.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    leaderboards = IMG_Load("leaderboard.png");
    leaderboardt = SDL_CreateTextureFromSurface(renderer, leaderboards);

    subranks = IMG_Load("subrank.png");
    subrankt = SDL_CreateTextureFromSurface(renderer, subranks);

    lmainmenus = IMG_Load("lmainmenu.png");
    lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);

    lexits = IMG_Load("lexit.png");
    lexitt = SDL_CreateTextureFromSurface(renderer, lexits);

    /*reading ranking file*/
    FILE *rfile;
    rfile = fopen("Ranking.bin", "rb");
    fread(&HvsHno, sizeof(int), 1, rfile);
    for (int i = 1; i < HvsHno + 1; i++)
    {
        fread(&PlayerScore, sizeof(int), 1, rfile);
        fread(&PlayerName, sizeof(char), 30, rfile);
        sprintf(stringg[i - 1], "%d.", i);
        memcpy(namestring, PlayerName, 30);
        strcat(stringg[i - 1], namestring);
        if (i < 10)
        {
            strcat(stringg[i - 1], "                    (score: ");
        }
        else
        {
            strcat(stringg[i - 1], "                   (score: ");
        }
        sprintf(scorestring, "%d)", PlayerScore);
        strcat(stringg[i - 1], scorestring);
    }


    int x1, y1, x3, y3;
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
            SDL_RenderCopy(renderer, subrankt, NULL, &subrect);
            SDL_RenderCopy(renderer, leaderboardt, NULL, &title);
            SDL_RenderCopy(renderer, lmainmenut, NULL, &mainrect);
            SDL_RenderCopy(renderer, lexitt, NULL, &exitrect);
            for (int i = 1; i < HvsHno + 1; i++)
            {
                text_rect1.y = 52 + i * 22;
                TTF_SizeText(textfont1, stringg[i - 1], &text_rect1.w, &text_rect1.h);
                SDL_FreeSurface(surfaceMessage);
                SDL_DestroyTexture(Message);
                surfaceMessage = TTF_RenderText_Blended(textfont1, stringg[i - 1], textcolor);
                Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                SDL_RenderCopy(renderer, Message, NULL, &text_rect1);
            }
            SDL_RenderPresent(renderer);
        }

        /*handling courser actions*/
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x1,&y1);
            if (y1 > 305 && y1 < 357 && x1 > 45 && x1 < 195)
            {
                SDL_FreeSurface(surfaceMessage);
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(subranks);
                SDL_FreeSurface(leaderboards);
                SDL_FreeSurface(lmainmenus);
                SDL_FreeSurface(lexits);
                SDL_DestroyTexture(Message);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(subrankt);
                SDL_DestroyTexture(leaderboardt);
                SDL_DestroyTexture(lmainmenut);
                SDL_DestroyTexture(lexitt);
                return 1;

            }
            else if (y1 > 305 && y1 < 357 && x1 > 550 && x1 < 700)
            {
                SDL_FreeSurface(surfaceMessage);
                SDL_FreeSurface(background_surface);
                SDL_FreeSurface(subranks);
                SDL_FreeSurface(leaderboards);
                SDL_FreeSurface(lmainmenus);
                SDL_FreeSurface(lexits);
                SDL_DestroyTexture(Message);
                SDL_DestroyTexture(background_texture);
                SDL_DestroyTexture(subrankt);
                SDL_DestroyTexture(leaderboardt);
                SDL_DestroyTexture(lmainmenut);
                SDL_DestroyTexture(lexitt);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x3,&y3);
            if (y3 > 305 && y3 < 357 && x3 > 550 && x3 < 700)
            {
                e = 1;
                SDL_FreeSurface(lexits);
                SDL_DestroyTexture(lexitt);
                lexits = IMG_Load("lexitg.png");
                lexitt = SDL_CreateTextureFromSurface(renderer, lexits);
                SDL_RenderCopy(renderer, lexitt, NULL, &exitrect);
            }
            else if (y3 > 305 && y3 < 357 && x3 > 45 && x3 < 195)
            {
                e = 1;
                SDL_FreeSurface(lmainmenus);
                SDL_DestroyTexture(lmainmenut);
                lmainmenus = IMG_Load("lmainmenug.png");
                lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);
                SDL_RenderCopy(renderer, lmainmenut, NULL, &mainrect);
            }
            else
            {
                e = 1;
                SDL_FreeSurface(lmainmenus);
                SDL_DestroyTexture(lmainmenut);
                SDL_FreeSurface(lexits);
                SDL_DestroyTexture(lexitt);
                lmainmenus = IMG_Load("lmainmenu.png");
                lexits = IMG_Load("lexit.png");
                lmainmenut = SDL_CreateTextureFromSurface(renderer, lmainmenus);
                lexitt = SDL_CreateTextureFromSurface(renderer, lexits);
                SDL_RenderCopy(renderer, lmainmenut, NULL, &mainrect);
                SDL_RenderCopy(renderer, lexitt, NULL, &exitrect);
            }
            break;
        }

        if(event.type == SDL_QUIT)
        {
            a = 0;
            SDL_DestroyTexture(background_texture);
            SDL_DestroyTexture(leaderboardt);
            SDL_DestroyTexture(subrankt);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(Message);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }
    }

    /*destroying textures*/
    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(leaderboardt);
    SDL_DestroyTexture(subrankt);
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
