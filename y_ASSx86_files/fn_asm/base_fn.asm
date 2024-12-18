
include C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib

.code

konec proc ;[1_param + 8],
;*
push ebp
mov ebp,esp

push dword ptr[ebp+8] 
call Sleep
;--------------
push 0
call ExitProcess


ret 4

;*
konec endp
