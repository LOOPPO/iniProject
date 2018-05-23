//
// Created by user on 23/05/18.
//

#include "iniHandler.h"

iniHandler::iniHandler(string filename) {
    this->filename=filename;
    this->error=false;
    this->file.open(filename); //open file
    string linenow,sectionnow,key,value;

    if(this->file.is_open()){
....................................................
    }
}
void iniHandler::Close() {
    if(filename.size()==0)
        return;
    .................................
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