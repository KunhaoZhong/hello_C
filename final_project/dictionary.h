#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>


class dictionary{
private:
    const std::string DEFAULT_DICTIONARY = "sgb-words.txt";
    std::vector<std::string> words;
    std::string dictionary_file;

public:
    dictionary();
    void load_dictionary(std::string);
    std::string file_name();
    std::string select_answer();
    int size();
};

#endif