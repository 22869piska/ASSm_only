.DATA

;masif dd 10 dup(0) 

masif dd 9,2,3,8,4,3,1,1,7,5  ; масиф сразу типа ну чел пон кроч lown;

data_print proto

.CODE  
;==============>

learn proc uses EBX ESI EDI
;>>>>>>>>

;------
CALL data_print
printf("\n \n NXT SORTIROVKA \n \n")
;->sort

LEA EBX,DWORD PTR[masif]
;REPEAT SORT n<n
MOV ECX,11
@TP:
DEC ECX

;FOR_1
MOV EDI,-1
@for:
INC EDI
CMP EDI,9  ;NE DESYAT
JE @ENDfor
;--------

MOV EAX,DWORD PTR [EBX + EDI * 4]
MOV EDX,DWORD PTR [ (EBX+EDI*4) +4 ]

CMP EAX,EDX
JL @for
;sortirovka
MOV DWORD PTR [  EBX+EDI*4 ],EDX
MOV DWORD PTR [ (EBX+EDI*4) +4],EAX


;--------
JMP @for
@ENDfor:

;FOR_1 END
CMP ECX,10
JECXZ @ENDTP
JMP @TP
@ENDTP:
;TP END ( C<10 )

CALL data_print

;--------
ret
learn endp  ;learn END

;{
data_print proc

 LEA EBX,DWORD PTR[masif]
 MOV EDI,-1
 ;---
 @REPEAT:
 INC EDI
 CMP EDI,10
 JE @RETURN

 MOV ESI,DWORD PTR[EBX+EDI*4]

 ;-PRINT
 printf("INDEX  %i = ",EDI)
 printf(" %i \n",ESI)

 JMP @REPEAT

;====
 @RETURN:
 ret
data_print endp
;}