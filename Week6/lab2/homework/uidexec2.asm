section .text
global _start
_start:
    ;execve(argv[], argv, NULL)
    xor ecx, ecx
    mul ecx
    push ecx
    push 0x0a444955
    push 0x24206f68
    push 0x63655c5c
    push 0x6e69622f
    mov ebx, esp
    mov al, 11
    int 0x80

    xor eax, eax
    mov ebx, 1
    mov ecx, 0
    int 0x80
