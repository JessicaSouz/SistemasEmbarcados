#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TEMPO_ESPERA 1000000

int main(){

	while(1){
		system("./entrada");

		usleep(TEMPO_ESPERA);

		system("./saida");

		usleep(TEMPO_ESPERA);
	}
		
	return(0);
}
