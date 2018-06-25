
# include "../../inc/asm.h"
void	ft_set_options(char c, unsigned long *op)
{
        if (c == 'o')
                (*op) = (*op) | MASK_OP_O;
        else if (c == 'a')
                (*op) = (*op) | MASK_OP_A;
/*      else if (c == '')
*/
}

