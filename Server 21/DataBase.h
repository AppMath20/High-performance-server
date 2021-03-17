#include <map> 
#include <vector>

#ifndef DATA_H
#define DATA_H

//База данных для хранения вопросов и ответов пользователя 
std::map<std::string, std::string> knowledge{
	{"hello","hello human"},
	{"how are you", "not tooo bad for mchine"},
	{"what is your name","my creator gave me name ChatBot21"},
};  

std::vector<std::string> exitPrashe{"exit","pay","good bay","bye","chaoo"};

#endif // !DATA_H