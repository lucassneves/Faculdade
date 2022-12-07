#include "my_lib.h"

//***************************************************************
//***************************************************************
//Funções

void make_structs(tab **x, con**y, int type, int sub_type){
	int i;
	if(type==0){
		if(sub_type==0){
			tab* t = malloc(sizeof(tab));
			t->num_product_list = 0;
			t->nomes = malloc(sizeof(char*));
			t->nomes[0] = NULL;
			t->cod = malloc(sizeof(int));
			t->supports = malloc(sizeof(float));
			t->cod[0] = t->supports[0] = 0;
			*x = t;
		}
		if(sub_type==1){
			tab* t = malloc(sizeof(tab));
			t->num_product_list = 0;
			t->nomes = malloc(2*sizeof(char*));
			for(i=0;i<2;i++) t->nomes[i] = NULL;
			t->cod = malloc(2*sizeof(int));
			for(i=0;i<2;i++) t->cod[i] = 0;
			t->supports = malloc(3*sizeof(float));
			for(i=0;i<3;i++) t->supports[i] = 0;
			*x = t;
			/*
			supports[0] = support_1;
			supports[1] = support_2;
			supports[2] = support_1_e_2;
			*/
		}
		if(sub_type==2){
			tab* t = malloc(sizeof(tab));
			t->num_product_list = 0;
			t->nomes = malloc(3*sizeof(char*));
			for(i=0;i<3;i++) t->nomes[i] = NULL;
			t->cod = malloc(3*sizeof(int));
			for(i=0;i<3;i++) t->cod[i] = 0;
			t->supports = malloc(7*sizeof(float));
			for(i=0;i<7;i++) t->supports[i] = 0;
			*x = t;
			/*
			supports[0] = support_1;
			supports[1] = support_2;
			supports[2] = support_3;
			supports[3] = support_1_e_2;
			supports[4] = support_1_e_3;
			supports[5] = support_3_e_2;
			supports[6] = support_1_2_3;
			*/
		}
	}
	if(type==1){
		if(sub_type==0){
			con *c = malloc(sizeof(con));
			c->confidence = 0;
			c->nomes = malloc(3*sizeof(char*));
			c->cod = malloc(3*sizeof(int));
			for(i=0;i<3;i++){
				c->nomes[i]=NULL;
				c->cod[i]=0;
			}
			*y = c;
		}
		if(sub_type==1){
			con *c = malloc(sizeof(con));
			c->confidence = 0;
			c->nomes = malloc(4*sizeof(char*));
			c->cod = malloc(4*sizeof(int));
			for(i=0;i<4;i++){
				c->nomes[i]=NULL;
				c->cod[i]=0;
			}		
			*y = c;
		}
		if(sub_type==2){
			con *c = malloc(sizeof(con));
			c->confidence = 0;
			c->nomes = malloc(5*sizeof(char*));
			c->cod = malloc(5*sizeof(int));			
			for(i=0;i<5;i++){
				c->nomes[i]=NULL;
				c->cod[i]=0;
			}
			*y = c;
		}
	}
}

void free_structs(void *x, int type, int sub_type){
	int i;
	if(type==0){
		if(sub_type==0){
			tab* t = x;
			free(t->nomes[0]);
			free(t->nomes);
			free(t->cod);
			free(t->supports);
			free(t);
		}
		if(sub_type==1){
			tab* t = x;
			for(i=0;i<2;i++) free(t->nomes[i]);
			free(t->nomes);
			free(t->cod);
			free(t->supports);
			free(t);
			/*
			supports[0] = support_1;
			supports[1] = support_2;
			supports[2] = support_1_e_2;
			*/
		}
		if(sub_type==2){
			tab* t = x;
			for(i=0;i<3;i++) free(t->nomes[i]);
			free(t->nomes);
			free(t->cod);
			free(t->supports);
			free(t);
			/*
			supports[0] = support_1;
			supports[1] = support_2;
			supports[2] = support_3;
			supports[3] = support_1_e_2;
			supports[4] = support_1_e_3;
			supports[5] = support_3_e_2;
			supports[6] = support_1_2_3;
			*/
		}
	}
	if(type==1){
		if(sub_type==0){
			con *c = x;
			for(i=0;i<3;i++) free(c->nomes[i]);
			free(c->nomes);
			free(c->cod);
			free(c);
		}
		if(sub_type==1){
			con *c = x;
			for(i=0;i<4;i++) free(c->nomes[i]);
			free(c->nomes);
			free(c->cod);
			free(c);
		}
		if(sub_type==2){
			con *c = x;
			for(i=0;i<5;i++) free(c->nomes[i]);
			free(c->nomes);
			free(c->cod);
			free(c);
		}
	}
}

