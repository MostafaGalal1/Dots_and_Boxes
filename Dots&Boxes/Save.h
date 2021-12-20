#include <stdio.h>
#define sleep(x) Sleep(1000 * (x))

int Save(int gametype, char P1Name[30], char P2Name[30], int x, int counter, int p1score, int p2score, int p1moves, int p2moves, int available_moves, int seconds, char lines[x+x+1][x+x+1], int player, int boxes[x*x], int history_len, int moves_history[history_len][3], int fileno){
	FILE *sfile;
	char name[11] = {'D','o','t','s','_',' ','.','b','i','n'};
	name[5] = fileno + 48;
	sfile = fopen(name, "wb");
	if(sfile == NULL){
        printf("\n\tError! saving the file");
        sleep(3);
        return 1;
    }

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
    fclose(sfile);
    printf("\n\tGame saved successfully in %s\033[0;33m", name);
    printf("\033[0;37m");
    sleep(3.5);
    return 1;
}
