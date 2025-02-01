 ;include /masm32/include/masm32rt.inc          ;[includes]
     
 ;comment~

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
include \masm32\include\masm32.inc
includelib \masm32\lib\masm32.lib
include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib
include \masm32\macros\macros.asm
;~
;----------------------
include arr_util.inc


;----------------------
 ;=====================================================================

 CL_clown struct ;CL_clown 

 
 _skok dd 0
 _v1 dd 0
 _v2 dd 0




 CL_clown ends  ;END STRUCT CL_clown 