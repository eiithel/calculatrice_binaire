;--------------------------------------
;File: MpyFloatPoint.asm
;Authors: tesl2401     marg2121    mare3016
;Created on 8 sept. 2016, 17:28
;--------------------------------------

;--------------------------------------
;Definitions globales
;--------------------------------------

        .def _MpyFlottant64bits

;--------------------------------------
;Fonctions
;--------------------------------------


_MpyFlottant64bits
	.asmfunc

	LDW *A4++,A0	;Load de l'argument 1 au registre A0
	NOP 4
	LDW *A4,A1	;Load de l'argument 2 au registre A4
	NOP 4
	
	MPYSP A0,A1,A5:A4	;Enregistrement du resultat de la multiplication en 64 bits
	NOP 3
	B B3	;Branch out
	NOP 5
	.endasmfunc
