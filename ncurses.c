#include "libft/src/libft.h"
#include "libft/src/get_next_line.h"
#include "libft/src/ft_printf/include/ft_printf.h"
#include <ncurses.h>

/*
char	*make_map(void)
{
	char	*str;

	str = ft_strdup(""
"0c 00 6a 02 90 ff ff fe f0 03 01 00 00 00 00 0c 00 2f 02 90 ff ff fe f0 03 0c 00 14 02 90 00 00 00 00 02 02 90 00 00 00 00 04 09 00 8b 02 90 00 00 00 04 02 02 90 00 00 00 00 04 09 00 7a 02 90"
"ff ff ff 36 03 0c 00 14 02 90 00 00 00 00 02 02 90 00 00 00 00 04 09 00 93 02 90 00 00 00 04 02 02 90 00 00 00 00 04 09 00 82 02 90 00 00 01 90 03 01 00 00 00 00 0c 00 28 0c 00 14 02 90 00 00"
"00 00 02 02 90 00 00 00 00 04 09 00 45 02 90 00 00 00 04 02 02 90 00 00 00 00 04 09 00 34 0c 00 0d 02 90 00 00 00 00 04 09 00 5b 02 90 00 00 00 00 04 09 00 5c 0a 64 02 00 12 06 02 90 00 00 00"
"00 04 01 00 00 00 01 0b 54 06 02 03 09 fe eb 0a 64 02 00 12 06 02 90 00 00 00 00 04 01 00 00 00 01 0b 54 06 02 03 09 01 8b 0a 64 02 00 12 06 02 90 00 00 00 00 04 01 00 00 00 01 0b 54 06 02 03"
"09 ff 31 01 00 00 00 01 0c ff fb 09 ff f8 01 00 00 00 01 0c ff fb 09 ff f8 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"02 d0 ff d6 02 09 00 49 0b 54 0a 0f 09 01 00 00 00 2a 09 fe 66 02 90 03 09 fe 10 0a 02 90 ff ff fe 78 09 02 90 05 09 fe 01 02 02 90 ff ff fe 19 03 02 90 07 09 ff f0 04 02 90 ff ff fe 0a 05 02"
"90 ff ff ff f9 07 02 d0 fe 01 01 09 ff bd 02 90 03 50 04 01 08 03 50 01 0f 03 70 08 ff fc 0c 01 2a 01 00 00 00 2a 0c ff af 02 90 0b 54 02 01 0a 02 90 ff ff fe 74 09 02 90 0b 54 04 01 02 02 90"
"ff ff fe 15 03 03 50 02 04 02 90 ff ff fe 06 05 02 90 ff ff ff f5 07 02 d0 fe 01 01 09 ff 6c 03 70 04 ff db 03 70 04 ff d1 03 70 04 ff c7 03 70 04 ff bd 03 70 04 ff b3 03 70 04 ff a9 03 70 04"
"ff 9f 03 70 04 ff 95 03 70 04 ff 8b 03 70 04 ff 81 03 70 04 ff 77 03 70 04 ff 6d 03 70 04 ff 63 03 70 04 ff 59 03 70 04 ff 4f 03 70 04 ff 45 03 70 04 ff 3b 03 70 04 ff 31 03 70 04 ff 27 03 70"
"04 ff 1d 03 70 04 ff 13 03 70 04 ff 09 03 70 04 fe ff 03 70 04 fe f5 03 70 04 fe eb 03 70 04 fe e1 03 70 04 fe d7 03 70 04 fe cd 03 70 04 fe c3 03 70 04 fe b9 03 70 04 fe af 03 70 04 fe a5 03"
"70 04 fe 9b 03 70 04 fe 91 03 70 04 fe 87 03 70 04 fe 7d 03 70 04 fe 73 03 70 04 fe 69 03 70 04 fe 5f 03 70 04 fe 55 03 70 04 fe 4b 03 70 04 fe 41 03 70 04 fe 37 03 70 04 fe 2d 03 70 04 fe 23"
"01 00 00 00 2a 09 ff 1a 02 90 0f 0f 0f 0f 04 01 00 00 00 2a 02 d0 01 ff 01 0c 00 10 03 70 0f ff e5 01 00 00 00 2a 09 fe f9 01 00 00 00 2a 0c fe f1 01 00 00 00 2a 0c 00 2f 01 00 00 00 2a 0c 00"
"5b 02 90 00 00 00 05 03 02 90 00 00 01 ff 05 02 90 0b 54 04 05 02 02 90 01 ff ff ff 06 02 d0 01 ff 01 09 00 76 01 00 00 00 2a 0c 00 50 02 90 00 00 00 09 03 02 90 00 00 01 fa 05 02 90 01 0b 54"
"06 02 02 d0 00 11 06 02 d0 01 ff 01 09 00 4c 01 00 00 00 2a 0b 54 02 03 01 02 90 00 00 00 0d 03 02 90 00 00 01 f5 05 02 90 03 01 0f 0f 02 03 50 02 06 02 d0 01 ff 01 09 00 21 03 70 0f ff d6 02"
"90 00 00 01 ff 03 02 90 00 00 01 f0 05 03 50 04 02 03 50 04 06 09 00 03 0b 54 02 03 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"0b 68 01 00 51 00 01 02 90 00 00 00 00 02 01 00 00 00 0a 02 90 00 00 00 2f 03 09 00 3f 02 90 00 00 00 46 03 09 00 9d 02 90 00 00 00 0f 03 02 d0 00 0a 04 05 54 03 04 03 03 70 03 ff 5e 03 70 03"
"ff 53 03 70 03 ff 48 03 70 03 ff 3d 03 70 03 ff 32 01 00 00 00 0f 09 00 03 03 70 02 fe f2 09 ff bf 03 70 02 fe fb 03 70 02 ff 04 03 70 02 ff 0d 03 70 02 ff 02 03 70 02 fe f7 03 70 02 fe ec 03"
"70 02 fe e1 03 70 02 fe d6 03 70 02 fe cb 03 70 02 fe c2 03 70 02 fe b9 03 70 02 fe b0 03 70 02 fe a7 03 70 02 fe 9e 03 70 02 fe 95 03 70 02 fe 8c 03 70 02 fe 83 03 70 02 fe 7a 09 ff 9e 09 ff"
"93 01 00 01 fb d0 03 70 05 00 42 03 70 05 00 4b 03 70 05 00 54 03 70 05 00 5d 03 70 05 00 66 03 70 05 00 6f 03 70 05 00 78 03 70 05 00 81 03 70 05 00 8a 03 70 05 00 93 03 70 05 00 9c 03 70 05"
"00 a5 03 70 05 00 ae 03 70 05 00 b7 03 70 05 00 c0 03 70 05 00 c9 03 70 05 00 d2 03 70 05 00 db 03 70 05 00 e4 01 00 00 00 83 09 fe d6 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"03 70 01 00 06 01 00 00 00 00 0c ff f6 02 d0 ff ff 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
	return (str);
	}


*/






