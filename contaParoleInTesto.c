void leggiTesto(char testo[]);
int contaParole(char testo[], char parola[]);
void contaParole2(char testo[], char parola[], int *conta);

int main(int argc, const char * argv[]) {
    char testo[501];
    char parola[11];
    char parola1[11];
    int cont;
    
    strcpy(parola1, parola);
    
    leggiTesto(testo);
    printf("%s\n",testo);
    printf("Inserisci la parola da cercare: ");
    scanf(" %s",parola);
    printf("La parola %s appare %d volte",parola, contaParole(testo, parola));
    contaParole2(testo, parola, &cont);
    printf("La parola %s appare %d volte\n",parola,cont);
    return 0;
}

void leggiTesto(char testo[]){
    gets(testo);
}

int contaParole(char testo[], char parola[]){
    int c=0;
    char *pos;
    
    do{
        pos = strstr(testo,parola);
        if (pos!=NULL){
            c++;
            testo = pos+1;
        }
    }while(pos!=NULL);
    return c;
}
void contaParole2(char testo[], char parola[], int *conta){
    *conta = 0;
    char *pos;
    
    do{
        pos = strstr(testo,parola);
        if (pos!=NULL){
            (*conta)++;
            testo = pos+1;
        }
    }while(pos!=NULL);
}
