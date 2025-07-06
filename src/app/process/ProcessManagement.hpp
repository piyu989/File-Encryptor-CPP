#ifndef PROCESS_MANAGEMENT.HPP
#define PROCESS_MANAGEMENT.HPP
#include "Task.hpp"
#include <iostream>
#include <queue>
#include <memory>
using namespace std;

class ProcessManagement{
    public:
        ProcessManagement();
        bool submitToQueue(unique_ptr<Task> task);
        void executeTasks();
    private:
        queue<unique_ptr<Task>>taskQueue;
};

#endif