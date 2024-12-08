; void inverse_colors(u_int8_t* pixel_data, int32_t data_size)
; pixel_data in %rdi, data_size in %rsi
global inverse_colors

section .data
  align 16 ; Align mask
  MaskIn db 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF

section .text
  inverse_colors:
    vmovdqa xmm0,[MaskIn]        ; Move values of MaskIN to register xmm0
    sar    rsi,4                 ; data_size /= 16
    mov    r8,0                  ; counter for the for loop. 
    mov    r9,0                  ; counter to advance in the array.
  
  .loop_for_inverse:
    cmp       r8,rsi             ; compares whether the counter has reached the value of data_size/16
    jge       .exit              ; if data_size/16 - i <= 0, exit the for. Else ...
    vmovdqa   xmm1,[rdi + r9]    ; Move pixel_data + i bytes of the pixel_data array %r8, (%rsi) 
    vpxor    xmm2,xmm0,xmm1     ; Add 10 to each byte of the pixels
    vmovdqa   [rdi + r9],xmm2    ; Modify the bytes of the data_pixel array.
    inc       r8                 ; ++i
    add       r9,16              ; Move to the next 16 bytes of the array.
    jmp       .loop_for_inverse              ; Return to beginning of loop.
  
  .exit:
      ret