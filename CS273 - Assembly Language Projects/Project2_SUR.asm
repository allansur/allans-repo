 .386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

include Irvine 32.inc
	;path 

.data
fibAr dword 30 DUP(?)
	;fibAr -  array
	;30 elements in the array
	;uninitialized array

.code
fib PROC
;fib - fibbonacci code

	mov fibAr, 1
	mov fibAr+4, 1
	mov esi, OFFSET fibAr+8
		;location of array in memory
		;move offset into source index ( beginning of array)
	mov ecx, 30
		;move size of array 30 into ecx

l1:

	mov eax, [esi-8]
		;move [esi-8] to eax
		; edx of ebx
	add eax, [esi-4]
		;add [esi-4] to eax
	mov [esi], eax
		;move eax into esi
		; esi now holds what eax was holding
	add esi, 4
		;add 4 to esi
	loop l1

	RET
		;puts the top of the stack into EIP

fib endp

main proc 
	
	mov ecx, LENGTHOF fibAr
	mov esi, OFFSET fibAr

call fib
;call fib code

	mov ecx, LENGTHOF fibAr
	;move length of array into ecx
	mov esi, OFFSET fibAr
	;move fibAr into esi
	mov ebx, TYPE fibAr
	;move type of array to ebx

	call DumpMem

invoke ExitProcess,0

main endp
end main
