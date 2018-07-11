.name "bonjour"ss
;.error #asd a
.comment "comment"

liv:	;live	%1
	ld	%:liv,r1;
	
	ld		42,//r2
	ld		//%42,r2
	ld		%-42,r2//
	st		r2,42
	
	ld	%:liv,r1;
	
/*	ld		42,r2
	ld		%42,r2
	ld		%-42,r2*/
	st		r2,42
