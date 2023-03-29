default rel

%macro nextSint 2
xor %1, %1
mov %2, 1
%%loop1:
movzx eax, byte [rsi]
inc rsi
cmp eax, '-'
je %%minus
sub eax, '0'
cmp eax, 9
ja %%loop1
jmp %%loop2

%%minus:
sub %2, 2
movzx eax, byte [rsi]
sub eax, '0'
inc rsi

%%loop2:
lea %1, [%1*5]
lea %1, [rax+%1*2]
movzx eax, byte [rsi]
inc rsi
sub eax, '0'
cmp eax, 9
jbe %%loop2

imul %1, %2
%endmacro


%macro printSint 1
mov rcx, %1
cmp rcx, 0
jge %%next
mov byte [rsi], '-'
inc rsi
neg rcx
%%next:
push 0

%%loop1:
mov rdx, -3689348814741910323
mov rax, rcx
mul rdx
shr rdx, 3
lea rax, [rdx*5]
neg rax
lea rcx, [rcx+rax*2+'0']
push rcx
mov rcx, rdx
test rcx, rcx
jnz %%loop1
pop rdx

%%loop2:
mov [rsi], dl
inc rsi
pop rdx
test rdx, rdx
jnz %%loop2
%endmacro


section .bss
buf: resb 8388608
buf_len: equ $-buf
resb 131072
exist: resb 131072

section .text
global main
main:

xor eax, eax
xor edi, edi
lea rsi, [buf]
mov rdx, buf_len
syscall
lea rdi, [exist]

nextSint rcx, r8
.loop:
nextSint rdx, r8
bts [rdi], rdx
loop .loop

lea rsi, [buf]
mov r8, -1000000
mov r9, 1000001

.loop2:
bt [rdi], r8
jnc .skip
printSint r8
mov byte [rsi], 10
inc rsi
.skip:
inc r8
cmp r8, r9
jne .loop2

mov rdx, rsi
lea rsi, [buf]
sub rdx, rsi
mov rax, 1
mov rdi, 1
syscall

mov rax, 231
xor edi, edi
syscall
