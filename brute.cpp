#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

bool isNumber(const string &str);
int getStopTime(unsigned long long int n);

int main(int argc, char *argv[])
{
    if (argc != 2 || !isNumber(argv[1]))
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: brute [argument(unsigned long long int)]" << endl;
        return 0;
    }
    
    unsigned long long int val = 0;
    val = stoull(argv[1]);

    auto start = std::chrono::system_clock::now();
    int stopTime = getStopTime(val);

    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Stepping Time: " << stopTime << endl;
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

int getStopTime(unsigned long long int n)
{
    int counter = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        counter++;
    }

    return counter;
}
