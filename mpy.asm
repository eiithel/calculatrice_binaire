;--------------------------------------
;File:   mpy.asm
;Authors: tesl2401     marg2121    xxxxyyyyy
;Created on 8 sept. 2016, 17:28
;--------------------------------------

;--------------------------------------
;Definitions globales
;--------------------------------------
	.def _MpyEntierNonSigneOp32bitsRes64bits
	.def _MpyEntierSigneOp32bitsRes64bits
;.def _MpyfractionnaireOp32bitsRes64bits_Q7.24_Q15.16
;.def _MpyFlottant64bits

;--------------------------------------
;Variables
;--------------------------------------
 	.data

;--------------------------------------
;Fonctions
;--------------------------------------
	.text

_MpyEntierNonSigneOp32bitsRes64bits   ;GE Fonction 7.3.9
;Multiplication de deux entier non signes de 32 bits
;Resultat en 64 bits
	.asmfunc
; Premier argument
	LDW *A4++,A0	;Load premier parametre
	NOP 4			;A0 = 32 bits unsigned
; Deuxieme argument
	LDW *A4,B0		;Load deuxieme parametre
	NOP 4			;B0 = 32 bits unsigned
;Etape intermediaire 1
;Multiplication des 16 LSB Operande1 avec les 16 LSB Operande2
	MPYU A0,B0,A1	;A1 = LSB1 * LSB2
	NOP 1
;Etape intermediaire 2
;Multiplication des 16 MSB Operande1 avec les 16 LSB Operande2
	MPYHLU A1,B0,A2	;A2 = MSB1 * LSB2
	NOP 1
;Etape intermediaire 3
;Multiplication des 16 LSB Operande1 avec les 16 MSB Operande2
	ADDU A1,A2,A5:A4	;Premiere somme partielle : A1 = A1 + A2
	MPYLHU A0,B0,A2		;A2 = LSB1 * MSB2
	NOP 1
;Etape intermediaire 4	
;Multiplication des 16 MSB Operande1 avec les 16 MSB Operande2
	ADDU A1,A2,A5:A4	;Deuxieme somme partielle : A1 = A1 + A2
	MPYHU A0,B0,A2 		;A2 = MSB1 * MSB2
	NOP 1
;Somme des 4 resultats intermediaires (Accumulateur 64 bits)
	ADDU A1,A2,A5:A4	;Deuxieme somme partielle : A1 = A1 + A2
;Branch out
	B B3
	NOP 5
	.endasmfunc


_MpyEntierSigneOp32bitsRes64bits  ;GE Fonction 7.3.10
;Multiplication de deux entier signes de 32 bits
;Resultat en 64 bits
	.asmfunc
;Premier argument
	LDW *A4++,A0	;Load premier parametre
	NOP 4			;A0 = 32 bits unsigned
;Deuxieme argument
	LDW *A4,B0		;Load deuxieme parametre
	NOP 4			;B0 = 32 bits unsigned
;Multiplication de 2x 32 bits avec reponse en 64 bits
	MPYID A0,B0,A5:A4
	NOP 9
;Branch out
	B B3
	NOP 5
	.endasmfunc


;_MpyfractionnaireOp32bitsRes64bits_Q7.24_Q15.16(ZZZ *TabXXX)   ;GE Fonction 7.3.11
;.asmfunc

; Code de la fonction
;But : Faire la multiplication entre deux fractionnaires Q7.24 et Q15.16. Par convention le 1er
;opŽrande rentrŽ est le Q7.24. Le rŽsultat doit �tre capable dÕoffrir la plus grande prŽcision
;possible pour de futurs calculs. Les opŽrandes rentrŽs doivent �tre sous la forme dÕentier et
;cohŽrent avec la reprŽsentation demandŽe.

;.endasmfunc


;_MpyFlottant64bits(ZZZ *TabXXX)   ;GE Fonction 7.3.12
;.asmfunc

; Code de la fonction
;But : Faire la multiplication entre 2 flottants ˆ double prŽcision.

;.endasmfunc


;--------------------------------------
 .end


