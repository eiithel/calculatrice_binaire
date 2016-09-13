#include <QCoreApplication>
#include<stdio.h>
#include "fonctions.h"


//variables globales

int *list;    // pointer to array of integer numbers
int size;     // size of data array
//gabriel divflot32 simple precision
int En_division =0;


//Operations fonctions asm en C

//addition
unsigned int AddEntierNonSigne32BitsC(unsigned int *TabIntNoS){
    unsigned int res;
    res = TabIntNoS[0]+TabIntNoS[1];
    return res;
}

int AddEntierSigne32BitsC(int *TabIntS){
    int res = TabIntS[0]+TabIntS[1];
    return res;
}

//soustraction
extern unsigned int SubEntierNonSigne32Bits(unsigned int *TabIntNoS);

int SubEntierSigne32Bits(int *TabIntS){
    int res = TabIntS[0]-TabIntS[1];
    return res;

}
extern double SubFlottant64bits(double *TabFloat64);
//printf("%lf",resultat);

//mpy
extern long long MpyEntierNonSigneOp32bitsRes64bits(unsigned int *TabIntNoS);
extern long long MpyEntierSigneOp32bitsRes64bits(unsigned int *TabIntS);
//div
extern unsigned int DivSubc(unsigned int *TabIntNoS);
extern float DivFlottant32bits(float *TabFloat);



//tous les types

int main(int argc, char* argv[]) {

    size=argc;

    list=(int*)calloc(size,sizeof(int));

    //on recupere les arguments passes et on les met dans un tableau
    for(int i=0;i<3;i++){
        list[i]=atoi(argv[i+1]);
    }


    //Initialisation tableaux contenant les operandes

    int TabIntS[2];
    int *TabIntS_ptr = TabIntS;

    unsigned int TabIntNos[2];
    unsigned int *TabIntNos_ptr = TabIntNos;

    unsigned short TabShortNoS[2];
    unsigned short *TabShortNoS_ptr=TabShortNoS;

    short TabShortS[2];
    short *TabShortS_ptr=TabShortS;

    unsigned char TabCharNoS[2];
    unsigned char *TabCharNoS_ptr =TabCharNoS;
    char TabCharS[2];
    char *TabCharS_ptr=TabCharS;

    unsigned long TabLongNos[2];
    unsigned long *TabLongNos_ptr=TabLongNos;

    long TabLongS[2];
    long *TabLongS_ptr=TabLongS;

    unsigned long long TabLongLongNos[2];
    unsigned long long *TabLongLongNos_ptr=TabLongLongNos;

    long long TabLongLongS[2];
    long long *TabLongLongS_ptr=TabLongLongS;

    float TabFloat32[2];
    float *TabFloat32_ptr=TabFloat32;

    double TabFloat64[2];
    double *TabFloat64_ptr=TabFloat64;

    /* long float TabFloat64[2];
       long float *TabFloat64_ptr = TabFloat64;
    */
    //erreur pour ce format a la compilation sous Qt mais fonctionne sur ccs...



    //donne bonne taille de tableau a chacun
    initTab(TabShortNoS, TabShortS, TabCharNoS, TabCharS, TabIntNos, TabIntS, TabLongNos, TabLongS, TabLongLongNos, TabLongLongS);

    for(int i=0;i<3;i++){
        printf("%d\n", list[i]);
    }

    AnalyserListe(list, TabShortNoS_ptr, TabShortS_ptr, TabCharNoS_ptr, TabCharS_ptr, TabIntNos_ptr, TabIntS_ptr, TabLongNos_ptr, TabLongS_ptr, TabLongLongNos_ptr, TabLongLongS_ptr);

    return 0;

}
