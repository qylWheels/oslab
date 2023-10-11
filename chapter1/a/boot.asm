	org	07c00h			; 告诉编译器程序加载到7c00处
	mov	ax, cs
	mov	ds, ax
	mov	es, ax
	mov cx, 5			; 打印字符串100次
PrintStr100times:
	mov ax, 5
	sub ax, cx
	push ax				; 将行号压栈
	call DispStr		; 调用显示字符串例程
	pop	ax				; 清栈
	loop PrintStr100times
	jmp	$				; 无限循环
DispStr:
	mov	ax, BootMessage
	mov	bp, ax			; ES:BP = 串地址
	mov	cx, 21			; CX = 串长度
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
	mov si, sp
	mov dh, byte [ss:si]		; 设置行号
	mov	dl, 0
	int	10h				; 10h 号中断
	ret
BootMessage:	db	"Hello, Zhihang Liang!"
times	510-($-$$) db 0	; 填充剩下的空间，使生成的二进制代码恰好为512字节
dw 0xaa55				; 结束标志
