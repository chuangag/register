//
//  main.cpp
//  registerxcode
//
//  Created by HUANG CHIA HUNG on 2016/11/20.
//  Copyright © 2016年 HUANG CHIA HUNG. All rights reserved.
//

#include <iostream>
#include "hashTable.h"
#include "doublySortedLinkedList.h"
#include "objects.h"
#include "courseRecord.h"
using namespace std;
int main(int argc, const char * argv[]) {
    HashTable<Student> studentTable(29,10);
    HashTable<Course> courseTable(17,36);
    DoublySortedLinkedList<CourseRecord> courseSelection;
    
    
    cout<<"-------------Student------------"<<endl<<endl<<endl;
    //test student
    Student s1;
    s1.setStudentID("12345678");
    s1.setStudentName("Gao Tong");
    s1.setYear("3");
    s1.setGender("M");
    
    Student s2;
    s2.setStudentID("12345677");
    s2.setStudentName("Mei Zi");
    s2.setYear("3");
    s2.setGender("F");
    
    Student s3;
    s3.setStudentID("12345676");
    s3.setStudentName("HAHA");
    s3.setYear("1");
    s3.setGender("F");
    
    studentTable.addItem(s1);
    studentTable.addItem(s2);
    studentTable.addItem(s3);
    /*
    studentTable.queryItem(s1);
    studentTable.removeItem(s3);
    studentTable.removeItem(s1);
    studentTable.removeItem(s1);
    studentTable.queryItem(s1);
    studentTable.queryItem(s2);
    studentTable.queryItem(s3);*/
    
    for(int i=0;i<studentTable.traverseAllInHashTable().size();i++){
        
        studentTable.traverseAllInHashTable().at(i).print_Query();
    }
    
    cout<<"-------------Course------------"<<endl<<endl<<endl;
    
    Course c1;
    c1.setCourseCode("COMP2333");
    c1.setCredit("4");
    c1.setCourseName("Bad OOP");
    
    Course c2;
    c2.setCourseCode("COMP2334");
    c2.setCredit("3");
    c2.setCourseName("Good OOP");
    
    Course c3;
    c3.setCourseCode("COMP1324");
    c3.setCredit("2");
    c3.setCourseName("Shit OOP");
    
    Course c4;
    c4.setCourseCode("COMP132");
    c4.setCredit("2");
    c4.setCourseName("Damn OOP");
    
    courseTable.addItem(c1);
    //courseTable.queryItem(c2);
    courseTable.addItem(c2);
    //courseTable.addItem(c2);
    //courseTable.queryItem(c2);
    //courseTable.queryItem(c1);
    //courseTable.removeItem(c2);
    //courseTable.queryItem(c2);
    courseTable.addItem(c3);
    courseTable.addItem(c4);
    //courseTable.removeItem(c3);
    //courseTable.queryItem(c3);
    for(int i=0;i<courseTable.traverseAllInHashTable().size();i++){
        
        courseTable.traverseAllInHashTable().at(i).print_Query();
    }
    
    cout<<"------------Course Registration------------"<<endl<<endl<<endl;
    
    CourseRecord cr1;
    cr1.setStudentID("12345678",studentTable);
    cr1.setCourseCode("COMP2333", courseTable);
    
    CourseRecord cr2;
    cr2.setStudentID("12345677",studentTable);
    cr2.setCourseCode("COMP2333", courseTable);
    
    CourseRecord cr3;
    cr3.setStudentID("12345677",studentTable);
    cr3.setCourseCode("COMP2334", courseTable);
    
    courseSelection.insertItem(cr1);
    courseSelection.insertItem(cr3);
    /*courseSelection.queryAndPrintItem(cr1);
    courseSelection.queryAndPrintItem(cr2);
    courseSelection.insertItem(cr1);*/
    courseSelection.insertItem(cr2);
    /*
    courseSelection.queryAndPrintItem(cr2);
    courseSelection.queryAndPrintItem(cr3);*/
    courseSelection.setExamMarkFor(cr3,"24");
    //courseSelection.queryAndPrintItem(cr3);
    
    //!!!!!!!!notice that deletion of hashtable and the register record is seperated
    /*courseTable.removeItem(c1);
    courseSelection.delete_all_courses(c1);
    
    courseSelection.queryAndPrintItem(cr1);
    courseSelection.queryAndPrintItem(cr3);
    
    courseTable.removeItem(c2);
    
    courseSelection.delete_all_courses(c2);
    courseSelection.queryAndPrintItem(cr3);*/
    for(int i=0;i<courseSelection.traverseAll().size();i++){
        
        courseSelection.traverseAll().at(i).print_Query();
    }
    return 0;
    
}
