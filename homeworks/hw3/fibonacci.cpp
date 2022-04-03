#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0;
    cout<<"How many elements do you want to for a Fibonacci series: ";
    cin>>n;
    vector<int> fib{0, 1};
    if (n <=2){
        for (auto e : fib) {
        std::cout << e << std::endl;
        } 
    }
    else{
        for (int i =2; i < n; i++){
            fib.push_back(fib[i - 1] + fib[i - 2]);
        }
        
        for (auto e : fib) {
        std::cout << e << std::endl;
        } 
    }
}