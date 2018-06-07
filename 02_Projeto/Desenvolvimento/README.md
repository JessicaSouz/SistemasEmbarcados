# FGParking

O projeto consiste em validar a entrada do veículo por reconhecimento de imagem da placa: ao entrar no estacionamento um sensor de movimento aciona uma câmera que captura a imagem da placa do veículo e, após processado os dados da placa, o usuário tem acesso à quantidade de vagas no estacionamento por um aplicativo/site. Além de recebe uma notificação pelo aplicativo, assim que entra informando o horário de entrada do veículo e, assim que sai, informando o horário de saída do estacionamento.

## Equipe

| Matrícula | Nome | GitHub | Papel |
| --- | --- | --- | --- |
| 14/0080619 | Camila Carneiro Ferrer Santos | [CamilaFerrer](https://github.com/CamilaFerrer) | Desenvolvedora |
| 14/0042784 | Jéssica de Souza Alves | [JessicaSouz](https://github.com/JessicaSouz) | Desenvolvedora |

## Execução

Para testar o andamento do programa, baixe a pasta **Desenvolvimento** no seu computador e salve-a dentro da pasta **Downloads**.

### Download de Programas

* Instale o programa OpenALPR:
[Compilation instructions (Ubuntu Linux)](https://github.com/openalpr/openalpr/wiki/Compilation-instructions-(Ubuntu-Linux))

* Instale o programa fswebcam:
```bash
sudo apt-get install fswebcam
```

* Entre na pasta **gpio-watch** e execute:
```bash
make
sudo make install
```

### Acionamento do Sistema (repositório gpio-watch)
Para observar botão que está conectado ao pin 23, execute a seguinte linha:

```bash
gpio-watch -e switch 23
cd /etc/gpio-scripts
sudo nano 23
```

Copie o código do arquivo webcam.sh e coloque dentro do arquivo aberto.

### Aquisição de Foto (webcam.sh)
Para a implementação desse processo, escrevemos um script Bash que tira as fotos dos veículos utilizando uma webcam. O script salva a imagem na pasta **Imagens** já criada dentro da pasta Desenvolvimento. Logo em seguida faça o arquivo ficar executável e mande rodá-lo:

```bash
chmod 777 23
```

### Reconhecimento da Placa (recon.c)
Existe 1 imagem no repositório disponíveis para testar o código e elas devem estar na mesma pasta que o arquivo recon.c. O nome das imagens devem ser no formato AAAA-MM-DD_HH-MM-SS.jpg e elas devem estar na pasta **Imagens**. Execute os seguintes comandos:

Entrando no estacionamento:
```bash
gcc -o recon recon.c
./recon Imagens/2018-04-27_16-45-25.jpg 1
```

Saindo do estacionamento:
```bash
gcc -o recon recon.c
./recon Imagens/2018-04-27_16-45-25.jpg 0
```

### Notificação
Para receber a notificação é necessário colocar o TOKEN do bot do telegram no arquivo bot.py na linha 81. Também é necessário colocar o CHAT_ID da pessoa que irá receber a notificação no arquivo Bando_deDados/FQF9941.txt. Por motivos de segurança, não disponibilizamos no Git o TOKEN e o CHAT_ID.
