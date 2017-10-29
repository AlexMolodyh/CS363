bash section .text
global _start
_start:
    ;execve(argv[], argv, NULL)
    xor ecx, ecx
    mul ecx
    push ecx
    push 0x20204449
    push 0x5524006f
    push 0x6863652f
    push 0x6e69622f
    mov ebx, esp
    mov eax, 11
    int 0x80

    xor eax, eax
    mov ebx, 1
    mov ecx, 0
    int 0x80