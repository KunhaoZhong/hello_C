#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define g 9.8
#define PI 3.1415926
struct projectile {
    vector<double> t;
    vector<double> x;
    vector<double> y;
};
int main() {


    double v_ini, angle_ini, dt;
    cout<<"What's the initial velocity magnitude, in m/s: ";
    cin>>v_ini;

    cout<<"What's the initial angle above the horizontal, in degree: ";
    cin>>angle_ini;

    cout<<"What's the time interval dt, in s: ";
    cin>>dt;

    projectile vec; //create a vec that holds projectile information, t, x, y;
    //initialization
    vec.t.push_back(0.);
    vec.x.push_back(0.);
    vec.y.push_back(0.);

    double t = 0.;

    //get velocity in x and y direction;
    double v_x = v_ini*cos(angle_ini*PI/180.0);
    double v_y = v_ini*sin(angle_ini*PI/180.0);
    while (vec.y.back() >=0) {
        t += dt;
        vec.x.push_back(v_x * t);
        vec.y.push_back(v_y * t - 0.5* g * t * t);
        vec.t.push_back(t+dt);
    }
    //erase the last time where y is already smaller than 0;
    vec.t.pop_back();
    vec.x.pop_back();
    vec.y.pop_back();


    //store in a table called tranjectory,
    vector<vector<double> > tranjectory{vec.t, vec.x, vec.y};
    //the data in in rows, so have to print in the reverse way to output as columns.
    int i, j;
    for (i=0; i<vec.t.size(); i++){
            for(j =0; j<3; j++){
                cout << "\t" << tranjectory[j][i];
            }
            cout << "\n";
    }
}


