#include "keyboard.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tgbot/Bot.h>

#ifndef EXAMPLE_BOT_LIB_HPP
#define EXAMPLE_BOT_LIB_HPP

#endif //EXAMPLE_BOT_LIB_HPP

void lib(TgBot::Bot& bot, TgBot::Message::Ptr message);

void onClickButton03(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton13(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton23(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton33(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);

void exitlibrary(TgBot::Bot& bot, TgBot::Message::Ptr message);
void onClickbuttonexitlib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
