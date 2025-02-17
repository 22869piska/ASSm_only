windowsize_proc proto :DWORD,:DWORD
prava_proc proto
hide_cursor proto


.const


GANDON equ 0x1F0FFF


.data



;----------------------------------------------------------------------------------------------------------------------------
.code
;----------------------------------------------------------------------------------------------------------------------------
windowsize_proc proc USES EBX EDI ESI shirina:DWORD,vysota:DWORD

      fn GetStdHandle, -11  ;STD_OUTPUT_HANDLE
        PUSH EAX
   
      ;--
      MOV EDX,shirina
      shl EDX,16
      OR EDX,vysota
      fn SetConsoleScreenBufferSize ,EAX,EDX

      ;--
       POP EAX

       LEA EDX,_negr
       PUSH EDX
       PUSH 1
       PUSH EAX
       CALL SetConsoleWindowInfo
    
   RET
windowsize_proc endp
;----------------------------------------------------------------------------------------------------------------------------
prava_proc proc uses ebx edi esi

    invoke IsUserAnAdmin
    cmp eax,0
    jnz admin_error
    printf("NOT ADMIN \n");
    admin_error:
  
    invoke GetCurrentProcessId

    mov ecx, eax
    MOV EAX,1F0FFFh

    PUSH EAX
    PUSH 0
    PUSH ECX
    CALL OpenProcess
   
    cmp eax,0
    jnz process_error
     printf("PROCESS_ERROR \n")
     process_error:

    RET
    prava_proc endp
 ;----------------------------------------------------------------------------------------------------------------------------
  hide_cursor proc
   LOCAL cci:CONSOLE_CURSOR_INFO
     
    fn GetStdHandle,-11;STD_OUTPUT_HANDLE
    PUSH EAX

    LEA ESI,cci
    fn GetConsoleCursorInfo,EAX,ESI
    MOV cci.bVisible,0

    POP EAX
    fn SetConsoleCursorInfo,EAX,ESI
    ;;;----

   RET
 hide_cursor endp
;----------------------------------------------------------------------------------------------------------------------------