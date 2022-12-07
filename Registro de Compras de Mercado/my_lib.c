#include "my_lib.h"

void make_file(db_file** file){
	db_file* x = malloc(sizeof(db_file));
	if(!x){
		ERR += 512;
		return;
	}
	x->line = NULL;
	x->n_prod = NULL;
	x->category = NULL;
	x->n_lines = 0;
	*file = x;
}

int make_dir(dir_tree** x, char* path){
	int i;
	dir_tree* Tree = malloc(sizeof(dir_tree));
	if(!Tree){
		ERR += 32;
		return -1;
	}
	Tree->n_entries = countfiles(path)-2;
	Tree->path = malloc(Tree->n_entries*sizeof(char*));
	if(!Tree->path){
		ERR += 64;
		return -1;
	}
	Tree->type = malloc(Tree->n_entries*sizeof(int));
	if(!Tree->type){
		ERR += 128;
		return -1;
	}
	Tree->files = malloc(Tree->n_entries*sizeof(db_file));
	if(!Tree->files){
		ERR += 256;
		return -1;
	}
	for(i=0;i<Tree->n_entries;i++){
        	Tree->type[i] = 0;
	        Tree->path[i] = NULL;
		Tree->files[i] = NULL;
	}
	Tree->sub_dir = NULL;
	Tree->n_folders = 0;
	*x = Tree;
    
	return 0;
}

void free_file(db_file* file){
	int i,j,k;
	for(i=0;i<file->n_lines;i++){
		for(j=4;j<file->n_prod[i];j++){
			if(!file->line[i][j].name){
				ERR += 131072;
				printf("%d,%d\n",i,j);
				break;
			}else free(file->line[i][j].name);
		}
		if(!file->line[i]){
			ERR += 262144;
			break;
		}else free(file->line[i]);
	}
	if(!file->line){
		ERR += 524288;
	}else free(file->line);
	if(!file->category){
		ERR += 1048576;
	}else free(file->category);
	if(!file->n_prod){
		ERR += 2097152;
	}else free(file->n_prod);
	if(!file){
		ERR += 4194304;	
	}else free(file);
}

void free_dir(dir_tree* dir){
	int i;
	for(i=0;i<dir->n_entries;i++){
		if(dir->type[i]==4){if(!dir->sub_dir[i]){
				ERR += 2048;
				break;
			}else free_dir(dir->sub_dir[i]);
		}else{
			if(!dir->files[i]){
				ERR += 4096;
				break;
			}else free_file(dir->files[i]);
		}
		free(dir->path[i]);
	}
	if(!dir->path){
		ERR += 8192;
	}else free(dir->path);
	if(!dir->type){
		ERR += 16384;
	}else free(dir->type);
	if(!dir->files){
		ERR += 32768;
	}else free(dir->files);
	if(!dir){
		ERR += 65536;
	}else free(dir);
}

void print_file(char* filename, db_file* file){
	FILE *f = fopen(filename,"a");
	int i,j=0;

	for(i=0;i<file->n_lines;i++){
		fprintf(f,"%d",file->category[i]);
		for(j=0;j<file->n_prod[i];j++){
			fprintf(f," %d %d %s %.2f %.2f",file->line[i][j].cod,file->line[i][j].quantity,file->line[i][j].name,file->line[i][j].price_buy,file->line[i][j].price_sell);
		}
		fprintf(f,"\n");
	}

	fclose(f);
}

void print_dir(dir_tree* dir,int level){
	int i,j,k;
	for(i=0;i<dir->n_entries;i++){
  		for(j=0;j<level;j++) printf("\t");
		printf("%s\n",dir->path[i]);
		if(dir->type[i]==4){
    			print_dir(dir->sub_dir[i],level+1);
	    	}else print_file("teste_file.txt",dir->files[i]);
	}
}

void read_file(char* filename, db_file* file){
	FILE *fp = fopen(filename,"r");
	int i,j;
	char x;
	
	file->n_lines = countlines(filename);
	file->n_prod = malloc(file->n_lines*sizeof(int));
	if(!file->n_prod){
		ERR += 1;
		return;
	}
	file->category = malloc(file->n_lines*sizeof(int));
	if(!file->category){
		ERR += 2;
		return;
	}
	file->line = malloc(file->n_lines*sizeof(product*));
	if(!file->line){
		ERR += 4;
		return;
	}
	
	for(i=0;i<file->n_lines;i++){
		file->n_prod[i] = countproduct(filename,i);
		file->line[i] = malloc(file->n_prod[i]*sizeof(product));
		if(!file->line[i]){
			ERR += 8;
			return;
		}
	}
	for(i=0;i<file->n_lines;i++){
		fscanf(fp,"%d",&file->category[i]);
		for(j=0;j<file->n_prod[i];j++){
			fscanf(fp,"%d%d%*c%s%f%f",&file->line[i][j].cod,&file->line[i][j].quantity,buff,&file->line[i][j].price_buy,&file->line[i][j].price_sell);
			file->line[i][j].profit_margin = (file->line[i][j].price_sell/file->line[i][j].price_buy)-1;
			file->line[i][j].name = malloc((strlen(buff)+1)*sizeof(char));
			if(!file->line[i][j].name){
				ERR += 16;
				return;
			}
			strcpy(file->line[i][j].name,buff);
		}
	}
	
	fclose(fp);
}

