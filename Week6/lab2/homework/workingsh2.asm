<<<<<<< HEAD
section .text
global _start
_start:
    ;execve(argv[], argv, NULL)
    xor ecx, ecx
    mul ecx
    push ecx
    push 0x00000000
    push 0x44495524
    push 0x6f
    push 0x6863652f
    push 0x6e69622f
    mov ebx, esp
    mov eax, 11
    int 0x80

    xor eax, eax
    mov ebx, 1
    mov ecx, 0
    int 0x80
=======
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
>>>>>>> 7d179384374928ed8ecd8863049b0f866f9d010d
