 	.def _AddEntierNonSigne32bits
 	.def _AddEntierSigne32bits
; ici va avoir les dÃ©finitions pour fractionaire

_AddEntierNonSigne32bits
	.asmfunc
	
	LDW *A4++,A0 ; Lecture et enregistrement du premier argument d'entré dans regsitre A0
	nop 4
	
	LDW *A4++,A1 ; Lecture et enregistrement du second argument d'entré dans regsitre A1
	nop 4
	
	addu .L1 A0,A1,A5:A4 ; addition des 2 registres avec l'instruction ADDU
	sat A5:A4,A4 ; limitation du nombre de bits de sorti à 32 bits
	
	B B3
	nop 5
	.endasmfunc
	
_AddEntierSigne32bits
	.asmfunc
		
	LDW *A4++,A0 ; Lecture et enregistrement du premier argument d'entré dans regsitre A0
	nop 4
	
	LDW *A4++,A1 ; Lecture et enregistrement du second argument d'entré dans regsitre A1
	nop 4
	
	sadd .L1 A0,A1,A4 ; addition des 2 registres avec l'instruction ADDU
	nop 1
	
	B B3
	nop 5
	.endasmfunc
	
	
