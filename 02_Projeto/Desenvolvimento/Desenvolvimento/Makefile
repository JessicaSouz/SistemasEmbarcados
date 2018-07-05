all: main

main: main.c entrada.c saida.c recon.c notificacao.c
	gcc -o main main.c
	gcc -o entrada entrada.c
	gcc -o saida saida.c
	gcc -o recon recon.c
	gcc -o notificacao notificacao.c

clean:
	rm -rf main
	rm -rf entrada
	rm -rf saida
	rm -rf recon
	rm -rf notificacao