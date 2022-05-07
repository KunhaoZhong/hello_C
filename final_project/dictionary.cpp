#include "dictionary.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>


dictionary::dictionary(){
    dictionary_file = DEFAULT_DICTIONARY; // default file
    load_dictionary(dictionary_file);
}

// loads words from file name passed in as long as it includes
// at least one word
void dictionary::load_dictionary(std::string file){
    std::ifstream read(file);
    std::vector <std::string> temp;

    if( !read.is_open() ){
        return;
    }
    else{
        std::string word;
        while( getline(read,word) ){
            //convert every word to UPPER CASE
            for(int i=0; i<word.length(); i++){
                word[i] = toupper(word[i]);
            }
           temp.push_back(word);
        }
    }

    if( temp.size() > 0 ){
        words = temp;
        dictionary_file = file;
    }
    read.close();
}

// returns the name of the file that was most recently used to 
// load the current dictionary
std::string dictionary::file_name(){
    return dictionary_file;
}

// select a random word from dictionary
//NOTE: there used to be bug here, need to use srand(time(NULL));
std::string dictionary::select_answer(){
    srand(time(NULL));
    int answer_index = rand() % size();
    return words.at(answer_index % words.size());
}


int dictionary::size(){
    return words.size();
}

