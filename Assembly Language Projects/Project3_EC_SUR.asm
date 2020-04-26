;Extra Credit
;Project 3
;Allan Sur
;Professor Arab
;TTH 17:30

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


INCLUDE c:\Irvine\Irvine32.inc

.data					;In .data i just initialized all of the messages that were gonna be output.

msg BYTE ": Your grade letter grade is: ", 0

msg2 BYTE "Diplaying 10 randomly generated grade values...", 0

msg3 BYTE "All 10 grades have been generated and displayed.", 0

.code

main PROC

call Randomize			; reset the randomize seed for libraries RandomRange
mov ecx, 10				; set the loop counter to 10 for the proper amount of grades to be generated
mov edx, OFFSET msg2	;set address of msg2 to edx
call WriteString		;Displayed msg2 through WriteString which uses edx
call CrLf				;spacing	
call CrLf				;spacing
loop1:					;loop to call calcGrade proc
	mov eax, 101		; moved 101 to give the random range (n-1) a range from 0 - 100
	call RandomRange	;called random range for the random unsigned integer between 0 - 100
	call calcGrade		;called calcgrade method
loop loop1				;end of loop
call CrLf				;spacing
mov edx, OFFSET msg3	;moved msg3 to edx to prepare for WriteString 
call WriteString		;displayed last message		
call Crlf				;spacing
ret						;returned
main ENDP				;end of program

calcGrade PROC			; initialized calcgrade procedure
pushad					;pushed registers onto the stack, this is to preserve the ecx because i was getting an infinite loop before
	CMP eax, 89			;compares eax, register where the randomRange value was stored
	JBE loop2			;jump if below or equal to eax
	CALL WriteDec		;if not Display the grade from eax register
	MOV al, 'A'			;moved A to al for WRiteChar command as specified
	MOV edx, OFFSET msg	; moved into edx address of msg to prepare for WriteString
	CALL WriteString	;display string
	CALL WriteChar		;display calculated letter grade
	JMP loopend			;jump to an empty loop that will allow the calcgrade to end

	;The same method is used below for all other letter grades except F, EXPLINATION @ Loop 5

loop2:
	CMP eax, 79
	Jbe loop3
	CALL WriteDec
	MOV al, 'B'
	MOV edx, OFFSET msg
	CALL WriteString
	CALL WriteChar
	JMP loopend
loop loop2

loop3:
	CMP eax, 69
	JBE loop4
	CALL WriteDec
	MOV al, 'C'
	MOV edx, OFFSET msg
	CALL WriteString
	CALL WriteChar
	JMP loopend
loop loop3

loop4:
	CMP eax, 59
	JBE loop5
	CALL WriteDec
	MOV al, 'D'
	MOV edx, OFFSET msg
	CALL WriteString
	CALL WriteChar
	JMP loopend
loop loop4

loop5:					;Since we're reached the point where the only thing they can score is an F as nothing is lower we just
	CALL WriteDec		;display the number grade
	MOV al, 'F'			;prepare for WriteChar
	MOV edx, OFFSET msg	;prepare for WriteString
	CALL WriteString	;display msg
	CALL WriteChar		;display letter grade
	JMP loopEnd			;jmp to end of program
loop loop5				;end of loop

loopEnd:
						;empty loop to allow the program to leave
loop loopEnd
popad					;pop the registers back to allow ecx to be decremented by loop1
	CALL Crlf			;spacing
	ret					;return
	calcGrade ENDP		;end of calcGrade procedure
ret						;return
END main				;end of entire program