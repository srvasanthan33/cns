#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    int rails, code[100][1000], count;
    int i,j;

    printf("Enter the text\n");
    fgets(str,sizeof(str),stdin);

    printf("enter the no of rails\n");
    scanf("%d",&rails);

    int len = strlen(str);

    for(i = 0;i <rails;i++)
    {
        for (j = 0; j < len;j++)
        {
            code[i][j] = 0;
        }
    }

    j = 0;
    count = 0;

    while(j < len)
    {
        if (count % 2 == 0)
        {
            for (i = 0; i < rails;i++)
            {
                code[i][j] = str[j];
                j++;
            }
        }
        else{
            for (i = rails - 2;i > 0;i--)
            {
                code[i][j] = str[j];
                j++;
            }

        }
        count++;
    }

    printf("Encrypted message \n");
    for( int i = 0; i < rails; i++)
    {
        for(int j = 0;j < len;j++)
        {
            printf("%c",code[i][j]);
        }
    }
    printf("\n");

}