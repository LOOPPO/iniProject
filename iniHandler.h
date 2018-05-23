//
// Created by user on 23/05/18.
//

#ifndef INIPROJECT_INIHANDLER_H
#define INIPROJECT_INIHANDLER_H

#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;
class iniHandler {
public:
    iniHandler(string filename);//constructor
    ~iniHandler();//destructor

    bool error();//if an error occur return true



private:
    string filename;
    map<string,map<string,string>>container;

    bool error;//errors are possible

};


#endif //INIPROJECT_INIHANDLER_H
