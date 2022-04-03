#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string word_list;
    string entry;
    int i;
    for (i = 1; i <= 10; i++ ){
        printf("Enter the %ith word of your word list: ", i);
        cin >> entry;
        word_list += entry;
        word_list += " ";
    }
    //test input is correct
    // cout << word_list << endl;

    //I wanted to use this method, but would be too complecated to deal with the case where there are several equally long words.
    // int start, longest, longest_pos;
    // for (i = 0; word_list[i] != '\0'; i++) {
    //     if (word_list[i] == ' ') {
    //         start = i + 1;
    //     } else {
    //         if (i - start > longest) {
    //             longest = i - start;
    //             longest_pos = start;
    //         }
    //     }
    // } 

    //This method words much better, that uses sstream;

    int max_size = 0;
    string max_word, word;

    istringstream is ( word_list );
    while ( is >> word )
    {
        if ( max_size < word.size() ) 
        { 
            max_size = word.size();
            max_word = word;
        }           
        else if ( max_size == word.size() ) 
        { 
            max_word += "; ";
            max_word += word;
        }            
    }

    printf("The longest words are: \" %s \", they have %i letters \n", max_word.c_str(), max_size);
    
    return 0;    


}