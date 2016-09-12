	.def _SubEntierNonSigne32Bits
	.def _SubEntierSigne32Bits
	.def _SubFlottant64bits
	.def _Circ_asm
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

_SubFlottant64bits
	.asmfunc

	LDDW *A4++, A1:A0; on load le premier flottant
	NOP 4
	LDDW *A4, B1:B0; on load le second flottant
	NOP 4
	SUBDP A1:A0, B1:B0, A5:A4; on soustrait et met le resultat dans registres de retour
	NOP 6


	B B3
	NOP 5
	.endasmfunc

_Circ_asm
	.asmfunc

	MVC AMR, B0; on met registre de controle dans B0
	;LMBD
	STW B0, *B15--; on met AMR sur la stack
	MV B15,A1; on copie le Stack pointeur
	ZERO A10; on met registre A10 a 0
	ADD 4, A10, A10;taille dans BK0 (N=5)
        SHL A10, 16, B0; on set la taille du buffer AMR:XXXX0000
	; set A4 (x) in circular mode
	SET B0, 0, 0, B0 ;A4mode=01
	MVC B0, AMR; set up AMR:0x00040001 BK0=4, A4 mode circulaire
	ZERO A2; On met le compteur a zero

_LOOP
	LDW *A4++, A7 ;parcours du buffer circulaire
	NOP 4
	CMPEQ A2,13,A1 ; if A0 == A4 -> A1 = 1
	ADD 1,A2,A2 ; increment A2 (counter)

	[!A1] B _LOOP
	NOP 5

	LDW *++B15, B8; enleve AMR de la stack
	NOP 4

	MVC B8, AMR ; Restore AMR

	B B3
	NOP 5
	.endasmfunc

	.end
