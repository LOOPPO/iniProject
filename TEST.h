//
// Created by user on 22/06/18.
//

#ifndef INIPROJECT_TEST_H
#define INIPROJECT_TEST_H

#include "iniHandler.h"
#include "iniHandler.cpp"
#include <cxxtest/TestSuite.h>
class testIni:public CxxTest::TestSuite{
public:
    void testerInt(){
        iniHandler testI ("testerI.ini");
        testI.setInt("Koala","Age",10);
        TS_ASSERT_EQUALS(testI.getInt("Koala","Age")==10,true);
    }
    void testerDouble(){
        iniHandler testD ("testerD.ini");
        testD.setDouble("Car","Speed",134.5);
        TS_ASSERT_EQUALS(testD.getDouble("Car","Speed")==134.5,true);
    };
    void testerString(){
        iniHandler testS("testS.ini");
        testS.set("Koala","Type","Australian");
        TS_ASSERT_EQUALS(testS.getString("Koala","Type")=="Australian",true);
    };
    void testerBool(){
        iniHandler testB("testB.ini");
        testB.setBool("Game","Level",false);
        TS_ASSERT_EQUALS(testB.getBool("Game","Level"),false);
    }
};


#endif //INIPROJECT_TEST_H
