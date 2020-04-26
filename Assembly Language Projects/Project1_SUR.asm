;Allan Sur 
; CS237 TTH 5:30 Professor Arab
;Project 1
.386
.model flat,stdcall
.stack 4096

ExitProcess proto,dwExitCode:dword

INCLUDE C:\Irvine\Irvine32.inc

INCLUDELIB C:\Irvine\Irvine32.lib

INCLUDELIB C:\masm32\lib\Kernel32.lib

.DATA

Ar1 DWORD 5d,10d,15d,20d,25d,30d,100d,200d

.CODE

	main PROC

		MOV esi, 0						;first we set the esi pointer to 0
		MOV edi, SIZEOF ar1-TYPE ar1	;by doing this sub of edi, we get the edi pointer to point to the end of the ar1 array.
		MOV ecx, LENGTHOF ar1/2			;dividing the length of ar1 by 2 and setting it to the counter register ECX for the upcoming loop

		loop1:
			MOV edx, ar1[edi]			; first, we add the last element of the array ar1 into the register edx
			MOV eax, ar1[esi]			;then we move the first element of the array ar1 into the eax register.
			XCHG eax, edx				; by doing this, we exchange the value in eax with the value in edi and vice versa
			MOV ar1[esi], eax			; move the last element of the array into the first space on the array ar1
			MOV ar1[esi], edx			; move the first element of the array ar1 into the last spot of the array.
			DEC edi						; decrementing the edi by 1 so that the pointer will continue all the way though the array
			INC esi						; increasing the esi by 1 so that the pointer will go all thebway through the list
		LOOP loop1

		MOV ecx, LENGTHOF ar1			; resetting the ECX so that it will run again for the correct number of times for this next loop
		MOV esi, OFFSET ar1				; sends the address of ar1 to the esi pointer resetting it again for this next loop

		loop2:
			MOV eax, [esi]				;we now move the element located in the esi location to eax so that it may be displayed by dumpmems
			ADD esi, TYPE ar1			; increasing the esi so that it will continue to be the correct address for retrieving the next number in the array,
			CALL DumpMem				; using one of Irvine32.inc's dumpmem method in order to print out the reversed array as asked for by Professor Arab
		LOOP loop2

		EXIT

	MAIN ENDP

END main
