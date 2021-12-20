#include <stdio.h>
#include <time.h>
#include <windows.h>
#include<string.h>
#include <string.h>
#include "Game_Display.h"
#include "scan.h"
#define sleep(x) Sleep(1000 * (x))

int Exit = 0, grid = 0, gametype;
char P1Name[30] = {' '};
char P2Name[30] = {' '};

int main_menu();

int One_player(int grid){
    printf("\n\n\tEnter player's one name: ");
    fflush(stdin);
    scanf("%[^\n]", P1Name);
    return Game_Display(1, P1Name, "Computer", grid, '\0');
}

int Two_player(int grid){
    printf("\n\n\tEnter player's one name: ");
    fflush(stdin);
    scanf("%[^\n]", P1Name);

    printf("\n\tEnter player's two name: ");
    fflush(stdin);
    scanf("%[^\n]", P2Name);

    return Game_Display(0, P1Name, P2Name, grid, '\0');
}

int New_game(){
    int New_game_key = 0, Player_key = 0;
    while(1){
        system("cls");
        printf("\n\tEnter game mode:");
        printf("\n\n\t1. Beginner (2x2)");
        printf("\n\n\t2. Expert (5x5)");
        printf("\n\n\t3. Main Menu");
        printf("\n\n\tEnter number: ");

        New_game_key = input();

        while(1){
            system("cls");
            if (New_game_key == 1 || New_game_key == 2){
                if (New_game_key == 1){
                    grid = 2;
                } else {
                    grid = 5;
                }
                printf("\n\t1. One Player");
                printf("\n\n\t2. Two Player");
                printf("\n\n\tEnter number: ");
                Player_key = input();
                if (Player_key == 1){
                    return One_player(grid);
                } else if (Player_key == 2){
                    return Two_player(grid);
                } else {
                    continue;
                }
            } else if (New_game_key == 3) {
                return 0;
            }
            break;
        }
    }
}

int Load_game(){
    int fileno = 0;
    FILE *lfile;
    system("cls");
    printf("\n\t\033[0;33mEnter file number (from 0 to 9): ");
    fflush(stdin);
    scanf("%d", &fileno);
    while (fileno < 0 || fileno > 9){
        system("cls");
        printf("\n\tPlease enter a number from 0 to 9");
        printf("\n\n\tEnter file number (from 0 to 9): ");
        scanf("%d", &fileno);
    }
    char name[11] = {'D','o','t','s','_',' ','.','b','i','n'};
	name[5] = fileno + 48;
    if ((lfile = fopen(name, "rb")) == NULL){
       printf("\n\tError! opening the file");
       sleep(3.5);
       return 0;
    }
    printf("%\033[0;37m");
    fread(&gametype, sizeof(int), 1, lfile);
    fread(&P1Name, sizeof(char), 30, lfile);
    fread(&P2Name, sizeof(char), 30, lfile);
    fread(&grid, sizeof(int), 1, lfile);
    fclose(lfile);

    return Game_Display(gametype, P1Name, P2Name, grid, name);
}

int Ranking(){
    int HvsHno, PlayerScore;
    char PlayerName[30];

    FILE *rfile;
    system("cls");
    if ((rfile = fopen("Ranking.bin", "rb")) == NULL){
       printf("\n\tError! opening the file");
       sleep(3.5);
       return 0;
    }

    fread(&HvsHno, sizeof(int), 1, rfile);
    printf("\n\tTop 10:");

    for (int i = 1; i < HvsHno + 1; i++){
        fread(&PlayerScore, sizeof(int), 1, rfile);
        fread(&PlayerName, sizeof(char), 30, rfile);
        printf("\n\n\t%d. %s    (score: %d)", i, PlayerName, PlayerScore);
    }

    fclose(rfile);
    scanf("%d");
    return 0;
}

int main_menu(){
    while(1){
        system("cls");
        printf("\033[0;35m\n");
        printf(
                "\t\t\t    _____                      ___      _                               \n"
                "\t\t\t   (___  \\       _            / _ \\    | |                            \n"
                "\t\t\t    _   \\ \\ ___ | |_   ___   ( (_) )   | | _   ___ _   _ ____  ___    \n"
                "\t\t\t   | |   | / _ \\|  _) /___)   ) _ (    | || \\ / _ ( \\ / ) _  )/___)  \n"
                "\t\t\t   | |__/ / |_| | |__|___ |  ( (/  \\   | |_) ) |_| ) X ( (/ /|___ |    \n"
                "\t\t\t   |_____/ \\___/ \\___|___/    \\__/\\_)  |____/ \\___(_/ \\_)___\\|___/ ");

        printf("\033[0;33m");
        printf("\n\n\t1. New game");
        printf("\n\n\t2. Load game");
        printf("\n\n\t3. Ranking");
        printf("\n\n\t4. Exit");
        printf("\n\n\tEnter number: ");

        switch(input()){
            case 1:
                return New_game();
                break;
            case 2:
                return Load_game();
                break;
            case 3:
                return Ranking();
                break;
            case 4:
                return 1;
                break;
            default:
                return 0;
                break;
        }
    }
}

int main()
{
    while (main_menu() == 0){}
    return 0;
}
