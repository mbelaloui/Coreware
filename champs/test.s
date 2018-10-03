.name	"test 01"
.comment	"comment"


bjr: live %0
	and :bjr,%42,r3
	live %:bjr
	and r1,r2,r3
	and 42,24,r3
	and %:bjr,%42,r3
#	and %:bjr,%42,3

