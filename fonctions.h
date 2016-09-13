#ifndef FONCTIONS_H
#define FONCTIONS_H

#endif // FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>


void initTab(unsigned short *TabShortNoS, short *TabShortS, unsigned char *TabCharNoS, char *TabCharS, unsigned int *TabIntNos, int *TabIntS, unsigned long *TabLongNos, long *TabLongS, unsigned long long *TabLongLongNos, long long *TabLongLongS);

int ObtenirFormat(int *Liste);
int ObtenirOperation(int *Liste);
int ObtenirType(int *Liste);
int ConvertirListe(int *Liste);

void ChoisirOperandesIntNoS(unsigned int *TabIntNoS);
void ChoisirOperandesIntS(int *TabIntS);
void ChoisirOperandesShortNoS(unsigned short *TabShortNoS);
void ChoisirOperandesShortS(short *TabShortS);
void ChoisirOperandesCharNoS(unsigned char *TabCharNoS);
void ChoisirOperandesCharS(char *TabCharS);
void ChoisirOperandesLongNos(unsigned long *TabLongNos);
void ChoisirOperandesLongS(long *TabLongS);

//add
unsigned int AddEntierNonSigne32BitsC(unsigned int *TabIntNoS);
int AddEntierSigne32BitsC(int *TabIntS);
//sub
extern unsigned int SubEntierNonSigne32Bits(unsigned int *TabIntNoS);
int SubEntierSigne32Bits(int *TabIntS);
//mpy
extern long long MpyEntierNonSigneOp32bitsRes64bits(unsigned int *TabIntNoS);
extern long long MpyEntierSigneOp32bitsRes64bits(unsigned int *TabIntS);
//div
extern unsigned int DivSubc(unsigned int *TabIntNoS);
extern float DivFlottant32bits(float *TabFloat);

void AnalyserListe(int *Liste, unsigned short *TabShortNoS, short *TabShortS, unsigned char *TabCharNoS, char *TabCharS, unsigned int *TabIntNos, int *TabIntS, unsigned long *TabLongNos, long *TabLongS, unsigned long long *TabLongLongNos, long long *TabLongLongS);
