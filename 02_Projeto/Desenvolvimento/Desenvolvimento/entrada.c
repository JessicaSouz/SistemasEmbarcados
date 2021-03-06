#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TEMPO_ESPERA 10000000

int main(){
	int num_imagens;
	char line[32];
	char comando[31];
	FILE *file;
	FILE *file2;

	system("ls Entrada | wc -l > iniciar.txt");
	file = fopen("iniciar.txt","r");
	if(!file){
		printf("Erro na abertura do arquivo iniciar.txt.");
		exit(1);
	}
	
	fgets(line, sizeof(line), file);
    num_imagens = atoi(line);

    if (num_imagens > 0){
		system("gpio -g pwm 18 100");
    	system("ls Entrada/*.png > lista.txt");
    
		file2 = fopen("lista.txt","r");
		if(!file2){
			printf("Erro na abertura do arquivo lista.txt.");
			exit(1);
		}
		while (fgets(line, sizeof(line), file2)) {
			if(strcmp (line, "\n") != 0){
				sprintf(comando, "./recon %s 1", line);
				system(comando);
			}
		}
	    
	    fclose(file2);
		system("rm lista.txt");
		system("mv Entrada/* Imagens/Entrada/");
		
		usleep(TEMPO_ESPERA);
		system("gpio -g pwm 18 210");
	}

	fclose(file);
	system("rm iniciar.txt");
	
	return(0);
}
