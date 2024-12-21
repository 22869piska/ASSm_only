include main.inc

.data


;>>>>>;
.code
start:

CALL main
;---------------
   push 0
   CALL ExitProcess           ;END TYT;
;---------------
main proc



CALL exploid

;#--------#
push 69
push 288
CALL konec
;#--------#


  ret
main endp

end start