void warning (int type) {
	int nrows;// numero de linhas e colunas do terminal
	nrows = get_terminal_nrows();
	clear();
	tela_padrao();

	if (type == 1){
		gotoxy(nrows - 3,3);
		printf("Opção Invalida");
		gotoxy(nrows - 2,3);
		printf("Digite Novamente!");
	} else if (type == 2){
		gotoxy(nrows - 4,3);
		printf("Erro 002");
		gotoxy(nrows - 3,3);
		printf("Arquivo 'table.txt' não inserido!!");
		gotoxy(nrows - 2,3);
		printf("Press 0) para tentar Novamente");
	}else if (type == 3){
		gotoxy(nrows - 4,3);
		printf("Erro 003");
		gotoxy(nrows - 3,3);
		printf("Tentativa de voltar ou Avançar Indevida");
		gotoxy(nrows - 2,3);
		printf("Press 0) para Escolher Novamente");

	}
}

int combine_product(int lines_table,int n_combine){
	int i,soma1 = 1,soma2 = 1,soma3 = 1;

	for(i = lines_table;i > 0;i--){
		soma1*=i;
	}
	for(i = n_combine;i > 0;i--){
		soma2*=i;
	}
	for(i = (lines_table - n_combine);i > 0;i--){
		soma3*=i;
	}
	return (soma1/(soma2*soma3));
}

