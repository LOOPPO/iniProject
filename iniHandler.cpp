//
// Created by user on 23/05/18.
//

#include "iniHandler.h"

iniHandler::iniHandler(string filename) {
    this->filename=filename;
    this->error=false;
    this->file.open(filename); //open file
    string linenow,sectionnow,key,value;
    bool insection=false;

    if(this->file.is_open()){
        while (getline(file,linenow)){ //analize each line
            if(!linenow.size()) //if nothing skip
                continue;
        }
    }
}
void iniHandler::Close() {
    if(filename.size()==0)
        return; //current file?
    this->file.open(filename,ofstream::out|ofstream::trunc);

}
bool iniHandler::error() {
    return this->error;
}
void iniHandler::set(string section, string key, string value) {
    container[section][key]=value;
}
void iniHandler::setInt(string section, string key, unsigned long long value) {
    this->set(section,key,to_string(value));
}
void iniHandler::setDouble(string section, string key, double value) {
    this->set(section,key,to_string(value));
}
void iniHandler::setBool(string section, string key, bool value) {
    if(value){
        this->set(section,key,"TRUE");
    } else
        this->set(section,key,"FALSE");
}
string iniHandler::getString(string section, string key) {
    if(!this->container.count(section)|| !this->container[section](key)){
        return "";
    }
    return this->container[section][key];
}
bool iniHandler::getBool(string setion, string key) {
    const string str=this->getString(section,key);
    return str=="TRUE";
}
bool iniHandler::delKey(string section, string key) {
    return container[section].erase(key);
}
bool iniHandler::delSection(string section) {
    return container.erase(section);
}