include main.inc
.DATA                   ;zvo



.CODE 
;{
start:
CALL main
invoke ExitProcess,0
;}
main proc


CALL learn




;-----------
ret
main endp ;MAIN END
end start