void scan_dir(dir_tree* tree, char* path){
	int i=0;

	struct dirent *dp;
    
	DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
	while (dp=readdir(dir)){ // if dp is null, there's no more content to read
		if( strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0 ) continue;
   		tree->path[i] = path_concatenate(path, dp->d_name);
	   	tree->type[i] = dp->d_type;
		if(tree->type[i]!=4){
			make_file(&tree->files[i]);
			read_file(tree->path[i],tree->files[i]);
		}
	   	if(tree->type[i]==4){
			tree->n_folders++;
		}
        	i++;
    	}
	sort_dir_tree(tree);
    
	if(tree->n_folders>0){
		tree->sub_dir = malloc(tree->n_folders*sizeof(dir_tree*));
		if(!tree->sub_dir){
			ERR += 1024;
			return;
		}
	    	for(i=0;i<tree->n_folders;i++){
			make_dir(&tree->sub_dir[i],path_concatenate(tree->path[i],"/"));
	    		scan_dir(tree->sub_dir[i],path_concatenate(tree->path[i],"/"));
	    	}
    	}

	closedir(dir); // close the handle (pointer)
}

void sort_dir_tree(dir_tree* dir){
	int i,j=0;
	char* path_tmp;
	db_file* file_tmp;
	int type_tmp;
	for(i=0;i<dir->n_entries;i++){
		if(dir->type[i]==4){
			path_tmp = dir->path[j];
			dir->path[j] = dir->path[i];
			dir->path[i] = path_tmp;

			type_tmp = dir->type[j];
			dir->type[j] = dir->type[i];
			dir->type[i] = type_tmp;
			
			file_tmp = dir->files[i];
			dir->files[i] = dir->files[j];
			dir->files[j] = file_tmp;

			j++;
		}
	}
	for(i=0;i<dir->n_folders;i++) for(j=i;j<dir->n_folders;j++){
		if(strcmp(dir->path[i],dir->path[j])>0){
			path_tmp = dir->path[j];
			dir->path[j] = dir->path[i];
			dir->path[i] = path_tmp;

			file_tmp = dir->files[i];
			dir->files[i] = dir->files[j];
			dir->files[j] = file_tmp;
		}
	}
	for(i=dir->n_folders;i<dir->n_entries;i++) for(j=i;j<dir->n_entries;j++){
		if(strcmp(dir->path[i],dir->path[j])>0){
			path_tmp = dir->path[j];
			dir->path[j] = dir->path[i];
			dir->path[i] = path_tmp;

			file_tmp = dir->files[i];
			dir->files[i] = dir->files[j];
			dir->files[j] = file_tmp;
		}
	}
}

char* path_concatenate(char *str1, char *str2){
    char *res;
    size_t strlen1 = strlen(str1);
    size_t strlen2 = strlen(str2);
    int i, j;
    res = malloc((strlen1+strlen2+1)*sizeof *res);
    strcpy(res, str1);
    for (i=strlen1, j=0; ((i<(strlen1+strlen2)) && (j<strlen2)); i++, j++)
        res[i] = str2[j];
    res[strlen1+strlen2] = '\0';
    return res;
}

int countlines(char *filename){                                 
	FILE *fp = fopen(filename,"r");
	int ch=0;
	int lines=0;
	if(fp == NULL) return 0;
	while ((ch = fgetc(fp)) != EOF) if(ch == '\n') lines++;
	fclose(fp);
	return lines;
}

int countfiles(char* dirname){
	int n=0;
	struct dirent *dp;
	DIR *dir = opendir(dirname);
	while (dp=readdir(dir)) n++;
    	return n;
	closedir(dir);
}

int countproduct(char *filename, int line){
	FILE *fp = fopen(filename,"r");
	int n=1;
	char x='0';
	while(line>0){
		fgets(buff,sizeof(buff),fp);
		line--;
	}
	while(x!='\n'){
		x=getc(fp);
		if(x==' ') n++;
	}
	fclose(fp);
	return (n+1)/5;
}

FILE* read_state(int n, void* x){
	FILE* f = fopen("state.txt","r");
	int i,j;
	if(n == 1 && f!= NULL){
		fscanf(f,"%s",buff);
		if(strcmp(buff,"HAS_DIRECTORY")==0) HAS_DIRECTORY = 1;
		fclose(f);
	}
	
	
}

