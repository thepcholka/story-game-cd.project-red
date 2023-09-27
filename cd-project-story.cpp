#pragma execution_character_set("utf-8")

#include "windows.h"
#include "Game.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Game game;
    game.play();
    /*MainPerson pers("Крестьянин", "боб");
    pers.make_choose(1);*/
}
