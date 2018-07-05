#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvar_acesso(char * placa, int opcao){
	FILE *fp, *f_access;
	char file_entrada[42];
	char file_saida[40];
	char semana[3], data[10], hora[8];
	
	system("date +'%a %d/%m/%Y %H:%M:%S' > acesso.txt");

	if (opcao == 1){
		sprintf(file_entrada, "Banco_de_Dados/%s-acessos-entrada.txt", placa);
		fp = fopen(file_entrada,"a+");

	} else {
		sprintf(file_saida, "Banco_de_Dados/%s-acessos-saida.txt", placa);
		fp = fopen(file_saida,"a+");
	}

	f_access = fopen("acesso.txt","r");
		
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
	char comando[55];
	char notificacao[23];
	char placa[7];
	char temp[7] = "AAA1234";
	char line[33];
	char arquivo[32];
	int acao = 0;
	int count = 0;
	FILE *fp;

	if(argc < 3){
		printf("---------------------------------------\n");
		printf("Erro na execução do recon. Sem arquivo de imagem\n");
		printf("---------------------------------------\n");
		exit(1);
	}

	sprintf(comando, "alpr -c br %s > placa.txt", argv[1]);
	system(comando);

  	fp = fopen("placa.txt","r+");
	if(!fp){
		printf("Erro na abertura do arquivo placa.txt. Fim do programa.");
		exit(1);
	}

	fgets(line, sizeof line, fp);
	fgets(line, sizeof line, fp);
	
    memcpy(temp, &line[6], 7);
    strcpy(placa, temp);
    
    fclose(fp);
    
  	salvar_acesso(placa, atoi(argv[2]));

	sprintf(notificacao, "./notificacao %s %s", placa, argv[2]);
    system(notificacao);

  	system("rm placa.txt");
	system("rm acesso.txt");

	return(0);
}
