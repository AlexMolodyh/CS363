global _start

section .text
_start:


push   0x64692f ; Push /id
push   0x6e69622f ; Push /bin
push   0x7273752f ; push /usr
mov    eax, esp         ; Store Pointer To /usr/bin/id In EAX

push   0x0000752d	 ; Push -c
mov    ebx, esp         ; Store Pointer To -c In EBX

push   0x0000752d
mov    ecx, esp         ; Store Pointer To /bin/bash In ECX(now 0000)

push   0                ; <----- NULL args terminator
push   ecx              ; Push /usr/bin/id Pointer
push   ebx              ; Push -u Pointer
push   eax              ; Push /usr/bin/id Pointer

mov    ebx, eax         ; Move /bin/sh Pointer To EAX
mov    ecx, esp         ; Store /bin/sh -c /bin/bash Pointer in ECX
xor    edx, edx         ; Store 0 In EDX
xor    eax, eax        ; <----- either xor eax, eax or mov into eax
mov    eax, 11          ; sys_execve
int    0x80             ; system call