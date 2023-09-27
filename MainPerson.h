#pragma once
#pragma execution_character_set("utf-8")

#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Person.h"


class MainPerson:public Person {
public:
	MainPerson() = delete;
	MainPerson(const std::string& role, const std::string& name);
	int make_choose(int num_repl1);
	void choose_name();
public:
	bool is_good = true;

};

