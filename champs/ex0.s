.name "bonjour"ss
;.error #asd a
.comment "comment"

liv:	;live	%1
	ld	%:liv,r1;
	ld		42,//r2
	ld		//%42,r2
	ld		%-42,r2//
	st		r2#,2
#	ld1	%:liv,r1;
/*	ld2		42,r2
	ld3		%42,r2
*/

	ld4		%-42,r3
	st		r2,4
