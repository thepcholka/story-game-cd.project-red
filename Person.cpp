#include "Person.h"

Person::Person(const std::string& role, const std::string& name):
	role(role), name(name) {}

void Person::say(int num_repl, const std::string& other_name) const {;
	std::string num_repl_str = std::to_string(num_repl);
	std::ifstream f("Repliks.json");
	json data = json::parse(f);
	f.close();
	if (data.find(role) == data.end()) {
		std::cout << "ERROR no role in json " << role << std::endl;
		throw std::exception("ERROR no role in json");
	}
	json replics = data[role];
	if (replics.find(num_repl_str) == replics.end()) {
		std::cout << "ERROR no replica in json " << num_repl_str << std::endl;
		throw std::exception("ERROR no replica in json");
	}
	std::string replika = replics[num_repl_str];
	replika = name_replace(replika, other_name);
	std::cout << role;
	if (name != "") {
		std::cout << ' ' << name;
	}
	std::cout << ": " << replika << std::endl;
}

std::string Person::name_replace(std::string replic, std::string other_name) const {
	if (other_name == "") {
		other_name = name;
	}
	const std::string word = "ÈÌß";
	size_t pos = 0;
	while (pos += other_name.length()) {
		pos = replic.find(word, pos);
		if (pos == std::string::npos) {
			break;
		}
		if (other_name == "") {
			std::cout << "ERROR no name in replik " << replic;
			throw std::exception("ERROR no name in replik");
		}
		replic.replace(pos, word.length(), other_name);
	}
	return replic;
}

std::string Person::get_name() const {
	return name;
}

