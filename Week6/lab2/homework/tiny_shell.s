BITS 32

section .text
global _start

_start:
; execve(const char *filename, char *const argv [], char *const envp[])
  xor eax, eax      ; zero our eax

  push eax	    ; push some nulls for string termination
  push 0x752d	    ; push "-u" to the stack
  mov ebx, esp	    ; put address of "-u" into ebx from esp(stack)

  push eax          ; push some nulls for string termination
  push 0x64692f2f   ; push "//id" to the stack
  push 0x6e69622f   ; push "/bin" to the stack
  mov eax, esp      ; put the address of "/bin//id" into ecx, via esp
  
  push eax
  push ecx
  push ebx	    ; push ebx onto the stack
  push eax

  mov ebx, eax      ; move "bin/id" prt to ebx
  mov ecx, esp
  xor edx, edx

  mov al, 11        ; syscall #11
  int 0x80          ; do it
  ret
