#include <stdio.h>

int main(){
    char str[100];
    scanf("%[^\n]", str);
    char primeiro_nome[100];
    char ultimo_nome[100];
    int i = 0;
    while (str[i] != ' '){
        primeiro_nome[i] = str[i];
        primeiro_nome[i+1] = '\0';
        i++;
    }
    for (int j = 0; str[i] != '\0'; j++, i++){
        ultimo_nome[j] = str[i];
        ultimo_nome[j+1] = '\0';
        if (str[i] == ' '){
            j = -1;
        }
    }
    if('A' >= primeiro_nome[0] && primeiro_nome[0] >= 'Z'){
        primeiro_nome[0] += 'a'-'A';
    }
    if('A' >= ultimo_nome[0] && ultimo_nome[0] >= 'Z'){
        ultimo_nome[0] += 'a'-'A';
    }
    printf("%s.%s@gmail.com", primeiro_nome, ultimo_nome);
    

    return 0;    
}