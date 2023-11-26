#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int keymat[3][3] = {{1,2,1},{2,3,2},{2,2,1}};
char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char* encode(char a, char b, char c)
{
    int x,y,z;
    char *ret = malloc(4);

    int posa = a - 65;
    int posb = b - 65;
    int posc = c - 65;

    x = posa * keymat[0][0] + posb * keymat[1][0] + posc * keymat[2][0];
    y = posa * keymat[0][1] + posb * keymat[1][1] + posc * keymat[2][1];
    x = posa * keymat[0][2] + posb * keymat[1][2] + posc * keymat[2][2];

    ret[0] = key[x % 26;
    ret[1] = key[y % 26;
    ret[2] = key[z % 26;

    ret[3] = '\0';

    return ret;
    
}

int main()
{
    int n;
    char message[1000];
    char enc[1000] = "";
    char dec[1000] = "";

    printf("HILL CIPHER \n");
    strcpy(message,"Vasanthan");
    printf("Input message : %s \n",message);

    for (int i = 0;i < strlen(message); i++)
    {
        message[i] = toupper(message[i]);
    }
    n = strlen(message) % 3;
    if (n != 0)
    {
        for (int i = 1; i <= 3-n; i++)
        {
            strcat(message,"X");
        }
    }
    printf("Padded Message : %s \n", message);

    for( int i = 0;i < strlen(message);i+=3)
    {
        char a = message[i];
        char b = message[i + 1];
        char c = message[i + 2];
        strcat(enc,encode(a,b,c));
    }
    printf("\nEncoded message : %s \n",enc);
    return 0;
}