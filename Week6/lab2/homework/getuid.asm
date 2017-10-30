push   0x64692f         ; Push /id
push   0x6e69622f       ; Push /bin
push   0x7273752f       ; push /usr
mov    eax, esp         ; Store ptr to /usr/bin/id in eax

push   0x752d	        ; Push -u
mov    ebx, esp         ; Store ptr to -u in ebx

push   0x752d           ; Push -u
mov    ecx, esp         ; Store ptr to -u

push   0x00             ; NULL args terminator
push   ecx              ; Push -u ptr
push   ebx              ; Push -u ptr
push   eax              ; Push /usr/bin/id ptr

mov    ebx, eax         ; Move /usr/bin/id ptr into ebx
mov    ecx, esp         ; Move /usr/bin/id ptr into ecx
xor    eax, eax         ; Zero out eax
mov    al, 11           ; sys_execve
int    0x80             ; system call