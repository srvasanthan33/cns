#include <stdio.h>
#include <string.h>

void encrypt(char *text, const char *key)
{
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0;i < textLen;i++)
    {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
        {
            text[i] = ((c - 'A' + key[i % keyLen] - 'A') %26) + 'A';
        }
        else if(c >= 'a'&& c <= 'z')
        {
            text[i] = ((c - 'a' + key[i % keyLen] - 'A') %26) + 'a';
        }
    }
}

void decrypt(char *text, const char *key)
{
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0;i < textLen;i++)
    {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
        {
            text[i] = ((c - 'A' - (key[i % keyLen] - 'A') + 26 ) %26) + 'A';
        }
        else{
            text[i] = ((c - 'a' - (key[i % keyLen] - 'A')+ 26 ) %26) + 'a';
        }
    }
}


int main()
{
    char message[] = "Thisisasecretmessage";
    const char key[] = "KEY";

    encrypt(message,key);
    printf("%s",message);

    decrypt(message,key);
    printf("%s",message);

}