;--------------------------------------
;File:   Addition.asm
;Authors: tesl2401     marg2121    mare3016
;Created on 8 sept. 2016, 17:28
;--------------------------------------

;--------------------------------------
;Definitions globales
;--------------------------------------

        .def _AddEntierNonSigne32bits
 	.def _AddEntierSigne32bits
 	.def _AddFractionnaire32bits_Q7_24_Q15_16

;--------------------------------------
;Fonctions
;--------------------------------------

        .text

_AddEntierNonSigne32bits
;addition non signee avec des operandes de 32 bits. Il est possible que le r�sultat
;depasse une repr�sentation de 32 bits. Le resultat doit rester sur 32 bits.

	.asmfunc
	
	LDW *A4++,A0 ; Lecture et enregistrement du premier argument d'entr� dans regsitre A0
	nop 4
	
	LDW *A4++,A1 ; Lecture et enregistrement du second argument d'entr� dans regsitre A1
	nop 4
	
	addu .L1 A0,A1,A5:A4 ; addition des 2 registres avec l'instruction ADDU
	sat A5:A4,A4 ; limitation du nombre de bits de sorti � 32 bits
	
	B B3
	nop 5
	.endasmfunc
	
_AddEntierSigne32bits
;addition signee avec des operandes de 32 bits. Il est possible que le resultat depasse
;une representation de 32 bits. Le resultat doit rester sur 32 bits.

	.asmfunc
		
	LDW *A4++,A0 ; Lecture et enregistrement du premier argument d'entr� dans regsitre A0
	nop 4
	
	LDW *A4++,A1 ; Lecture et enregistrement du second argument d'entr� dans regsitre A1
	nop 4
	
	sadd .L1 A0,A1,A4 ; addition des 2 registres avec l'instruction ADDU
	nop 1
	
	B B3
	nop 5
	.endasmfunc
	
_AddFractionnaire32bits_Q7_24_Q15_16; entier signe
;addition entre un fractionnaire Q7.24 et un Q15.16. Suivez la convention selon
;laquelle le 1er operande entre est le Q7.24. Vous devez fournir le r�sultat le plus cohe�rent possible
;sur 32 bits.

	.asmfunc

	LDW *A4++,A0 ; Lecture et enregistrement du premier argument d'entr� dans regsitre A0
	nop 4

	LDW *A4++,A1 ; Lecture et enregistrement du second argument d'entr� dans regsitre A1
	nop 4

	SHL A0,8,A0
	add A0,A1,A4 ; addition des 2 registres avec l'instruction

	B B3
	nop 5
	.endasmfunc

	
