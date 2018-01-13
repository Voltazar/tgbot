#include "api.hpp"
#include "utils.hpp"
#include "lib.hpp"
#include "lib1.hpp"
#include "lib2.hpp"

// Файл, для демонстрации работы с клавиатурой

using namespace std;
using namespace TgBot;
using namespace Utils;


// Функция для демонстрации работы с Inline Keyboard 
// https://core.telegram.org/bots/2-0-intro
// Для вызова необходимо прислать сообщение /keyboard
void onCommandKeyboard(Bot& bot, Message::Ptr message)
{
    // Создаем объект клавиатуры
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);

    // создаем новую строку в клавиалуре
    // обычный вектор
    vector<InlineKeyboardButton::Ptr> row0;

    // создаем кнопку
    InlineKeyboardButton::Ptr buttonOne(new InlineKeyboardButton);
    // текс кнопки
    buttonOne->text = "Film";
    // текстовый идентификатор кнопки
    // при нажатии на кнопку будет приходить именно этот текст
    // смотри функцию getAllCallbacks
    buttonOne->callbackData = "id_button_one";

    InlineKeyboardButton::Ptr buttonTwo(new InlineKeyboardButton);
    buttonTwo->text = "Serial";
    buttonTwo->callbackData = "id_button_two";

    // добавляем кнопки на строку
    row0.push_back(buttonOne);
    row0.push_back(buttonTwo);

    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row0);


    // создаем еще строку в клавиатуре
    vector<InlineKeyboardButton::Ptr> row1;

    InlineKeyboardButton::Ptr buttonThree(new InlineKeyboardButton);
    buttonThree->text = "Game";
    buttonThree->callbackData = "id_button_three";

    row1.push_back(buttonThree);
    keyboard->inlineKeyboard.push_back(row1);

    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("Итак, вот и наши возможные варианты! Ты можешь выбрать фильм, сериал или игру. "
                                                   "После выбора определенной категории тебе будет предложен список. Что же ты выберешь?");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}


void onClickButtonOne(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Ты выбрал фильм!"));
    lib(bot, query->message);
}

void onClickButtonTwo(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Ты выбрал сериал!"));
    lib1(bot, query->message);
}

void onClickButtonThree(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Ты выбрал игру!"));
    lib2(bot, query->message);
}
// Регистрируем наши кнопки
std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> getAllCallbacks()
{
    // Ключом является идентификатор кнопки
    // значением является функция-обработчик кнопки
    // т.е. при нажатии на кнопку с идентификатором, произойдет вызов соответствующей функции
    // Например, при нажании на кнопку с идентификатором id_button_one вызовется функция onClickButtonOne
    std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> callbacks =
    {   // начало
        {"id_button_one", onClickButtonOne},
        {"id_button_two", onClickButtonTwo},
        {"id_button_three", onClickButtonThree},
        // фильмы
        {"id_button_03", onClickButton03},
        {"id_button_13", onClickButton13},
        {"id_button_23", onClickButton23},
        {"id_button_33", onClickButton33},
        {"id_button_exitlib", onClickbuttonexitlib},
        // игры
        {"id_button_02", onClickButton02},
        {"id_button_12", onClickButton12},
        {"id_button_22", onClickButton22},
        {"id_button_32", onClickButton32},
        // сериалы
        {"id_button_01", onClickButton01},
        {"id_button_11", onClickButton11},
        {"id_button_21", onClickButton21},
        {"id_button_31", onClickButton31}
    };

    return callbacks;
}

