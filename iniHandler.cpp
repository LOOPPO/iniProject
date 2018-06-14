//
// Created by user on 23/05/18.
//

#include "iniHandler.h"
using namespace std;
iniHandler::iniHandler(string filename) {
    this->filename=filename;
    this->error=false; //no errors when open a file
    this->file.open(filename);
    string actual_line,actual_section,key,value; //to check of what a line is composed of
    bool in_section=false;
    unordered_map<string,string>section; //a section is composed of this elements:key,value
    if (this->file.is_open()){ //check if the file is open
        while (getline(file,actual_line)) {
            if (!actual_line.size())
                continue; //if a line is empty pass to next line
            if (actual_line[0] == '[' && actual_line[actual_line.size() - 1 ]== ']') { //a line at the end has a null term this is why -1
                if (actual_section != this->getSection(actual_line)) {
                    if (!section.empty() && !actual_section.empty()) { //if the section retrieved is not empty and the section container is empty
                        container[actual_section] = section; //add to the section map of map in map
                        section.clear(); //delete the aquisited section
                    }
                    actual_section = this->getSection(actual_line); //save new section//delete the aquisited section
                }
                in_section=true;
            }
            else{
                if(in_section) { //already in a section
                    if(this->getLine(actual_line,key,value)){
                        section[key]=value;
                    }
                    else
                        {
                        //we have ;comment
                    }
                }
            }
        }
        if(!section.empty()){
            container[actual_section]=section; //add the section
            section.clear(); //delete the aquisited section
        }
        file.close(); //terminated operations on file
    }
    else{
        this->error= true; //here there was a fatal error,discarded the else.......
    }
}
void iniHandler::Close() {
    if(filename.size()==0)
        return;
        //current file?
    //else if the size is!=0 we have a file in the buffer
    this->file.open(filename,ofstream::out | ofstream::trunc);
    size_t count = 0,total_section = container.size(),total_key,key_count = 0;
    for(auto section:container){ //go in each section and count them
        ++count;
        key_count=0;
        file << '['+section.first + ']'<< endl;
        total_key=section.second.size();
        for(auto key:section.second){ //go in each key and count them
            ++key_count;
            if(key_count!=total_key){
                file<< key.first + "=" + key.second << endl;
            } else
                file << key.first + "=" + key.second;
        }if(count!=total_section)
            file << endl << endl;
    }

    //surely i'll have to clear everything if the file is closed
    this->container.clear();
    this->filename.clear();
    this->file.close();
    this->error=false; //also the error has to be set to the default mode, if a future file is being opened everything has to be ok
}
bool iniHandler::Error(){
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
    if(!this->container.count(section)|| !this->container[section].count(key)){
        return "";
    }
    return this->container[section][key];
}
unsigned long long iniHandler::getInt(string section, string key) {
    string::size_type sz=0;
    const string str=this->getString(section,key);
    return str.size()?stoull(str,&sz,0):0;
}
double iniHandler::getDouble(string section, string key) { //for real numbers
    string::size_type sz;
    const string str=this->getString(section,key);
    return str=="True";
}
bool iniHandler::getBool(string setion, string key) {
    const string str=this->getString(setion,key);
    return str=="TRUE";
}
std::set<string> iniHandler::get_section() const {
    std::set<string>buffer; //why unless put std:: buffer error?
    for(auto section:container){
        buffer.insert(section.first);
    }
    return buffer;
}
std::set<string> iniHandler::get_fields(string section) {
    std::set<string>buffer;
    if(!container.count(section))
        return buffer;
    for(auto key:container[section]){
        buffer.insert(key.first);
    }
    return buffer;
}

bool iniHandler::delKey(string section, string key) {
    return container[section].erase(key);
}
bool iniHandler::delSection(string section) {
    return container.erase(section);
}
//faster functions used a lot
string iniHandler::getSection(string line) const {
    line.erase(line.begin());
    line.erase(line.end()-1);
    return line;
}
bool iniHandler::getLine(const string line, string &key, string &value) {
    auto found=line.find("=");
    if (found){
        key=line.substr(0,found-1);
        value=line.substr(found+2,line.size()-1);
                return true;
    }
    return false; //if comment no valid line found!!!
}
