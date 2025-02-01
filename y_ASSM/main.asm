include main.inc

;=======================
.DATA                  



.CODE 
start:

CALL main                    ;; *тут происходит выход когда main end
invoke ExitProcess,0

;----------------------
 main proc

  CALL learn



inkey
;----------------------
ret
main endp ;MAIN END
end start
