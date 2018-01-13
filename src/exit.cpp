#include "api.hpp"
#include "utils.hpp"
#include <tgbot/tgbot.h>
#include "exit.hpp"
#include "keyboard.hpp"
//
using namespace std;
using namespace TgBot;
using namespace Utils;



void exitlibrary(Bot& bot, Message::Ptr message) {
    // exit
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboardexit(new InlineKeyboardMarkup);
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> rowexit;
    // создаем кнопку
    InlineKeyboardButton::Ptr buttonexit(new InlineKeyboardButton);
    // текст кнопки
    buttonexit->text = Utils::fromLocale("Выход из режима");
    // текстовый идентификатор кнопки
    buttonexit->callbackData = "id_button_exitlib";
    // добавляем кнопки на строку
    rowexit.push_back(buttonexit);
    // добавляем строку кнопок в клавиатуру
    keyboardexit->inlineKeyboard.push_back(rowexit);
    // result
    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("А теперь настало время запастись едой и идти!");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboardexit, "Markdown");
}
// описание выхода
void onClickbuttonexitlib(Bot& bot, CallbackQuery::Ptr query) {
    onCommandKeyboard(bot, query->message);
}
//