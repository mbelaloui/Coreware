.name   "s"
.comment "ss"
  
#bonjour:

voila:	ld :voila,r5
aff r1
ld %:voila,r5
live %4
ld 4,r5
ld :voila,r5
ld %42,r5
ld %:voila,r5
fin: and r1,r2,r5

sti r10,%:fin,r3
