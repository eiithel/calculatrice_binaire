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


int *list;    // pointer to array of integer numbers
int size;     // size of data array

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

    printf("Tappez premier operande \n");
    scanf("%u", &intnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%u", &intnos2);

    TabIntNoS = (unsigned int*)calloc(2,sizeof(unsigned int));
    TabIntNoS[0]=intnos1;
    TabIntNoS[1]=intnos2;
}

void ChoisirOperandesIntS(int *TabIntS){
    int ints1, ints2;

    printf("Tappez premier operande \n");
    scanf("%d", &ints1);

    printf("Tappez deuxieme operande \n");
    scanf("%d", &ints2);

    TabIntS = (int*)calloc(2,sizeof(int));
    TabIntS[0]=ints1;
    TabIntS[1]=ints2;
}


void ChoisirOperandesShortNoS(unsigned short *TabShortNoS){
    unsigned short shortnos1, shortnos2;

    printf("Tappez premier operande \n");
    scanf("%hu", &shortnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%hu", &shortnos2);

    TabShortNoS = (unsigned short*)calloc(2,sizeof(unsigned short));
    TabShortNoS[0]=shortnos1;
    TabShortNoS[1]=shortnos2;
}


void ChoisirOperandesShortS(short *TabShortS){
    short shorts1, shorts2;

    printf("Tappez premier operande \n");
    scanf("%hd", &shorts1);

    printf("Tappez deuxieme operande \n");
    scanf("%hd", &shorts2);

    TabShortS = (short*)calloc(2,sizeof(short));
    TabShortS[0]=shorts1;
    TabShortS[1]=shorts2;
}


void ChoisirOperandesCharNoS(unsigned char *TabCharNoS){
    unsigned char charnos1, charnos2;

    printf("Tappez premier operande \n");
    scanf("%hhu", &charnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%hhu", &charnos2);

    TabCharNoS = (unsigned char*)calloc(2,sizeof(unsigned char));
    TabCharNoS[0]=charnos1;
    TabCharNoS[1]=charnos2;
}


void ChoisirOperandesCharS(char *TabCharS){
    char chars1, chars2;

    printf("Tappez premier operande \n");
    scanf("%hhd", &chars1);

    printf("Tappez deuxieme operande \n");
    scanf("%hhd", &chars2);

    TabCharS = (char*)calloc(2,sizeof(char));
    TabCharS[0]=chars1;
    TabCharS[1]=chars2;
}


void ChoisirOperandesLongNos(unsigned long *TabLongNos){
    unsigned long longnos1, longnos2;

    printf("Tappez premier operande \n");
    scanf("%lu", &longnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%lu", &longnos2);

    TabLongNos = (unsigned long*)calloc(2,sizeof(unsigned long));
    TabLongNos[0]=longnos1;
    TabLongNos[1]=longnos2;
}


void ChoisirOperandesLongS(long *TabLongS){
    long longs1, longs2;

    printf("Tappez premier operande \n");
    scanf("%ld", &longs1);

    printf("Tappez deuxieme operande \n");
    scanf("%ld", &longs2);

    TabLongS = (long*)calloc(2,sizeof(long));
    TabLongS[0]=longs1;
    TabLongS[1]=longs2;
}


//operations fonctions asm

//add
extern unsigned int AddEntierNonSigne32Bits(unsigned int *TabIntNoS);
extern int AddEntierSigne32Bits(int *TabIntS);
//sub
extern unsigned int SubEntierNonSigne32Bits(unsigned int *TabIntNoS);
extern int SubEntierSigne32Bits(int *TabIntS);


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
    size=argc;

    list=(int*)calloc(size,sizeof(int));

    //on recupere les arguments passes et on les met dans un tableau
    for(int i=0;i<3;i++){
        list[i]=atoi(argv[i+1]);
    }


    for(int i=0;i<3;i++){
        printf("%d\n", list[i]);
    }








    return 0;

}
