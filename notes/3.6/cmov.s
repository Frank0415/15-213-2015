	.file	"cmov.c"
	.text
	.globl	ter
	.type	ter, @function
ter:
.LFB0:
	.cfi_startproc
	cmpl	%esi, %edi
	jle	.L2
	movl	%edi, %eax
	subl	%esi, %eax
	ret
.L2:
	movl	%esi, %eax
	subl	%edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	ter, .-ter
	.ident	"GCC: (GNU) 15.1.1 20250729"
	.section	.note.GNU-stack,"",@progbits
