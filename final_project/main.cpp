#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "dictionary.h"
#include "color.h"

//define colors
Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier black(Color::FG_BLACK);
Color::Modifier def(Color::FG_DEFAULT);

void get_hint(std::string,std::string);
void capitalize(std::string &);
bool check_word(std::string);
dictionary word_list;


int main(){



std::string guess;
std::string answer;
std::string hint;
int guess_time = 0;


answer = word_list.select_answer();

#ifdef DEBUG
    std::cout << "The answer is " << red << answer << def << std::endl;
#endif


std::cout << "Welcome to the world of Wordle! \n";
std::cout << "Strat your guess:\n_____\n";

    do{

        std::cin >> guess;
        capitalize(guess);
        

        // The word entered must be 5 letters
        if(guess.length() != 5){
            std::cout << "You need to answer a five-letter word \n";
        }
        else if(check_word(guess) == false){
            std::cout << "Your guess is not on the list, take another guess: \n";
        }
        else if (guess.length() == 5){
            guess_time++;

            if( guess == answer ){
            get_hint(guess, answer);
            std::cout << "\n Congratulations! you got it in " << guess_time << " guesses!\n";
            break;
            }
            else{
            get_hint(guess, answer);
            std::cout <<"\n Guess again: \n";
            }


             if( guess_time == 5 ){
            std::cout << "Sorry you failed, try another time :) \n";
           }
        }
    }while( guess != answer && guess_time < 5);

return 0;
}



// capitalizes a word (to UPPER CASE)
void capitalize(std::string & word){
    for(int i=0; i<word.length(); i++){
        word[i] = toupper(word[i]);
    }
}


// std::string get_hint(std::string match, std::string word){
//     for(int i=0; i<word.length(); i++){
//         if( word[i] != match[i] ){
//             word[i] = '_';
//         }
//     }
//     return word;
// }


void get_hint(std::string guess, std::string answer){
    std::string hint = guess;
    for (int i=0; i<guess.length(); i++){

        if( guess[i] == answer[i] ){
            std::cout << green << guess[i] << def ;
        }
        else if(answer.find(guess[i]) != std::string::npos  ){
            std::cout << yellow << guess[i] << def ;
        }
        else{
            std::cout << red << guess[i] << def ;
        }
    }
}


bool check_word(std::string entry){
    std::ifstream all_words("all_5_letter_words.txt");
    int offset; 
    std::string line;
    
    if (all_words.is_open())
    {
        while (!all_words.eof())
        {
            getline(all_words,line);
            if ((offset = line.find(entry, 0)) != std::string::npos) 
            {
                all_words.close();
                return true;
            }
        }
        all_words.close();
    }
    else
        std::cout << "Unable to open this file." << std::endl;
    return false;
}