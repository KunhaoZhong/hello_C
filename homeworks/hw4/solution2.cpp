#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<std::string> word_list{};

    std::string word{};
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter word " << i+1 << ": ";
        std::cin >> word;
        word_list.push_back(word);
    }

     int max_len = 0;
     for (auto w : word_list) {
         if (w.size() > max_len) {
             max_len = w.size();
             word = w;
         }
     }

    std::cout << "longest word is: " << word << std::endl;
}