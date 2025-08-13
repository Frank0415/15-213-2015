	.file	"128.c"
	.text
	.globl	store_uprod
	.type	store_uprod, @function
store_uprod:
.LFB0:
	.cfi_startproc
    # dest in %rdi, x in %rsi, y in %rdx
	movq	%rsi, %rax
	mulq	%rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi) # little endian -> "higher" part stores in later 8 bits
	ret
	.cfi_endproc
.LFE0:
	.size	store_uprod, .-store_uprod
	.globl	remdiv
	.type	remdiv, @function
remdiv:
.LFB1:
	.cfi_startproc
	movq	%rdi, %rax
	movq	%rdx, %r8
	cqto
	idivq	%rsi
	movq	%rax, (%r8)
	movq	%rdx, (%rcx)
	ret
	.cfi_endproc
.LFE1:
	.size	remdiv, .-remdiv
	.ident	"GCC: (GNU) 15.1.1 20250729"
	.section	.note.GNU-stack,"",@progbits
