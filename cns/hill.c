#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int keymat[3][3] = {{1,2,1}, {2,3,2}, {2,2,1}};
int keyinvmat[3][3] = {{2,2,1}, {1,2,1}, {2,3,2}};
char key[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char* encode(char a, char b, char c)
{
    char *ret = malloc(4);
    int x,y,z;
    int posa = a - 65;
    int posb = b - 65;
    int posc = c - 65;

    x = posa * keymat[0][0] + posb * keymat[1][0] + posc * keymat[2][0];
    y = posa * keymat[0][1] + posb * keymat[1][1] + posc * keymat[2][1];
    z = posa * keymat[0][2] + posb * keymat[1][2] + posc * keymat[2][2];

    ret[0] = key[x % 26];
    ret[1] = key[y % 26];
    ret[2] = key[z % 26];

    ret[3] = '\0';
    return ret;    
}

void decode(char *text)
{
    char ret[4];
    int x,y,z;
    int posa = 'a' - 65;
    int posb = 'b' - 65;
    int posc = 'c' - 65;

    x = posa * keyinvmat[0][0] + posb * keyinvmat[1][0] + posc * keyinvmat[2][0];
    y = posa * keyinvmat[0][1] + posb * keyinvmat[1][1] + posc * keyinvmat[2][1];
    z = posa * keyinvmat[0][2] + posb * keyinvmat[1][2] + posc * keyinvmat[2][2];
    printf("%s \n",text);
}

int main()
{
    char message[1000];
    char enc[1000] ="";
    char dec[1000] ="";

    int n;
    strcpy(message,"Vasanthan");
    printf("HILL CIPHER \n");
    printf("Input msg : %s",message);

    for(int i = 0;i <= strlen(message);i++)
    {
        message[i] = toupper(message[i]);

    }
    n = strlen(message) % 3;
    if (n!=0)
    {
        for(int i = 1;i <= (3-n); i++)
        {
            strcat(message,"X");
        }
    }
    printf("Padded Message :%s\n",message);
    for (int i = 0;i < strlen(message);i += 3)
    {
        char a = message[i];
        char b = message[i + 1];
        char c = message[i + 2];
        strcat(enc,encode(a,b,c));
    }
    printf("encoded message : %s \n",enc);
    printf("decoded message : %s \n",message);
    return 0;


}