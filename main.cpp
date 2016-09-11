#include <QCoreApplication>
#include<stdio.h>

/*

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int size;
    size=argc;
    char *data;

    data=(char*)calloc(size,sizeof(char));
    int i=0;
    for (i=1;i<size;i++)
    {
        data[i]=argv[i];
        printf("%d\n",data[i]);
    }


    return a.exec();
}
*/

//variables globales

int *list;    // pointer to array of integer numbers
int size;     // size of data array


void initTab(unsigned short *TabShortNoS, short *TabShortS, unsigned char *TabCharNoS, char *TabCharS, unsigned int *TabIntNos, int *TabIntS, unsigned long *TabLongNos, long *TabLongS, unsigned long long *TabLongLongNos, long long *TabLongLongS){

    //TabIntNos = (unsigned int*)calloc(2,sizeof(unsigned int));
    TabIntS = (int*)calloc(2,sizeof(int));
    TabShortNoS = (unsigned short*)calloc(2,sizeof(unsigned short));
    TabShortS = (short*)calloc(2,sizeof(short));
    TabCharNoS = (unsigned char*)calloc(2,sizeof(unsigned char));
    TabCharS = (char*)calloc(2,sizeof(char));
    TabLongNos = (unsigned long*)calloc(2,sizeof(unsigned long));
    TabLongS = (long*)calloc(2,sizeof(long));
}



int ObtenirFormat(int *Liste){
    return Liste[1];
}

int ObtenirOperation(int *Liste){
    return Liste[2];
}

int ObtenirType(int *Liste){
    return Liste[0];
}

int ConvertirListe(int *Liste){
    int result;
    return result = Liste[0]*10+Liste[1];
}


//ChoisirOperandes fonctions

void ChoisirOperandesIntNoS(unsigned int *TabIntNoS){
    unsigned int intnos1, intnos2;
/*
    printf("Tappez premier operande \n");
    scanf("%u", &intnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%u", &intnos2);
*/
    //TabIntNoS = (unsigned int*)calloc(2,sizeof(unsigned int));
    TabIntNoS[0]=3;
    TabIntNoS[1]=2;
}

void ChoisirOperandesIntS(int *TabIntS){
    int ints1, ints2;

    printf("Tappez premier operande \n");
    scanf("%d", &ints1);

    printf("Tappez deuxieme operande \n");
    scanf("%d", &ints2);

    //TabIntS = (int*)calloc(2,sizeof(int));
    TabIntS[0]=ints1;
    TabIntS[1]=ints2;
}


