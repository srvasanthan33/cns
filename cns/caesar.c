#include <stdio.h>
#include <stdlib.h>

void caesarEncrypt(char *text,int key)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];
        if (c >= 'A' && c <= 'Z')
        {
            text[i] = ( (c - 'A' + key) % 26 + 26 ) % 26 + 'A';
        }
        else if(c >= 'a' && c <= 'z')
        {
            text[i] = ( (c - 'a' + key) %26 + 26 ) % 26 + 'a';
        }
    }

}

void caesarDecrypt(char *message,int key)
{
    caesarEncrypt(message,- key);
}

int main()
{
    char message[100];
    int key;

    printf("Enter the message ");
    fgets(message,sizeof(message),stdin);
    printf("Enter the value of key an integer ");
    scanf("%d",&key);

    caesarEncrypt(message,key);
    printf("Encrypted Message: %s",message);

    caesarDecrypt(message,key);
    printf("Decrypted Message: %s",message);
    return 0;
}