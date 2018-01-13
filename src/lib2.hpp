
#ifndef EXAMPLE_BOT_LIB2_HPP
#define EXAMPLE_BOT_LIB2_HPP

#endif //EXAMPLE_BOT_LIB2_HPP

#include "keyboard.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tgbot/Bot.h>

void lib2(TgBot::Bot& bot, TgBot::Message::Ptr message);

void onClickButton01(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton11(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton21(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton31(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);

void exitlibrary(TgBot::Bot& bot, TgBot::Message::Ptr message);
void onClickbuttonexitlib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
