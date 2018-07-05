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
    """Manda a mensagem quando o comando /start é enviado."""
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'w')
    resposta_file.write('chat_id ' + str(ID) + "\n")

    #print ("%s %d", NOME_2,ID_2)
    update.message.reply_text(
        'Você acaba de se cadastrar nas notificações do estacionamento da FGA!\n\n'
        'Mande /registrar para registrar seu veículo ou /cancelar para parar de falar comigo.')

def registrar(bot, update):
    """Manda a mensagem quando o comando /registrar é enviado."""
    update.message.reply_text(
        'Ok, vamos começar a registrar seu veículo!\n\n'
        'Mande para mim a placa do seu veículo da seguinte forma:\n/placa ABC1234')

def placa_para_modelo(bot, update):
    """Manda a mensagem quando o comando /placa é enviado."""
    PLACA = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(PLACA + "\n")

    update.message.reply_text(
        'Registrada a sua placa!\n\n'
        'Agora mande para mim o modelo do seu veículo da seguinte forma:\n/modelo nome')

def modelo_para_cor(bot, update):
    """Manda a mensagem quando o comando /modelo é enviado."""
    MODELO = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(MODELO + "\n")
    update.message.reply_text(
        'Anotado seu modelo!\n\n'
        'Ultima informação, mande para mim a cor do seu veículo da seguinte forma:\n/cor nome')

def cor_para_finalizar(bot, update):
    """Manda a mensagem quando o comando /cor é enviado."""
    COR = update.message.text
    ID = update.message.chat_id
    FILE = str(ID) + '.txt'
    resposta_file = open(FILE,'a')
    resposta_file.write(COR + "\n")
    update.message.reply_text(
        'Pronto! Seu carro está registrado no meu banco de dados.\n'
        'Sempre que ele entrar ou sair do estacionamento da FGA, você irá receber uma notificação!')

def help(bot, update):
    """Send a message when the command /help is issued."""
    update.message.reply_text(
        'Eu só respondo Comandos existentes Help!')

def cancelar(bot, update):
    """Manda a mensagem quando o comando /cancelar é enviado."""
    update.message.reply_text('Cancelei a sua inscrição para notificação!\nAdorei conversar com você ;)!\n\n'
                              'Se quiser receber novamente, mande /start para mim.\nAté mais!')
    #logger.info("Olá %s", user.first_name)
    call('cat "funcionou" > msg.txt')

def main():
    """Start the bot."""
    # Create the EventHandler and pass it your bot's token.
    updater = Updater("597705993:AAHNvx7SV5FjRwQxuDnTokasA8FTl0ADVMM")

    # Get the dispatcher to register handlers
    dp = updater.dispatcher

   # NOME_2 = user.full_name
    #ID_2 = user.id

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start))
    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("cancelar", cancelar))
    dp.add_handler(CommandHandler("registrar", registrar))
    dp.add_handler(CommandHandler("placa", placa_para_modelo))
    dp.add_handler(CommandHandler("modelo", modelo_para_cor))
    dp.add_handler(CommandHandler("cor", cor_para_finalizar))

    # Start the Bot
    updater.start_polling()

    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()


if __name__ == '__main__':
    main()