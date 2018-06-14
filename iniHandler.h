//
// Created by user on 23/05/18.
//

#ifndef INIPROJECT_INIHANDLER_H
#define INIPROJECT_INIHANDLER_H
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
class iniHandler {
public:
    iniHandler(string filename);//constructor
    ~iniHandler(){
        this->Close();
    };//destructor
    bool Error();//if an error occur return true
    //functions to set values
    void set(string section,string key,string value);
    void setInt(string section,string key, unsigned long long value);
    void setDouble(string section,string key,double value);
    void setBool(string section,string key,bool value);
    //functions to read values
    unsigned long long getInt(string section,string key);
    double getDouble(string section,string key);
    bool getBool(string setion,string key);
    string getString(string section,string key);
    std::set<string>get_section()const; //to return a set of unique strings
    std::set<string>get_fields(string section);
    //functions to delete
    bool delKey(string section,string key);
    bool delSection(string section);
    //something to add news to the file,if there are
    void Close(); //save all!!

private:
    string filename;
    fstream file;
    unordered_map<string,unordered_map<string,string>>container;
    bool error;//errors are possible
    inline string getSection(string line)const; //take the current section,inline for better resources use
    bool getLine(const string line,string&key,string&value); //take the line
};


#endif //INIPROJECT_INIHANDLER_H
