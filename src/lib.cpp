#include "api.hpp"
#include "utils.hpp"
#include "lib.hpp"
#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;
using namespace Utils;


void lib(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Здесь ты найдешь много интересных работ известных режиссеров.");
    bot.getApi().sendMessage(message->chat->id, answer);
    //
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    // 0
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row0;
    // создаем кнопку
    InlineKeyboardButton::Ptr button0(new InlineKeyboardButton);
    // текст кнопки
    button0->text = Utils::fromLocale("Заводной Апельсин");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_03";
    // добавляем кнопки на строку
    row0.push_back(button0);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row0);
    //
    // 1
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row1;
    // создаем кнопку
    InlineKeyboardButton::Ptr button1(new InlineKeyboardButton);
    // текст кнопки
    button1->text = Utils::fromLocale("Величайший шоумен");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_13";
    // добавляем кнопки на строку
    row1.push_back(button1);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row1);
    //
    // 2
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row2;
    // создаем кнопку
    InlineKeyboardButton::Ptr button2(new InlineKeyboardButton);
    // текст кнопки
    button2->text = Utils::fromLocale("Аватар");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_23";
    // добавляем кнопки на строку
    row2.push_back(button2);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row2);
    //
    // 3
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row3;
    // создаем кнопку
    InlineKeyboardButton::Ptr button3(new InlineKeyboardButton);
    // текст кнопки
    button3->text = Utils::fromLocale("Титаник");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_33";
    // добавляем кнопки на строку
    row3.push_back(button3);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row3);
    //
    answer = Utils::fromLocale("Выберите фильм:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}

void onClickButton03(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Заводной апельсин"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Безжалостный лидер банды подростков, совершающей убийства и изнасилования, "
                                                                          "попадает в тюрьму и подвергается специальной обработке по подавлению "
                                                                          "подсознательного стремления к насилию. Но жизнь за воротами тюрьмы такова, "
                                                                          "что меры, принятые по «исправлению жестокости характера» не могут ничего изменить. "
                                                                          "\nРежиссер: Стэнли Кубрик"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/99966"));
    exitlibrary(bot, query->message);


}

void onClickButton13(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Величайший шоумен"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Финеас Тейлор Барнум всегда мечтал войти в историю, но все его занятия не приносили "
                                                                          "ему удовольствия. И когда, казалось, весь мир обернулся против него, он решает "
                                                                          "пойти вслед за своей мечтой. Барнум создает завораживающее представление-сенсацию, "
                                                                          "которое стало рождением мирового шоу-бизнеса."
                                                                          "\nРежиссер: Майкл Грэйси"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/133350/description"));
    exitlibrary(bot, query->message);
}
// 2
void onClickButton23(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Аватар"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Джейк Салли — бывший морской пехотинец, прикованный к инвалидному креслу. Несмотря на немощное "
                                                                          "тело, Джейк в душе по-прежнему остается воином. Он получает задание совершить "
                                                                          "путешествие в несколько световых лет к базе землян на планете Пандора, где корпорации "
                                                                          "добывают редкий минерал, имеющий огромное значение для выхода Земли из энергетического кризиса."
                                                                          "\nРежиссер: Джеймс Кэмерон"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/99906"));
    exitlibrary(bot, query->message);

}
// 3
void onClickButton33(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Титаник"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Молодые влюбленные Джек и Роза находят друг друга в первом и последнем плавании «непотопляемого» "
                                                                          "Титаника. Они не могли знать, что шикарный лайнер столкнется с айсбергом в холодных водах "
                                                                          "Северной Атлантики, и их страстная любовь превратится в схватку со смертью…"
                                                                          "\nРежиссер: Джеймс Кэмерон"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/93869"));
    exitlibrary(bot, query->message);

}
