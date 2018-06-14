#include <iostream>
#include "iniHandler.h"
using namespace std;
int main() {
    //main for test
    iniHandler test ("test.ini");
    if (test.Error()){
        std::cout<<"Can't open or create the file"<<std::endl;
        return 1;
    }
    test.setInt("Koala","Age",10);
    test.set("Koala","Type","Australian");
    test.setBool("Level","Stage_3",false); //false==0 true==1
    test.setInt("Audio","Volume",50);
    test.setDouble("Car","Distance",120.5);

    cout<<"Sections:"<<endl;
    for(auto section:test.get_section()){
        cout<<section<<endl;
    }
    cout<<endl<<"Keys:"<<endl;
    for(auto key:test.get_fields("Audio")){
        cout<<key<<endl;
    }
    for(auto key:test.get_fields("Car")){
        cout<<key<<endl;
    }
    for(auto key:test.get_fields("Koala")){
        cout<<key<<endl;
    }
    for(auto key:test.get_fields("Level")){
        cout<<key<<endl;
    }
    cout<<endl<<"Values:"<<endl;
    cout<<test.getInt("Audio","Volume")<<endl;
    cout<<test.getDouble("Car","Distance")<<endl;
    cout<<test.getInt("Koala","Age")<<endl;
    cout<<test.getString("Koala","Type")<<endl;
    cout<<test.getBool("Level","Stage_3")<<endl; //true==1 false==0
    test.Close();
    return 0;
}