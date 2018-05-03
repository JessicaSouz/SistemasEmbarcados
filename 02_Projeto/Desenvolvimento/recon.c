#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvar_acesso(char * placa){
	FILE *fp, *f_access;
	char filename[26];
	char semana[3], data[10], hora[8];
	
	system("date +'%a %d/%m/%Y %H:%M:%S' > acesso.txt");

	sprintf(filename, "Banco_de_Dados/%s.txt", placa);
	
	f_access = fopen("acesso.txt","r");
	fp = fopen(filename,"a+");
	
	if(!fp && !f_access){
		printf("Erro na abertura dos arquivos. Fim do programa.");
		exit(1);
	}	
	fseek(fp, 0, SEEK_END);
	
	fscanf(f_access, "%s %s %s", semana, data, hora);
	fprintf(fp, "%s %s %s\n", semana, data, hora);

	fclose(f_access);
	fclose(fp);
}

int main(int argc, char *argv[]){
	
	char openalpr[183];
	char comando[52];
	char placa[7];
	char arquivo[15];
	FILE *fp;

	if(argc < 2){  
		printf("---------------------------------------\n");
		printf("Erro na execução. Sem arquivo de imagem\n");
		printf("Fim do programa\n");
		printf("---------------------------------------\n");
		exit(1);
	}

	strncpy(arquivo, argv[1], 15);

	sprintf(comando, "alpr -c br %s.jpg > placa.txt", arquivo);
	system(comando);

  	fp = fopen("placa.txt","r+");
	if(!fp){
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	
	fseek (fp , 25 , SEEK_SET );
	fscanf(fp, "%s", placa);
	
	fclose(fp);

  	salvar_acesso(placa);

	return(0);
}