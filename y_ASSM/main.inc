;------------
 ;.686
 ;.model flat, stdcall
 ;option casemap:none
;------------
   include \masm32\include\masm32rt.inc
   include \masm32\include\winmm.inc
   includelib \masm32\lib\winmm.lib

     ;include C:\MASM32\Include\windows.inc    ; основные определения Windows API
     ;include C:\MASM32\Include\user32.inc    ; функции для работы с окнами и сообщениями
     ;include C:\MASM32\Include\kernel32.inc  ; базовые функции Windows API
;-------------------------
include data/strct.inc
;---------------------
include data/arr_util.inc
;---------
include fn_asm\init.inc
include fn_asm\game.inc


 