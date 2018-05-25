//
// Created by user on 23/05/18.
//

#include "iniHandler.h"

iniHandler::iniHandler(string filename) {
    this->filename=filename;
    this->error=false; //no errors when open a file
    this->file.open(filename);
    string actual_line,actual_section,key,value; //to check of what a line is composed of
    bool in_section=false;
    unordered_map<string,string>section; //a section is composed of this elements:key,value
    if (this->file.is_open()){ //check if the file is open
        while (getline(file,actual_line)) {
            if (actual_line.empty())
                continue; //if a line is empty pass to next line
            if (actual_line[0] == '[' && actual_line.size() - 1 == ']') { //a line at the end has a null term this is why -1
                if (actual_section != this->getSection(actual_line)) {
                    if (!actual_section.empty() && !section.empty()) { //if the section retrieved is not empty and the section container is empty
                        container[actual_section] = section; //add to the section map of map in map
                        section.clear(); //delete the aquisited section
                    }actual_section = this->getSection(actual_line); //save new section//delete the aquisited section
                }in_section=true;
            } else{
                if(in_section) { //already in a section
                    if(this->getLine(actual_line,keyy,value)){
                        section[key]=value;
                    }else
                        {
                        //we have ;comment
                    }
                }                                   //need to be revisionated for a better form, don't like it so much
            }
        }if(!section.empty()){
            container[actual_section]=section; //add the section
            section.clear(); //delete the aquisited section
        }file.close(); //terminated operations on file
    }error=true;
}
void iniHandler::Close() {
    if(filename.size()==0)
        return 0; //current file?
    else{//else if the size is!=0 we have a file in the buffer

    }
    //surely i'll have to clear everything if the file is closed
    this->container.clear();
    this->filename.clear();
    this->file.close();
    this->error=false; //also the error has to be set to the default mode, if a future file is being opened everything has to be ok
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