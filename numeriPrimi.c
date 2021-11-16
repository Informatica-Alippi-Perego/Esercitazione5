#include <stdio.h>
#define MAX 100
//leggere al massimo 100 numeri positivi. Mi fermo appena leggo un numero negativo
//Individuare all'interno dell'array i numeri primi
int leggoArray(int array[]);
void stampaArray(int array[], int l);
int numeriPrimi(int val);

int main(int argc, const char * argv[]) {
    int array_int[MAX];
    int len = 0;

    len = leggoArray(array_int);
    stampaArray(array_int, len);
    return 0;
}

int leggoArray(int array[]){
    int i;
    for (i=0; i<MAX && array[i-1]>=0; i++){
        printf("Inserisci nuovo valore: ");
        scanf("%d",&array[i]);
    }
    return i-1;
}
/*
void stampaArray(int array[], int l){
    int *puntArray;
    for (puntArray = array; (puntArray<array+l); puntArray++){
        if (numeriPrimi(*puntArray)==1)
            printf("%d è primo\n",*puntArray);
        else
            printf("%d\n",*puntArray);
    }
}
*/

void stampaArray(int array[], int l){
    int i;
    for (i=0; i<l; i++){
        if (numeriPrimi(array[i])==1)
            printf("%d è primo\n",array[i]);
        else
            printf("%d\n",array[i]);
    }
}

/*int numeriPrimi(int val){
    int i;
    for (i=2; i<val; i++){
        if (val%i==0)
            return -1;
    }
    return 1;
}
 */
int numeriPrimi(int val){
    int i;
    int isPrimo = 1;
    for (i=2; (i<val) && (isPrimo == 1); i++){
        if (val%i==0)
            isPrimo = -1;
    }
    return isPrimo;
}
