#include <stdio.h>
#include <string.h>
#define MAX 11

int disegna(char matrice[][MAX], char istruzioni[]);
void stampaMatrice(char matrice[][MAX]);


int main(int argc, const char * argv[]) {
    char matrice[MAX][MAX];
    char istruzioni[MAX*2];
    int i,j;
    
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            matrice[i][j] = '_';
        }
    }
    matrice[MAX/2][MAX/2] = 'x';
    
    printf("Inserisci i comandi da eseguire: ");
    scanf(" %s",istruzioni);
    
    if (disegna(matrice, istruzioni)==-1)
        printf("Non è possibile fare il disegno");
    else
        stampaMatrice(matrice);
    return 0;
}

int disegna(char matrice[][MAX], char istruzioni[MAX]){
    char dir = 'u';
    int posX = MAX/2;
    int posY = MAX/2;
    int i;
    
    for (i=0; i<strlen(istruzioni);i++){
        switch (istruzioni[i]) {
            case 'a':
                switch (dir) {
                    case 'u':
                        if (posY==(MAX-1))
                            return -1;
                        else
                            posY++;
                        break;
                        
                    case 'd':
                        if (posY==0)
                            return -1;
                        else
                            posY--;
                        break;
                        
                    case 'l':
                        if (posX==0)
                            return -1;
                        else
                            posX--;
                        break;
                        
                    case 'r':
                        if (posX==(MAX-1))
                            return -1;
                        else
                            posX++;
                        break;
                }
                matrice[posY][posX] = 'x';
                break;
            case 's':
                switch (dir) {
                    case 'u':
                        dir='l';
                        break;
                    case 'd':
                        dir='r';
                        break;
                    case 'l':
                        dir='d';
                        break;
                    case 'r':
                        dir = 'u';
                        break;
                }
                break;
            case 'd':
                switch (dir) {
                    case 'u':
                        dir='r';
                        break;
                    case 'd':
                        dir='l';
                        break;
                    case 'l':
                        dir='u';
                        break;
                    case 'r':
                        dir = 'd';
                        break;
                }
                break;
        }
    }
    return 0;
}

void stampaMatrice(char matrice[][MAX]){
    int i,j;
    for (i=MAX-1; i>=0; i--){
        for (j=0; j<MAX-1; j++){
            if (matrice[i][j] != '_')
                printf("%c",matrice[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}
