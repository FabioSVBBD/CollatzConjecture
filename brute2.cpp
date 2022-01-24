#include <iostream>
#include <chrono>
#include <ctime>

#include "include/BigInt.cpp"

using namespace std;

bool isNumber(const string &str);
int getStopTime(BigInt n);

int main(int argc, char *argv[])
{
    if (argc != 2 || !isNumber(argv[1]))
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: brute [argument(unsigned long long int)]\n\n";
        return 0;
    }

    BigInt val(argv[1]);

    if (val <= BigInt(0))
    {
        cout << "Error: Invalid Range.\nValid range: (0; Inf)\n\n";
        return 0;
    }

    auto start = std::chrono::system_clock::now();
    int stopTime = getStopTime(val);

    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << stopTime << endl;
    // cout << "elapsed time: " << elapsed_seconds.count() << "s\n\n";

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

int getStopTime(BigInt n)
{
    int counter = 0;

    while (! (n == BigInt(1)) )
    {
        if (n % 2 == 0)
            n = n / BigInt(2);
        else
            n = BigInt(3) * n + BigInt(1);

        counter++;
    }

    return counter;
}
