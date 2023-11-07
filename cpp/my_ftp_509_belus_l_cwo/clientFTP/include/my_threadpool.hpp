#ifndef MY_THREADPOOL_
#define MY_THREADPOOL_

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>

unsigned int GetThreadCount(unsigned int divBy);
using Task = std::function<void()>;

class ThreadPool
{
    private:
        std::vector<std::thread> workers;
        std::queue<Task> tasks;
        std::mutex mutex;
        bool stop = false;

    public:
    ThreadPool(unsigned int nbThread)
    {
        unsigned int index = 0;
        while (index < nbThread)
        {
            workers.emplace_back(&ThreadPool::workerFunction, this);
            index += 1;
        }
    }


    void enqueue(Task task) 
    {
        std::lock_guard<std::mutex> lock(mutex);
        tasks.push(task);
    }


    void workerFunction()
    {
        while (!stop)
        {
            Task task;
            {
                std::lock_guard<std::mutex> lock(mutex);
                if (tasks.empty()) 
                {
                    continue;
                }
                task = tasks.front();
                tasks.pop();
            }
            task();
        }
    }
};


#endif