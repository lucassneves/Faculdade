#include "my_lib.h"

int main(){
	int u,c;
	char *path = "./database/";
	dir_tree* d;
	read_state(1,d);
	if(HAS_DIRECTORY != 1){		
		mkdir("database");
		filegen(path,4,4,25,"table.txt");
		write_state(1,d);
	}
	make_dir(&d,path);
	scan_dir(d,path);

	print_dir(d,0);

	inicio:
	for (u = 0 ;1;u = 1){	
		clear();
		tela_padrao ();
		tela_main ();

		if (c == '0' && u == 1) {
			clear();		
			return 0;

		} else if (c == '1' && u == 1){
			iniciar();
			goto inicio;
		
		} else if (c != '1' && c!= '0' && u == 1) {
			warning(1);
			gotoxy(3,3);
			tela_main();
		}
		c = getch();	
	}
	
	free_dir(d);

	return 0;
}
