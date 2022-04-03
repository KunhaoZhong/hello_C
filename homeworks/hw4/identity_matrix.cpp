#include <iostream>
#include <vector>
using namespace std;

int main(){

vector<vector<int> > matrix;
int n;

cout << "size of a your identity matrix: " << endl;
cin >> n;

matrix = vector< vector<int> >(n, vector<int>(n,0));

for(unsigned int i = 0; i < n; i++){

    matrix[i][i] = 1;
}

for(unsigned int y = 0; y < n; y++){
        for(unsigned int x = 0; x < n; x++)
            cout << "\t" << matrix[y][x];
        cout << "\n";
    }

return 0;

}