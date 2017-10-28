section .text
global _start
_start:
    xor eax, eax    ;write your code here
    mov eax, 24
    int 0x80
    POP ecx         ;get uid
    xor eax, eax
    mov eax, 4
    mov ebx, 1
    mov edx, 2
    int 0x80
    mov eax, 1      ;exit
    mov ebx, 0
    int 0x80