include main.inc



;------***************************************** proto func 
learn proto 
prava_proc proto

;=======================
.DATA                  
       
       msg_caption db "READ",0
       msg_text db "Remove capslock and choose english layout",0


       _negr SMALL_RECT<0,0,100,35>;<140,80>




.CODE 
start:
CALL main                   
invoke ExitProcess,0
;---------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 main proc
  CALL prava_proc

  fn MessageBox,0, addr msg_text, addr msg_caption, MB_OK
  ;--
  CALL learn

  inkey
ret
main endp 
;=====================================================================
;_______________________________________________________________________________________________________
learn proc uses EBX ESI EDI

       lea esi,_negr
      ;---
      fn SetConsoleTitle,"VELIKIY ASSM"
      fn windowsize_proc,80,80
      fn hide_cursor
      ;---
   
      CALL game


;--
 RET
learn endp 
;----------------------------------------------------------------------------------------------------------------------------



;=====================================================================
end start
