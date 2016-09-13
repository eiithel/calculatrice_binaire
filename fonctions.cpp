#include "fonctions.h"

extern int En_division;//variable globale indiquant si l'operation en cours est une division
extern int En_QFormat;

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

    printf("Tappez premier operande \n");
    scanf("%u", &intnos1);

    printf("Tappez deuxieme operande \n");
    scanf("%u", &intnos2);

    TabIntNoS[0]=intnos1;
    TabIntNoS[1]=intnos2;

}

void ChoisirOperandesIntS(int *TabIntS){
    int ints1, ints2;

    printf("Tappez premier operande \n");
    scanf("%d", &ints1);

    printf("Tappez deuxieme operande \n");
    scanf("%d", &ints2);

    //protection de la division par zero
    if(En_division && ints2==0){
        printf("erreur! Division par zero");
        return;
    }

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

void ChosirOperandesLongLong(long long *TabLongLong){

    long long l1, l2;

    printf("Tappez premier operande \n");
    scanf("%ll", &l1);

    printf("Tappez deuxieme operande \n");
    scanf("%ll", &l2);

    TabLongLong[0]=l1;
    TabLongLong[1]=l2;
}

void ChoisirOperandesFloat(float *TabFloat){

    int f1, f2;

    printf("Tappez premier operande \n");
    scanf("%f", &f1);

    printf("Tappez deuxieme operande \n");
    scanf("%f", &f2);

    TabFloat[0]=f1;
    TabFloat[1]=f2;

}

void ChoisirOperandesQFormat(int *TabIntS){

    float f1, f2;

    printf("Tappez premier operande \n");
    scanf("%f", &f1);

    printf("Tappez deuxieme operande \n");
    scanf("%f", &f2);

    TabIntS[0] = (f1 * 16777216);	//Q7.24 number format - Multiplication par la resolution (2^24)
    TabIntS[1] = (f2 * 65536);	//Q15.16 number format - Multiplication par la resolution (2^16)

}
//Pour MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16(TabIntS);

void AnalyserListe(int *Liste, unsigned short *TabShortNoS, short *TabShortS, unsigned char *TabCharNoS, char *TabCharS, unsigned int *TabIntNos, int *TabIntS, unsigned long *TabLongNos, long *TabLongS, unsigned long long *TabLongLongNos, long long *TabLongLongS, float *TabFloat){

    int operation, choix;

    choix = ConvertirListe(Liste);


    operation = ObtenirOperation(Liste);

    switch (operation) {
    case 1://+

        switch (choix) {
        case 12://entier nos 32 bits
            ChoisirOperandesIntNoS(TabIntNos);
            unsigned int res;
            res = AddEntierNonSigne32BitsC(TabIntNos);//fait suivre le tableau a la fonction assembleur
            printf("resultat addNonSigne32bits:%d\n", res);

            break;

        case 22://entier signe 32 bits

            ChoisirOperandesIntS(TabIntS);
            int res2;
            res2 = AddEntierSigne32BitsC(TabIntS);
            printf("resultat addSigne32bits: %d\n", res2);

            break;

        case 32://fractionnaire 32 bits

            long long res32a;
            ChoisirOperandesQFormat(TabIntS);
            /*res32a = AddFractionnaire32bits_Q7_24_Q15_16(TabIntS);
            res32a = res32a /(2.1990233e+12);
            printf("le resultat de loperation est: %lld\n", res32a);
            */

            break;

        }

        break;

    case 2://-

        switch (choix) {
        case 12://entier nos 32 bits
            ChoisirOperandesIntNoS(TabIntNos);
            unsigned int res12s;
            /*
            res12s = SubEntierNonSigne32Bits(TabIntNos);
            printf("Resultat subNonSigne32Bits: %d\n", res12s);
            */

            break;

        case 22://entier signe 32 bits
            ChoisirOperandesIntS(TabIntS);
            int res22s;
            res22s = SubEntierSigne32Bits(TabIntS);
            printf("Resultat subSigne32Bits: %d\n", res22s);

            break;
        case 44://flottant64bits
            ChoisirOperandesFloat(TabFloat);
            double res44s;//verifier long float sur ccs
            /*
            res44s=SubFlottant64bits(float *TabFloat);
            printf("Resultat SubFlottant64bits: %lf\n", res44s);

            */

            break;

        }

        break;

    case 3://*

        switch (choix) {
        case 12://entier nos 32 bits
            /*
            long long res12m;
            ChoisirOperandesIntNoS(TabIntNos);
            res12m = MpyEntierNonSigneOp32bitsRes64bits(TabIntNos);
            printf("le resultat de loperation est: %lld\n", res12m);
            */

            break;

        case 22://entier signe 32 bits
            long long res22m;
            ChoisirOperandesIntS(TabIntS);
            /*
            res22m=MpyEntierSigneOp32bitsRes64bits(unsigned int *TabIntS);
            printf("le resultat de loperation est: %lld\n", res22m);
            */

            break;
        case 32://fractionnaire 32 bits
            long long resfr3;
            ChoisirOperandesQFormat(TabIntS);
            /*resfr3 = MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16(TabIntS);
            resfr3 = resfr3 /(2.1990233e+12);
            printf("le resultat de loperation est: %lld\n", resfr3);
            */
            break;

        case 44://flottant64bits

            break;
        }

        break;

    case 4://div

        En_division=1;//set du flag en division a 1

        switch (choix) {
        case 12://entier non signe 32 bits
            unsigned int res12d;
            ChoisirOperandesIntS(TabIntS);
            /*
            res12d=DivIncrementation(TabIntS);
            printf("le resultat de la division Incrementation est: %u ", res12d);
            */
            En_division=0;
            break;

        case 14://entier non signe 32 bits
            //long long normalement...
            unsigned int res14d;
            ChoisirOperandesIntNoS(TabIntNos);
            /*
            res14d=DivSubc(TabIntNos);
            printf("le resultat de la division Subc est: %u\n", res14d);
            */

            En_division=0;
            break;
        case 44://flottant simple precision 32
            float re44d;
            ChoisirOperandesFloat(TabFloat);
            /*
            re44d=DivFlottant32bits(TabFloat);
            printf("le resultat de la division DivFlottant32bits est: %f\n", re44d);
            */
            En_division=0;
            break;

        }
        break;

    case 5://encrypter

        break;

    }

}
