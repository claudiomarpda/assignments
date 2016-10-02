global AndOperation
global OrOperation
global NegativeNumber
global NotOperation

segment .text

AndOperation:
	mov eax, edi
	and eax, esi
	ret

OrOperation:
	mov eax, edi
	or eax, esi
	ret

NegativeNumber:
	mov eax, edi
	not eax
	inc eax
	ret

NotOperation:
	mov eax, edi
	not eax
	ret