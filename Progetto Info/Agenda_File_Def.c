#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// DEFINIAMO LA STRUTTURA APPUNTAMENTO
typedef struct appuntamento{
int mese;
int giorno;
float ora;
char nota[1000];
}appuntamento;


//FUNZIONE "INSERISCIAPPUNT" è IN GRADO DI INSERIRE GLI APPUNTAMENTI
//ESSA CONTIENE TUTTI I COSTRUTTI DI CONDIZIONE PER EVENTUALI ERRORI NEL DEFINIRE "mese","giorno","ora"
void inserisciappunt(appuntamento *agend, int riempimento){ 
printf("inserisci nota\n");
scanf("%s", agend[riempimento].nota);
printf("inserisci ora\n");
scanf("%f", &agend[riempimento].ora);
if(agend[riempimento].ora<0 || agend[riempimento].ora>24){
printf("inserimento errato, inserisci un valore tra 0 e 24");
scanf("%f", &agend[riempimento].ora);
}
printf("inserisci mese\n");
scanf("%d", &agend[riempimento].mese);
if(agend[riempimento].mese<1||agend[riempimento].mese>12){
printf("inserimento errato, inserisci un valore tra 1 e 12");
scanf("%d", &agend[riempimento].mese);
}
printf("inserisci giorno\n");
scanf("%d", &agend[riempimento].giorno);
if
(agend[riempimento].mese==1||agend[riempimento].mese==3||agend[riempimento].mese==4||agend[riempimento].mese==
5||agend[riempimento].mese==7||agend[riempimento].mese==8||agend[riempimento].mese==10||agend[riempimento].mese==12){
while(agend[riempimento].giorno<1||agend[riempimento].giorno>31){
printf("inserimento sbagliato, inserisci un valore tra 1 e 31");
scanf("%d", &agend[riempimento].giorno);
}
}else{
if(agend[riempimento].mese==6||agend[riempimento].mese==9||agend[riempimento].mese==11){
while(agend[riempimento].giorno<1||agend[riempimento].giorno>30){
printf("inserimento sbagliato, inserisci un valore tra 1 e 30");
scanf("%d", &agend[riempimento].giorno);
}
}else{
if(agend[riempimento].mese==2){
while(agend[riempimento].giorno<1||agend[riempimento].giorno>28){
printf("inserimento sbagliato, inserisci un valore tra 1 e 28");
scanf("%d", &agend[riempimento].giorno);
}
}
}
}
}


//FUNZIONE "STAMPAAPPUNT" è IN GRADO DI STAMPARE SU UN FILE DI TESTO ESTERNO TUTTI I DATI INSERITI DALL'UTENTE

void stampaappunt(appuntamento *agend, int riempimento){
FILE *Agenda;
Agenda=fopen("agd.txt","a+");
if(Agenda)
{
printf("Dati contenuti nel file\n");
printf("Si prega l'utenza di uscire dal programma per visionare gli appuntamenti,grazie!\n");
int i;
for (i=0; i<=riempimento-1; i++){
fprintf(Agenda,"mese: %d\n", agend[i].mese);
fprintf(Agenda,"giorno: %d\n", agend[i].giorno);
fprintf(Agenda,"ora: %f \n", agend[i].ora);
fprintf(Agenda,"nota: %s\n", agend[i].nota);
fprintf(Agenda,"\n");
}
}
}

//MAIN DEL PROGRAMMA CONTENTENT I RICHIAMI ALLE FUNZIONI PRECEDENTEMENTE DEFINITE
int main(){
appuntamento Agenda[1000];
int riemp=0;
int scelta=0;
do{
printf("Digita un numero per le seguenti azioni\n");
printf("1 - Scrivi appuntamento\n");
printf("2 - Stampa appuntamenti\n");
printf("3 - Esci\n");
scanf("%d", &scelta);
if((scelta!=1)&&(scelta!=2)&&(scelta!=3)){
printf("scelta errata, digita un numero tra 1, 2 e 3");
} else if(scelta==1){
inserisciappunt(Agenda, riemp);
riemp++;
} else if(scelta==2){
stampaappunt(Agenda, riemp);
}
}while(scelta!=3);
system("PAUSE");
return 0;
}

