#include <iostream>
#include <string>
using namespace std;

int main()
{
   string sentence {"may the force be with you"};
   int size = sentence.size();
   sentence[0] = toupper(sentence[0]);
   bool flag = false;
   
   for (auto it = sentence.begin(); it < sentence.end(); ++it)
   {

         if (flag == true){
             *it = toupper(*it);
             flag = false;
         }
         if ( *it == ' ' ){
             flag = true;
         }

   }

    cout << sentence << endl;
   
   return 0;
}