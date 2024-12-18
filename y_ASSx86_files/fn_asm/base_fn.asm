
include C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib

.code

konec proc ;[1_param + 8],[2_param + 12],
;*
push ebp
mov ebp,esp
;--------------

mov eax, dword ptr[ebp+8] 
add eax, dword ptr[ebp+12]




;--------------
mov esp,ebp
pop ebp

ret 8
;*
konec endp
