.name   "s"
.comment "ss"
  
bonjour:
aff r1

live1: live %:voila

labe1: and %:voila,r3,r1
voila: or %:voila,r3,r1
voila:	ld :voila,r5
voila:	ld 4,r5
	add r7,r2,r1 
voila:	ld :voila,r5
	add r10,r6,r7
	sti r1,r3,%:voila
