SECTION .data
cmd    db    '/usr/bin/id', 0h ; Command to be run
arg1   db    '-u', 0h ; The argument for the command.
argv   dd    cmd ; Start struct for the arguments
       dd    arg1
       dd    0h ; end the struct for arguments
env    dd    0h ; empty struct for env vars

SECTION .text
global _start

_start:
    mov    edx, env
    mov    ecx, argv
    mov    ebx, cmd
    mov    eax, 11 ; SYS_EXECVE, opcode 0x0c
    int    80h

    mov    ebx, 0
    mov    eax, 1
    int    80h
    ret