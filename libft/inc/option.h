


/*
structurer les fonction pour recupere les options
*/

typedef struct          s_option
{
	int                             B : 1;
	int                             D : 1;
	int                             d : 1;
	int                             e : 1;
	int                             H : 1;
	int                             h : 1;
	int                             o : 1;
	int                             p : 1;
	int                             s : 1;
	int                             S : 1;
	int                             t : 1;
	int                             u : 1;
}                                       t_option;


void                   ft_init_option(t_option *op);
void                   ft_error_option(int id_error, char *name, t_option *op, char c);
BOOL                   ft_extract_options(char *param, t_option *options, char *name);
