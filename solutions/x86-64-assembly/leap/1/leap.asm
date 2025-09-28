section .text
global leap_year
leap_year:
    ; Not leap if not divisible by 4
    xor     edx, edx
    mov     eax, edi
    mov     ecx, 4
    div     ecx
    cmp     edx, 0
    jne     is_false

    ; Leap if not divisible by 100
    xor     edx, edx
    mov     eax, edi
    mov     ecx, 100
    div     ecx
    cmp     edx, 0
    jne     is_true

    ; Not leap if not divisible by 400
    xor     edx, edx
    mov     eax, edi
    mov     ecx, 400
    div     ecx
    cmp     edx, 0
    jne     is_false

is_true:
    mov     eax, 1
    ret

is_false:
    xor     eax, eax
    ret