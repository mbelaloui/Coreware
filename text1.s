.name "1"
.comment "1"

#st	r2,r1
#st	r1,-64
#st	r1,0
#st	r1,64
#st	r1,r2
#    ld	0,r2
#st	r2,0
#st	r2,64

ld	1,r2
st	r2,64


ld	0,r2
st	r2,64


ld	-5,r2
st	r2,64


    
ld	%1,r2
st	r2,64


ld	%0,r2
st	r2,64


ld	%-5,r2
st	r2,64