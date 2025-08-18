	.file	"struct.c"
	.text
	.globl	example_arr
	.type	example_arr, @function
example_arr:
.LFB11:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$64, %edi
	call	malloc@PLT
	movq	$10, 16(%rax)
	movb	$65, 24(%rax)
	movl	$10, 32(%rax)
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	example_arr, .-example_arr
	.ident	"GCC: (GNU) 15.1.1 20250729"
	.section	.note.GNU-stack,"",@progbits
