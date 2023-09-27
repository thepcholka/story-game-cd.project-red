#include "Game.h"

Game::Game():
	main_person("Торговец", "Райан"),
	knight("Рыцарь", "Мортимер"),
	barmen("Бармен", "Джон"),
	other_main("Крестьянин", "Боб"),
	talker("Рассказчик") {}

void Game::play() {
	//выбор перса
	std::cout << "Выберите персонажа:" << std::endl;
	std::cout << "1: Крестьянин" << std::endl;
	std::cout << "2: Торговец" << std::endl;
	std::cout << "Введите 1 или 2" << std::endl;
	int chose;
	std::cin >> chose;
	if (chose == 1) {
		std::swap(main_person, other_main);
	}
	//выбор имени
	main_person.choose_name();
	//квест
	if (chose == 2) {
		talker.say(1, main_person.get_name());
		int a = main_person.make_choose(1);
		if (a == 1) {
			knight.say(1);
			int b = main_person.make_choose(4);
			if (b == 1) {
				knight.say(4);
				talker.say(8);
				main_person.say(4);
				other_main.say(1);
				main_person.say(5);
				other_main.say(6);
				main_person.say(8);
				other_main.say(5);
				talker.say(7, other_main.get_name());
			}
			else {
				knight.say(2);
				main_person.say(2);
				knight.say(3);
				talker.say(8);
				main_person.say(4);
				other_main.say(3);
				main_person.say(5);
				other_main.say(2);
				main_person.say(6);
				other_main.say(4);
				main_person.say(7);
				other_main.say(7);
				talker.say(6, other_main.get_name());
			}
		}
		else {
			main_person.say(4);
			other_main.say(1);
			main_person.say(5);
			other_main.say(6);
			main_person.say(8);
			other_main.say(5);
			talker.say(6, other_main.get_name());
		}
	}
	else if (chose == 1) {
		talker.say(2);
		int c = main_person.make_choose(2);
		if (c == 1) {
			other_main.say(4);
			main_person.say(3);
			other_main.say(5);
			main_person.say(6);
			other_main.say(8);
			main_person.say(5);
			talker.say(6, other_main.get_name());
		}
		else {
			barmen.say(1);
			main_person.say(1);
			barmen.say(2);
			main_person.say(2);
			barmen.say(3);
			int d = main_person.make_choose(3);
			if (d == 1) {
				talker.say(3);
			}
			else {
				other_main.say(4);
				main_person.say(3);
				other_main.say(5);
				other_main.say(6);
				main_person.say(4);
				other_main.say(7);
				main_person.say(5);
				talker.say(6, main_person.get_name());
			}
		}
	}
}