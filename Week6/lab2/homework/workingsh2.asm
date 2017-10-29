section .text
global _start
_start:
    ;execve(argv[], argv, NULL)
    xor ecx, ecx
    push 0x44495524
    mov ecx, esp
    push 0x006f
    push 0x6863652f
    push 0x6e69622f
    mov ebx, esp
    mov eax, 11
    int 0x80

    xor eax, eax
    mov ebx, 1
    mov ecx, 0
    int 0x80
