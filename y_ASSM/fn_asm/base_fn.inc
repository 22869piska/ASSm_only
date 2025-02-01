.DATA

  
  _masif dd 1,8,2,3,5,0,4,6,9
  _size_masif dd $ - _masif


.CODE
;------***************************************** proto func 
learn proto ;NULL (main)

arr_print proto :DWORD,:DWORD      ; 1[ARR_SIZE] : *2[ADR MASIVA]  ;

;_______________________________________________________________________________________________________
learn proc uses EBX ESI EDI
    
    LEA EBX,_masif
    mov ESI,_size_masif    ;типа разделить байты чтоб неайти размер по 4байт
    shr ESI,2
      ;---
       fn arr_print , offset _masif,ESI
      
      fn arr_getall_sum, EBX, ESI
      printf("%i arr sum \n",EAX)

      fn arr_find_max_value, EBX, ESI
      printf("%i max value \n",EAX)
     
      fn arr_find_max_valueEx, EBX, offset _masif+16
       printf("%i max value EX \n",EAX)

        fn arr_find_min_value, EBX, ESI
      printf("%i MIN value \n",EAX)

       fn arr_find_min_valueEx, EBX, offset _masif+16
       printf("%i MIN value EX \n",EAX)

      ;---


;--
 RET
learn endp 
;_______________________________________________________________________________________________________