void ChoisirOperandesShortNoS(unsigned short *TabShortNoS){
    unsigned short shortnos1, shortnos2;

    printf("Tappez premier operande \n");
    scanf("%hu", &shortnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%hu", &shortnos2);

    //TabShortNoS = (unsigned short*)calloc(2,sizeof(unsigned short));
    TabShortNoS[0]=shortnos1;
    TabShortNoS[1]=shortnos2;
}


void ChoisirOperandesShortS(short *TabShortS){
    short shorts1, shorts2;

    printf("Tappez premier operande \n");
    scanf("%hd", &shorts1);

    printf("Tappez deuxieme operande \n");
    scanf("%hd", &shorts2);

    //TabShortS = (short*)calloc(2,sizeof(short));
    TabShortS[0]=shorts1;
    TabShortS[1]=shorts2;
}


void ChoisirOperandesCharNoS(unsigned char *TabCharNoS){
    unsigned char charnos1, charnos2;

    printf("Tappez premier operande \n");
    scanf("%hhu", &charnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%hhu", &charnos2);

    //TabCharNoS = (unsigned char*)calloc(2,sizeof(unsigned char));
    TabCharNoS[0]=charnos1;
    TabCharNoS[1]=charnos2;
}


void ChoisirOperandesCharS(char *TabCharS){
    char chars1, chars2;

    printf("Tappez premier operande \n");
    scanf("%hhd", &chars1);

    printf("Tappez deuxieme operande \n");
    scanf("%hhd", &chars2);

    //TabCharS = (char*)calloc(2,sizeof(char));
    TabCharS[0]=chars1;
    TabCharS[1]=chars2;
}


void ChoisirOperandesLongNos(unsigned long *TabLongNos){
    unsigned long longnos1, longnos2;

    printf("Tappez premier operande \n");
    scanf("%lu", &longnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%lu", &longnos2);

    //TabLongNos = (unsigned long*)calloc(2,sizeof(unsigned long));
    TabLongNos[0]=longnos1;
    TabLongNos[1]=longnos2;
}


void ChoisirOperandesLongS(long *TabLongS){
    long longs1, longs2;

    printf("Tappez premier operande \n");
    scanf("%ld", &longs1);

    printf("Tappez deuxieme operande \n");
    scanf("%ld", &longs2);

    //TabLongS = (long*)calloc(2,sizeof(long));
    TabLongS[0]=longs1;
    TabLongS[1]=longs2;
}


//operations fonctions asm

//add
unsigned int AddEntierNonSigne32Bits(unsigned int *TabIntNoS){
    //unsigned int res = 1+2;
    unsigned int res;
    res = TabIntNoS[0]+TabIntNoS[1];
    return res;
}
int AddEntierSigne32Bits(int *TabIntS){
    int res = TabIntS[0]+TabIntS[1];
    return res;
}

//sub
extern unsigned int SubEntierNonSigne32Bits(unsigned int *TabIntNoS);
extern int SubEntierSigne32Bits(int *TabIntS);
//mpy
extern long long MpyEntierNonSigneOp32bitsRes64bits(unsigned int *TabIntNoS);
extern long long MpyEntierSigneOp32bitsRes64bits(unsigned int *TabIntS);
//div
extern unsigned int DivSubc(unsigned int *TabIntNoS);
extern float DivFlottant32bits(float *TabFloat);


void AnalyserListe(int *Liste, unsigned short *TabShortNoS, short *TabShortS, unsigned char *TabCharNoS, char *TabCharS, unsigned int *TabIntNos, int *TabIntS, unsigned long *TabLongNos, long *TabLongS, unsigned long long *TabLongLongNos, long long *TabLongLongS){

    int operation, choix;

    choix = ConvertirListe(Liste);


    operation = ObtenirOperation(Liste);

    switch (operation) {
    case 1://+

        switch (choix) {
        case 12://entier nos 32 bits
            ChoisirOperandesIntNoS(TabIntNos);

            break;

        case 22://entier signe 32 bits
            ChoisirOperandesIntS(TabIntS);

            break;
        case 32://fractionnaire 32 bits

            break;

        }

        break;

    case 2://-

        switch (choix) {
        case 12://entier nos 32 bits
            ChoisirOperandesIntNoS(TabIntNos);
            unsigned int res;
            res = AddEntierNonSigne32Bits(TabIntNos);//fait suivre le tableau a la fonction assembleur
            printf("%d\n", res);

            break;

        case 22://entier signe 32 bits
            ChoisirOperandesIntS(TabIntS);

            break;
        case 44:

            break;

        }

        break;

    case 3://*

        switch (choix) {
        case 12://entier nos 32 bits
            ChoisirOperandesIntNoS(TabIntNos);


            break;

        case 22://entier signe 32 bits
            ChoisirOperandesIntS(TabIntS);

            break;
        case 32://fractionnaire 32 bits

            break;

        case 44:

            break;

        }


        break;

    case 4://div

        switch (choix) {
        /*case 1Y:

            break;

        case 1Y:

            break;
        case 44:

            break;
        */
        }
        break;

    case 5://encrypter

        break;

    }

}
//tous les types

int main(int argc, char* argv[]) {
    // initialize array data

    /*
    size=argc;

    list=(int*)calloc(size,sizeof(int));

    //on recupere les arguments passes et on les met dans un tableau
    for(int i=0;i<3;i++){
        list[i]=atoi(argv[i+1]);
    }
    */

    //tableau contenant les operandes
    int *TabIntS;
    unsigned int TabIntNos[2];
    unsigned int *TabIntNos_ptr = TabIntNos;


    unsigned short *TabShortNoS;
    short *TabShortS;

    unsigned char *TabCharNoS;
    char *TabCharS;

    unsigned long *TabLongNos;
    long *TabLongS;

    unsigned long long *TabLongLongNos;
    long long *TabLongLongS;


    //donne bonne taille de tableau a chacun
    initTab(TabShortNoS, TabShortS, TabCharNoS, TabCharS, TabIntNos, TabIntS, TabLongNos, TabLongS, TabLongLongNos, TabLongLongS);


    list=(int*)calloc(3,sizeof(int));

    //on fixe valeurs sub 32bits noS
    list[0]=1;
    list[1]=2;
    list[2]=2;

    for(int i=0;i<3;i++){
        printf("%d\n", list[i]);
    }

    AnalyserListe(list, TabShortNoS, TabShortS, TabCharNoS, TabCharS, TabIntNos_ptr, TabIntS, TabLongNos, TabLongS, TabLongLongNos, TabLongLongS);








    return 0;

}
