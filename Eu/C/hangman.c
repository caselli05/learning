#include <ctype.h> 
#include <stdio.h>
#include <stdlib.h>

char* getString(char* input);
void drawHang(int mistakes);
void drawLetters(char used_letters[52], char* found_letters);
char getChar(char* input, char used_letters[52]);
int inWord(char letter, char* word, char* found_letters);
int strlen(char* word);

int main(void){
    char* word = getString("Word: ");
    int mistakes = 0;
    char used_letters[52];
    for(int i = 0; i < 52; i+=2){
        used_letters[i] = '-';
        used_letters[i+1] = ',';
    }
    char* found_letters = malloc(strlen(word)*sizeof(char));
    if(found_letters == NULL){
        printf("Malloc error =/ \n");
        return 1;
    }
    for(int i = 0, j = strlen(word); i < j; i++){
        found_letters[i] = '-';
    }
    int game_on = 1;
    while (game_on == 1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        drawHang(mistakes);
        drawLetters(used_letters, found_letters);
        char letter = getChar("Letter: ", used_letters);
        used_letters[(letter - 'a')*2] = letter;
        if(inWord(letter, word, found_letters) == 1){
            int word_complete = 1;
            for(int i = 0, j = strlen(found_letters); i < j; i++){
                if(found_letters[i] == '-'){
                    word_complete = 0;
                }
            }
            if(word_complete == 1){
                game_on = 0;
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou won!!!\n");
            }
        }
        else{
            mistakes++;
            if(mistakes == 6){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou lost!!!\n");
                game_on = 0;
            }
        }
    }
    drawHang(mistakes);
    drawLetters(used_letters, word);
    printf("\n");

    printf("Type anything to continue\n");
    scanf("%c", &used_letters[0]);
    scanf("%c", &used_letters[0]);


    return 0;
}









char* getString(char* input){
    char s[20];

    printf("%s", input);
    scanf("%s", s);
    char* word = malloc(strlen(s)*sizeof(char));
    if(word == NULL){
        free(s);
        return NULL;
    }
    for(int i = 0, j = strlen(s); i < j; i++){
        word[i] = tolower(s[i]);
    }
    return word;
}


void drawHang(int mistakes){
    switch (mistakes){
        case 0:
            printf("-+-------+\n |       |\n |\n |\n |\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 1:
            printf("-+-------+\n |       |\n |       O\n |\n |\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 2:
            printf("-+-------+\n |       |\n |       O\n |       |\n |\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 3:
            printf("-+-------+\n |       |\n |       O\n |       |\\      \n |\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 4:
            printf("-+-------+\n |       |\n |       O\n |      /|\\      \n |\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 5:
            printf("-+-------+\n |       |\n |       O\n |      /|\\      \n |      /\n |\n |\n |\n |\n-+--------------\n");
        break;
        case 6:
            printf("-+-------+\n |       |\n |       O\n |      /|\\      \n |      / \\      \n |\n |\n |\n |\n-+--------------\n");
        break;
    }
}


void drawLetters(char used_letters[52], char* found_letters){
    printf("%s       Used Letters: ",found_letters);
    for(int i = 0; i < 52; i++){
        printf("%c", used_letters[i]);
    }
    printf("\n");
}


char getChar(char* input, char used_letters[52]){
    char c = 0;
    printf("%s", input);
    scanf("%c", &c); 
    scanf("%c", &c); 
    c = tolower(c);
    if(((97 <= c) && (c <= 122))){
        if(used_letters[(c-'a')*2] == '-'){
            return c;
        }
    }
    return getChar("Already used\nLetter: ", used_letters);
}


int inWord(char letter, char* word, char* found_letters){
    int is_in = 0;
    for(int i = 0, j = strlen(word); i < j; i++){
        if(letter == word[i]){
            is_in = 1;
            found_letters[i] = letter;
        }
    }
    return is_in;
}


int strlen(char* word){
    int len = 0;
    while(word[len] != '\0'){
        len++;
    }
    return len;
}

