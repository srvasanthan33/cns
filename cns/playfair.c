#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function to prepare the key matrix
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int k = 0;
    int flag[26] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (flag[key[k] - 'A']) {
                k++;
            }

            keyMatrix[i][j] = key[k];
            flag[key[k] - 'A'] = 1;
            k++;
        }
    }
}

// Function to find the position of a given character in the key matrix
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') {
        ch = 'I';
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to apply the Playfair cipher encryption
void encrypt(char keyMatrix[SIZE][SIZE], char plaintext[], char ciphertext[]) {
    int len = strlen(plaintext);
    int i = 0;

    while (i < len) {
        int row1, col1, row2, col2;

        findPosition(keyMatrix, plaintext[i], &row1, &col1);
        findPosition(keyMatrix, plaintext[i + 1], &row2, &col2);

        if (row1 == row2) {
            ciphertext[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = keyMatrix[row1][col2];
            ciphertext[i + 1] = keyMatrix[row2][col1];
        }

        i += 2;
    }

    ciphertext[len] = '\0';
}

int main() {
    char key[26];
    char keyMatrix[SIZE][SIZE];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the key (uppercase letters): ");
    scanf("%s", key);

    // Prepare the key matrix
    prepareKeyMatrix(key, keyMatrix);

    printf("Enter the plaintext (uppercase letters): ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    encrypt(keyMatrix, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}