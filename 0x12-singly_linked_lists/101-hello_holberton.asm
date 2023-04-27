section .data
    ; Define message string and format string
    message db 'Hello, Holberton', 0
    format db '%s', 10, 0

section .text
    global main
    extern printf

main:
    ; Push arguments for printf function call onto the stack
    push format
    push message
    ; Call printf function
    call printf
    ; Adjust the stack pointer to remove arguments
    ; Note: we use `sub` instead of `add` because we are subtracting from the stack pointer
    ; by pushing two values
    sub rsp, 16
    ; Return 0 to indicate successful execution
    mov eax, 0
    ret

