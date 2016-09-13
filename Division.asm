;--------------------------------------
;File:   Division.asm
;Authors: tesl2401     marg2121    mare3016
;Created on 8 sept. 2016, 17:28
;--------------------------------------

;--------------------------------------
;Definitions globales
;--------------------------------------

        .def _DivIncrementation
	.def _DivSubc
	.def _DivFlottant32bits

;--------------------------------------
;Fonctions
;--------------------------------------

        .text
	
_DivIncrementation; entier non signe
;Faire la division entre deux entiers non signes d?une façon incrementale, cest-a-dire en
;effectuant une succession de soustraction (comme à la main). format de donnees 32 bits.

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
	CMPGT A0,0,B1
	[B1] B _soustration_sucessive
	NOP 5
_FIN
	B B3
	NOP 5
	.endasmfunc
	
	ZERO A4

_DivSubc   ;GE Fonction 7.3.14
;Division de deux entier non signes
	.asmfunc
; Premier argument
	LDW *A4++,A0	;Load premier parametre (Numerateur)
	NOP 4			;A0 = 32 bits unsigned
; Deuxieme argument
	LDW *A4,A1		;Load deuxieme parametre (Denominateur)
	NOP 4			;B0 = 32 bits unsigned
; comparaison pour la sécurité
	CMPGTU A1,A0,A4
	CMPEQ A1,0,A4
	CMPEQ A0,0,A4

; align denominator
	lmbd 1,A1,A7
	lmbd 1,A0,A6

	sub A7,A6,A7
	SHL A7,A1,A1
_loop
	subc A0,A1,A0
	add 1,A4,A4

	CMPEQ A4,A1,A2
	[!A2] B _loop
	nop 5

	B B3
	nop 5
	.endasmfunc

;Branch out
	B B3
	NOP 5
	.endasmfunc

_DivFlottant32bits
;Division entre deux flottants a simple precision.
	.asmfunc

	LDW *A4++,A0
	nop 4

	LDW *A4++,A1
	nop 4

	RCPSP A1,A1
	MPYSP A0,A1,A4
	NOP 3

	B B3
	nop 5

	.endasmfunc
