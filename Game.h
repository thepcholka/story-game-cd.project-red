#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include "MainPerson.h"
#include "Person.h"


class Game {
public:
	Game();
	void play();
private:
	MainPerson main_person;
	Person knight;
	Person barmen;
	MainPerson other_main;
	Person talker;
};

