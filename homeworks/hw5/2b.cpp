#include <iostream>
#include <string>
using namespace std;

int main()
{
   string sentence {"may the force be with you"};
   int size = sentence.size();
   sentence[0] = toupper(sentence[0]);
   
   for (int i = 1; i < size; i++)
   {
        if ( sentence[i - 1] == ' ' )
            sentence[i] = toupper( sentence[i] );
   }

   cout << sentence << endl;
   
   return 0;
}