;------------
 ;.686
 ;.model flat, stdcall
 ;option casemap:none
;------------
   include \masm32\include\masm32rt.inc
   include \masm32\include\winmm.inc
   includelib \masm32\lib\winmm.lib

     ;include C:\MASM32\Include\windows.inc    ; �������� ����������� Windows API
     ;include C:\MASM32\Include\user32.inc    ; ������� ��� ������ � ������ � �����������
     ;include C:\MASM32\Include\kernel32.inc  ; ������� ������� Windows API
;-------------------------
include data/strct.inc
;---------------------
include data/arr_util.inc
;---------
include fn_asm\init.inc
include fn_asm\game.inc


 