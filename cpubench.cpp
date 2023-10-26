#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
using namespace std;
using namespace chrono;
int arithmetic();
int memory();
int floating_point();
int main()
{
    int sum=0;
     auto startTime = high_resolution_clock::now();
    const int numIterations = 1000000000;
    arithmetic();
    memory();
    floating_point();
     auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout<< "Total score: " <<duration.count()<<" ms\n";
    return 0;
}
int arithmetic()
{
    auto startTime = high_resolution_clock::now();
    const int numIterations = 1000000000; // Adjust the number of iterations as needed
    double result = 0.0;
    for (int i = 0; i < numIterations; ++i)
    {
        result += i * 0.5 + 2.0 / (i + 1);
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout<< "Arithmetic: " <<duration.count()<<" ms\n";
   
}
int memory(){
    auto startTime = high_resolution_clock::now();
    const int arraySize = 100000000;
    int* dataArray = new int[arraySize];


    for (int i = 0; i < arraySize; ++i) {
        dataArray[i] = i;
    }

    long long sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += dataArray[i];
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout<< "Memory: " <<duration.count()<<" ms\n";
}
int floating_point(){
    auto startTime = high_resolution_clock::now();
     double result = 0.0;
     const int numIterations = 200000000;
     int i=0;
    for ( i = 0; i < numIterations; i++) {
        result += sqrt(i) + sin(i) + cos(i);
    }
 auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout<< "floating points: " <<duration.count()<<" ms\n";
}
// int vector(){
// }