;Project #3 Part 1 
;Allan Sur.
;Professor Arab TTH 17:30

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE c:\Irvine\Irvine32.inc

.data

msg1 BYTE "Enter the first hexadecimal integer: ", 0			;Created the first message asking for input

msg2 BYTE "Enter the second hexadecimal integer: ", 0			;Second msg asking for input

answer BYTE "The answer is = ", 0	;Answer msg prompt before the answer is shown

msg BYTE "Hexadecimal Boolean Caculator", 0dh, 0ah			;First, created a message to be the title of the program that will show

	BYTE 0dh,0ah						;clear space then the table will display
	BYTE "1. X AND Y", 0dh, 0ah			;Option 1 AND
	BYTE "2. X OR Y", 0dh, 0ah			;Option 2 Or
	BYTE "3. NOT X", 0dh, 0ah			;Option 3 NOT
	BYTE "4. X XOR Y", 0dh, 0ah			;Option 4 XOR
	BYTE "5. Exit the Program", 0		;Option 5 Exit, if we set the addresses at the end to the same as the others we get a weird error therefore it has to be 0


cT	BYTE '1'					; Start of the casetable from 6.5.4 that needs to be used for selection, lookup value 1
		DWORD AND_Op			;Address of the procedure				

	entrySize = ($ - cT )		;entry size of the table

	BYTE '2'					;lookup val 2
		DWORD OR_Op				;address for OR_Op
	BYTE '3'					;lookup val 3
		DWORD NOT_Op			;address for NOT_Op
	BYTE '4'					;lookup val 4
		DWORD XOR_Op			;address for XOR_Op
	BYTE '5'					;lookup val 5
		DWORD exitProg			;address of exit procedure

entryList = ($ - cT) / entrySize	;This is basically the number of entries

.code

main PROC					;start of the main procedure
	CALL Clrscr				;spacing
Menu:						;for the menu

	MOV edx, OFFSET msg		;move the address of msg into edx to prepare for WriteString
	CALL WriteString		;Write the string, basically the entire menu at this point with the title
	CALL Crlf				;more spacing

Input:						;start the input

	CALL ReadChar			;read whatever value is input for the menu selection
	CMP al, '5'				;compare that input to 5 due to us only having 5 chocies
	JA Input				;jump if above the value of 5 to Input again
	CMP al, '1'				; if the value is not above 5, then we compare the same value with 1
	JB Input				; if it is below we start input again for a valid value
	CALL Crlf				;spacing
	CALL chosenOperation	;if the value is within 1 and 5, including 1 and 5, we call our chosenOperation procedure
	JC quit					;we jump to quit if the carry flag is set
	CALL Crlf				;spacing
	JMP Menu				;jump back ot menu when the operation is done and we are now restarting the whole program to do another input

quit: exit					;this is just to exit the program

MAIN ENDP					;end of main procedure

chosenOperation PROC		;chosenOperation Procedure start
	
	PUSH ecx					;move ecx onto the stack
	PUSH ebx					;move ebx onto the stack
	MOV ecx, entryList			;move the value of entrylist onto the register ebx
	MOV ebx, OFFSET cT			;move the value address of the case table onto the register ebx


loop1:			

	CMP al, [ebx]				; first we compare al, our given input value, to the value in the address at ebx
	JNE loop2					;we jump to loop 2 if the value are not equal
	CALL NEAR PTR [ebx + 1]		;if the value is equal to al, we call the procedure that with the same set value
	JMP loop3					; then we jump to loop 3

Loop2:    

	ADD ebx, entrySize			;we add the entrysize to ebx in order to point to the next input
	LOOP loop1					; we end loop 1

LOOP loop2						;end loop 2

Loop3:   
	
	POP ecx						;we pop ecx out from the stack
	POP ebx						;we pop ebx out from the stack

RET								;return out of the procedure

loop loop3						;end loop3

chosenOperation ENDP			;end of chosenOperation procedure and end of the selection process

