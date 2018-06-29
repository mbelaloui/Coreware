.name "n ame"
.comment "comment"

	live	%2147483647
	ld		-42,r1
	ld		0,r2
	ld		1,r99
	ld		42,r2
	ld		%42,r99
	ld		%-42,r99
	st		r1,-42
	st		r1,42
	st		r1,r50
toi:	st		r2,r3
bonjour:
	add		r2,r5,r8
	sub		r2,r5,r8
	and		1,2,r5
	and		1,%2,r5
	and		%1,2,r5
	and		1,-2,r5
	and		-1,2,r5
	and		-1,-2,r5
	and		1,%2,r5
	and		%1,2,r5
	and		%-1,%-2,r5
	and		r1,2,r5
	and		1,r2,r5
	and		r1,r2,r5
	or		1,2,r5
	or		1,%2,r5
	or		%1,2,r5
	or		1,-2,r5
	or		-1,2,r5
	or		-1,-2,r5
	or		1,%2,r5
	or		%1,2,r5
	or		%1,r2,r5
	or		%-1,%-2,r5
	or		r1,2,r5
	or		2147483648,r2,r5
	or		r1,r2,r5
	zjmp	%42
	zjmp	%0
	zjmp	%-42
	ldi		3,%1,r5
	ldi		r3,%1,r5
	ldi		%3,%1,r5
	sti		r5,%2,%2
	sti		r5,%2,r2
	sti		r2,r2,r2
	fork	%4
	lld		-42,r1
	lld		0,r2
	lld		1,r99
	lld		42,r2
	lld		%42,r99
	lld		%-42,r99
	aff		r1
#	sti		%3,%1,r5
#	sti		%3,%1,r5
#	sti		%3,%1,r5
#	and		%+1,+%+2,r5