int iniciar(void) {
	int i,n,j,u;
	int y,k,l,lines_table = 0,total_product_1 = 0,n_two_table = 0,n_three_table = 0;
	int flag = 0,pass_lines,cout_pass, m = 0,direita  = 0, esquerda = 0;
	char c = 'b',*local= "table.txt",*file = "teste_file.txt";
	//int u,pass_lines,cout_pass,k,teto;
	tab **t,**t2,**t3;
	con **c2,**c3_1,**c3_2;
	void **z;
	
	lines_table = countlines(local);
	n_two_table = combine_product(lines_table,2);
	n_three_table = combine_product(lines_table,3);
	
	t = malloc(lines_table*sizeof(*t));
	t2 = malloc(n_two_table*sizeof(*t2));
	t3 = malloc(n_three_table*sizeof(*t3));
	
	c2 = malloc(2*n_two_table*sizeof(*c2));
	c3_1 = malloc(3*n_three_table*sizeof(*c3_1));
	c3_2 = malloc(3*n_three_table*sizeof(*c3_2));
	
	for(i=0;i<lines_table;i++){
		make_structs(&t[i],(con**)z,0,0);
	}
	for(i=0;i<n_two_table;i++){
		make_structs(&t2[i],(con**)z,0,1);
		make_structs((tab**)z,&c2[i],1,0);
		make_structs((tab**)z,&c2[i+n_two_table],1,0);
	}
	for(i=0;i<n_three_table;i++){
		make_structs(&t3[i],(con**)z,0,2);
		make_structs((tab**)z,&c3_1[i],1,1);
		make_structs((tab**)z,&c3_1[i+n_three_table],1,1);
		make_structs((tab**)z,&c3_1[i+2*n_three_table],1,1);
		make_structs((tab**)z,&c3_2[i],1,2);
		make_structs((tab**)z,&c3_2[i+n_three_table],1,2);
		make_structs((tab**)z,&c3_2[i+2*n_three_table],1,2);
	}
//------------------------------------------------------------------------

	db_file *f;
	make_file(&f);
	read_file(file,f);
	
	tab table_tmp;
	tab table2_tmp;
	tab table3_tmp;
	con confidence2_tmp;
	con confidence3_mod1_tmp;
	con confidence3_mod2_tmp; 

	
	FILE *arq;

	arq = fopen (local,"r");
	
	for(i = 0;i < lines_table;i++){
		t[i]->num_product_list = 0;
	}
	for(i = 0;i < n_two_table;i++){
		t2[i]->num_product_list = 0;
	}
	for (i = 0;i < n_three_table;i++){
		t3[i]->num_product_list = 0;
	}
	for (i = 0 ; i < lines_table ; i++){
		fscanf(arq,"%d %s %*f",&t[i]->cod[0],buff);
		t[i]->nomes[0] = malloc((strlen(buff)+1)*sizeof(char));
		strcpy(t[i]->nomes[0],buff);
	}
	fclose(arq);
	
	
	for (i = 0,k = 0;i < lines_table;i++){
		for (j = i;j < lines_table;j++){
			if(i!= j) {
				n = strlen(t[i]->nomes[0])+1;
				t2[k]->nomes[0] = malloc(n*sizeof(char));
				strcpy(t2[k]->nomes[0],t[i]->nomes[0]);
				t2[k]->cod[0] = t[i]->cod[0];

				n = strlen(t[j]->nomes[0])+1;
				t2[k]->nomes[1] = malloc(n*sizeof(char));
				strcpy(t2[k]->nomes[1],t[j]->nomes[0]);
				t2[k]->cod[1] = t[j]->cod[0];
				k++;
			}
		}
	}
	for (i = 0,k = 0;i < lines_table;i++){
		for (j = i;j < lines_table ;j++) {
			for(l = j;l < lines_table ;l++){
				if(j!=i && l!= j && i!= l){
					n = strlen(t[i]->nomes[0]) +1;
					t3[k]->nomes[0] = malloc(n*sizeof(char));
					strcpy(t3[k]->nomes[0],t[i]->nomes[0]);
					t3[k]->cod[0] = t[i]->cod[0];
					
					n = strlen(t[j]->nomes[0]) +1;
					t3[k]->nomes[1] = malloc(n*sizeof(char));
					strcpy(t3[k]->nomes[1],t[j]->nomes[0]);
					t3[k]->cod[1] = t[j]->cod[0];

					n = strlen(t[l]->nomes[0]) +1;
					t3[k]->nomes[2] = malloc(n*sizeof(char));
					strcpy(t3[k]->nomes[2],t[l]->nomes[0]);
					t3[k]->cod[2] = t[l]->cod[0];
					k++;
				}
				
			}
		}
	}
	

	//supports de Cada Produto de Uma lista

	for(i=0;i<f->n_lines;i++){
		if(f->category[i] == 1){
			for(j=0;j< f->n_prod[i];j++) {
				for(k = 0; k < lines_table ; k++) {
					if(f->line[i][j].cod == t[k]->cod[0]){
						
						t[k]->num_product_list++;

					}
				}

				total_product_1++;

				for(y = j;y < f->n_prod[i];y++){
					if(j!=y && f->line[i][j].cod != f->line[i][y].cod){
						for(k = 0;k < n_two_table;k++){
							if((f->line[i][j].cod == t2[k]->cod[0] ||
								 f->line[i][j].cod == t2[k]->cod[1]) && ( 
								 f->line[i][y].cod == t2[k]->cod[0] ||
								 f->line[i][y].cod == t2[k]->cod[1]) ){

								t2[k]->num_product_list++;
							}
						}
					}

					for(l = y;l < f->n_prod[i];l++){
						if(l!=y && l!= j && j!=y && f->line[i][j].cod != f->line[i][y].cod &&
						 	f->line[i][j].cod != f->line[i][l].cod &&
						 	 f->line[i][y].cod != f->line[i][l].cod ){

								 for(k = 0;k < n_three_table;k++){
							 		if((f->line[i][j].cod == t3[k]->cod[0] || f->line[i][j].cod == t3[k]->cod[1] || f->line[i][j].cod == t3[k]->cod[2]) &&
							 			(f->line[i][y].cod == t3[k]->cod[0] || f->line[i][y].cod == t3[k]->cod[1] || f->line[i][y].cod == t3[k]->cod[2]) &&
							 			(f->line[i][l].cod == t3[k]->cod[0]|| f->line[i][l].cod == t3[k]->cod[1] || f->line[i][l].cod == t3[k]->cod[2]) ){
							 			
							 			t3[k]->num_product_list++;
							 		}
							 	}

						}
					}
						
				}

			}
		}
	}

	for(k = 0 ; k < lines_table ; k++){
		t[k]->supports[0] = ((float)t[k]->num_product_list)/((float)total_product_1);
	}

	for(k = 0 ; k < n_two_table; k++){
		t2[k]->supports[2] = ((float)t2[k]->num_product_list)/((float)total_product_1);
	
		for(i = 0 ; i < lines_table ; i++){
			if(t2[k]->cod[0] == t[i]->cod[0]){
				t2[k]->supports[0] = t[i]->supports[0];

			}else if (t2[k]->cod[1] == t[i]->cod[0]){
				t2[k]->supports[1] = t[i]->supports[0];

			}
		}
	}
	for(k = 0 ; k < n_three_table; k++){
		t3[k]->supports[6] = ((float)t3[k]->num_product_list)/((float)total_product_1);
		
		for(i = 0 ; i < lines_table ; i++) {
			if(t3[k]->cod[0] == t[i]->cod[0]){
				t3[k]->supports[0] = t[i]->supports[0];

			}else if (t3[k]->cod[1] == t[i]->cod[0]){
				t3[k]->supports[1] = t[i]->supports[0];

			}else if (t3[k]->cod[2] == t[i]->cod[0]){
				t3[k]->supports[2] = t[i]->supports[0];

			}
		}

		for( l = 0; l < n_two_table; l++){
			if((t3[k]->cod[0] == t2[l]->cod[0] && t3[k]->cod[1] == t2[l]->cod[1])|| (t3[k]->cod[1] == t2[l]->cod[0] && t3[k]->cod[0] == t2[l]->cod[1])){
				t3[k]->supports[3] = t2[l]->supports[2];
			} else if ((t3[k]->cod[0] == t2[l]->cod[0] && t3[k]->cod[2] == t2[l]->cod[1])|| (t3[k]->cod[2] == t2[l]->cod[0] && t3[k]->cod[0] == t2[l]->cod[1])){
				t3[k]->supports[4] = t2[l]->supports[2];
			} else if ((t3[k]->cod[2] == t2[l]->cod[0] && t3[k]->cod[1] == t2[l]->cod[1])|| (t3[k]->cod[1] == t2[l]->cod[0] && t3[k]->cod[2] == t2[l]->cod[1])){
				t3[k]->supports[5] = t2[l]->supports[2];
			}

		}


	}
	
	//Confiança com 2 produtos
	for(i = 0,j = 0,l = 0;i < n_two_table;i++){

		for (k = 0 ; k < 2; k++){
			if(l == 0){
				n = strlen(t2[i]->nomes[0]) + 1;
				c2[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[0],t2[i]->nomes[0]);
				
				c2[j]->cod[0] = t2[i]->cod[0];

				n = strlen(t2[i]->nomes[1]) +1;
				c2[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[1],t2[i]->nomes[1]);
				c2[j]->cod[1] = t2[i]->cod[1];


				n = strlen(t2[i]->nomes[0])+1;
				c2[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[2],t2[i]->nomes[0]);
				c2[j]->cod[2] = t2[i]->cod[0];

				c2[j]->confidence = ((float)t2[i]->supports[2])/(float)(t2[i]->supports[0]);

				j++;
				l=1;
			}else if (l == 1){
				n = strlen(t2[i]->nomes[1]) +1;
				c2[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[0],t2[i]->nomes[1]);
				//printf("%s",c2[19]->nomes[0]);
				c2[j]->cod[0] = t2[i]->cod[1];

				n = strlen(t2[i]->nomes[0]) +1;
				c2[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[1],t2[i]->nomes[0]);
				c2[j]->cod[1] = t2[i]->cod[0];

				n = strlen(t2[i]->nomes[1]) +1;
				c2[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c2[j]->nomes[2],t2[i]->nomes[1]);
				c2[j]->cod[2] = t2[i]->cod[1];

				c2[j]->confidence = ((float)t2[i]->supports[2])/((float)t2[i]->supports[1]);

				j++;
				l=0;
			}
			
		}

	}

	//Confiança com 3 produtos modo one
	for (i = 0,j = 0,l = 0;i < n_three_table;i++){
		for (k = 0 ; k < 3; k++){
			if(l == 0){
				n = strlen(t3[i]->nomes[0]) +1;
				c3_1[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[0],t3[i]->nomes[0]);
				c3_1[j]->cod[0] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_1[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[1],t3[i]->nomes[1]);
				c3_1[j]->cod[1] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_1[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[2],t3[i]->nomes[2]);
				c3_1[j]->cod[2] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_1[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[3],t3[i]->nomes[0]);
				c3_1[j]->cod[3] = t3[i]->cod[0];

				c3_1[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[0]);

				j++;
				l = 1;
			} else if (l == 1){

				n = strlen(t3[i]->nomes[1]) +1;
				c3_1[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[0],t3[i]->nomes[1]);
				c3_1[j]->cod[0] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_1[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[1],t3[i]->nomes[0]);
				c3_1[j]->cod[1] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_1[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[2],t3[i]->nomes[2]);
				c3_1[j]->cod[2] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_1[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[3],t3[i]->nomes[1]);
				c3_1[j]->cod[3] = t3[i]->cod[1];

				c3_1[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[1]);

				j++;
				l = 2;
			}else if (l == 2){

				n = strlen(t3[i]->nomes[2]) +1;
				c3_1[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[0],t3[i]->nomes[2]);
				c3_1[j]->cod[0] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_1[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[1],t3[i]->nomes[0]);
				c3_1[j]->cod[1] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_1[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[2],t3[i]->nomes[1]);
				c3_1[j]->cod[2] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_1[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_1[j]->nomes[3],t3[i]->nomes[2]);
				c3_1[j]->cod[3] = t3[i]->cod[2];

				c3_1[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[2]);

				j++;
				l = 0;
			} 

		}

	}
	//Confiança com 3 produto modo 2
	for (i = 0,j = 0,l = 0;i < n_three_table;i++){
		for (k = 0 ; k < 3; k++){
			if(l == 0){
				n = strlen(t3[i]->nomes[0]) +1;
				c3_2[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[0],t3[i]->nomes[0]);
				c3_2[j]->cod[0] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_2[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[1],t3[i]->nomes[1]);
				c3_2[j]->cod[1] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_2[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[2],t3[i]->nomes[2]);
				c3_2[j]->cod[2] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_2[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[3],t3[i]->nomes[0]);
				c3_2[j]->cod[3] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_2[j]->nomes[4] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[4],t3[i]->nomes[1]);
				c3_2[j]->cod[4] = t3[i]->cod[1];
				
				c3_2[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[3]);

				j++;
				l = 1;
			} else if (l == 1){
				n = strlen(t3[i]->nomes[0]) +1;
				c3_2[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[0],t3[i]->nomes[0]);
				c3_2[j]->cod[0] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_2[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[1],t3[i]->nomes[2]);
				c3_2[j]->cod[1] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_2[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[2],t3[i]->nomes[1]);
				c3_2[j]->cod[2] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_2[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[3],t3[i]->nomes[0]);
				c3_2[j]->cod[3] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_2[j]->nomes[4] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[4],t3[i]->nomes[2]);
				c3_2[j]->cod[4] = t3[i]->cod[2];
				
				c3_2[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[4]);

				
				j++;
				l = 2;
			}else if (l == 2){
				n = strlen(t3[i]->nomes[2]) +1;
				c3_2[j]->nomes[0] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[0],t3[i]->nomes[2]);
				c3_2[j]->cod[0] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_2[j]->nomes[1] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[1],t3[i]->nomes[1]);
				c3_2[j]->cod[1] = t3[i]->cod[1];

				n = strlen(t3[i]->nomes[0]) +1;
				c3_2[j]->nomes[2] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[2],t3[i]->nomes[0]);
				c3_2[j]->cod[2] = t3[i]->cod[0];

				n = strlen(t3[i]->nomes[2]) +1;
				c3_2[j]->nomes[3] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[3],t3[i]->nomes[2]);
				c3_2[j]->cod[3] = t3[i]->cod[2];

				n = strlen(t3[i]->nomes[1]) +1;
				c3_2[j]->nomes[4] = malloc(n*sizeof(char));
				strcpy(c3_2[j]->nomes[4],t3[i]->nomes[1]);
				c3_2[j]->cod[4] = t3[i]->cod[1];
				
				c3_2[j]->confidence = ((float)t3[i]->supports[6])/((float)t3[i]->supports[5]);
				j++;
				l = 0;
			} 

		}

	}
	//Ordenação das estruturas(Supporte e Confiança)

	for(i = 0;i<lines_table;i++){
		for(j = i;j<lines_table;j++){
			if (t[i]->supports[0] < t[j]->supports[0]){
				table_tmp = *t[i];
				*t[i] = *t[j];
				*t[j] = table_tmp;
			}

		}
	}

	for(i = 0;i<n_two_table;i++){
		for(j = i;j<n_two_table;j++){
			if (t2[i]->supports[2] < t2[j]->supports[2]){
				table2_tmp = *t2[i];
				*t2[i] = *t2[j];
				*t2[j] = table2_tmp;
			}

		}
	}

	for(i = 0;i<n_three_table;i++){
		for(j = i;j<n_three_table;j++){
			if (t3[i]->supports[6] < t3[j]->supports[6]){
				table3_tmp = *t3[i];
				*t3[i] = *t3[j];
				*t3[j] = table3_tmp;
			}

		}
	}

	

	for(i = 0 ; i < 2*n_two_table-1 ; i++){
		for(j = i;j< 2*n_two_table-1;j++){
			if (c2[i]->confidence < c2[j]->confidence){
				confidence2_tmp = *c2[i];
				*c2[i] = *c2[j];
				*c2[j] = confidence2_tmp;
			}

		}
	}

	for(i = 0 ; i < 3*n_three_table-1 ; i++){
		for(j = i;j< 3*n_three_table-1;j++){
			if (c3_1[i]->confidence < c3_1[j]->confidence){
				confidence3_mod1_tmp = *c3_1[i];
				*c3_1[i] = *c3_1[j];
				*c3_1[j] = confidence3_mod1_tmp;
			}

		}
	}

	for(i = 0 ; i < 3*n_three_table-1 ; i++){
		for(j = i;j< 3*n_three_table-1;j++){
			if (c3_2[i]->confidence < c3_2[j]->confidence){
				confidence3_mod2_tmp = *c3_2[i];
				*c3_2[i] = *c3_2[j];
				*c3_2[j] = confidence3_mod2_tmp;
			}

		}
	}
	free_file(f);
	
	printf("11\n");
	
