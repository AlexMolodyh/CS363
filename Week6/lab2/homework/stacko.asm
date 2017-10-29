global _start

section .text
_start:


push   dword 0x64692f ; Push /sh
push   dword 0x6e69622f ; Push /bin
push   dword 0x7273752f
mov    eax, esp         ; Store Pointer To /bin/sh In EAX

push   dword 0x0000752d	 ; Push -c
mov    ebx, esp         ; Store Pointer To -c In EBX

push   dword 0x68
push   dword 0x64692f ; Push /sh
push   dword 0x6e69622f ; Push /bin
push   dword 0x7273752f
mov    ecx, esp         ; Store Pointer To /bin/bash In ECX

push   0                ; <----- NULL args terminator
push   ecx              ; Push /bin/bash Pointer
push   ebx              ; Push -c Pointer
push   eax              ; Push /bin/sh Pointer

mov    ebx, eax         ; Move /bin/sh Pointer To EAX
mov    ecx, esp         ; Store /bin/sh -c /bin/bash Pointer in ECX
xor    edx, edx         ; Store 0 In EDX
xor    eax, eax        ; <----- either xor eax, eax or mov into eax
mov    eax, 11          ; sys_execve
int    0x80             ; system call