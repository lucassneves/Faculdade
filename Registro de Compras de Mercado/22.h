// Estruturas
typedef struct tabela{
	int *cod;
	char **nomes;
	int num_product_list;
	float *supports;
	//t2 tem 2 nomes/cod e 3 supp
	/*
	supports[0] = support_1;
	supports[1] = support_2;
	supports[2] = support_1_e_2;
	*/
	//t3 tem 3 nomes/cod e 7 supp
	/*
	supports[0] = support_1;
	supports[1] = support_2;
	supports[2] = support_3;
	supports[3] = support_1_e_2;
	supports[4] = support_1_e_3;
	supports[5] = support_3_e_2;
	supports[6] = support_1_2_3;
	*/
}tab;

typedef struct confidence{
	char **nomes;
	int *cod;
	float confidence;
}con;

//Funções
int iniciar(void) ;
void warning(int type);
int combine_product(int lines_table,int n_combine);

void make_structs(tab **x,con **y, int type, int sub_type);
/*
   0,0 = tabela
   0,1 = tabela_2
   0,2 = tabela_3
   1,0 = confidence_2_product
   1,1 = confidence_3_product_mod_one
   1,2 = confidence_3_product_mod_two
*/
void free_structs(void *x, int type, int sub_type);

//void calculos(tab **t, tab **t3, tab **t3, con **c2, con **c3_1, con **c3_2);

//Funções utilizadas no layout no Terminal(Telas)
void tela_padrao(void);
void tela_main (void);
void tela_iniciar(int type);

//ver depois
void carregar_func(void);
