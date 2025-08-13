	.file	"cmp.c"
	.text
	.globl	cmp_more
	.type	cmp_more, @function
cmp_more:
.LFB0:
	.cfi_startproc
	cmpl	%esi, %edi
	setl	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	cmp_more, .-cmp_more
	.globl	cmp_more_1
	.type	cmp_more_1, @function
cmp_more_1:
.LFB1:
	.cfi_startproc
	cmpl	%esi, %edi
	setl	%al
	ret
	.cfi_endproc
.LFE1:
	.size	cmp_more_1, .-cmp_more_1
	.globl	cmp_more_2
	.type	cmp_more_2, @function
cmp_more_2:
.LFB2:
	.cfi_startproc
	cmpl	%esi, %edi
	jle	.L5
	movl	$114, %eax
	ret
.L5:
	movl	$514, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	cmp_more_2, .-cmp_more_2
	.ident	"GCC: (GNU) 15.1.1 20250729"
	.section	.note.GNU-stack,"",@progbits
