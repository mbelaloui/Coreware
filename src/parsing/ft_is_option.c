#include "../../inc/asm.h"

BOOL     ft_is_option(const char option)
{
        if (option == 'o' || option == 'a')// || option == 'l' || option == 'm'
                return (T);
        return (F);
}
