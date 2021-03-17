#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "DataBase.h"
#include <regex>

//
// Server 21.cpp : Этот файл содержит функцию "main".
//  Здесь начинается и заканчивается выполнение программы.
//

//Вывод строки ботом
void bot_say(std::string text) {

    std::cout << "[ChatBot21]:" << text << std::endl;

}

//Преобразование в нижний регистр
std::string to_lower(std::string text) {

    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

//Анализ ботом выражения и вывод ответа
void bot_answer(std::string question) {
    //Найден ли ответ
    bool foundAnswer = false;
    for (auto entry:knowledge) {

        //применение регулярные выражения
        std::regex expression = std::regex(".*" + entry.first + ".*");
        if (regex_match(question,expression)) {
            bot_say(entry.second);
            foundAnswer = true;
        }
    }
    if (!foundAnswer) {
        bot_say("Do not comprende");
    }
}

//Получить вопрос от пользователя
std::string user_question() {

    std::string question;
    std::cout << "[USER]:";
    getline(std::cin,question);
    question = to_lower(question);

    return question;
}

bool isExit(std::string text) {

    for (auto phrase : exitPrashe) {
        std::regex expression = std::regex(".*" + phrase + ".*");
        if (regex_match(text, expression)) {
            bot_say("Ok,byeee!");
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << "Hello User!\n";

    std::string question;

    while (!isExit(question)){

        question = user_question();
        bot_answer(question);
    }

    system("pause");
    return 0;
}