//------------------------------------------------------------------------


///// Loop de Inicialição

	for(u = 0; 1 ; u = 1) {
		
		if (0){
			reset:
			u = 0;
			flag = 0;
		}

		if (u == 0) {
			clear();
			tela_iniciar(0);
			
		} else if ((c - '0') == 0){

			for(i=0;i<lines_table;i++){
				free_structs(t[i],0,0);
			}
			for(i=0;i<n_two_table;i++){
				free_structs(t2[i],0,1);
				free_structs(c2[i],1,0);
			}
			for(i=0;i<n_three_table;i++){
				free_structs(t3[i],0,2);
				free_structs(c3_1[i],1,1);
				free_structs(c3_2[i],1,2);
			}

			free(t);
			free(t2);
			free(t3);
			free(c2);
			free(c3_1);
			free(c3_2);
			
			return 0;

		} else if ((c - '0') == 1) {
			back1:
			clear();
			tela_iniciar(1);
			gotoxy(8,3);
			printf("Atualmente há %d tipos Produtos no Banco de Dados",lines_table);
			c = getch();

			if(c-'0'!= 1 && c-'0'!= 2 && c-'0'!= 0 ) {
				warning(1);
				tela_iniciar(-1);
				while (1){
					if (c - '0' == 0)
						goto back1;
					c = getch();	
				}

			}

			while (1){
				
				if ((c - '0') == 1){
					
					for(u = 0,pass_lines = 0,cout_pass = 1; 1 ; u = 1) {
						back2:
						clear();
						tela_iniciar(-1);
						gotoxy(4,3);
						printf("Lista de Produtos mais vendidos" );
						if (lines_table <= 9){
							for (i = 0;i<lines_table;i++){
								gotoxy(i+5,3);
								printf("Rank %d) %s Cod: %d Quantidade: %d\n",i+1,t[i]->nomes[1],t[1]->cod[1],t[i]->num_product_list);
								//printf("%d\n",b);
							}
							
						} else if (lines_table > 9){
							if (u == 0) {
								pass_lines = 9;
								for(i = 0;i < pass_lines ;i++){
									gotoxy(i+5,3);
									printf("Rank %d) %s Cod: %d Quantidade: %d\n",i+1,t[i]->nomes[0],t[i]->cod[0],t[i]->num_product_list);
								}
								gotoxy(16,3);
								printf("Press =>) para mais Opções!!");
							} else if (u == 1) {

								if(c == direita ){
									if(cout_pass < (float)lines_table/9.0){
										cout_pass++;
										

									} else {
										warning(3);
										tela_iniciar(-1);
										while (1){
											if (c - '0' == 0)
												goto back2;
											c = getch();	
										}

									}
								} else if (c == esquerda && cout_pass > 1)
									cout_pass--;
								else if (c == esquerda && cout_pass <= 1){
									warning(3);
									tela_iniciar(-1);
									while (1){
										if (c == '0')
											goto back2;
										c = getch();	
									}
									
								}

								pass_lines = 9*cout_pass;
								if(pass_lines <= lines_table){
									for(i = 0,j = 9*cout_pass - 9;j < pass_lines ;i++,j++){
										gotoxy(i+5,3);
										printf("Rank %d) %s Cod: %d Quantidade: %d\n",i+1,t[i]->nomes[0],t[i]->cod[0],t[i]->num_product_list);
									}
									gotoxy(16,3);
									printf("Press =>) para mais Opções!!");
								
								} else if (pass_lines > lines_table){
									pass_lines = lines_table - 9*(cout_pass - 1);

									for(i = 5,k = 1,j = 9*(cout_pass - 1);j < lines_table;i++,j++,k++){
										gotoxy(i,3);
										printf("Press %d) %s\n",k,t[i]->nomes[0]);
										gotoxy(17,3);
										printf("%d %d %d\n",j,lines_table,cout_pass );
									}

								}
								
								
								if(cout_pass > 1){
									gotoxy(17,3);
									printf("Press <=) para voltar as Opções!!");
								
								}  
							}	

						}



						if (c -'0' == 0 ){
							goto back1;
						}

						c = getch();


					}
				} else if (c - '0' == 2){
					back3:
					clear();
					tela_iniciar(-1);
					gotoxy(4,3);
					c = 'b';
					u = 0;
					printf("Lista de Produtos mais vendidos");
					gotoxy(5,3);
					printf("Indique a quantidade que deseja visualizar, variando de 1 a %d ",lines_table);
					gotoxy(6,3);
					printf("1° Digite a quantidade de Digitos");
					gotoxy(7,3);
					printf("2° Digite digito por digito");
					gotoxy(9,3);
					printf("n. de Digitos 0");
					gotoxy(10,3);
					printf("n: 0");
					c = getch();
					n = c - '0';
					gotoxy(9,3);
					printf("n. de Digitos %d",n);
					for (i = 0;i < n ;i++){
						c = getch();
						
						m = 10*m + (c - '0');
						gotoxy(10,3);
						printf("n: %d",m);
					}
					clear();
					tela_iniciar(-1);
					gotoxy(4,3);
					printf("Lista de Produtos mais vendidos");
					gotoxy(5,3);
					printf("A quanidade desejada é %d",m);
					gotoxy(6,3);
					printf("Isso esta certo?");
					gotoxy(7,3);
					printf("1) sim");
					gotoxy(8,3);
					printf("2) não");
					c = getch ();
					if (c - '0' == 2){
						goto back3;
					} else if (c - '0' != 1 && c -'0'!= 2){
						clear();
						warning(1);
						tela_iniciar(-1);
						while (1) {
							if (c - '0' == 0)
								goto back3;
							c = getch();	
						}

					}

					if (m > 0 && m <= lines_table) {
						n = lines_table - (lines_table -  m);
						for(u = 0,pass_lines = 0,cout_pass = 1; 1 ; u = 1) {
							back4:
							clear();
							tela_iniciar(-1);
							gotoxy(4,3);
							printf("Lista de Produtos mais vendidos" );
							if (n <= 9){
								for (i = 0;i<n;i++){
									gotoxy(i+5,3);
									printf("Rank %d) %s Cod: %d Quantidade: %d >> Supporte: %.2f",i+1,t[i]->nomes[0],t[i]->cod[0],t[i]->num_product_list,t[i]->supports[0]);
									//printf("%d\n",b);
								}
								
							} else if (n > 9){
								if (u == 0) {
									pass_lines = 9;
									for(i = 0;i < pass_lines ;i++){
										gotoxy(i+5,3);
										printf("Rank %d) %s Cod: %d Quantidade: %d >> Supporte: %.2f",i+1,t[i]->nomes[0],t[i]->cod[0],t[i]->num_product_list,t[i]->supports[0]);
									}
									gotoxy(16,3);
									printf("Press =>) para mais Opções!!");
								} else if (u == 1) {

									if(c == direita ){
										if(cout_pass < (float)n/9.0){
											cout_pass++;
											

										} else {
											warning(3);
											tela_iniciar(-1);
											while (1){
												if (c - '0' == 0)
													goto back4;
												c = getch();	
											}

										}
									} else if (c == esquerda && cout_pass > 1)
										cout_pass--;
									else if (c == esquerda && cout_pass <= 1){
										warning(3);
										tela_iniciar(-1);
										while (1){
											if (c == '0')
												goto back4;
											c = getch();	
										}
										
									}

									pass_lines = 9*cout_pass;
									if(pass_lines <= n){
										for(i = 0,j = 9*cout_pass - 9;j < pass_lines ;i++,j++){
											gotoxy(i+5,3);
											printf("Rank %d) %s Cod: %d Quantidade: %d\n",i+1,t[i]->nomes[0],t[i]->cod[0],t[i]->num_product_list);
										}
										gotoxy(16,3);
										printf("Press =>) para mais Opções!!");
									
									} else if (pass_lines > n){
										pass_lines = n - 9*(cout_pass - 1);

										for(i = 5,k = 1,j = 9*(cout_pass - 1);j < n;i++,j++,k++){
											gotoxy(i,3);
											printf("Press %d) %s\n",k,t[i]->nomes[0]);
										}

									}
									
									
									if(cout_pass > 1){
										gotoxy(17,3);
										printf("Press <=) para voltar as Opções!!");
									
									}  
								}	

							}



						if (c -'0' == 0 ){
							goto back2;
						}

						c = getch();


						} 

					} else if (u != 0 ) {
						clear();
						warning(1);
						tela_iniciar(-1);
						while (1){
							if (c - '0' == 0)
								goto back2;
							c = getch();	
						}


					}

				} else if (c - '0' == 0){
					goto reset;
				} 

			}
		
// Caso 2 ************************************************

		} else if (c - '0' == 2){




		} else if (9){
			while(1){
				clear();
				tela_iniciar(-1);
				gotoxy(3,3);
				printf("Ajustando os botoes de Esquerda e direita");
				gotoxy(4,3);
				printf("direita (symbol) = %d", direita);
				gotoxy(5,3);
				printf("esquerda (symbol) = %d", esquerda);
				direita = c = getch();
				gotoxy(4,3);
				printf("direita (symbol) = %d", direita);
				esquerda = c = getch();
				gotoxy(5,3);
				printf("esquerda (symbol) = %d", esquerda);
				gotoxy(7,3);
				printf("Isso esta certo?" );
				gotoxy(8,3);
				printf("1) sim");
				gotoxy(9,3);
				printf("2) não");
				c = getch();
				if (c - '0' == 1)
					goto reset;
				else if (c - '0' != 1 && c - '0' != 2) {
					clear();
					warning(1);
					tela_iniciar(-1);
					while (1){
						if (c - '0' == 0)
							goto back2;
						c = getch();	
					}


				}
			}

		}

		/*else if (c - '0' != 1 && c - '0' != 0 && c - '0' != 2 && c - '0' != 3 && c - '0' != 4 && c - '0' != 5 && c - '0' != 6 && ) {


		}*/	
		c = getch();
	}
	
}

