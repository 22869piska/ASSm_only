
.data

_skok dd ?

.code           ;CODE TYT  ;1= +8 , 2= +12

konec proc 
;*
push ebp
mov ebp,esp
;---------
  
mov dword ptr[_skok],0

@while:

 printf("_skok: %i",dword ptr[_skok])
 printf( "  if  == 10 end\n")

 inc dword ptr[_skok]
 cmp dword ptr[_skok],10
 je @go
 jmp @while
@go:

;-end
 mov esp,ebp
 pop ebp

 ret 
;*
konec endp
