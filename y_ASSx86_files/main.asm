include main.inc

;--------->

.code             ;-------------------->>;START MY CODE pidr;
start:



;------
push 228
push 69

CALL konec ;2param

;--
push eax
CALL Sleep

;------
push 0
CALL ExitProcess

end start         ;-------------------->>;STOP TYT END;

