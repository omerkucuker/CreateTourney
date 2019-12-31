#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int cikmaDurumu=0;
	while(cikmaDurumu==0){
	menu();
	scanf("%d", &choice);

		switch(choice){
		case 1:
			takimlariOku();
			break;
		case 2:
			karistir();
			break;
		
		case 3:
			cikmaDurumu=1;
			break;
		default:
			printf("hatali secim \n");
	   }
	}
	 
	
	
	return 0;
}
