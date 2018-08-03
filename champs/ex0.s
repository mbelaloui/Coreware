.name   "s"
.comment "ss"
  
bonjour:
aff r2

live1: live %5 
labe1: and %:live1,r3,r1
voila: or %-1,r3,r1
	ld :voila,r5
	ld 4,r5
#	ld r1,r6
#	ld r+8,r6
#	ld r-8,r6
#	ld r8,r6
#	add %:live1,r3,r1
	add r7,r3,r1
#	ld r0,r6
