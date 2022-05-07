# Wordle game in c++

Final project of PHY 504 at SBU Spring 2022(https://github.com/zingale/phy504/blob/main/projects.md).

Wordle (https://en.wikipedia.org/wiki/Wordle) is a very popular game that let people guess a ramdom five letter word every day. In this repo, I'll reproduce the game in command line using c++, and let people play whatever times they want. I'll use the same rule as in the original game, so if the player enter a word that's not on the list it will be disallowed. A very interesting vedio about this game and information theory can be found here: https://youtu.be/v68zYyaEmEA. 

Usage
-----
The game use `ANSI color codes` (https://en.wikipedia.org/wiki/ANSI_escape_code) to output color letters in command line.

To build:

```bash
make
```
which will also test the code.

To run with the default words list:

```bash
./wordle
```

Alternatively, you can run with your own word list, such as:

```bash
./wordle ./word-list-500.txt
```
which only contains 500 words, suppose to be easier :)




Explanation of the code:
-------
Since this is a final project, I'll explain each part in this repo here:

1. The list of words is publicly available in their source code (https://www.nytimes.com/games/wordle/index.html), we can take them by using, for example:

```bash
curl -s https://raw.githubusercontent.com/tabatkins/wordle-list/main/words | grep ...
```
I use this list as the standard list `all_5_letter_words` to check if the user enters a reasonable word, and the real word-list is from `sgb-words`.
2. make file: a standard GNUmakefile makefile that builds in optimized and debug mode.
3. `dictionary.cpp` a class that generate and operate the dictionary.
4. I was originally designed to seperate the game in the game.cpp, and then add it into the main.cpp, but it fails with a `clang error `, I'm not sure why this is Apple-silicon related issue, but now I can only have the main part of the game in the main.cpp
5. `color.h` contains the header notes to output with color.



Develop log
------
1. In generating the random answer, need to use  `srand(time(NULL));`
2. Add the function that the code will produce yellow letter, same as in the original game.
3. Now the code can detect whether the input user give is in the list or not, which I think is a very important point about this game. If people can choose irrational word, I would start with "aueio", which probably increase my score significantlly. The allowed words list is, however, much larger than the real word-list that the code use to generate an answer.


