;Allan Sur
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
INCLUDE c:\Irvine\Irvine32.inc

BufSize = 80												;this is the bufsize of the string

.data

   title1 BYTE "Encryption and Decryption Program", 0				;title message
   prompt1 BYTE "Please write a string to be encrypted.", 0			;Input message 1
   alert1 BYTE "This message is being encrypted", 0					;alert that the message is being encrypted
   alert2 BYTE "This string has been encrypted:  ", 0				;progress alert of the encryption
   fin BYTE "This string has been decrypted:  ", 0					;finished message
   key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6						;IMPORTANT: This is the key that will be used to encrypt and decrypt the input strings
   buffer BYTE BufSize DUP(?),0,0									;this is our buffer that we have to make for the incoming string
   stdInHandle HANDLE ?												;this is our standard input handle
   bytesRead DWORD ?												;this is the size of the string that will be input which is why it is unknown before the input is given

.code
main PROC

	MOV edx, OFFSET title1		;prepare edx for write string of the title
	CALL WriteString			;displays the title
	CALL CrLf					;formatting

	MOV edx, OFFSET prompt1		;prepares to display ask for user input
	CALL WriteString			;displays message asking for user input
	CALL CrLf					;formatting

	INVOKE GetStdHandle, STD_INPUT_HANDLE	;here we invoke the get standard handle instruction and use the standard input handle to read our string
	MOV stdInHandle,eax						;move the string given to us from EAX nto stdinhandle
	
	INVOKE ReadConsole, stdInHandle, ADDR buffer,	;here we read the characters input that was input to the console input buffer and remove it from the buffer
	BufSize, ADDR bytesRead, 0  ;it also reads the string length, bytesread, and string pointer, ADDR buffer, and the 0 is to let it know when to stop reading.

	MOV edx, OFFSET buffer		;we now move the address of the buffer into edx
	MOV ecx, BufSize			;we then move the string length, BufSize into ecx to give our loops the correct amount of times to rotate in order to encrypt/decrypt the whole string
	MOV ebx, 0					;we then move 0 into the ebx register to get it set for encryption as having it at 1 would decrypt the message before it was encrypted
	CALL encDecrypt				;call our encryption/decryption method
	CALL WriteString			;call WriteString after the string has been encrypted and it will now display the encrypted string
	CALL Crlf					;formatting
	
	MOV ebx, 1					;now we move 1 into ebx, this signals our loop inside the encDecrypt procedure to decrypt the passed string
	CALL encDecrypt				;call our decryption method
	CALL WriteString			;write the decrypted string
	CALL CrLf					;formatting

INVOKE ExitProcess,0			;end of project
main ENDP

encDecrypt PROC				;beginning of our encryption/decryption program			

   pushad					;push all of the 32 bit registers onto the stack

   CMP ebx, 0				;compare ebx with 0, if it is 0 we rotate left for encryption and if it is 1 we rotate right for decryption
	JZ encryption			;if ebx is = 0 then we jump to the 
		MOV ebx, esi		;we then move the value of the stack pointer into ebx
		ADD ebx, LENGTHOF key	;add 9, or the LENGTHOF key, since we are trying to encrypt the first 10 bits
		
		decryption:			;start the decryption loop if the ebx is not set to 0

			MOV al, [edx]	;we then move the contents stored in edx, the value of the text, into the al register
			PUSH ecx		;push the ecx register onto the stack
			MOV cl, [esi]	;move the value of the key, esi, into CL
			ROR al, cl		;then we rotate right the value located at AL the same amount of times as the value in CL
			MOV [edx], al	;we then move al back into the edx spot that 
			POP ecx			;we then pop the ecx register back out of the stack
			CMP esi, ebx	;here we compare esi to ebx to make sure all keys are used, and if they are we reset the offset of the key so that it uses the beginning again
			JE r1			;jump if equal to reset1
			INC esi			;increase the ESI by 1
			JMP endR1		;jump to endR1
			r1:

				SUB esi, 9	;subtract 9 from the esi to bring us back to the beginnning of the key
				endR1:

				INC edx		;increase the edx by 1

		loop decryption		;end of decryption loop
		
		MOV edx, OFFSET fin	;move the offset of the finished message into edx to prepare for WriteString
		
		CALL WriteString	;display finished message
		
		JMP endPROG			;jump to the end of the program in order to exit out of it


   encryption:				;this is where we jump to when the ebx = 1 which means encrypt and rotate left
      
	  MOV ebx, esi			;move the pointer into ebx
      ADD ebx, LENGTHOF key			;we then add 9 to ebx since we want the first 10 bytes and we already have a 1 in ebx
      
	  encrypt:				;beginning of our encryption process

		MOV al, [edx]		;move the value of the input string into the al register
		PUSH ECX			;push ecx onto the stack
		MOV cl, [esi]		;move the value of the key into the CL register
		ROL al, cl			;we rotate left the amount of times to al as the value of cl
		MOV [edx], al		;move the encrypted value of the text in AL back into the same spot it was taken from at edx now encrypting it
		POP ecx				;pop ecx out of the stack

		CMP esi, ebx		;same idea as before, if all of the keys have been used the ESI and EBX values are now the same and if so the program must be reset in order to start encrypting from the first key again
		JE r2				;jump if equal to r2 or reset 2 in order to reset the key
		INC esi				;increase the esi by 1
      
		JMP endR2			;jump to the endR2 loop
		r2:					;beginning of reset 2
		
		SUB esi, 9			;subtract 9 from the esi to reset the key value back to the first value in the key
		
		endR2:				;beginning of the endReset2 loop

		INC edx				;increase edx by 1 to continue onto the next part of the string

		loop encrypt		;end of the encryuption loop

	MOV edx, OFFSET alert2	;set edx to the address of alert 2 to show that it has been encrypted
	CALL WriteString		;display the messagfe has been encrypted
	endProg:				;end of program loop

		popad				;pop all of the registers that were pushed in the beginning off of the stack
		RET					;return

	 loop endProg

encDecrypt ENDP				;end of encryption/decryption program

END main
