#include <stdio.h>
#include <string.h>

#define MAX 100

int inserisciParola(char s[]);
void stampaNumeroVocali(char s[]);

int main(int argc, const char * argv[]) {
    char parola[MAX];
    
    printf("La lunghezza vale %d\n", inserisciParola(&parola[0]));
    stampaNumeroVocali(parola);
    
    return 0;
}

int inserisciParola(char s[]){
    int i;
    printf("Inserisci la parola da verificare: ");
    scanf(" %s",s);
    //scanf(" %s",&s[0]);
    for (i=0; s[i]!='\0'; i++);
    return i;
}


void stampaNumeroVocali(char s[]){
    int i;
    int contaVocali = 0;
    int contaLettere = 0;
    for (i=0; i<strlen(s); i++){
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contaVocali++;
            default:
                contaLettere++;
                break;
                
        }
    }
    printf("Le vocali della parola %s sono %d\n",s,contaVocali);
}
