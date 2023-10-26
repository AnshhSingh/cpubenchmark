#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    const int numIterations = 100000000; // Adjust the number of iterations as needed

    // Start timing
    auto startTime = high_resolution_clock::now();

    // Benchmarking test: Arithmetic operations
    double result = 0.0;
    for (int i = 0; i < numIterations; ++i) {
        result += i * 0.5 + 2.0 / (i + 1);
    }

    // Stop timing
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);

    // Print results
    cout << "Arithmetic Benchmark Results:" << endl;
    cout << "Iterations: " << numIterations << endl;
    cout << "Result: " << result << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}