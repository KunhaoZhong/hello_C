#include <vector>
#include <string>


class Wordle{
 public:
  Wordle(const std::string&);
  int size();
  void StartGame();

 private:
  std::vector<std::string> word_list_;
  std::string answer_;
  std::vector<std::string> guessed_words_;
};

