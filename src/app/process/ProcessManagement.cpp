#include<iostream>
#include <cstring>
#include <windows.h>
#include "ProcessManagement.hpp"
#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement :: ProcessManagement(){}

bool ProcessManagement ::submitToQueue(unique_ptr<Task> task){
    taskQueue.push(move(task));
    return true;
}

void ProcessManagement :: executeTasks(){
    while(taskQueue.empty()){
        unique_ptr<Task> taskToExecute = move(taskQueue.front());
        taskQueue.pop();
        cout<<"executing task"<<taskToExecute->toString()<<endl;
        executionCryption(taskToExecute->toString());
    }
}