NOT_Op PROC						;I decided to start with the not operation because it was one step easier

	PUSHAD						;push all 32 bit registers onto the stack
		
		MOV edx, OFFSET msg1		;move the address of p1 into edx to prepare for WriteString
		CALL WriteString		;display
		CALL ReadHex			;read user input value of hexadecimal digit
		MOV edx, OFFSET answer	;mov address of the answer string into edx to prepare to display again
			NOT eax					;here the actual calculation is made and the value input is NOT
		CALL WriteString		;Write answer string
		CALL WriteHex			;Write new hex value after NOT operation
		CALL CrLf				;spacing

	POPAD						;pop all the registers off of the stack

RET								;return out of the procedure

NOT_Op ENDP						;end of NOT operation

AND_Op PROC					;AND operation beginning

	PUSHAD					;push 32 bit registers onto the stack

		MOV edx, OFFSET msg1	;move address of first message into edx
		CALL WriteString	;display p1
		CALL ReadHex		;read the given input hexadecimal value
		MOV edx, OFFSET msg2	;sets edx to address of the second message p2
		MOV ebx, eax		;move eax into the ebx register to allow it to be stored and get read for the next input
		CALL WriteString	;display p2
		CALL ReadHex		;puts the newley input value into eax so now we have a value in eax and ebx
			AND ebx, eax		;AND operation on the two values
		MOV edx, OFFSET answer	;get the edx register ready with the address for the answer string
		CALL WriteString	;display
		MOV eax, ebx		;move the AND value of both eax and ebx into EAX to prepare for the dispaly
		CALL WriteHex		;display the value in eax, the calculated value
		CALL CrLf			;spacing

	POPAD					;pop all registers off of the stack

RET							;returns from the procedure

AND_Op ENDP					;end of AND operation

OR_Op PROC					;start of the OR operation

	PUSHAD					;pushes registers onto the stack

		MOV edx, OFFSET msg1	;prepares the 1st message for display by passing the address to edx
		CALL WriteString		;display
		CALL ReadHex			;reads user input
		MOV edx, OFFSET msg2	;preps edx for second message asking for input 
		MOV ebx, eax			;stores input into ebx register
		CALL WriteString		;display
		CALL ReadHex			;reads second input
			OR ebx, eax				;OR OPERATION on saved ebx value and eax
		MOV eax, ebx			;move the now calculated EBX value into eax for display
		MOV edx, OFFSET answer	;moves the address of the answer message into edx for display
		CALL WriteString		;display
		CALL WriteHex			;display
		CALL CrLf				;spacing

	POPAD						;pops registers out from the stack (all 32 bit registers)

RET								;returns out of the proc
			
OR_Op ENDP						;end of the OR operation

XOR_Op PROC						;Start of the XOR operation

	PUSHAD						;push the registers onto the stack

		MOV edx, OFFSET msg1	;give edx the address of the string 1 that will ask for the input
		CALL WriteString		;display
		CALL ReadHex			;read user input
		MOV edx, OFFSET msg2	;gets edx ready for the second msg asking for the second input
		MOV ebx, eax			;stores input into ebx register to let eax be ready for the next input
		CALL WriteString		;display
		CALL ReadHex			; reads input and sets it to eax
			XOR ebx, eax			;XOR operation
		MOV eax, ebx			;store new value of the operation back into eax for display
		MOV edx, OFFSET answer	;sets edx ready for display of the answer string
		CALL WriteString		;display
		CALL WriteHex			;display
		CALL CrLf				;spacing

	POPAD						;pop the registers off of the stack

RET								;returns out of the proc

XOR_Op ENDP						;end of the XOr operation

exitProg PROC					;exitProgram operation 
	stc							;sets the carry flag to allow the input to know when to quit when '5' is selected
	ret							;is blank as to allow it to just exit the program
exitProg ENDP

       RET						;return out of exitProg
				
END MAIN						;end of the project