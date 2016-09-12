	.def _DivIncrementation
	;.def _DiSubc
	;.def _DivFlottant32bits
	
_DivIncrementation
	.asmfunc
	
	LDW *A4++,A0
	nop 4
	
	LDW *A4++,A1
	nop 4

	ZERO A4 ; remise à zéro du registres A4 pour devenir un compteur

_soustration_sucessive
	sub A0,A1,A0 ; les soustractions succesives
	add 1,A4,A4 ; compteur pour donner le résultat

	; comparateur pour savoir si la loop est terminé
	CMPEQ A0,0,B1
	[!B1] B _soustration_sucessive ; je comprends pas pourquoi il ne veut pas sortir de la loop
	NOP 5
	
	B B3
	NOP 5
	.endasmfunc
	
