;Allan Sur
;CS 237
;Project 4 First file

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE c:\Irvine\Irvine32.inc

GCD PROTO

.data
title1 BYTE "~Greatest Common Divisor Calculator~", 0
input1 BYTE "Please enter the first integer: ", 0
input2 BYTE "Please enter the second integer: ", 0
answer BYTE "The GCD of the two numbers is: ", 0

.code
main PROC

MOV edx, OFFSET title1	; move the address of the title1 BYTE into edx to prepare for display
CALL WriteString		; write the string
CALL CrLf				; we use two clear line calls in order to make a bit cleaner interface
CALL CrLf

MOV edx, OFFSET input1	; get edx ready to write string for the first integer input
CALL WriteString		; display the second input
CALL ReadDec			; I decided to use ReadDec since I figured that the input would only be unsigned integers
MOV ebx, eax			; take the input integer stored in eax and move it to ebx
PUSH ebx				; then we push ebx onto the stack so now the first integer is the first value in the stack

MOV edx, OFFSET input2	; prepare for displaying of the second integer input
CALL WriteString		; display the message
CALL ReadDec			; write the input integer into eax register
MOV ebx, eax			; move the second integer into ebx
PUSH ebx				; push the second integer into the second spot on the stack, so basically the second from the bottom of the stack and currently it is at the top of the stack

INVOKE GCD				; we use the INVOKE instruction to allow us to call the GCD procedure from the GCD file using the input values

MOV edx, OFFSET answer	; move the address of the answer string to EDX to prepare it for display
CALL WriteString		; display the answer string
CALL WriteDec			; display the value stored in eax, which is the greatest common divisor from the gcd method which was returned in loop1
CALL CrLf				; clear screen for spacing

EXIT

MAIN ENDP

END MAIN
