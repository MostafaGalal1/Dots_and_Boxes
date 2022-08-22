#include <time.h>
#include <stdlib.h>

/*AI code*/
int AI(int x, int y, char lines[2*x+1][2*x+1], int moves_history[x*(x+1)*2][3], int counter, int roww, int columnn, int gametype)
{
    int rowno = 0, columnno = 0, prohibited[x*(x+1)*2][2], p_counter = 0, found = 0, dim = 0, row, column;

    void c_prohibited(int r, int c)
    {
        prohibited[p_counter][0] = r;
        prohibited[p_counter][1] = c;
        p_counter++;
    }

    int check_prohibited(int r, int c)
    {
        for (int i = 0; i < p_counter; i++)
        {
            if (prohibited[i][0] == r && prohibited[i][1] == c)
            {
                return 1;
            }
        }
        return 0;
    }

    void c_move(int r, int c)
    {
        rowno = r;
        columnno = c;
        row = rowno;
        column = columnno;
        dim = row * 100 + column;
    }

    row = roww;
    column = columnn;

    /*AI logic in case of hard*/
    if (gametype == 1)
    {
        /*check for a box to complete*/
        for (int i = 1; i < x+x+1; i+=2)
        {
            for (int j = 1; j < y+y+1; j+=2)
            {
                if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    c_move(i+1,j);
                    return dim;
                }
                else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    c_move(i-1,j);
                    return dim;
                }
                else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                {
                    c_move(i,j+1);
                    return dim;
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                {
                    c_move(i,j-1);
                    return dim;
                }
            }
        }

        /*exclude moves that give the user advantage*/
        for (int i = 1; i < x+x+1; i+=2)
        {
            for (int j = 1; j < y+y+1; j+=2)
            {
                if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                {
                    c_prohibited(i, j-1);
                    c_prohibited(i, j+1);
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    c_prohibited(i, j-1);
                    c_prohibited(i-1, j);
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    c_prohibited(i, j-1);
                    c_prohibited(i+1, j);
                }
                else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    c_prohibited(i, j+1);
                    c_prohibited(i-1, j);
                }
                else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    c_prohibited(i, j+1);
                    c_prohibited(i+1, j);
                }
                else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51))
                {
                    c_prohibited(i-1, j);
                    c_prohibited(i+1, j);
                }
            }
        }

        /*make a move in one line made box*/
        for (int i = 1; i < x+x+1; i+=2)
        {
            for (int j = 1; j < y+y+1; j+=2)
            {
                if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51))
                {
                    if (check_prohibited(i, j+1) == 0)
                    {
                        c_move(i, j+1);
                        return dim;
                    }
                    else if (check_prohibited(i-1, j) == 0)
                    {
                        c_move(i-1, j);
                        return dim;
                    }
                    else if (check_prohibited(i+1, j) == 0)
                    {
                        c_move(i+1, j);
                        return dim;
                    }
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51))
                {
                    if (check_prohibited(i, j-1) == 0)
                    {
                        c_move(i, j-1);
                        return dim;
                    }
                    else if (check_prohibited(i-1, j) == 0)
                    {
                        c_move(i-1, j);
                        return dim;
                    }
                    else if (check_prohibited(i+1, j) == 0)
                    {
                        c_move(i+1, j);
                        return dim;
                    }
                }
                else if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    if (check_prohibited(i, j-1) == 0)
                    {
                        c_move(i, j-1);
                        return dim;
                    }
                    else if (check_prohibited(i, j+1) == 0)
                    {
                        c_move(i, j+1);
                        return dim;
                    }
                    else if (check_prohibited(i+1, j) == 0)
                    {
                        c_move(i+1, j);
                        return dim;
                    }
                }
                else if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    if (check_prohibited(i, j-1) == 0)
                    {
                        c_move(i, j-1);
                        return dim;
                    }
                    else if (check_prohibited(i, j+1) == 0)
                    {
                        c_move(i, j+1);
                        return dim;
                    }
                    else if (check_prohibited(i-1, j) == 0)
                    {
                        c_move(i-1, j);
                        return dim;
                    }
                }
            }
        }

        /*make a move in zero line made box*/
        for (int i = 1; i < x+x+1; i+=2)
        {
            for (int j = 1; j < y+y+1; j+=2)
            {
                if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51))
                {
                    if (check_prohibited(i, j-1) == 0)
                    {
                        c_move(i, j-1);
                        return dim;
                    }
                    else if (check_prohibited(i, j+1) == 0)
                    {
                        c_move(i, j+1);
                        return dim;
                    }
                    else if (check_prohibited(i-1, j) == 0)
                    {
                        c_move(i-1, j);
                        return dim;
                    }
                    else if (check_prohibited(i-1, j) == 0)
                    {
                        c_move(i+1, j);
                        return dim;
                    }
                }
            }
        }

        /*make a move in two line made box*/
        for (int i = 1; i < x+x+1; i+=2)
        {
            for (int j = 1; j < y+y+1; j+=2)
            {
                if (!(lines[i][j-1] == -70) && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && lines[i+1][j] == -51)
                {
                    c_move(i, j+1);
                    return dim;
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    c_move(i, j-1);
                    return dim;
                }
                else if (!(lines[i][j-1] == -70) && lines[i][j+1] == -70 && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    c_move(i+1, j);
                    return dim;
                }
                else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && !(lines[i-1][j] == -51) && lines[i+1][j] == -51)
                {
                    c_move(i, j+1);
                    return dim;
                }
                else if (lines[i][j-1] == -70 && !(lines[i][j+1] == -70) && lines[i-1][j] == -51 && !(lines[i+1][j] == -51))
                {
                    c_move(i+1, j);
                    return dim;
                }
                else if (lines[i][j-1] == -70 && lines[i][j+1] == -70 && !(lines[i-1][j] == -51) && !(lines[i+1][j] == -51))
                {
                    c_move(i-1, j);
                    return dim;
                }
            }
        }

        /*AI logic in case of easy*/
    }
    else
    {
        /*choose a random move and check its validity*/
        while(1)
        {
            found = 0;
            rowno = rand()%(2*x+1);
            columnno = rand()%(2*x+1);
            if (rowno % 2 == columnno % 2)
            {
                continue;
            }

            for (int i = 0; i < x*(x+1)*2; i++)
            {
                if ((rowno + 1 == moves_history[i][0]) && (columnno + 1 == moves_history[i][1]))
                {
                    continue;
                }
            }
            row = rowno;
            column = columnno;
            dim = row * 100 + column;
            return dim;
        }
    }
    return 0;
}
