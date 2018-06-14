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
    test.setInt("Audio","Volume",50);
    test.setInt("Koala","Age",12);
    test.set("Koala","Type","Koala_Type");
    test.setBool("Level","Stage_3",true);
    test.setDouble("Distance","Car",120.5);

    cout<<"Section:"<<endl;
    for(auto section:test.get_section()){
        cout<<section<<endl;
    }
    cout<<endl<<"Keys:"<<endl;
    for(auto key:test.get_fields("Koala")){
        cout<<key<<endl;
    }
    test.Close();
    return 0;
}