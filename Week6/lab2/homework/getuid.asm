global _start

section .text
_start:
push   0x64692f         ; Push /id
push   0x6e69622f       ; Push /bin
push   0x7273752f       ; push /usr
mov    eax, esp         ; Store Pointer To /usr/bin/id In EAX

push   dword 0x752d	    ; Push -u
mov    ebx, esp         ; Store Pointer To -c In EBX

push   dword 0x0000752d
mov    ecx, esp         ; Store Pointer To -u

push   0x00             ; <----- NULL args terminator
push   ecx              ; Push -u Pointer
push   ebx              ; Push -u Pointer
push   eax              ; Push /usr/bin/id Pointer

mov    ebx, eax         ; Move /usr/bin/id Pointer To eax
mov    ecx, esp         ; Store /bin/sh -c /bin/bash Pointer in ecx
xor    edx, edx         ; Store 0 In edx
xor    eax, eax         ; zero out eax
mov    al, 11           ; sys_execve
int    0x80             ; system call