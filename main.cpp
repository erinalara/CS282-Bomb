#include <iostream>
#include <random>
#include "bomb.cpp"

using namespace std;
int main() {
    bool hit = false;
    int seed = getSeed();
    mt19937 engine = mt19937(seed);
    uniform_real_distribution<double> bound{ 1.0, 1000.0 };

    double d = bound(engine);
    double r = (int) (d*100.0) / (100.0);
    cout << "The target is " << r  << "m away. " << endl;

    while (hit != true) {
        double angle = getAngle();
        double gun = getGun();
        double distance = calculateD(gun, angle);
        hit = bombHit(r, distance);
    }
    return 0;

}
