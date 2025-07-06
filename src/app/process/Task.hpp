#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <IO.hpp>
using namespace std;

enum class Action{
    ENCRYPT,
    DECRYPT
};

struct Task{
    string file_path;
    fstream f_stream;
    Action action;

    Task(string path,fstream &&stream,Action act): f_stream(move(stream)),action(act),file_path(path){}

    string toString(){
        ostringstream oss;
        oss<<file_path<<","<<(action==Action::DECRYPT?"DECRYPT":"ENCRYPT");
        return oss.str();
    }

    static Task fromString(const string &taskData){
        istringstream iss(taskData);
        string file_path;
        string actionStr;

        if(getline(iss,file_path,',')&&getline(iss,actionStr)){
            Action action = (actionStr == "ENCRYPT"?Action::ENCRYPT:Action::DECRYPT);
            IO io(file_path);
            fstream f_stream = move(io.getFileStream());
            if(f_stream.is_open()){
                return Task(file_path,move(f_stream),action);
            }else{
                throw runtime_error("unable to open the file");
            }
        }else{
            throw runtime_error("invalid task data found");
        }
    }
};

#endif