/*
 * COLOR_
 * COLOR_WHITE
 * COLOR_BLACK
 * COLOR_GREEN
 * COLOR_BLUE
 * COLOR_RED
 * COLOR_YELLOW
 * COLOR_MAGENTA
 * COLOR_CYAN
 */

# define WIN_PLAYER_X 64
# define WIN_PLAYER_Y 7
# define WIN_STATS_X 64
# define WIN_STATS_Y 9
# define WIN_MAP_X 191
# define WIN_MAP_Y 64
# define COLOR_DEEP 1
# define COLOR_MAP 2
# define COLOR_STATS 3
# define COLOR_BASIC 139
# define COLOR_GREY_LESS 232
# define COLOR_GREY_LOW 234
# define COLOR_GREY_MEDIUM 235
# define COLOR_GREY_LIGHT 237
# define COLOR_PLAYER_1 24
# define COLOR_PLAYER_2 208
# define COLOR_PLAYER_3 106
# define COLOR_PLAYER_4 88     // 52
# define PLAYER_1 11
# define PLAYER_2 12
# define PLAYER_3 13
# define PLAYER_4 14
# define PLAYER_REVERSE_1 21
# define PLAYER_REVERSE_2 22
# define PLAYER_REVERSE_3 23
# define PLAYER_REVERSE_4 24

