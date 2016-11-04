BITS 32													; Tell nasm this is 32-bit code

jmp short one										; Jump down to a call at the end

two:
; ssize_t write(int fd, const void *buf, size_t count);
pop ecx													; Pop the return address (string ptr) int ecx.
xor eax, eax										; Zero out full 32 bits of eax register
mov al, 4												; Write syscall #4 to the low byte of eax
xor ebx, ebx										; Zero out ebx
inc ebx													; Increment ebx to 1, STDOUT file descriptor
xor edx, edx										; Zero out edx
mov dl, 15											; Length of string
int 0x80												; Do syscall: write(1, string, 15)

; void exit(int status);
mov al, 1												; Exit syscall #1, the top 3 bytes are still zeroed
dec ebx													; Decrement ebx back to 0 for status = 0
int 0x80												; Do syscall: exit(0)


one:
call two												; Call below the string to instruction
db "Hello, world!", 0x0a, 0x0d	; with newline and carriage return bytes.
