	.text
	.file	"test.s"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$10, 4(%rsp)
	movl	$0, (%rsp)
	movl	$20, %edi
	callq	imprimei@PLT
	movl	$10, %edi
	callq	imprimei@PLT
	movl	$7, (%rsp)
	movl	$7, %edi
	callq	imprimei@PLT
	movl	$6, (%rsp)
	movl	$6, %edi
	callq	imprimei@PLT
	movl	$4, (%rsp)
	movl	$4, %edi
	callq	imprimei@PLT
	movl	$10, (%rsp)
	movl	$10, %edi
	callq	imprimei@PLT
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