# define NB_PLAYER 4			// a remplacer par la variable qui contient le nb de player

void		color_pallet(void)
{
	int		i;

	i = 0;
	printw("\n\n\n\n\n\n\n");
	while (i <= 255)
	{
		init_pair(i, COLOR_BLACK, i);
		attron(COLOR_PAIR(i));
		printw("  %03d  ", i);
		if (i % 36 == 0)
			printw("\n");
		i++;
	}
	attroff(A_NORMAL);
}
/*
void		color_the_deep(void)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	x = 0;
	str = ft_strnew(COLS);
	while (x <= COLS)
		str[x++] = ' ';
	init_pair(COLOR_DEEP, COLOR_BASIC, COLOR_GREY_MEDIUM);
	attrset(COLOR_PAIR(COLOR_DEEP));
	while (y <= LINES)
	{
		printw("%s", str);
		y++;
	}
	mvprintw(64, 204, "Vitesse :\t20/20");
}
*/
/*void		esc_visu(WINDOW *map, WINDOW *stats, WINDOW *player_1, WINDOW *player_2, WINDOW *player_3, WINDOW *player_4)
{
	delwin(map);
	delwin(stats);
	delwin(player_1);
	delwin(player_2);
	delwin(player_3);
	delwin(player_4);
	endwin();
	exit(1);
}*/
/*
void	init_visu()
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
}*/
/*
WINDOW		*init_win_map(WINDOW *map)
{
	init_pair(COLOR_MAP, COLOR_GREY_LOW, COLOR_GREY_LESS);
	map = newwin(WIN_MAP_Y, WIN_MAP_X, 1, 2);
	wattrset(map, COLOR_PAIR(COLOR_MAP));
	wrefresh(map);
	return (map);
}*/
/*
WINDOW		*init_win_stats(WINDOW *stats)
{
	char	str[WIN_STATS_X * WIN_STATS_Y];
	int		i;

	i = 0;
	init_pair(COLOR_STATS, COLOR_BASIC, COLOR_GREY_LIGHT);
	stats = newwin(WIN_STATS_Y, WIN_STATS_X, 2, 200);
	while (i <= WIN_STATS_X * WIN_STATS_Y)
		str[i++] = ' ';
	wattrset(stats, COLOR_PAIR(COLOR_STATS));
	wprintw(stats, "%s", str);
	wrefresh(stats);
	return (stats);
}
*/
/*
WINDOW		*init_win_player(WINDOW *player, int num, int color)
{
	char	str[WIN_PLAYER_X * WIN_PLAYER_Y];
	int		i;
	int		j;

	i = 0;
	j = 25 + ((WIN_PLAYER_Y + 1) * (num - 10));
	init_pair(num, color, COLOR_GREY_LIGHT);
	player = newwin(WIN_PLAYER_Y, WIN_PLAYER_X, j, 200);
	while (i <= WIN_PLAYER_X * WIN_PLAYER_Y)
		str[i++] = ' ';
	wattrset(player, COLOR_PAIR(num));
	wprintw(player, "%s", str);
	wrefresh(player);
	return (player);
}
*/
/*
void		print_player(WINDOW *player, int nb)
{
	wmove(player, 0, 0);
	mvwprintw(player, 1, 4, "Champion %d :\t\t%s", nb, "name");
	mvwprintw(player, 2, 4, "Last live :\t\t\t%d (%d)", 0, 0);
	mvwprintw(player, 3, 4, "Size :\t\t\t%d", 0);
	mvwprintw(player, 4, 4, "Live :\t\t\t%d", 0);
	mvwprintw(player, 5, 4, "Processes :\t\t\t%d", 0);
	wrefresh(player);
}

void		print_stats(WINDOW *stats, int nb, int time)
{
	wmove(stats, 0, 0);
	mvwprintw(stats, 1, 4, "Cycle :\t\t\t%d", nb);
	mvwprintw(stats, 3, 4, "Cycle delta :\t\t%d", 0);
	mvwprintw(stats, 2, 4, "Cycles to die :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 4, 4, "Processes :\t\t\t%d", 0);
	mvwprintw(stats, 5, 4, "Number of lives :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 6, 4, "Checks :\t\t\t%d/%d", 0, 0);
	mvwprintw(stats, 7, 4, "Cycle per second :\t\t%d", time / 1000000);
	wrefresh(stats);
}
*/
/*void		print_maps(char *line, WINDOW *map)
{
	wmove(map, 0, 0);
	wprintw(map, "%s", line);
	wrefresh(map);
}
*/
/*
void		visu_pause(WINDOW *map, WINDOW *stats, WINDOW *player_1, WINDOW *player_2, WINDOW *player_3, WINDOW *player_4)
{
	char	c;

	mvprintw(64, 226, "	PAUSE");
	while (1)
	{
		c = getch();
		if (c == 32)
			break ;
		if (c == 27)
			esc_visu(map, stats, player_1, player_2, player_3, player_4);
	}
	mvprintw(64, 226, "	     ");
}*/
/*
void		print_visu(WINDOW *map, WINDOW *stats, char *line, WINDOW *player_1, WINDOW *player_2, WINDOW *player_3, WINDOW *player_4)
{
int i = 0;//
int	time = 1;
while (i < 100000)//
{//
	int		j;
	char	c;

	j = 1;
	print_maps(line, map);
	print_player(player_1, 1),
	print_player(player_2, 2),
	print_player(player_3, 3),
	print_player(player_4, 4),
	print_stats(stats, i, time);
	c = getch();
	if (c == 27)
		esc_visu(map, stats, player_1, player_2, player_3, player_4);
	else if (c == '-' || c == '+')
	{
		if (c == '+' && time > 1)
			time -= 1000000;
		else if (c == '-' && time < 19000001)
			time += 1000000;
		mvprintw(64, 204, "Vitesse :\t%02d/20", 20 - (time / 1000000));
	}
	else if (c == 32 || c == '=')
		visu_pause(map, stats, player_1, player_2, player_3, player_4);
	j = 1;
	while (j < time)
		j++;
i++;//
}//
}
*/
int			main(void)
{
/*	WINDOW	*map;			//a mettre dans la struc principal
	WINDOW	*stats;			//a mettre dans la struc principal
	WINDOW	*player_1;		//a mettre dans la struc principal
	WINDOW	*player_2;		//a mettre dans la struc principal
	WINDOW	*player_3;		//a mettre dans la struc principal
	WINDOW	*player_4;		//a mettre dans la struc principal
	char	*line;
*/
/*
	init_visu();
	line = make_map();
//	color_pallet();
//	getch();
	color_the_deep();
	getch();
	map = init_win_map(map);
*/	/*stats = init_win_stats(stats);
*/
//le bloc a mettre dans une fonction quand les struct des player seront ds la struct principal
/*
	player_1 = init_win_player(player_1, PLAYER_1, COLOR_PLAYER_1);
	player_2 = init_win_player(player_2, PLAYER_2, COLOR_PLAYER_2);
	if (NB_PLAYER > 2)
		player_3 = init_win_player(player_3, PLAYER_3, COLOR_PLAYER_3);
	if (NB_PLAYER > 3)
		player_4 = init_win_player(player_4, PLAYER_4, COLOR_PLAYER_4);
	getch();
	print_visu(map, stats, line, player_1, player_2, player_3, player_4);
*/







/*	win = init_visu(win, c);
	c = cbreak();
	stats = newwin(LINES, 75, 0, COLS - 75);
	box(stats, 0, 0);
	wrefresh(stats);
	i = 0;
	time = 100001;
	save = line;
	while (i < 10000)
	{
		j = 0;
		while (j < time)
		{
			c = wgetch(win);
			if (c == '+' && time > 1)
				time -= 10000;
			if (c == '-' && time < 200001)
				time += 10000;
			if (c == 27)
				exit_visu(win);
			j++;
		}
		i++;
		y = 1;
		line = save;
		mvwprintw(win, y, 2, "%s", line);
		wrefresh(win);
		y++;
	}
*/
//	esc_visu(map, stats, player_1, player_2, player_3, player_4);
	return (0);
}
