#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class Person {
public:
	Person() = delete;
	Person(const std::string& role, const std::string& name = "");
	virtual ~Person() = default;
	void say(int num_repl, const std::string& other_name = "") const;
	std::string get_name() const;
protected:
	std::string name_replace(std::string replic, std::string other_name = "") const;
protected:
	std::string role;
	std::string name;
};

