#include "api.hpp"
#include "utils.hpp"
#include "lib1.hpp"
#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;
using namespace Utils;


void lib1(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Здесь ты найдешь много интересных работ, известных по всему миру.");
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
    button0->text = Utils::fromLocale("Очень странные дела");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_02";
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
    button1->text = Utils::fromLocale("Молодой папа");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_12";
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
    button2->text = Utils::fromLocale("Доктор Хаус");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_22";
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
    button3->text = Utils::fromLocale("Ганнибал");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_32";
    // добавляем кнопки на строку
    row3.push_back(button3);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row3);
    //
    answer = Utils::fromLocale("Выберите сериал:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}

void onClickButton02(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Очень странные дела"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Действие сериала разворачивается в 80-х годах в тихом провинциальном городке. "
                                                                          "Благоприятное течение местной жизни нарушает загадочное исчезновение подростка "
                                                                          "по имени Уилл. Выяснить обстоятельства дела полны решимости родные мальчика и "
                                                                          "местный шериф. Также события затрагивают лучшего друга Уилла — Майка. Он начинает"
                                                                          " собственное расследование. Майк уверен, что близок к разгадке, и теперь "
                                                                          "ему предстоит оказаться в эпицентре ожесточенной битвы потусторонних сил."
                                                                          "\nРежиссер: Мэтт Даффер"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/ochen-strannyie-dela"));
    exitlibrary(bot, query->message);


}

void onClickButton12(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Молодой папа"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("История италоамериканца Ленни Белардо, избранного папой римским Пием XIII. Ленни — сложный "
                                                                          "человек, который ведет себя эксцентрично, а иногда и пугающе, и действия его на посту папы "
                                                                          "предугадать не так-то просто, отчего кардиналы плетут свои интриги против него."
                                                                          "\nРежиссер: Паоло Соррентино"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/molodoj-papa"));
    exitlibrary(bot, query->message);
}
// 2
void onClickButton22(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Доктор Хаус"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Сериал рассказывает о команде врачей, которые должны правильно поставить диагноз пациенту "
                                                                          "и спасти его. Возглавляет команду доктор Грегори Хаус, который ходит с тростью после "
                                                                          "того, как его мышечный инфаркт в правой ноге слишком поздно правильно диагностировали. "
                                                                          "Как врач Хаус просто гений, но сам не отличается проникновенностью в общении с больными "
                                                                          "и с удовольствием избегает их, если только есть возможность. Он сам всё время проводит в"
                                                                          " борьбе с собственной болью, а трость в его руке только подчеркивает его жесткую, ядовитую"
                                                                          " манеру общения. Порой его поведение можно назвать почти бесчеловечным, и при этом он прекрасный"
                                                                          " врач, обладающий нетипичным умом и безупречным инстинктом, что снискало ему глубокое уважение. "
                                                                          "Будучи инфекционистом, он ещё и замечательный диагност, который любит разгадывать медицинские загадки, "
                                                                          "чтобы спасти кому-то жизнь. Если бы все было по его воле, то Хаус лечил бы больных не выходя из своего кабинета."
                                                                          "\nРежиссер: Грег Яйтанс"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/doktor_haus"));
    exitlibrary(bot, query->message);

}
// 3
void onClickButton32(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Ганнибал"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Уилл Грэм — одаренный профайлер, который вместе с ФБР разыскивает серийного убийцу. Уникальный способ "
                                                                          "мышления Грэма дает ему удивительную способность глубоко проникаться чувствами другого человека, "
                                                                          "даже психопата. Он может понять, что ими движет. Но когда ум преследуемого убийцы оказывается слишком "
                                                                          "сложным, он прибегает к помощи доктора Лектера, одного из ведущих психиатрических умов в стране."
                                                                          "\nРежиссер: Майкл Раймер"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Держи на него ссылку: https://www.ivi.ru/watch/gannibal"));
    exitlibrary(bot, query->message);

}

