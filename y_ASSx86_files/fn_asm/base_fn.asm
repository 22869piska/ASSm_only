
include C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib

.code

konec proc 
;*


push 1488
call Sleep
;--------------
push 0
call ExitProcess

ret

;*
konec endp
