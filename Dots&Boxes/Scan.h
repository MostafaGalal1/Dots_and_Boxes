#include<string.h>
#include<math.h>

int input(){

	char readstr[100];
    int  i, len, x;
    int input_int = 0, w;

    gets(readstr);

    len = strlen(readstr);
    x = len-1;

    for(i = 0; i < len; i++)
    {
        if(readstr[i] > 47 && readstr[i] < 58){
            w = readstr[i] - 48;
        } else {
            return -1;
        }
        input_int += w*pow(10,x);
        x--;
    }

	return input_int;
}
