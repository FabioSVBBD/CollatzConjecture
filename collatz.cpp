#include <iostream>
#include <thread>
#include <queue>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

bool isNumber(const string &str);
void getNextValue(int max);
void calcStoppingTime(int number);
int get_map_IJ(int i, int j);
int getStepSizeFromMap(int key);

vector<tuple<int, int> *> stepsMap;
int MAX = -1;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error: Invalid Arguments.\nAcceptable format: collatz [argument(int)]" << endl;
        return 0;
    }

    if (isNumber(argv[1]))
        MAX = stoi(argv[1]);

    queue<thread *> threads;
    int thread_count = 2;

    auto start = std::chrono::system_clock::now();
    cout << "Beginning ..." << endl;

    for (int i = 0; i < thread_count; i++)
        threads.push(new thread(getNextValue, MAX));

    for (int i = 0; i < thread_count; i++)
    {
        threads.front()->join();
        threads.pop();
    }

    auto end = std::chrono::system_clock::now();

    cout << "Done!" << endl;
    cout << "Map Size: " << stepsMap.size() << endl;
    int size = getStepSizeFromMap(MAX);
    cout << "Key: " << MAX << "\tValue: " << size;

    chrono::duration<double> elapsed_seconds = end - start;
    cout << "\n\nelapsed time: " << elapsed_seconds.count() << "s\n";

    // for (unsigned int i = 0; i < stepsMap.size(); i++)
    //     cout << "Key: " << get_map_IJ(i, 0) << "\tValue: " << get_map_IJ(i, 1) << endl;

    return size;
}

/*
auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
*/

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

void getNextValue(int max)
{
    int nextToCalc = 0;
    int counter = 0;
    bool nextFound = false;

    while (!nextFound && counter < max)
    {
        counter++;
        bool counterInMap = false;

        for (unsigned int i = 0; i < stepsMap.size() && !counterInMap; i++)
        {
            if (get_map_IJ(i, 0) == counter)
                counterInMap = true;
        }

        if (!counterInMap)
        {
            nextFound = true;
            break;
        }
    }

    // next element found, continue
    if (nextFound)
        calcStoppingTime(counter);
    // else nothing to search, thread is destroyed.
}

void calcStoppingTime(int number)
{
    int n = number;
    int counter = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        counter++;
    }

    stepsMap.push_back(new tuple<int, int>(number, counter));
    getNextValue(MAX);  // "event loop"
}

int get_map_IJ(int i, int j)
{
    if (i < stepsMap.size())
    {
        if (j == 0)
            return get<0>(*stepsMap[i]);
        else if (j == 1)
            return get<1>(*stepsMap[i]);
    }

    return -1;
}

int getStepSizeFromMap(int key)
{
    for (unsigned int i = 0; i < stepsMap.size(); i++)
        if (get_map_IJ(i, 0) == key)
            return get_map_IJ(i, 1);

    return -1;
}