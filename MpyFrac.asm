	.def _MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16

	
_MpyfractionnaireOp32bitsRes64bits_Q7_24_Q15_16
	.asmfunc
	
	LDW *A4++,A0	;Transfert de largument 1 dans le registre A0
	NOP 4
	LDW *A4,A1	;Transfert de largument 2 dans le registre A1
	NOP 4

	ZERO A4	;Remise a zero du registre A4
	ZERO A5	;Remise a zero du registre A5

	MPYID A0,A1,A3:A2	;Multiplication de 2x32bits : resultat sur 64 bits
	NOP 9
	
; Eliminer le double 1 du signe des 32 bits sup.
	SHL A3,1,A3	;Shift du registre vers la gauche

; Eviter la perte de donnee
	LMBD 1,A2,A1 ;Detection du dernier bit : Si MSB = 1, LMBD = 0
	CMPEQ A1,0,A1	;Si le MSB = 1, La comparaison sera égale et on set le dernier bit de A3 = 1

	[A1]	SET A3,0,0,A3
	SHL A2,1,A2

	MV A3,A5
	MV A2,A4

	B B3
	NOP 5

	.endasmfunc	