//***************************************************************
//***************************************************************
//Telas
void tela_padrao(void) {
	int nrows, ncols; // numero de linhas e colunas do terminal
	nrows = get_terminal_nrows();
	ncols = get_terminal_ncols();
	window(1, 1, ncols, nrows, "Data Mining");
}

void tela_main (void){
	gotoxy(3,3);
	printf("Menu inicial");
	gotoxy(4,3);
	printf("Press 1) Iniciar");
	gotoxy(5,3);
	printf("Press 0) Encerrar");
}
void tela_iniciar(int type){
	int ncols = get_terminal_ncols();
	/*
	type 0 >> 1 - 9 opçoes
	type n >> 1 - n  opçoes, sendo n < 9 
	*/
	tela_padrao();

	if (type == 0) {
		gotoxy(3,3);
		printf("!Prgrama carregado! --- !Calculos Prontos!");
		gotoxy(4,3);
		printf("O que desejar saber?");
		gotoxy(6,3);
		printf("1) Lista de Produtos mais vendidos?");
		gotoxy(8,3);
		printf("2) A frequência que um par de produto é comprada em conjunto de 3 produtos?");
		gotoxy (10,3);
		printf("3) A frequência que três de produto são comprados em conjunto de 3 produtos?");
		gotoxy(12,3);
		printf("4) A probabilidade de alguem comprar um determinado produto,");
		gotoxy(13,3);
		printf("   baseado a frequência de compras feitas por pares?" );
		gotoxy(15,3);
		printf("5) A probabilidade de alguem comprar um determinado produto,");
		//printf("5) A chanse de alguem comprar um produto, se  ");
		gotoxy(16,3);
		printf("   baseado a frequência de vendas de conjuntos de 3 produtos?" );
		gotoxy(18,3);
		printf("6) A probabilidade de alguem comprar um determinado Par de produto,");
		gotoxy(19,3);
		printf("   baseado a frequência de vendas de conjuntos de 3 produtos?" );

		gotoxy(22,18);
		printf("   Press 9) para ajustar Direita e Esquerda");
	} else if (type == 1 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos" );
		gotoxy(5,3);
		printf("1) Deseja ver Todos");
		gotoxy (6,3);
		printf("2) Deseja especificar uma determinada Quantidade?\n");
	} else if (type == 2 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos" );
	} else if (type == 3 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos" );
	} else if (type == 4 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos" );
	} else if (type == 5 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos" );
	} else if (type == 6 ){
		gotoxy(4,3);
		printf("Lista de Produtos mais vendidos");
	} else if (type == 23){


	}

	gotoxy(22,3);
	printf("Press 0) EXIT");


}

//***************************************************************
//***************************************************************
//Calculos De supports e Confiança

/*void calculos(tab **t, tab **t3, tab **t3, con **c2, con **c3_1, con **c3_2){

	int n,i,j,y,k,l,lines_table = 0,total_product_1 = 0,n_two_table = 0,n_three_table = 0; 
	char c,*local= "table.txt",*file = "teste_file.txt";
	
}*/