void write_state(int n, void* x){
	int i,j;
	if(n==1){ //void* = dir_tree pointer
		FILE *f = fopen("state.txt","a");
		dir_tree *d = x;
		fprintf(f,"HAS_DIRECTORY\n");
	}
/*	if(state==2){ //write tabela
		struct tabela* t = x;
		FILE* f = fopen("state.txt","a");
		
		fprintf(f,"%d %s %d %.4f\n",t->cod,t->nome,t->num_product_list,t->support);

		fclose(f);
	}
	if(state==3){ //write tabela_2_product
		struct tabela_2_product* t2p = x;
		FILE* f = fopen("state.txt","a");

		fprintf(f,"%d %d %s %s %d %.4f %.4f %.4f\n",t2p->cod_1,t2p->cod_2,t2p->nome_1,t2p->nome_2,t2p->num_product_list,t2p->support_1,t2p->support_2,t2p->support_1_e_2);

		fclose(f);
	}
	if(state==4){ //write tabela_3_product
		struct tabela_3_product* t3p = x;
		FILE* f = fopen("state.txt","a");

		fprintf(f,"%d %d %d %s %s %s %d %.4f %.4f %.4f %.4f\n",t3p->cod_1,t3p->cod_2,t3p->cod_3,t3p->nome_1,t3p->nome_2,t3p->nome_3,t3p->num_product_list,t3p->support_1,t3p->support_2,t3p->support_3,t3p->support_1_e_2,t3p->support_1_e_3,t3p->support_3_e_2,t3p->support_1_2_3);

		fclose(f);
	}
	if(state==5){ //write confidence_2_product
		struct confidence_2_product* c2p = x;
		FILE* f = fopen("state.txt","a");

		fprintf(f,"%s %s %s %d %d %d %.4f\n",c2p->product1,c2p->product2,c2p->product3,c2p->cod_1,c2p->cod_2,c2p->cod_3,c2p->confidence);

		fclose(f);
	}
	if(state==6){ //write confidence_3_product_mod_one
		struct confidence_3_product_mod_one* c3p1 = x;
		FILE* f = fopen("state.txt","a");

		fprintf(f,"%s %s %s %s %d %d %d %d %.4f\n",c3p1->product1,c3p1->product2,c3p1->product3,c3p1->product4,c3p1->cod_1,c3p1->cod_2,c3p1->cod_3,c3p1->cod_4,c3p1->confidence);

		fclose(f);
	}
	if(state==7){ //write confidence_3_product_mod_two
		struct confidence_3_product_mod_two* c3p2 = x;
		FILE* f = fopen("state.txt","a");

		fprintf(f,"%s %s %s %s %s %d %d %d %d %d %.4f\n",c3p2->product1,c3p2->product2,c3p2->product3,c3p2->product4,c3p2->product5,c3p2->cod_1,c3p2->cod_2,c3p2->cod_3,c3p2->cod_4,c3p2->cod_5,c3p2->confidence);

		fclose(f);
	}*/

}

void filegen(char* path, int n_dir, int n_files, int n_lines, char *table_name){
	struct dirent *dp;
	DIR *dir = opendir(path);
	DIR *sub_dir;
	FILE *files[n_files];
	char *name,*dirname,*filename,*fullpath;
	int i,j,k,l,m,cod,qnt,type,n_prod;
	float pv,pb,margin;
	
	FILE *table = fopen(table_name,"r");
	int tab_size = countlines(table_name);
	int *codes = malloc(tab_size*sizeof(int));
	char **names = malloc(tab_size*sizeof(char*));
	float *prices = malloc(tab_size*sizeof(float));
	
	for(i=0;i<tab_size;i++){
		fscanf(table,"%d%*c%s%f",&codes[i],buff,&prices[i]);
		names[i]=malloc(strlen(buff)+1*sizeof(char));
		strcpy(names[i],buff);
	}
	
	fclose(table);

	srand(time(NULL));
	for(i=0;i<n_dir;i++){
		dirname = malloc(10*sizeof(char));
		sprintf(dirname,"day_%d",i);
		fullpath = path_concatenate(path,dirname);
		mkdir(fullpath,0777);
		sub_dir = opendir(path_concatenate(fullpath,"/"));
		for(j=0;j<n_files;j++){
			filename = malloc(10*sizeof(char));
			sprintf(filename,"%s/file_%d",fullpath,j);
			files[j] = fopen(filename,"w");
			for(k=0;k<n_lines;k++){
				type = rand()%2+1;
				fprintf(files[j],"%d",type);
				n_prod = rand()%MAX_PROD_PER_LINE+1;
				for(m=0;m<n_prod;m++){
					cod = rand()%tab_size+1;
					qnt = rand()%MAX_QNT+1;
					for(l=0;l<tab_size;l++){
						if(cod == codes[l]){
							name = names[l];
							pb = qnt*prices[l];
							margin = (float)(rand())/(float)(RAND_MAX);
							if(type == 1) pv = pb*(1+margin/2);
							else pv = 0;
						}
					}
					fprintf(files[j]," %d %d %s %.2f %.2f",cod,qnt,name,pb,pv);
				}
				fprintf(files[j],"\n");
			}
			free(filename);
		}
		for(j=0;j<n_files;j++) fclose(files[j]);
		free(dirname);
		free(fullpath);
	}
	free(codes);
	for(i=0;i<tab_size;i++) free(names[i]);
	free(names);
	free(prices);
}
