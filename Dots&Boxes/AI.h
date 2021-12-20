#include <time.h>
void AI(int x, int y, char lines[x+x+1][y+y+1], int moves_history[x*(x+1)*2][3], int counter, int *row, int *column){

    int rowno = 0, columnno = 0, prohibited[x*(x+1)*2][2], p_counter = 0;

    void c_prohibited(int r, int c){
        prohibited[p_counter][0] = r;
        prohibited[p_counter][1] = c;
        p_counter++;
    }

    int check_prohibited(int r, int c){
        for (int i = 0; i < p_counter; i++){
            if (prohibited[i][0] == r && prohibited[i][1] == c){
                return 1;
            }
        }
        return 0;
    }

    void c_move(int r, int c){
        rowno = r;
        columnno = c;
        *row = rowno + 1;
        *column = columnno + 1;
    }

    for (int i = 1; i < x+x+1; i+=2){
        for (int j = 1; j < y+y+1; j+=2){
            if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)){
                c_move(i+1,j);
                return;
            } else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                c_move(i-1,j);
                return;
            } else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51) {
                c_move(i,j+1);
                return;
            } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51) {
                c_move(i,j-1);
                return;
            }
        }
    }

    for (int i = 1; i < x+x+1; i+=2){
        for (int j = 1; j < y+y+1; j+=2){
            if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51) {
                c_prohibited(i, j-1);
                c_prohibited(i, j+1);
            } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                c_prohibited(i, j-1);
                c_prohibited(i-1, j);
            } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)) {
                c_prohibited(i, j-1);
                c_prohibited(i+1, j);
            } else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                c_prohibited(i, j+1);
                c_prohibited(i-1, j);
            } else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)) {
                c_prohibited(i, j+1);
                c_prohibited(i+1, j);
            } else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51)) {
                c_prohibited(i-1, j);
                c_prohibited(i+1, j);
            }
        }
    }

    for (int i = 1; i < x+x+1; i+=2){
        for (int j = 1; j < y+y+1; j+=2){
            if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51)){
                if (check_prohibited(i, j+1) == 0){
                    c_move(i, j+1);
                    return;
                }
                else if (check_prohibited(i-1, j) == 0){
                    c_move(i-1, j);
                    return;
                }
                else if (check_prohibited(i+1, j) == 0){
                    c_move(i+1, j);
                    return;
                }
            } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51)) {
                if (check_prohibited(i, j-1) == 0){
                    c_move(i, j-1);
                    return;
                }
                else if (check_prohibited(i-1, j) == 0){
                    c_move(i-1, j);
                    return;
                }
                else if (check_prohibited(i+1, j) == 0){
                    c_move(i+1, j);
                    return;
                }
            } else if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)) {
                if (check_prohibited(i, j-1) == 0){
                    c_move(i, j-1);
                    return;
                }
                else if (check_prohibited(i, j+1) == 0){
                    c_move(i, j+1);
                    return;
                }
                else if (check_prohibited(i+1, j) == 0){
                    c_move(i+1, j);
                    return;
                }
            } else if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                if (check_prohibited(i, j-1) == 0){
                    c_move(i, j-1);
                    return;
                }
                else if (check_prohibited(i, j+1) == 0){
                    c_move(i, j+1);
                    return;
                }
                else if (check_prohibited(i-1, j) == 0){
                    c_move(i-1, j);
                    return;
                }
            }
        }
    }
    for (int i = 1; i < x+x+1; i+=2){
        for (int j = 1; j < y+y+1; j+=2){
            if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51)){
                if (check_prohibited(i, j-1) == 0){
                    c_move(i, j-1);
                    return;
                } else if (check_prohibited(i, j+1) == 0){
                    c_move(i, j+1);
                    return;
                } else if (check_prohibited(i-1, j) == 0){
                    c_move(i-1, j);
                    return;
                } else if (check_prohibited(i-1, j) == 0){
                    c_move(i+1, j);
                    return;
                }
            }
        }
    }

    for (int i = 1; i < x+x+1; i+=2){
        for (int j = 1; j < y+y+1; j+=2){
                if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51) {
                    c_move(i, j+1);
                    return;
                } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                    c_move(i, j-1);
                    return;
                } else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)) {
                    c_move(i+1, j);
                    return;
                } else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51) {
                    c_move(i, j+1);
                    return;
                } else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51)) {
                    c_move(i+1, j);
                    return;
                } else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51)) {
                    c_move(i-1, j);
                    return;
                }
            }
        }
    return;
}
