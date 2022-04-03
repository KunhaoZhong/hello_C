#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

struct OrbitState {
    double t;
    double x;
    double y;
    double vx;
    double vy;
};

OrbitState rhs(const OrbitState& state);
void write_history(const std::vector<OrbitState>& history);
double error(const std::vector<OrbitState>& history);
std::vector<OrbitState> integrate(const double a, const double tmax, const double dt);
std::vector<OrbitState> integrate_rk2(const double a, const double tmax, const double dt);

const double GM = 4.0 * M_PI * M_PI;   // G * Mass in AU, year, solar mass units

OrbitState rhs(const OrbitState& state) {

    OrbitState dodt{};
    
    // dx/dt = vx; dy/dt = vy

    dodt.x = state.vx;
    dodt.y = state.vy;
    
    // d(vx)/dt = - GMx/r**3; d(vy)/dt = - GMy/r**3

    double r = std::sqrt(state.x * state.x + state.y * state.y);

    dodt.vx = - GM * state.x / std::pow(r, 3);
    dodt.vy = - GM * state.y / std::pow(r, 3);

    return dodt;

}

void write_history(const std::vector<OrbitState>& history) {

    //HW6.a: output the orbit directly to a file, called orbit.dat here.
    std::ofstream of;
    of.open("orbit.dat");
    
    for (auto o : history) {
        // std::cout << std::setw(12) << o.t
        //           << std::setw(12) << o.x
        //           << std::setw(12) << o.y
        //           << std::setw(12) << o.vx
        //           << std::setw(12) << o.vy << std::endl;
        of << std::setw(12) << o.t
                  << std::setw(12) << o.x
                  << std::setw(12) << o.y
                  << std::setw(12) << o.vx
                  << std::setw(12) << o.vy << std::endl;
    }
    of.close();

}

std::vector<OrbitState> integrate(const double a, const double tmax, const double dt) {

    // how the history of the orbit

    std::vector<OrbitState> orbit_history{};

    // set initial conditions
    OrbitState state{};

    // assume circular orbit on the x-axis, counter-clockwise orbit

    state.t = 0.0;
    state.x = a;
    state.y = 0.0;
    state.vx = 0.0;
    state.vy = std::sqrt(GM / a);

    orbit_history.push_back(state);

    // integration loop
    while (state.t < tmax) {

        // get the derivatives
        auto state_derivs = rhs(state);

        // update the state
        state.t += dt;
        state.x += state_derivs.x * dt;
        state.y += state_derivs.y * dt;
        state.vx += state_derivs.vx * dt;
        state.vy += state_derivs.vy * dt;

        orbit_history.push_back(state);
    }

    return orbit_history;

}

//HW6b: Add an error() function that define the error as the magnitude of the difference between the initial and final orbital radius after integrating for one period.
//header is added in the beginning of this file
//I add a print here so the error value is also printed out.
double error(const std::vector<OrbitState>& history){
    double r_start = sqrt(history.front().x*history.front().x + history.front().y*history.front().y);
    double r_end = sqrt(history.back().x*history.back().x + history.back().y*history.back().y);
    double error_value = r_end-r_start;
    return error_value;
}
std::vector<OrbitState> integrate_rk2(const double a, const double tmax, const double dt) {

    // how the history of the orbit

    std::vector<OrbitState> orbit_history{};

    // set initial conditions
    OrbitState state{};
    

    // assume circular orbit on the x-axis, counter-clockwise orbit

    state.t = 0.0;
    state.x = a;
    state.y = 0.0;
    state.vx = 0.0;
    state.vy = std::sqrt(GM / a);

    orbit_history.push_back(state);

    // integration loop
    while (state.t < tmax) {
        
        //rk2 method
        auto k0 = rhs(state);
        //define Y_mid as a struct OrbitState, then the code is similar to other parts
        OrbitState Y_mid{};
        Y_mid.x = state.x + 0.5 * dt * k0.x;
        Y_mid.y = state.y + 0.5 * dt * k0.y;
        Y_mid.vx = state.vx + 0.5 * dt * k0.vx;
        Y_mid.vy = state.vy + 0.5 * dt * k0.vy;
        Y_mid.t = state.t + 0.5*dt;

        auto k1 = rhs(Y_mid);


        // update the state
        state.t += dt;
        state.x += k1.x * dt;
        state.y += k1.y * dt;
        state.vx += k1.vx * dt;
        state.vy += k1.vy * dt;

        orbit_history.push_back(state);
    }

    return orbit_history;

}


int main() {

    double tmax = 1.0;
    double dt = 0.001;
    //double dt = 0.1;
    double a = 1.0;      // 1 AU

    auto orbit_history = integrate(a, tmax, dt);
    write_history(orbit_history);
    printf("For dt = %f, the error is: %f, with 1st order Euler method \n", dt, error(orbit_history));

    auto orbit_history_2 = integrate(a, tmax, dt*2);
    printf("For dt = %f, the error is: %f, with 1st order Euler method \n", dt*2, error(orbit_history_2));

    auto orbit_history_4 = integrate(a, tmax, dt*4);
    printf("For dt = %f, the error is: %f, with 1st order Euler method \n", dt*4 ,error(orbit_history_4));

    auto orbit_history_rk2 = integrate_rk2(a, tmax, dt);
    printf("For dt = %f, the error is: %e, with 2nd order Runge-Kutta method \n", dt, error(orbit_history_rk2));

    auto orbit_history_rk2_2 = integrate_rk2(a, tmax, dt*2);
    printf("For dt = %f, the error is: %e, with 2nd order Runge-Kutta method \n", dt*2, error(orbit_history_rk2_2));

    auto orbit_history_rk2_4 = integrate_rk2(a, tmax, dt*4);
    printf("For dt = %f, the error is: %e, with 2nd order Runge-Kutta method \n", dt*4, error(orbit_history_rk2_4));

}