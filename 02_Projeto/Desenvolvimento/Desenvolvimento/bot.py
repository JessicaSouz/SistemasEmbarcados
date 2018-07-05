from telegram.ext import Updater, CommandHandler
import logging
from subprocess import call

# Enable logging
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)


# Define a few command handlers. These usually take the two arguments bot and
# update. Error handlers also receive the raised TelegramError object in error.
def start(bot, update):
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'w')
    resposta_file.write('chat_id ' + str(ID) + "\n")

    #print ("%s %d", NOME_2,ID_2)
    update.message.reply_text(
        'Voce acaba de se cadastrar nas notificacoes do estacionamento da FGA!\n\n'
        'Mande /registrar para registrar seu veiculo ou /cancelar para parar de falar comigo.')

def registrar(bot, update):
    update.message.reply_text(
        'Ok, vamos comecar a registrar seu veiculo!\n\n'
        'Mande para mim a placa do seu veiculo da seguinte forma:\n/placa ABC1234')

def placa_para_modelo(bot, update):
    PLACA = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(PLACA + "\n")

    update.message.reply_text(
        'Registrada a sua placa!\n\n'
        'Agora mande para mim o modelo do seu veiculo da seguinte forma:\n/modelo nome')

def modelo_para_cor(bot, update):
    MODELO = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(MODELO + "\n")
    update.message.reply_text(
        'Anotado seu modelo!\n\n'
        'Ultima informacao, mande para mim a cor do seu veiculo da seguinte forma:\n/cor nome')

def cor_para_finalizar(bot, update):
    COR = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(COR + "\n")
    update.message.reply_text(
        'Pronto! Seu carro estah registrado no meu banco de dados.\n'
        'Sempre que ele entrar ou sair do estacionamento da FGA, voce ira receber uma notificacao!')

def help(bot, update):
    update.message.reply_text(
        'Eu soh respondo comandos existentes Help!')

def cancelar(bot, update):
    update.message.reply_text('Cancelei a sua inscricao para notificacao!\nAdorei conversar com voce ;)!\n\n'
                              'Se quiser receber novamente, mande /start para mim.\nAte mais!')
    call('cat "funcionou" > msg.txt')

def main():
    """Start the bot."""
    updater = Updater("597705993:AAHNvx7SV5FjRwQxuDnTokasA8FTl0ADVMM")

    dp = updater.dispatcher

    dp.add_handler(CommandHandler("start", start))
    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("cancelar", cancelar))
    dp.add_handler(CommandHandler("registrar", registrar))
    dp.add_handler(CommandHandler("placa", placa_para_modelo))
    dp.add_handler(CommandHandler("modelo", modelo_para_cor))
    dp.add_handler(CommandHandler("cor", cor_para_finalizar))

    updater.start_polling()

    updater.idle()


if __name__ == '__main__':
    main()