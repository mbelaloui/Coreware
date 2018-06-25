#include "../../inc/asm.h"

void	ft_is_good_format_param(char *url_file)
{

        if (ft_isempty(url_file))
		ft_error_param(ERROR_NO_URL_FILE, url_file);
        // voir ici avec le -o si ca pourrait engendrer des problemes
	// si non extraire les donnes en ammont le nom du fichier in et out 
	if (ft_comptword(url_file, ' ') != 1)
	{
	// voir si ont ne peut pas faire une boucle est boucler sur charque ficheir 
	// 	avec ou sans flag -m multipul
		ft_error_param(ERROR_MULTIPUL_PARAM, url_file);
        }
        else if (ft_is_good_format_file(url_file))
	{
		ft_printf("ouvrire le fichier est commancer a exraire les infos\n", url_file);
	}
}
