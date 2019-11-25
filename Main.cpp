//
// Created by clays on 11/22/2019.
//

#include "iostream"

#include "Hanoi.h"
#include "chrono"

using namespace std;
using namespace std::chrono;

int main (){

    auto start = high_resolution_clock::now();

    Hanoi towerOfHanoi = Hanoi(3, 4);

    auto stop = high_resolution_clock::now();

    auto durationRaw = duration_cast<microseconds>(stop - start);
    double duration = durationRaw.count() / pow(10, 6);
    cout << "Execution time: " << duration << endl;

    return 0;
}