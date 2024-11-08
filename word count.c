#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int countWords(const char *str) {
    int state = 0; // 0: outside a word, 1: inside a word
    int wordCount = 0;

    while (*str) {
        if (isspace(*str)) {
            state = 0; // We are outside a word
        } else if (state == 0) {
            state = 1; // We found a new word
            wordCount++;
        }
        str++;
    }
    return wordCount;
}

int main() {
    char text[MAX_LENGTH];

    printf("Enter text (max %d characters):\n", MAX_LENGTH);
    fgets(text, MAX_LENGTH, stdin); // Read a line of text

    int wordCount = countWords(text);
    printf("Total number of words: %d\n", wordCount);

    return 0;
}
