#include "MainPerson.h"


MainPerson::MainPerson(const std::string& role, const std::string& name) :
	Person(role, name) {}

int MainPerson::make_choose(int num_repl) {
	std::string num_repl_str = std::to_string(num_repl);
	std::ifstream f("Repliks.json");
	json data = json::parse(f);
	f.close();
	json chooses = data[(std::string)"Выбор"];
	if (chooses.find(num_repl_str) == chooses.end()) {
		std::cout << "ERROR no choose in json " << num_repl_str << std::endl;
		throw std::exception("ERROR no choose in json");
	}
	std::string chose1 = name_replace(chooses[num_repl_str]["1"]);
	std::string chose2 = name_replace(chooses[num_repl_str]["2"]);
	std::cout << "1: " << chose1 << std::endl << "2: " << chose2 << std::endl;
	std::cout << "Введите 1 или 2: " << std::endl;
	int nomchoose;
	std::cin >> nomchoose;
	return nomchoose;
}
void MainPerson::choose_name() {
	std::string name1;
	std::cout << "Введите имя главного персонажа:" << std::endl;
	std::cin >> name1;
	name = name1; 
}
