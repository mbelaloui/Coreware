.name "1"
.comment "1"

#st, ld, lld, add, and, xor, or, 

#st	r2,r1
#st	r1,-64
#st	r1,0
#st	r1,64
#st	r1,r2
#    ld	0,r2
#st	r2,0
#st	r2,64

lld	%2123456789,r2
st	r2,64


lld	0,r2
st	r2,64


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




#sub r2,r3,r4
