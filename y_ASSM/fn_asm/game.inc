
;-----
game proto
main_menu proto

;----
.data



.code
;==================================================================================================================
;------------------------------------------------------------------------------------------------------------------
game proc USES EBX EDI ESI 

  CALL main_menu
  JMP @START_GAME

       ;START_GAME;
                                                           @START_GAME:
        @WHILE:  
         ;-------------



        JMP @WHILE
        ;--------------
 
   @RRET:
   RET
game endp
;------------------------------------------------------------------------------------------------------------------
main_menu proc USES EBX EDI ESI
 
    LOCAL hcons:DWORD
    LOCAL cho:DWORD
     
    ;---
    MOV hcons,rv(GetStdHandle,-11);STD_OUTPUT_HANDLE
    MOV cho,1
    ;---
    CALL ClearScreen
    
    @PRINT_MENU_1:
      fn locate,50,5
    print "* START"
      fn locate,50,10
    print "  CREATE"
      fn locate,50,15
    print "  EXIT"
    JMP @SKIP
    ;--
      @PRINT_MENU_2:
      fn locate,50,5
    print "  START"
      fn locate,50,10
    print "* CREATE"
      fn locate,50,15
    print "  EXIT"
    JMP @SKIP
    ;--
      @PRINT_MENU_3:
      fn locate,50,5
    print "  START"
      fn locate,50,10
    print "  CREATE"
      fn locate,50,15
    print "* EXIT"
    JMP @SKIP
    ;--
       ;--
       @SKIP:
       @CYCLE_1:
         
          CALL key_state_wait
           CMP KEY_STATE,13
           JE @END

          CMP EAX,'s'
          JNE @G
          
          INC cho  
          
          CMP cho,4
          JNE @ANAL
          DEC cho

          JMP @SKIP
          ;---------
          @G:
          CMP EAX,'w'
          JNE @ANAL
         
          DEC cho

          CMP cho,0
          JNE @ANAL
          INC cho
          ;---------
           @ANAL:
           CMP cho,1
           JE  @PRINT_MENU_1
            CMP cho,2
           JE  @PRINT_MENU_2
            CMP cho,3
           JE  @PRINT_MENU_3

      ;--END CYCLE
        JMP @CYCLE_1
        @END:
        cls
    ;--
    MOV EAX,cho
    CMP EAX,1
    JE @RRET
    CMP EAX,2
    JNE @skp1
    printf("NOT WORK")
    @skp1:
    fn ExitProcess,0

  @RRET:
  RET
main_menu endp
;------------------------------------------------------------------------------------------------------------------


;------------------------------------------------------------------------------------------------------------------