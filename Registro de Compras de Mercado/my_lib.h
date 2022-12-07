/* Functions that will be used on the Data-Mining project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "termip.h"
#include "22.h"

// --------------------------------------------------------
// ------------ DEFINITIONS -------------------------------
// --------------------------------------------------------


#define MAX_PROD_PER_LINE 4
#define MAX_QNT 100

char buff[200];

int HAS_DIRECTORY;
// --------------------------------------------------------
// ------------ ERRORS ------------------------------------
// --------------------------------------------------------


unsigned int ERR;
/*
	2⁰ = read_file (malloc n_prod)
	2¹ = read_file (malloc n_category)
	2² = read_file (malloc n_line)
	2³ = read_file (malloc n_line[i])
	2⁴ = read_file (malloc n_line[i][j].name)

	2⁵ = make_dir (malloc tree)
	2⁶ = make_dir (malloc path)
	2⁷ = make_dir (malloc type)
	2⁸ = make_dir (malloc files)
	
	2⁹ = make_file (malloc file)
	
	2¹⁰ = scan_dir (malloc sub_dir)
	
	2¹¹ = free_dir (free sub_dir[i])
	2¹² = free_dir (free files[i])
	2¹³ = free_dir (free path)
	2¹⁴ = free_dir (free type)
	2¹⁵ = free_dir (free files)
	2¹⁶ = free_dir (free dir)
	
	2¹⁷ = free_file (free line[i][j].name)
	2¹⁸ = free_file (free line[i])
	2¹⁹ = free_file (free line)
	2²⁰ = free_file (free category)
	2²¹ = free_file (free n_prod)
	2²² = free_file (free file)
*/
unsigned int ERR_FILEGEN;
/*
	
*/


// --------------------------------------------------------
// ------------ TYPES ------------------------------------- 
// --------------------------------------------------------


typedef struct product{
	int cod,quantity;
	char* name;
	float price_buy,price_sell,profit_margin;
}product;
/*
	> cod = product code on internal database.
	> quantity = amount of product that was bought or sold on this particular operation (check db_file documentation for more info).
	> name = product name for human interface.
	> price_buy:
		- operation = 1 : price paid by owner;
		- operation = 2 : price paid by customer.
	> price_sell:
		- operation = 1 : price the owner will sell the product for (margin applied);
		- operation = 2 : 0.00.
	> profit_margin:
		- operation = 1 : (price_sell/preice_buy)-1;
		- operation = 2 : -1.
*/

typedef struct db_file{
	int* category;
	product** line;
	int n_lines,*n_prod;
}db_file;
/*
	This struct maps a file into an easy-access matrix.
	> n_lines = number of lines found on the file (number of '\n' occurrences).
	> n_prod = number of products found on each line (integer array).
	> category = operation type for each line (integer array).
	> line = matrix of products, can be indexed using [i][j] for instance:
		- i = (0,n_lines);
		- j = (0,n_prod[i]).
*/

typedef struct dir_tree{
	db_file **files;
	char** path;
	int* type;
	int n_entries,n_folders;
	struct dir_tree** sub_dir;
}dir_tree;
/*
	> n_entries = number of items found on directory, can include folders, files, object-files... (does not include . and ..).
	> n_folders = number of items on directory, that are also folders.
	> type = integer array with size <n_entries>, encodes the type of the item:
		- 4 = folder;
		- 8 = text file.
	> path = name of the path, has <n_entries> lines, and the size of the name (+1 for '\0') columns.
	> files = array of pointers to db_files, each pointer maps to a line in <path> that has type != 4.
*/


// --------------------------------------------------------
// ------------ FUNCTIONS --------------------------------- 
// --------------------------------------------------------


void make_file(db_file** file);
/*
	Creates a blank structure, initializing every value with 0, and pointer with NULL.
*/

int make_dir(dir_tree** x,char* path);
/*
	Creates a blank structure, initializing every value with 0, and pointer with NULL.
*/

void free_file(db_file* file);
/*
	Frees struct, clearing the matrix of lines, and freeing every pointer.
*/

void free_dir(dir_tree* dir);
/*
	Frees struct recursively, freeing every pointer and calling the function to free every file on it as well.
*/

void print_file(char* filename, db_file* file);
/*
	Prints a struct db_file to text file (appends to the end), passed to this function via its name.
*/

void print_dir(dir_tree* dir, int level);
/*
	Prints a dir_tree to terminal, using indentation for better visualization.
	Also creates a file containing a list of all the operations in the database (optional).
*/

void read_file(char* filename, db_file* file);
/*
	Fills a struct db_file by reading a text file, passed to this function via its name.
*/

void scan_dir(dir_tree* Tree,char* path);
/*
	Fills a dir_tree, recursively scanning each sub directory, reading its files and filling the correspondig db_files, as well as each product.
*/

void sort_dir_tree(dir_tree* dir);
/*
	Sorts a dir_tree:
	- Folders are listed on the first <dir->n_folders> positions;
	- Files and folders are listed in ascending order (string value), respecting the first restriction.
*/

char *path_concatenate(char *str1, char *str2);
/*
	Similar (if not equal) to strcat, from <string.h>.
	Returns a single string comprised of str1 followed by str2.
*/

int countproduct(char *filename, int line);
/*
	Returns the number of products found on the line, the file is parsed by its name, and the line as an integer value.
*/

int countlines(char *filename);
/*
	Returns the number of '\n' found on the file, given to this function by its name.
*/

int countfiles(char* dirname);
/*
	Returns the number of entries found on directory (INCLUDES . AND ..).
*/

FILE* read_state(int n, void* x);
/*
	Search current directory for state file, if it is found, resume program execution from there.
*/

void write_state(int n, void* x);
/*
	Writes current state of the program to a file on the current directory:
	> 1 = write HAS_DIRECTORY to file, to indicate that the database has been created 
	> 2 = write tabela
	> 3 = write tabela_2_product
	> 4 = write tabela_3_product
	> 5 = write confidence_2_product
	> 6 = write confidence_3_product_mod_one
	> 7 = write confidence_3_product_mod_two
	> 0 = finished execution
*/
void filegen(char* path,int n_dir, int n_files, int n_lines, char *table_name);
/*
	Used to generate the constrained random database, used here merely as an example.
*/
