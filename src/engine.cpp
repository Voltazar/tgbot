#include "api.hpp"
#include "keyboard.hpp"
#include "utils.hpp"
#include "lib.hpp"
#include "lib1.hpp"

// Файл, для демонстрации работы с командами и другими сообщениями

using namespace std;
using namespace TgBot;
using namespace Utils;

// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /photo
// В ответ пользователю придет сообщение с картинкой

void onCommandCom(Bot& bot, Message::Ptr message);

void onCommandPhoto(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("0.jpg", "image/jpeg"));
}

// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /start
void onCommandStart(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Привет!Я очень рад тебя видеть! "
                                                                          "Я твой домашний бот, который поможет "
                                                                          "тебе придумать, чем занять себя вечером. "
                                                                          "Для того, чтобы я помог тебе, введи /keyboard и выбери "
                                                                          "категорию или введи /allcommands, чтобы увидеть все мои команды."));

}

// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /end
void onCommandEnd(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Bye! Hope to see you soon!");
}


void onCommandCom(Bot& bot, Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Нажми на одну из этих функций, чтобы посмотреть, что я умею: "));
    std::map<std::string, std::string> commands = {
            {"/start", Utils::fromLocale(" - Начало работы")},
            {"/end", Utils::fromLocale(" - Конец работы")},
            {"/keyboard", Utils::fromLocale(" - Выбор занятия на вечер ")},
            {"/allcommands", Utils::fromLocale("Все возможные команды")}
    };
    std::string answs = {};
    for (auto it = commands.begin(); it != commands.end(); ++it)
    {
        answs += Utils::fromLocale((it->first) + " " + (it->second) + "\n");
    }
    bot.getApi().sendMessage(message->chat->id, answs);
}


// регистрируем команды
std::map<std::string, std::function<void(Bot&, Message::Ptr)>> getAllCommands()
{
    // Ключом является идентификатор команды
    // значением является функция-обработчик коаманды
    // Например, при получении команды /end вызовется функция onCommandEnd
    std::map<std::string, std::function<void(Bot&, Message::Ptr)>> commands =
    {
        {"start", onCommandStart},
        {"end", onCommandEnd},
        {"keyboard", onCommandKeyboard},
        {"allcommands", onCommandCom},
        {"photo", onCommandPhoto}
    };

    return commands;
}



// Функция, которая вызывается при любом сообщении
void onAnyMessage(Bot& bot, Message::Ptr message) {
    // логгируем действия в консоль
    printf("User wrote %s\n", message->text.c_str());
    //
    // игнорируем сообщения, которые начинаются с /start и /end и пр.
    if (StringTools::startsWith(message->text, "/start")) {
        return;
    }
    //
    if ((StringTools::startsWith(message->text, "/allcommands"))) {
        return;
    }
    //
    if ((StringTools::startsWith(message->text, "/keyboard"))) {
        return;
    }
    //
    if (StringTools::startsWith(message->text, "/end")) {
        return;
    }

    //
    // если в тексте сообщения есть "Привет" или "hi" или "Hi!" или "Hi", то приветствуем собеседника
    if (StringTools::startsWith(message->text, "hi")) {
        bot.getApi().sendMessage(message->chat->id, "hi, " + message->from->firstName);
        onCommandCom(bot, message);
        return;
    } else if ((StringTools::startsWith(message->text, "Hi!")) || (StringTools::startsWith(message->text, "Hi"))) {
        bot.getApi().sendMessage(message->chat->id, "Hi, " + message->from->firstName);
        onCommandCom(bot, message);
        return;
    }
    std::string hello = Utils::fromLocale("Привет");
    std::string hello1 = Utils::fromLocale("Привет!");
    if ((message->text.find(hello) != std::string::npos) || (message->text.find(hello1) != std::string::npos)) {
        bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Привет, ") + message->from->firstName);
        onCommandCom(bot, message);
        return;
    }
    // отправляем сообщение об ошибке
    std::string answer = Utils::fromLocale("Такой команды нет, введите /allcommands, чтобы посмотреть все команды!");
    bot.getApi().sendMessage(message->chat->id, answer);
}