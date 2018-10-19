.name "itest_name"
.comment "itest_comment"

#st, ld, lld, add, and, xor, or, ldi

#st	r2,r1
#st	r1,-64
#st	r1,0
#st	r1,64
#st	r1,r2
#    ld	0,r2
#st	r2,0
#st	r2,64

#lld	%2123456789,r2
#st	r1,6

#live %55
#lld	0,r2
#st	r2,64

#lld	-5,r2
#st	r2,64

#lld	%1,r2
#st	r2,64

#ld	%0,r2
#st	r2,64

#ld	%-5,r2
#st	r2,64
#and 2,3,r2

#ld	1,r2
#ld	2,r3
#ld	3,r4

#add r2,r3,r4
#and r2,r3,r4
#or r2,r3,r4
#xor r2,r3,r4

#st	r2,64
#st	r3,64
#st	r4,64

#zjmp %-64

#ld	1,r2
#zjmp %-4
#ld	2,r3
#zjmp %4

#st	r1,64
#sub r2,r3,r4
#st	r1,64

#ldi	0,%0,r2
#st	r2,64

#ldi	0,%1,r2
#st	r2,64




#ldi	3,%4,r2
#st	r2,64

#add r2,r3,r4

#zjmp %12

#ldi	9,%50,r2
#st	r1,64

#zjmp %32



#ldi	0,%3,r2
#ldi 4,%8,r2
#ldi	6,%1,r2
#ldi	6,%2,r2
#ldi	,%15,r2
#ldi	,%1,r2
#ldi	,%2,r2
#ldi	,%3,r2

#st	r1,64

#add r2,r3,r4


#zjmp %-32
#ld	8,r2
#zjmp %-64
#ld  9,r3
#zjmp %-64


#st	r3,64
#st	r2,64

#ldi	r2,r3,r2
#zjmp %64
#ldi  r2,r3,r2
#zjmp %64

#ld  9,r2
#ld  5,r3


#st	r4,64


#ld	10,r2
#st	r2,64
#ld	1,r3
#st	r3,64


#ldi	r2,%0,r7
#ldi	r2,%1,r7
#ldi	r2,%2,r7
#ldi	r2,%3,r7ldi	r2,%4,r7
#ldi	r2,%4,r7
#ldi	r2,%5,r7
#ldi	r2,%0,r7

#ld  %0,r3
#ld  %0,r2

#add r2,r3,r4
#and r2,r3,r4
#or r2,r3,r4
#sub r2,r3,r4
#xor r2,r3,r4


#ldi %6,%1,r1
#zjmp %64
#st	r1,-64

#fork	%512

#ldi 9,%1,r1
#zjmp %64
#st	r1,-64

#ldi %64,%0,r1
#st	r1,64
#zjmp %64

#lld -2,r1
#st	r1,64
#zjmp %64

#lld %12,r1
#st	r1,64
#zjmp %64

#st	r2,64
#st	r3,64
#st	r4,64
#zjmp %-64
#zjmp %-64
#zjmp %-64
#zjmp %-64
#zjmp %-64
#zjmp %-64
#zjmp %-64


#fork     %128

#lldi	%-10,%-10,r2

#st		r2,64
#ldi		%1,r2
#zjmp	%-64
#st		r1,64
#st		r2,64
#st		r3,64

#ld		%0,r2
#and		r1,r1,r3
#and		r1,r1,r3
#or		r1,r1,r3
##sub		r1,r2,r3
#xor		r1,r2,r3
#zjmp	%-64

#st		r1,64
#st		r2,64
#st		r3,64

#or		r2,r2,r3
#sub		r2,r2,r3
#xor		r2,r2,r3
#and		r1,r1,r3
#zjmp	%-64


#zjmp	%-1024
#zjmp	%-512

#live	%0
#live	%1
#live	%2
#live	%3


st r1,6
live %4
#lld -45,r3

#st r3,64
#fork %64
