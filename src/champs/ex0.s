.name   "s"
.comment "ss"
  
#bonjour:

aff r1
live %4
#live 4
#live r4
#live1: live %4#:voila

ld 4,r5
voila:	ld :voila,r5
#/*voila:*/	
ld %42,r5
#/*voila:*/
ld %:voila,r5

#labe1: and %5,r3,r1
#voila: or %:voila,r3,r1
#	add r7,r2,r1 
#voila:	ld :voila,r5
#	add r10,r6,r7
#	sti r1,r3,%:voi
#	lfork %5
#
#	#lfork r5
#	lld 1,r2
#lfork %8#/*labe1
