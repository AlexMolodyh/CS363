%include "io.inc"

section .data
    mes db "Hello there", 0

section .text
global CMAIN
CMAIN:
    ;write your code here
    xor eax, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, mes
    mov edx, 12
    int 0x80
    
    ;exit
    mov eax, 1
    mov ebx, 0
    int 0x80