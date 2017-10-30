BITS 32

push   dword 0x64692f2f         ; Push /id
push   dword 0x6e69622f       ; Push /bin
push   dword 0x7273752f       ; push /usr
mov    eax, esp         ; Store ptr to /usr/bin/id in eax

push   word 0x752d	    ; Push -u
mov    ebx, esp         ; Store ptr to -u in ebx

xor edx, edx            ; NULL args terminator
push   edx              ; Push -u ptr
push   ebx              ; Push -u ptr
push   eax              ; Push /usr/bin/id ptr

mov    ebx, eax         ; Move /usr/bin/id ptr into ebx
mov    ecx, esp         ; Move /usr/bin/id ptr into ecx
xor    eax, eax         ; Zero out eax
mov    al, 11           ; sys_execve
int    0x80             ; system call