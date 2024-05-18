NAME BUTTON_C

Public button

Rutina Segment code

Rseg Rutina

	button:
	clr p3.2
	clr p3.3
	jb p3.2, up
	jb p3.3, down
	sjmp final

	up:
	mov A, B
	cjne A, #0FEh, upfr
	sjmp final
	
	upfr:
	add A, #4
	mov B, A
	sjmp final
	
	down:
	mov A, B
	cjne A, #0, downfr
	sjmp final
	
	downfr:
	subb A, #4
	mov B, A
	sjmp final

	final:
		RET
end