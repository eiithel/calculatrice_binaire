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
        SAT A5:A4, A7; on rend un resultat sur 32bits
	NOP 1
	STW A7, *A6++; A7 contient le resultat de la soustraction

	B B3 ; Branch pour retourner au code C, EVITER DE OVERWRITE B3
	NOP 5

	.endasmfunc

_SubEntierSigne32Bits
	.asmfunc

	LDDW *A4++, A1:A0; on load le premier flottant dp
	NOP 4
	LDDW *A4, B1:B0
	NOP 4
	SUBDP A1:A0, B1:B0, A5:A4; on soustrait resultat direct dans registres de retour
	NOP 6 

	B B3
	NOP 5

	.endasmfunc

	.end
