.data

arr_print proto           :DWORD,:DWORD    ;1 PTR ARR,   2 SIZE  ;
arr_getall_sum proto      :DWORD,:DWORD    ;1 ptr arr,  ;2 size	     | RET->	[EAX = SUM]
arr_find_max_value proto   :DWORD,:DWORD    ;1 ptr arr   ;2 size     | RET-> [EAX = VALUE]
arr_find_max_valueEx proto :DWORD,:DWORD    ;1 ptr arr   ;2 end_arr  | RET-> [EAX = VALUE]
arr_find_min_value proto   :DWORD,:DWORD    ;1 ptr arr   ;2 size     | RET-> [EAX = VALUE]
arr_find_min_valueEx proto :DWORD,:DWORD    ;1 ptr arr   ;2 end_arr  | RET-> [EAX = VALUE]



.code
;========================================================================================================================
arr_print proc uses EBX ESI EDI ,_arr_adr:DWORD ,_arr_size:DWORD 
  ;---
  MOV EDI, _arr_size
  MOV ESI, _arr_adr

  XOR EBX,EBX
  @FOR_1:
  ;--
  MOV EAX,DWORD PTR [ ESI + EBX * 4 ]
  printf("param in index %i = %i \n",EBX ,EAX  )
  ;--
  INC EBX
  CMP EDI,EBX     
  JNE @FOR_1
;--
 RET
arr_print endp 
;--------------------------------------------------------------------------------------------------------
arr_getall_sum proc uses EBX ESI EDI _arr_ptr:DWORD, _arr_size:DWORD
 
  XOR EAX,EAX
  ;----
  MOV ESI,_arr_ptr
  MOV EDI,_arr_size
  XOR ECX,ECX
  @FOR:

   ADD EAX,DWORD PTR[ESI+ECX*4]

  ;----
  INC ECX
  CMP ECX,EDI
  JNE @FOR

  ;----
  @@RET:
  RET
arr_getall_sum endp
;--------------------------------------------------------------------------------------------------------
arr_find_max_value proc uses EBX EDI ESI _arr_ptr:DWORD, _arr_size:DWORD
 
 MOV ESI,_arr_ptr
 MOV EDI,_arr_size

           XOR ECX,ECX
           MOV EAX,DWORD PTR[ESI]
           @FOR: 
            ;-
            INC ECX
            CMP ECX,EDI
            JGE @@RET
            ;-
              MOV EDX,DWORD PTR[ESI+ECX*4]
              CMP EDX,EAX
              JLE @FOR         
              MOV EAX,EDX
            JMP @FOR
 ;----
 @@RET:
 RET
arr_find_max_value endp
;--------------------------------------------------------------------------------------------------------
arr_find_max_valueEx proc uses EBX EDI ESI _arr_ptr:DWORD, _arr_end:DWORD
 
 MOV ESI,_arr_ptr
 MOV EDI,_arr_end
          ;*
           
           MOV EAX,DWORD PTR[ESI]
           @FOR: 
            ;-
            LEA ESI,DWORD PTR[ESI+4]  ;inc addr 4 
            CMP ESI,EDI
            JE @@RET
            ;-
              MOV EDX,DWORD PTR[ESI]
              CMP EDX,EAX
              JLE @FOR         
              MOV EAX,EDX
            JMP @FOR
           ;*
 ;----
 @@RET:
 RET
arr_find_max_valueEx endp
;--------------------------------------------------------------------------------------------------------
arr_find_min_value proc uses EBX EDI ESI _arr_ptr:DWORD, _arr_size:DWORD
 
 MOV ESI,_arr_ptr
 MOV EDI,_arr_size

           XOR ECX,ECX
           MOV EAX,DWORD PTR[ESI]
           @FOR: 
            ;-
            INC ECX
            CMP ECX,EDI
            JGE @@RET
            ;-
              MOV EDX,DWORD PTR[ESI+ECX*4]
              CMP EDX,EAX
              JGE @FOR         
              MOV EAX,EDX
            JMP @FOR
 ;----
 @@RET:
 RET
arr_find_min_value endp
;---------------------------------------------------------------------------------------------------------
arr_find_min_valueEx proc uses EBX EDI ESI _arr_ptr:DWORD, _arr_end:DWORD
 
 MOV ESI,_arr_ptr
 MOV EDI,_arr_end
          ;*
           
           MOV EAX,DWORD PTR[ESI]
           @FOR: 
            ;-
            LEA ESI,DWORD PTR[ESI+4]  ;inc addr 4 
            CMP ESI,EDI
            JE @@RET
            ;-
              MOV EDX,DWORD PTR[ESI]
              CMP EDX,EAX
              JGE @FOR         
              MOV EAX,EDX
            JMP @FOR
           ;*
 ;----
 @@RET:
 RET
arr_find_min_valueEx endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;--------------------------------------------------------------------------------------------------------














