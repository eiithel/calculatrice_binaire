	.def _DivIncrementation

_DivFlottant32bits
	.asmfunc

	LDW *A4++,A0
	nop 4

	LDW *A4++,A1
	nop 4

	MPYSP A0,A1,A4
	NOP 3

	B B3
	nop 5

	.endasmfunc
