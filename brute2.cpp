#include <iostream>
#include <chrono>
#include <ctime>
#include <map>
#include <list>

using namespace std;

bool isNumber(const string &str);
int getStopTime(unsigned long long int n);

enum STATE { OPEN, BUSY, DONE };

std::map<int, int> stopMap;
std::list<STATE> states;

int main(int argc, char *argv[])
{
    cout << "Starting ..." << endl;

    if (argc != 2)
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: collatz [argument(int)]" << endl;
        return 0;
    }
    unsigned long long int val = 0;

    if (isNumber(argv[1]))
        val = stoull(argv[1]);

    auto start = std::chrono::system_clock::now();

    cout << "before" << endl;

    for (unsigned long long int i = 1; i < val; i++)
    {
        int stopTime = getStopTime(i);
        stopMap.insert(pair<int, int>(i, stopTime));
    }

    int stopTime = getStopTime(val);

    auto end = std::chrono::system_clock::now();

    cout << "Stepping Time for " << val << ": " << stopTime << endl;
    chrono::duration<double> elapsed_seconds = end - start;
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
        if (stopMap.count(n))
        {
            counter += stopMap.at(n);
            return counter;
        }

        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        counter++;
    }

    return counter;
}