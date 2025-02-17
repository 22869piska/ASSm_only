

;========================================
.const

KEY_S EQU 115
KEY_W EQU 119
KEY_ENTER EQU 13
.data

KEY_STATE db 30h

;=======================================

;======================================
.code
;---------------------------------------------------------------------------------------------------------
key_state_wait proc USES EBX EDI ESI
 
 fn FlushConsoleInputBuffer,rv(GetStdHandle,-10);STD_INPUT_HANDLE
   
    @REPEAT:
   fn Sleep,1

   fn crt__kbhit
   OR EAX,EAX

   JE @REPEAT
   ;-----
   fn crt__getch
   MOV BYTE PTR[KEY_STATE],AL
  ; MOV AL,KEY_STATE
   
 ;-----
 @RRET:
 RET
key_state_wait endp
;---------------------------------------------------------------------------------------------------------