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

push 1
push 9
CALL konec

;print(eax)




  ret
main endp

end start
