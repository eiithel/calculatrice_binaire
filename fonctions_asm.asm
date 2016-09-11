        .def _AddEntierNonSigne32Bits
        .def _AddEntierSigne32Bits
        .def _SubEntierNonSigne32Bits
        .def _SubEntierSigne32Bits
        .def _MpyEntierNonSigneOp32bitsRes64bits
        .def _MpyEntierSigneOp32bitsRes64bits

	.data
val .float 0.5 ;Il faut coller les symboles a la gauche


_AddEntierNonSigne32Bits
	.asmfunc
	;add .L1 A4,B4,A4 ;A4 = first arguement, B4 le deuxieme, A4 est le registre de retour
	;add .L2 A4,A6,A4
	;add .S1 A4,B6,A4
	;add .S2 A4,A8,A4
	;add .L1 A4,B8,A4
	;add .L2 A4,A10,A4
	;add A4,B10,A4
	MVKL val,A1 ;Load 16 bits de l'addr de val
	MVKH val,A1 ;Load 16 bits de l'addr de val
	LDW *A1,A0 ; Load val dans A0
	NOP 4
	ADDSP A4,A0,A4
	B B3 ; Branch pour retourner au code C, EVITER DE OVERWRITE B3
	NOP 5

	.endasmfunc


_AddEntierSigne32Bits
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


_SubEntierNonSigne32Bits
        .asmfunc


        B B3
        NOP 5
        .endasmfunc


__SubEntierSigne32Bits
        .asmfunc


        B B3
        NOP 5
        .endasmfunc


_MpyEntierNonSigneOp32bitsRes64bits
        .asmfunc


        B B3
        NOP 5
        .endasmfunc

_MpyEntierSigneOp32bitsRes64bits
        .asmfunc


        B B3
        NOP 5
        .endasmfunc


	.end
