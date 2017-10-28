section .text
global _start
_start:
    ;execve(argv[], argv, NULL)
    xor ecx, ecx
    mul ecx
    push ecx
    push 0x0a4449
    push 0x5524206f
    push 0x6863655c
    push 0x6e69622f
    mov ebx, esp
    mov al, 11
    int 0x80

    xor eax, eax
    mov ebx, 1
    mov ecx, 0
    int 0x80
