.DATA

  
  _masif dd 1,2,3,4,5,6,7,8,9
  _size_masif dd $ - _masif


.CODE
;------***************************************** proto func 
learn proto ;NULL (main)

arr_print proto :DWORD,:DWORD      ; 1[ARR_SIZE] : *2[ADR MASIVA]  ;

;_______________________________________________________________________________________________________
learn proc uses EBX ESI EDI

    mov ESI,_size_masif    ;типа разделить байты чтоб неайти размер по 4байт
    shr ESI,2
      ;---
       fn arr_print , offset _masif,ESI
      
      fn arr_getall_sum, offset _masif, ESI
      printf("%i arr sum \n",EAX)

      fn arr_find_max_value, offset _masif, ESI
      printf("%i max value \n",EAX)


      ;---


;--
 RET
learn endp 
;_______________________________________________________________________________________________________

