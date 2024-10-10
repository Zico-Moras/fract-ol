#1 aprender a usar minilibx
	cirar uma window
	fechar uma window no x e no ESC in a clean way
	tem que conseguir minizar smoothly
	usar cores

#aprender a matematica de fractals

#aprender linked lists






void *mlx_init()

funcao utilizada para inicar a libraria mlx
establece a ligacao entre o software e o "display"
o apontador retornado e utilizado para as outras funcoes da libraria
devolve um apontador para uma struct

void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)

funcao utilizada para criar a uma window com propocoes, "size_x" e "size_y" e nome "title"
