#include "game.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


void StartGame() {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    std::cout << "This ->" << red << "word" << def << "<- is red." << std::endl;
}

int main(int argc, char **argv) {
  std::string word_list_path(".words-list/sgb-words.txt");
  if (argc == 2) {
    word_list_path = argv[1];
  }

  Wordle game(word_list_path);
  game.StartGame();
  return 0;

    // Color::Modifier red(Color::FG_RED);
    // Color::Modifier def(Color::FG_DEFAULT);
    // std::cout << "This ->" << red << "word" << def << "<- is red." << std::endl;
}


