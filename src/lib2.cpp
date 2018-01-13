#include "api.hpp"
#include "utils.hpp"
#include "lib2.hpp"
#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;
using namespace Utils;


void lib2(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Здесь ты найдешь много интересных и увлекательных игр, которые завлекут тебя и дадут"
                                                   "погрузиться в чужие миры.");
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
    button0->text = ("Mass Effect");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_01";
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
    button1->text = ("Skyrim");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_11";
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
    button2->text = ("Dragon Age");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_21";
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
    button3->text = ("Firewatch");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_31";
    // добавляем кнопки на строку
    row3.push_back(button3);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row3);
    //
    answer = Utils::fromLocale("Выберите игру:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}

void onClickButton01(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, "Mass Effect");
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Mass Effect - это мастшабная ролевая игра от BioWare на тему космических приключений. "
                                                                          "История повествует о далеком будущем, где человечество занимает далеко не лидирующее "
                                                                          "положении среди межрасового альянса, которым управляет так назыываемый Совет Цитадели."
                                                                          " Главным героем игры становится капитан Шепард, основной претендент на звание первого "
                                                                          "человека - спектра, элитного бойца Совета. Шепарду предстоит вместе со своей командой "
                                                                          "раскрыть ужасающий заговор, и помешать древнему злу уничтожить жизнь в галактике."
                                                                          "\nРарзработчик: BioWare"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на нее ссылку: http://store.steampowered.com/app/17460/Mass_Effect/"));
    exitlibrary(bot, query->message);


}

void onClickButton11(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, "Skyrim");
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("The Elder Scrolls V: Skyrim - это приключенческая ролевая игра, пятая часть в серии The Elder Scrolls, "
                                                                          "с огромным открытым миром, который с самого начала полностью доступен для исследования. Игрокам предстоит "
                                                                          "выступить в роли Довакина, Драконорожденного, который появляется в провинции Скайрим аккурат во время "
                                                                          "возвращения легендарных драконов, которые, по преданию, собираются разрушить мир. Довакину предстоит "
                                                                          "преодолеть множество трудностей на пути к своей цели - остановить драконьего повелителя Алдуина, который "
                                                                          "готовится обрушить свою ярость на весь мир. "
                                                                          "\nРазработчик: Bethesda Game Studios"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на нее ссылку: http://store.steampowered.com/app/489830/The_Elder_Scrolls_V_Skyrim_Special_Edition/"));
    exitlibrary(bot, query->message);
}
// 2
void onClickButton21(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, "Dragon Age");
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы – Серый Страж, один из последних членов легендарного ордена стражей. Во время возвращения древнего врага в "
                                                                          "раздираемое гражданской войной королевство вы были выбраны судьбой, чтобы объединить разрозненные земли "
                                                                          "и убить Архидемона раз и навсегда. Начните своё приключение, став человеком, эльфом или гномом, а затем "
                                                                          "выберите один из трёх классов (воин, маг или разбойник). После этого всё зависит только от вас. Выборы, "
                                                                          "которые вы совершите, проведут вас через девятый век: век Дракона. Это начало истории первого Dragon Age. "
                                                                          "\nРазработчик: BioWare"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на нее ссылку: http://store.steampowered.com/app/17450/Dragon_Age_Origins/"));
    exitlibrary(bot, query->message);

}
// 3
void onClickButton31(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, "Firewatch");
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Firewatch - это приключенческий проект от бывших работников Telltale, Double Fine и 2K, в котором игрок управляет лесником "
                                                                          "по имени Генри, который должен следить за пожарной безопасностью в лесу. В один прекрасный день Генри понимает, "
                                                                          "что кроме него в лесу есть еще кто-то, и что ему следует каким-то образом защитить себя."
                                                                          "\nРазработчик: Campo Santo"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на нее ссылку: http://store.steampowered.com/app/383870/Firewatch/"));
    exitlibrary(bot, query->message);

}
