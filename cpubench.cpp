#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <thread>
using namespace std;
using namespace chrono;
void arithmetic();
void memory();
void floating_point();
void vec();
void threading();
int main()
{

    auto startTime = high_resolution_clock::now();
   arithmetic();
    memory();
    floating_point();
    vec();
    
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);

    auto startTime2 = high_resolution_clock::now();
    threading();
 auto endTime2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(endTime2 - startTime2);
    cout << "Multi-threading: " << duration.count() << " ms\n";
}
void arithmetic()
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
    cout << "Arithmetic: " << duration.count() << " ms\n";
}
void memory()
{
    auto startTime = high_resolution_clock::now();
    const int arraySize = 100000000;
    int *dataArray = new int[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        dataArray[i] = i;
    }

    long long sum = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        sum += dataArray[i];
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout << "Memory: " << duration.count() << " ms\n";

}
void floating_point()
{
    auto startTime = high_resolution_clock::now();
    double result = 0.0;
    const int numIterations = 200000000;
    int i = 0;
    for (i = 0; i < numIterations; i++)
    {
        result += sqrt(i) + sin(i) + cos(i);
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout << "floating points: " << duration.count() << " ms\n";
    
}
void vec()
{
    auto startTime = high_resolution_clock::now();
    const int N = 10000; // Matrix size
    std::vector<std::vector<double>> matrix1(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> matrix2(N, std::vector<double>(N, 3.0));
    std::vector<std::vector<double>> result(N, std::vector<double>(N, 0.0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout << "Vector: " << duration.count() << " ms\n";
    
}
void threading()
{
    auto startTime = high_resolution_clock::now();
    
   
     std::thread t2(arithmetic);
     std::thread t1(memory);
     std::thread t3(arithmetic);
     std::thread t4(memory);
     std::thread t5(floating_point);
     std::thread t6(vec);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
        auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout << "Arithmetic: " << duration.count() << " ms\n";
    
}