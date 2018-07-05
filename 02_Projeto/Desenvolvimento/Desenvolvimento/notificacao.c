#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void montar_php(char * chat_id, char * placa, char * modelo, char * cor, int opcao){
	FILE *fp;

	fp = fopen("update.php","w");
	if(!fp){
		printf("Erro na abertura do arquivo php. Fim do programa.");
		exit(1);
	}

	fprintf(fp, "<?php\n$apiToken = \"597705993:AAHNvx7SV5FjRwQxuDnTokasA8FTl0ADVMM\";\n");
	fprintf(fp, "$data = [\n\t'chat_id' => '%s',\n", chat_id);
	if (opcao == 1){
		fprintf(fp, "\t'text' => 'Seu carro %s de cor %s e placa %s entrou no estacionamento!'\n];\n", modelo, cor, placa);
	} else {
		fprintf(fp, "\t'text' => 'Seu carro %s de cor %s e placa %s saiu do estacionamento!'\n];\n", modelo, cor, placa);
	}
	
	fprintf(fp, "$response = file_get_contents(\"https://api.telegram.org/bot$apiToken/sendMessage?\" . http_build_query($data) );\n?>");

	fclose(fp);
}

void salvar_usuario(){
	char comando[39];
	char * line = NULL;
	size_t len = 0;
    ssize_t read;
	FILE * fp;
	int count = 0;

	fp = fopen("temp.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	/* Pega a linha 2 para salvar o nome da placa */
    read = getline(&line, &len, fp);
    read = getline(&line, &len, fp);
    strtok(line, "\n");
    
    sprintf(comando, "cp temp.txt Banco_de_Dados/%s.txt", line);
    system(comando);

    fclose(fp);
    if (line)
        free(line);
    system("rm temp.txt");
}

void organizar_banco(){
	char comando_listar[30];
	char comando_remover[14];
	char comando[38];
	char arquivo[14];
	char * line = NULL;
	size_t len = 0;
    ssize_t read;
	FILE * fp;

	/* Lista todos os arquivos que começem com numeros */
	sprintf(comando_listar, "ls | grep '^[0-9]' > chats.txt");
	system(comando_listar);

	fp = fopen("chats.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
    	/* Retira o \n e deleta primeira palavra de cada linha */
		strtok(line, "\n");
        sprintf(comando, "sed 's/.* //' %s > temp.txt", line);
        system(comando);
		
		/* Salva no Banco de Dados as informações do usuário*/
		salvar_usuario();

		/* Remover o arquivo salvo pelo bot*/
		sprintf(comando_remover, "rm %s", line);
		system(comando_remover);
    }

    fclose(fp);
    if (line)
        free(line);

    system("rm chats.txt");
}

int main(int argc, char *argv[]){
	char arquivo[26];
	char * chat_id = NULL; char * placa = NULL; char * modelo = NULL; char * cor = NULL;
	size_t len = 0;
    ssize_t read;
	FILE * fp;
	
	if(argc < 3){  
		printf("---------------------------------------\n");
		printf("Erro na execução da notificação. Sem arquivo de imagem.\n");
		printf("---------------------------------------\n");
		exit(1);
	}
	
	organizar_banco();

	sprintf(arquivo, "Banco_de_Dados/%s.txt", argv[1]);

	fp = fopen(arquivo, "r");
    if (fp == NULL){
    	printf("Não existe arquivo: %s\n", argv[1]);
        exit(1);
    }

	getline(&chat_id, &len, fp);
	strtok(chat_id, "\n");
	
	getline(&placa, &len, fp);
	strtok(placa, "\n");
	
	getline(&modelo, &len, fp);
	strtok(modelo, "\n");
	
	getline(&cor, &len, fp);
	strtok(cor, "\n");

	montar_php(chat_id, placa, modelo, cor, atoi(argv[2]));

  	system("php update.php");

  	system("rm update.php");
  	free(chat_id);
  	free(placa);
  	free(modelo);
  	free(cor);

	return(0);
}
