#include <iostream>
#include <chrono>
#include <ctime>

// #include "include/BigInt.cpp"
#include "APA/bint/bint.hpp"

using namespace std;

bool isNumber(const string &str);
int getStopTime(apa::bint n);

int main(int argc, char *argv[])
{
    if (argc != 2 || !isNumber(argv[1]))
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: brute [argument(unsigned long long int)]\n\n";
        return 0;
    }

    apa::bint val(argv[1]);

    if (val <= 0)
    {
        cout << "Error: Invalid Range.\nValid range: (0; Inf)\n\n";
        return 0;
    }

    auto start = std::chrono::system_clock::now();
    int stopTime = getStopTime(val);

    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Stppping Time: " << stopTime << endl;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n\n";

    return stopTime;
}

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

int getStopTime(apa::bint n)
{
    int counter = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;

        counter++;
    }

    return counter;
}