;Allan Sur
;CS 237
;Project 4 Second file

.386
.model flat,stdcall
.stack 4096
INCLUDE c:\Irvine\Irvine32.inc
.data


.code

GCD PROC							; start of the GCD procedure

	PUSH ebp						; we push ebp to establish the stack frame for the GCD program and to point to the top of the stack

	MOV ebp, esp					; you now move the value of esp, the stack pointer, into ebp in order to set the pointer to the top of the stack
	MOV eax, [ebp + 3 * TYPE ebx]	; in our case a 32 bit unsigned integer which was what was accepted through ReadDec is 4 Bytes we do 3 * 4 Bytes to get 12, which moves 3 down the stack and access our first input variable that was pushed 
	MOV ecx, [ebp + 2 * TYPE ebx]	; we then multiply 2 * type of ebx which gives us 8 which moves to the second position in the stack to access the second input integer
	CMP ecx, 0						; then we compare ebx, the second value, to 0 because if the inputed integer is 0 then that is the gcd of the two numbers
	
	JZ loop1						; if the zero flag is set, which means ebx was = 0, then we jump to loop1
	
	MOV edx, 0						; if the value is !=0, then we move 0 into the edx register in order to reset it for the remaineder of the next instruction
	DIV ecx							; we now divide eax by ebx and the remained for the division is sent into edx
	MOV eax, edx					; we now move the remainder back into eax to get ready for the next recursion call
	PUSH ecx						; push ebx back onto the stack 
	PUSH eax						; push eax, the remainder, back onto the stack for another call of the GCD procedure

	CALL GCD						; we now call GCD again, in order to make sure that we follow 



loop1:								; loop to return the procedures greatest common divisor
	
	POP ebp							; pop the start of the stack off of the stack
	MOV ecx, 1						; we reset ecx to one since we used it to hold the second integer for our divison and allow it to not return the answer more than once	
	RET [2 * TYPE ebx]				; we return the 8 because this is where eax is stored since we popped ebp out of the stack eax is now only 2 * type EAX away from the top of the stack rather than 3* and this is where the gcd is when the remainder of the algorithm is 0

LOOP loop1							; the end of this loop is basically the end of the GCD program meaning your greatest common divisor has been returned



GCD ENDP

Exit
END 