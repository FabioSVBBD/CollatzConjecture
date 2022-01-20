#include <iostream>
#include <chrono>
#include <ctime>
#include <map>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

bool isNumber(const string &str);
int getStopTime(unsigned long long int n);
void startThread();

std::map<int, int> stopMap;
vector<thread *> threads;
unsigned long long int MAX = 0;
std::mutex m;

int main(int argc, char *argv[])
{
    if (argc != 2 || !isNumber(argv[1]))
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: collatz [argument(int)]" << endl;
        return 0;
    }
    
    int NUM_THREADS = 5;
    MAX = stoull(argv[1]);

    cout << "Beginning ..." << endl;
    auto start = std::chrono::system_clock::now();

    // Creates and Starts Threads
    for (int i = 0; i < NUM_THREADS; i++)
        threads.push_back(new thread(startThread));

    // Waits for threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
        threads[i]->join();

    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Stepping Time for " << MAX << ": " << stopMap.find(MAX)->second << endl;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n\n";

    return stopMap.find(MAX)->second;
}

bool isNumber(const string &str)
{
    for (char const &c : str)
        if (std::isdigit(c) == 0)
            return false;

    return true;
}

void startThread()
{
    for (unsigned long long int i = 1; i <= MAX; i++)
    {
        // critical section
        m.lock();
        if (stopMap.find(i) != stopMap.end())
        {
            int stopTime = getStopTime(i);
            stopMap.insert(pair<int, int>(i, stopTime));
        }
        m.unlock();
    }
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