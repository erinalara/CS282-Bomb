// Created by Erina Lara on 2/6/20.
#include <iostream>
#include <cmath>

using namespace std;

int getSeed() {
    int seed = 0;
    while (seed <= 0) {
        cout << "Please enter a positive integer seed value: " << endl;
        cin >> seed;
    }
    return seed;
}

double getAngle() {
    double angle = 0;
    while (angle <= 0 || angle > 90) {
        cout << "Please enter an angle between 0 and 90 degrees: " << endl;
        cin >> angle;
    }
    return angle;
}

double getGun() {
    double gun = 0;
    while (gun <= 0) {
        cout << "Please enter an amount of gunpowder in kilograms: " << endl;
        cin >> gun;
    }
    return gun;
}

double calculateD(double gun, double angle) {
    double velocity = gun * 30;
    double pi = 3.141592653589793238463;
    double g = 9.81;

    double vx = velocity * (cos (angle * (pi / 180.0) ));
    double vy = velocity * (sin (angle * (pi / 180.0) ));
    double time = (vy / g) * 2;
    double range = vx * time;

    double distance = (int) (range*100.0) / (100.0);
    return distance;
}

bool bombHit(double r, double distance) {
    double diff;
    if (distance < r) {
        diff = distance - r;
    }
    else {
        diff = r - distance;
    }
    if ((diff <= 1.0) & (diff >= -1.0)) {
        cout << "It's a hit!";
        return true;
    }
    else {
        if (distance < r) {
            cout << "You were " << r - distance << "m short. " << endl;
        }
        else {
            cout << "You were " << distance - r << "m long. " << endl;
        }
    }
    return false;
}

