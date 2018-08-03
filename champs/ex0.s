.name   "s"
.comment "ss"
  
bonjour:
aff 2

live1: live %5 
labe1: and %:live1,r3,r1
voila: or %-1,r3,r1
	ld :voila,r5
	ld 4,r5
	ld r18,r6
	ld r+8,r6
	ld r-8,r6
	ld r8,r6
	ld r0,r6
