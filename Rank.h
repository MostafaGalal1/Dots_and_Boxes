void Rank(char PlayerName[30], int PlayerScore)
{
    int HvsHno = 0, scores_array[10], stemp, minum = 25, minindex;
    char names_array[10][30] = {{'\0'}},ntemp[30];

    for (int i = 0; i < 10; i++)
    {
        scores_array[i] = 0;
    }

    FILE *rfile;

    /*check if ranking file exists*/
    if ((rfile = fopen("Ranking.bin", "rb")) == NULL)
    {
        /* if it does not exist create a new one*/
        rfile = fopen("Ranking.bin", "wb");
        HvsHno = 1;
        fwrite(&HvsHno, sizeof(int), 1, rfile);
        fwrite(&PlayerScore, sizeof(int), 1, rfile);
        fwrite(PlayerName, sizeof(char), 30, rfile);
        fclose(rfile);
        return;
    }
    /*if it exists read it*/
    fread(&HvsHno, sizeof(int), 1, rfile);
    for (int i = 0; i < HvsHno; i++)
    {
        fread(&scores_array[i], sizeof(int), 1, rfile);
        fread(&names_array[i], sizeof(char), 30, rfile);
    }

    /*searching for the lowest score or an empty place*/
    for (int i = 0; i < 10; i++)
    {
        if (scores_array[i] < minum)
        {
            minum = scores_array[i];
            minindex = i;
        }
    }

    /*place player name and score*/
    if (PlayerScore > scores_array[minindex])
    {
        scores_array[minindex] = PlayerScore;
        for (int i = 0 ; i < 30; i++)
        {
            names_array[minindex][i] = PlayerName[i];
        }
    }

    /*sorting the data*/
    for (int i = 0; i < HvsHno ; i++)
    {
        for (int j = i + 1 ; j < HvsHno ; j++)
        {
            if (scores_array[i] < scores_array[j])
            {
                stemp = scores_array[i];
                for (int k = 0 ; k < 30; k++)
                {
                    ntemp[k] = names_array[i][k];
                }
                scores_array[i] = scores_array[j];
                for (int k = 0 ; k < 30; k++)
                {
                    names_array[i][k] = names_array[j][k];
                }
                scores_array[j] = stemp;
                for (int k = 0 ; k < 30; k++)
                {
                    names_array[j][k] = ntemp[k];
                }
            }
        }
    }

    /*writing in the file*/
    rfile = fopen("Ranking.bin", "wb");
    if (HvsHno > 9)
    {
        fwrite(&HvsHno, sizeof(int), 1, rfile);
        for (int i = 0; i < HvsHno; i++)
        {
            fwrite(&scores_array[i], sizeof(int), 1, rfile);
            fwrite(names_array[i], sizeof(char), 30, rfile);
        }
    }
    else
    {
        HvsHno++;
        fwrite(&HvsHno, sizeof(int), 1, rfile);
        for (int i = 0; i < HvsHno; i++)
        {
            fwrite(&scores_array[i], sizeof(int), 1, rfile);
            fwrite(names_array[i], sizeof(char), 30, rfile);
        }
    }

    /*closing the file*/
    fclose(rfile);
    return;
}
