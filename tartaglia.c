#include <stdio.h>
#include <string.h>
#define N 100

/* Scrivere una funzione che, preso in ingresso un testo (al massimo 500 caratteri), conta quante volte trova una parola (max 10 caratteri) inserita dall'utente all'interno del testo.*/
/* Scrivere la funzione che, preso in ingresso la dimensione n, permette di scrivere il triangolo di tartaglia.
     1
    1 1
   1 2 1
  1 3 3 1
 1 3 6 4 1
 */
void creaMatrice(int matrix[][2*N-1],int n);
void stampaMatrice(int matrix[][2*N-1],int n);

int main(int argc, const char * argv[]) {
    int triangoloTartaglia[N][2*N-1];
    int n;
    
    printf("Inserisci la dimensione n: ");
    scanf("%d",&n);
    creaMatrice(triangoloTartaglia,n);
    stampaMatrice(triangoloTartaglia,n);
    return 0;
}

void creaMatrice(int matrix[][2*N-1],int n){
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<2*n-1; j++){
            matrix[i][j] = 0;
        }
    }
    matrix[0][n-1] = 1;
    matrix[n-1][0] = 1;
    matrix[n-1][2*(n-1)] = 1;
    
    for (i=1; i<n; i++){
        for (j=1; j<2*(n-1); j++){
            matrix[i][j] = matrix[i-1][j-1]+matrix[i-1][j+1];
        }
    }
}

void stampaMatrice(int matrix[][2*N-1],int n){
    int i,j;
    
    for (i=0; i<n; i++){
        for (j=0; j<=2*(n-1); j++){
            if (matrix[i][j] == 0)
                printf("    ");
            else
                printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }
}
