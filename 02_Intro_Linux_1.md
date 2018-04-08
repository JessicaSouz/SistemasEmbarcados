Data: 09/03/2017

1. Por que o Linux recebeu esse nome?
	R: Foi nomeado em homenagem a seu criador, Linus Tovalds.

2. O que são daemons?
	R: Daemons são programas que rodam no plano de fundo de um sistema, não sendo controlados diretamente pelo usuário.

3. O que é o shell?
	R: Shell é uma interface de usuário que permite o acesso aos serviços de um sistema operacional. Elas podem usar uma interface por linhas de comando (CLI), ou uma interface gráfica (GUI).

4. Por que é importante evitar executar o terminal como super-usuário?
	R: As permissão em comandos com super-usuário pode realizar qualquer alteração em pastas e arquivos, e deve ser utilizado com precaução para que assim se evite danos ao sistema operacional.

5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?
	R: TAB
6. Quais botões do teclado apresentam instruções escritas anteriormente?
	R: Arrow-up (Seta pra cima)

7. Apresente os respectivos comandos no terminal para:
  (a) Obter mais informações sobre um comando.
	R: man "nomedocomando"
  (b) Apresentar uma lista com os arquivos dentro de uma pasta.
	R: ls
  (c) Apresentar o caminho completo da pasta.
	R: pwr
  (d) Trocar de pasta.
	R: cd  
  (e) Criar uma pasta.
	R: mkdir	
  (f) Apagar arquivos definitivamente.
	R: rm
  (g) Apagar pastas definitivamente.
	R: rmdir -r
  (h) Copiar arquivos.
	R: cp
  (i) Copiar pastas.
	R: cp -r "pasta"/ "novonomedapasta"
  (j) Mover arquivos.
	R: mv "arquivo" "local/"
  (k) Mover pastas.
	R: mv "pasta1/" "pasta2/"
  (l) Renomear pastas.
	R: mv "nomeatualdapasta" "nomenovodapasta"
  (m) Apresentar o conteúdo de um arquivo.
	R: cat "nomedoarquivo.txt"
  (n) Apresentar o tipo de um arquivo.
	R: file "nomedoarquivo" 
  (o) Limpar a tela do terminal.
	R: clear
  (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.
	R: cat "nomedoarquivo" | grep "arquivocompalavraschave"
  (q) Ordenar informações em um arquivo-texto.
	R: sort -flags "nomedoarquivo"
  (r) Substituir ocorrências de palavras-chave em um arquivo-texto.
	R: Na primeira ocorrencia: sed -e s/"palavrasubstituida"/"palavrasubstituta" "nomedoarquivo.txt"
	   Em todas as ocorrencias: sed -e s/"palavrasubstituida"/"palavrasubstituta"/g "nomedoarquivo.txt"
  (s) Conferir se dois arquivos são iguais.
	R: diff "arquivo1" "arquivo2"
  (t) Escrever algo na tela.
	R: printf "algo \n"
