#include <iostream>
#include <thread>
#include <queue>
#include <vector>

using namespace std;

void getNextValue(int max);
void calcStoppingTime(int number);
int get_map_IJ(int i, int j);
bool is_n_in_map(int n);
pair<bool, int> get_n_pair(int n);
void getTotalStoppingTime();
bool isNumber(const string &str);

vector<string> STATES = {"open", "busy", "done"}; // might be removed

vector<tuple<int, int> *> stepsMap;
vector<string> stepsMapStates;
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
    int thread_count = 5;

    for (int i = 0; i < thread_count; i++)
    {
        threads.push(new thread(getNextValue, MAX));
    }

    for (int i = 0; i < thread_count; i++)
    {
        threads.front()->join();
        threads.pop();
    }

    for (unsigned int i = 0; i < stepsMap.size(); i++)
        cout << "Key: " << get_map_IJ(i, 0) << "\tValue: " << get_map_IJ(i, 1) << endl;

    return 0;
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

    // specify here using stepsMapStates that 'counter' is in 'busy' state

    // next element found, continue
    if (nextFound)
        calcStoppingTime(counter);
    // else nothing to search, thread is destroyed.
}

void calcStoppingTime(int number)
{
    // This should be ammended to look in the table
    // to actually make sense in being concurrent
    int n = number;
    int counter = 0;

    while (n != 1)
    {
        // if n is in map, get n's map, add it to counter, break
        // else (n not in map) do below calc
        pair<bool, int> mapVal = get_n_pair(n);
        bool isInMap = get<0>(mapVal);

        if (isInMap)
        {
            // get n's step size, add it to counter, break
            int stepSize = get<1>(mapVal);
            counter += stepSize;
            break;
        }
        else
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = 3 * n + 1;

            counter++;
        }
    }

    // Total stopping time = counter.
    stepsMap.push_back(new tuple<int, int>(number, counter));
    // cout << "Key: " << get_map_IJ(stepsMap.size() - 1, 0) << "\tValue: " << get_map_IJ(stepsMap.size() - 1, 1) << endl;
    // specify here that number is done, and can be read

    getNextValue(MAX);
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

pair<int, int> get_map_I(int i)
{
    if (i < stepsMap.size())
        return pair<int, int>(get<0>(*stepsMap[i]), get<1>(*stepsMap[i]));

    return pair<int, int>(-1, 0); // default
}

bool is_n_in_map(int n)
{
    for (unsigned int i = 0; i < stepsMap.size(); i++)
        if (n == get_map_IJ(i, 0))
            return true;

    return false;
}

pair<bool, int> get_n_pair(int n)
{
    for (unsigned int i = 0; i < stepsMap.size(); i++)
        if (n == get<0>(get_map_I(i)))
            return pair<bool, int>(true, get<1>(get_map_I(i)));

    return pair<bool, int>(false, -1);
}

void getTotalStoppingTime(int num)
{
    int number = num;
    int count = 1;

    while (number != 1)
    {
        if (number % 2 == 0)
            number = number / 2;
        else
            number = number * 3 + 1;

        count++;
    }

    // cout << "Steps for " << num << " to enter 4-2-1: " << count << endl;
}