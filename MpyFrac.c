/*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>

extern long long  MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16(int *TabQFormat);

/*
int main(void) {
	
	float TabFloat[2];
	TabFloat[0] = 0.33;	//Argument d'entree 1 (Entier)
	TabFloat[1] = 100.100;	//Argument d'entree 2 (Entier)

	int TabQFormat[2];
	TabQFormat[0] = (TabFloat[0] * 16777216);	//Q7.24 number format - Multiplication par la resolution (2^24)
	TabQFormat[1] = (TabFloat[1] * 65536);	//Q15.16 number format - Multiplication par la resolution (2^16)
	
	long long res;
	res = MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16(TabQFormat);
	res = res /(2.1990233e+12);

	printf("le resultat de loperation est: %lld\n", res);

	return 0;
}
*/
