; void increment_saturation(u_int8_t* pixel_data, int32_t data_size)
; pixel_data in %rdi, data_size in %rsi
global increment_saturation

section .data
  align 16 ; Align mask
  Mask10 db 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF ; Create mask

section .text
  increment_saturation:
      vmovdqa xmm0,[Mask10]        ; Move values of Mask10 to register xmm0
      sar    rsi,4                 ; data_size /= 16
      mov    r8,0                  ; counter for the for loop. 
      mov    r9,0                  ; counter to advance in the array.

  .loop:                           ; for (int i = 0; i <= data_size/16; ++i)
      cmp       r8,rsi             ; compares whether the counter has reached the value of data_size/16
      jge       .exit              ; if data_size/16 - i <= 0, exit the for. Else ...
      vmovdqa   xmm1,[rdi + r9]    ; Move pixel_data + i bytes of the pixel_data array %r8, (%rsi) 
      vpmaxsb    xmm2,xmm0,xmm1    ; Maximize packed signed integers
      vmovdqa   [rdi + r9],xmm2    ; Modify the bytes of the data_pixel array.
      inc       r8                 ; ++i
      add       r9,16              ; Move to the next 16 bytes of the array.
      jmp       .loop              ; Return to beginning of loop.

  .exit:
      ret