#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void menu(){
//	system("cls"); //ekraný temizliyor
	printf("\n");
	printf("\nTurnuva Duzenleme Otomasyonu...\n");
	printf("\nMenuden secim yapiniz: \n");
	printf("\n1. Takimlari Oku  \n");
	printf("2. Karistir &  Ekrana Bas & Dosyaya Yaz \n");
	printf("3. Cikis \n");
	
	
}


void takimlariOku(){ //menudeki 1. seçenek için gerekli fonksiyon. Takimlar dosyasýndaki verileri ekrana basýyor.
	
	
	char karakter;
	FILE *file;
	file=fopen("takimlar.txt", "r");
	if(file){  //dosya varmi kontrol ediyoruz
		
		karakter=fgetc(file);
		while(karakter!=EOF){  //dosyanýn içindeki son karaktere kadar okur
			printf("%c",karakter);
			karakter=fgetc(file);
		}
		
	
	
		fclose(file);
		
	}else{
		printf("Dosya bulunamadi!");
	}
	
	
}

void rasgeleSirala(int rasgeleDizisi[], int n){  //1 den 32 ye kadar olan sayýlarý rasgele dizdik, dosyadan çektiðimiz takimlarý bu sýraya göre dosyaya yazdýk.
	int rasgele;
	int i;
	int temp;
	srand(time(NULL));
	for(i=n-1;i>0;i--){
		
		  int j=rand()%(i+1);
		  temp=rasgeleDizisi[i];
		  rasgeleDizisi[i]=rasgeleDizisi[j];
		  rasgeleDizisi[j]=temp;
		}
}

void karistir(){  //menudeki 2.seçenek takimlarý rasgele sýralayýp 4 erli gruba ayýrýyor ve gruplar.txt dosyasýna basýyor
	int rasgeleDizisi[36]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
	rasgeleSirala(rasgeleDizisi,36);
	
	char takimlars[40][40];
	/*int a;
 	char **takimlars;    //yapamadýðým kýsým. 2 boyutlu dinamik array oluþturamadým. 83.satýrdaki While döngüsünde hata aldým.
	takimlars=(char**)malloc(M*sizeof(char));
	for(a=0;a<2;a++){
		takimlars[a]=(char*)malloc(N*sizeof(char));
	} */
	/* int n1=4;
	int n2=9;
	int p;
 	double **C = (double **)malloc(n1 * sizeof(double *));
	for (p = 0; p < n1; p++) {
		C[p] = (double *)malloc(n2 * sizeof(double));
		}*/
	
	FILE *file;
	file=fopen("takimlar.txt", "r");
	int j;
	int i=0;
	int k,s;
	int sira;
	int grup=0;
	int son=4;
	int bas=1;
	
	if(file){
		while (!feof(file)){ 
			sira=rasgeleDizisi[i];
			fgets(takimlars[sira],32,file);
			takimlars[sira][strlen(takimlars[sira])-1]='\0';
			i++;		
						
		}
		
	FILE *filee;
	filee=fopen("gruplar.txt", "w");

	for(k=0;k<9;k++){   //ekrana basma ve dosyaya yazma
		printf("%d . Grup \n",(k+1));
		fprintf(filee,"%d . Grup \n",(k+1));
			for(s=grup;s<son;s++){					
					printf("\t %d . %s \n", (bas),takimlars[s]);
					fprintf(filee,"\t %d . %s \n", (bas++),takimlars[s]);
			}
			bas=1;
			grup+=4;
			son+=4;
		printf("\n");
		fprintf(filee,"\n");
	}
		fclose(file);
		fclose(filee);
	}
	else{
		printf("dosya bulunamadý");
	}
	
}





