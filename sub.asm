	.def _SubEntierNonSigne32Bits
	.def _SubEntierSigne32Bits
	.data

valcsr .int 0x00000200
val .float 0.5 ;Il faut coller les symboles a la gauche


	.text

_SubEntierNonSigne32Bits
	.asmfunc

	LDW *A4++, A7 ;on met la valeur du tableau dans A7, apres on incremente A4
	NOP 4
	LDW *A4, A8
	NOP 4
	SUBU A7, A8, A5:A4; soustraction
	SAT A5:A4, A7
	NOP 1
	STW A7, *A6++; A7 contient le resultat de la soustraction

	B B3 ; Branch pour retourner au code C, EVITER DE OVERWRITE B3
	NOP 5

	.endasmfunc

_SubEntierSigne32Bits
	.asmfunc

	LDW *A4++, A7 ;on met la valeur du tableau dans A7, apres on incremente A4
	NOP 4
	LDW *A4, A8
	NOP 4

	;Clear le bit SAT de CSR avant la proc
	MVK 0, B5
	MVC B5, CSR
	SSUB A7, A8, A7; SSUB permet de lever bit SAT
	NOP 1
	MVC CSR, B5; recupere valeur du CSR

	MV A7, A4

	B B3
	NOP 5

	.endasmfunc

_proc_3D
	.asmfunc
	MVK 0,A0 ; counter pour une boucle pseudo while NOTE INDEX APARTIR DE 1 ET NON 0
	SUB A4,1,A4
_etiquette ;label pour retourner
	LDW *B4++,A7 ; Mettre la valeur de B4 dans A7, et apres incrementer B4 NOTE: LDW mem externe -> mem interne
	NOP 4 ; Delay
	MPY 2,A7,A7
	NOP 1
	STW A7,*A6++ ; Mettre la valeur de B4 (A travers de A7) dans A6 NOTE: STW mem intern -> mem externe
	CMPEQ A0,A4,A1 ; if A0 == A4 -> A1 = 1
	ADD 1,A0,A0 ; increment A0 (counter)
	[!A1] B _etiquette;
	NOP 5


	B B3
	NOP 5
	.endasmfunc

	.end
