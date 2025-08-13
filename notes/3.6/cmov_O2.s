	.file	"cmov.c"
	.text
	.p2align 4
	.type	ter, @function
# This is compiled under -O2, while most of the .s is compiled under -O0 or -Og.
ter:
.LFB0:
	.cfi_startproc
	movl	%edi, %edx
	movl	%esi, %eax
	subl	%esi, %edx
	subl	%edi, %eax
	cmpl	%esi, %edi
	cmovg	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	ter, .-ter	.globl	ter

	.ident	"GCC: (GNU) 15.1.1 20250729"
	.section	.note.GNU-stack,"",@progbits
