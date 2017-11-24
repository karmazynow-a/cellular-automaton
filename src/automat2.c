#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



# define ROZ 30
# define OP 7500


int main(void){

/***** INICJALIZACJA */
	char * tab = malloc (ROZ+1);
	char *tab_p =malloc (ROZ+1);

	int i;
	for (i=0; i<ROZ; i++){
		*(tab+i)='-';
		*(tab_p+i)='-';
	}

	*(tab+ ROZ/2) = 'x';
	*(tab+ROZ +1) = '\0';
	*(tab_p+ROZ +1) = '\0';

//puts(tab);
//puts("\n");

/***** WYŚWITLANIE*/
	int j=0;
	while(j==0){
		for (i=1; i<ROZ-1; i++){
			if ((tab[i-1] == 'x' && tab[i]==tab[i+1] && tab[i+1]=='-') ||(tab[i-1]== '-' && tab[i]==tab[i+1] && tab[i+1]=='x') || (tab[i] == 'x'&& tab[i-1]==tab[i+1] && tab[i+1]=='-') || (tab[i+1] == 'x'&& tab[i-1]==tab[i] && tab[i]=='-') ){tab_p[i] = 'x';}
			else {tab_p[i] = '-';}
			}

    czekaj();
	//puts (tab);
	//printf("%s\r", tab);
	system("clear");
	printf("%s\n%s", tab, tab_p);
	if (memcmp (tab, tab_p, ROZ)==0) break;
	memmove(tab, tab_p, ROZ);
	}


free (tab);
free (tab_p);
return 0;
}

void czekaj(){
	int czas = clock();
	while (clock() < czas + OP);
}




