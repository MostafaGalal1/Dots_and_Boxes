#ifndef SAVE_H
#define SAVE_H
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

int Save(int gametype, char P1Name[30], char P2Name[30], int x, int counter, int p1score, int p2score, int p1moves, int p2moves, int available_moves, int seconds, char lines[x+x+1][x+x+1],int player, int boxes[70], int history_len, int moves_history[70][3], int fileno, SDL_Rect Darr[70], SDL_Rect Darr_redo[70])
{

    FILE *sfile;
    char name[11] = {'D','o','t','s','_',' ','.','b','i','n'};
    name[5] = fileno + 48;
    sfile = fopen(name, "wb");

    /*check if the file created correctly*/
    if(sfile == NULL)
    {
        return 1;
    }

    /*writing information in the file*/
    fwrite(&gametype, sizeof(int), 1, sfile);
    fwrite(P1Name, sizeof(char), 30, sfile);
    fwrite(P2Name, sizeof(char), 30, sfile);
    fwrite(&x, sizeof(int), 1, sfile);
    fwrite(&counter, sizeof(int), 1, sfile);
    fwrite(&p1score, sizeof(int), 1, sfile);
    fwrite(&p2score, sizeof(int), 1, sfile);
    fwrite(&p1moves, sizeof(int), 1, sfile);
    fwrite(&p2moves, sizeof(int), 1, sfile);
    fwrite(&available_moves, sizeof(int), 1, sfile);
    fwrite(&seconds, sizeof(int), 1, sfile);
    fwrite(lines, sizeof(char), (x+x+1) * (x+x+1), sfile);
    fwrite(&player, sizeof(int), 1, sfile);
    fwrite(boxes, sizeof(int), x*x, sfile);
    fwrite(&history_len, sizeof(int), 1, sfile);
    fwrite(moves_history, sizeof(int), history_len * 3, sfile);
    fwrite(Darr, sizeof(SDL_Rect), x*(x+1)*2, sfile);
    fwrite(Darr_redo, sizeof(SDL_Rect), x*(x+1)*2, sfile);

    /*closing the file*/
    fclose(sfile);
    return 1;
}

#endif //SAVE.H
