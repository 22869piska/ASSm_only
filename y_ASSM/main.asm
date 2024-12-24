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



CALL konec

CALL exploid

;#--------#

;#--------#


  ret
main endp

end start
