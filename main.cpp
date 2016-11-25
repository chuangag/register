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
/*TODO: might need to implement insert fuction pack since I don't think the pointer table is inserted yet, but I am too tired to check now, 11/24
 
 BUGS: when inserting course record, first time input wrong coursecorde , then invalid message will print twice, check the while loop and maybe the sequence of cout!!!!!!!!
 
 */



//declare functions, implementations below

//simplify delete fuctions into one line

void deleteCourse(Course &c,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);
void deleteStudent(Student &s,HashTable<Student> &studentTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);

//simplify insert functions of CourseSelection (also need to add to the Pointer table)
void addCourseSelection(CourseRecord &cr,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);

//menu functions
void main_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);
void student_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);
void course_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);
void course_selection_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);

void return_main_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);




int main(int argc, const char * argv[]) {
    HashTable<Student> studentTable(29,10);
    HashTable<Course> courseTable(17,36);
    HashTable<CourseRecord*> pstudentTable(29,10);
    HashTable<CourseRecord*> pcourseTable(17,36);
    DoublySortedLinkedList<CourseRecord> courseSelection;
    
    main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
    
    return 0;
}




/* for testing only
int main(int argc, const char * argv[]) {
    
    
    HashTable<Student> studentTable(29,10);
    HashTable<Course> courseTable(17,36);
    HashTable<CourseRecord*> pstudentTable(29,10);
    HashTable<CourseRecord*> pcourseTable(17,36);
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
    
    studentTable.queryItem(s1);
    studentTable.removeItem(s3);
    studentTable.removeItem(s1);
    studentTable.removeItem(s1);
    studentTable.queryItem(s1);
    studentTable.queryItem(s2);
    studentTable.queryItem(s3);
    
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
    
    CourseRecord cr1;CourseRecord* pcr1=&cr1;
    cr1.setStudentID("12345678",studentTable);
    cr1.setCourseCode("COMP2333", courseTable);
    
    CourseRecord cr2;CourseRecord* pcr2=&cr2;
    cr2.setStudentID("12345677",studentTable);
    cr2.setCourseCode("COMP2333", courseTable);
    
    CourseRecord cr3;CourseRecord* pcr3=&cr3;
    cr3.setStudentID("12345677",studentTable);
    cr3.setCourseCode("COMP2334", courseTable);
    
    courseSelection.insertItem(cr1);pstudentTable.addItembyStuIDHash(pcr1);pcourseTable.addItembyCCodeHash(pcr1);
    courseSelection.insertItem(cr3);pstudentTable.addItembyStuIDHash(pcr3);pcourseTable.addItembyCCodeHash(pcr3);
    courseSelection.queryAndPrintItem(cr1);
    courseSelection.queryAndPrintItem(cr2);
    courseSelection.insertItem(cr1);
    courseSelection.insertItem(cr2);pstudentTable.addItembyStuIDHash(pcr2);pcourseTable.addItembyCCodeHash(pcr2);
    
    courseSelection.queryAndPrintItem(cr2);
    courseSelection.queryAndPrintItem(cr3);
    courseSelection.setExamMarkFor(cr3,"24");
    //courseSelection.queryAndPrintItem(cr3);
    
    
    //!!!!!!!!notice that deletion of hashtable and the register record is seperated
    courseTable.removeItem(c1);
    courseSelection.delete_all_courses(c1);
    
    courseSelection.queryAndPrintItem(cr1);
    courseSelection.queryAndPrintItem(cr3);
    
    courseTable.removeItem(c2);
    
    courseSelection.delete_all_courses(c2);
    courseSelection.queryAndPrintItem(cr3);
    
    
    
    
    for(int i=0;i<courseSelection.traverseAll().size();i++){
        
        courseSelection.traverseAll().at(i).print_Query();
    }
    courseSelection.eraseItem(cr2);
    courseSelection.eraseItem(cr1);
    deleteCourse(c1,courseTable,courseSelection,pstudentTable,pcourseTable);
    
    deleteStudent(s2, studentTable, courseSelection, pstudentTable, pcourseTable);
    return 0;
    
}*/


//function definition

//fuctions wrapping for simplier main
void deleteCourse(Course &c,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    if(!courseSelection.checkCourseExist(c)){//check if any register record exist, if exist, deletion failed
        courseTable.removeItem(c);
        courseSelection.delete_all_courses(c);
        pcourseTable.remove_all_Pointer_by_course(c);
        pstudentTable.remove_all_Pointer_by_course(c);
    }
    else{
        cout<<"Some students already registered in this course, deletion fail"<<endl;
    }
}

void deleteStudent(Student &s,HashTable<Student> &studentTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    studentTable.removeItem(s);
    courseSelection.delete_all_students(s);
    pcourseTable.remove_all_Pointer_by_student(s);
    pstudentTable.remove_all_Pointer_by_student(s);
    
}

void addCourseSelection(CourseRecord &cr,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    courseSelection.insertItem(cr);
    CourseRecord* pcr = &cr;
    pcourseTable.addItembyCCodeHash(pcr);
    pstudentTable.addItembyStuIDHash(pcr);
}

void return_main_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    cout<<endl<<"Hit ENTER to continue..."<<endl;
    getchar();
    main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
}



//input of main menu should be 1-6 TODO:4,5 not available yet
void main_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    //clear the screen first
    system("clear");
    //print the menu
    cout<<"HKUST Course Registration System"<<endl;
    cout<<"--------------------------------"<<endl<<endl;
    cout<<"1. Student Management"<<endl;
    cout<<"2. Course Management"<<endl;
    cout<<"3. Course Registration"<<endl;
    cout<<"4. Report Management"<<endl;
    cout<<"5. File Management"<<endl;
    cout<<"6. Exit"<<endl<<endl;
    cout<<"Enter your choice (1-6): ";
    string schoice;
    getline(cin,schoice);
    while(!is_number(schoice)||stoi(schoice)>6||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-6): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{
            student_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 2:{
            course_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 3:{
            course_selection_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 4:{
            //TODO: html report
            break;
        }
        case 5:{
            //TODO: file I/O
            break;
        }
        case 6:{
            system("exit");
            break;
        }
        default:
            break;
    }
}

void student_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    //clear the screen first
    system("clear");
    //print the menu
    cout<<"HKUST Course Registration System  (Student Menu)"<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;
    cout<<"1. Insert Student Record"<<endl;
    cout<<"2. Modify Student Record"<<endl;
    cout<<"3. Delete Student Record"<<endl;
    cout<<"4. Query Student Record"<<endl;
    cout<<"5. Go back to main menu"<<endl<<endl;
    cout<<"Enter your choice (1-5): ";
    string schoice;
    getline(cin,schoice);
    while(!is_number(schoice)||stoi(schoice)>6||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-5): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{//insert new student
            Student stu;
            string StuID;
            string StuName;
            string StuYear;
            string StuGender;
            
            
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            stu.setStudentID(StuID);
            int index=studentTable.hashedIndex(stu);
            if(studentTable.getTable().at(index).checkInList(stu)){
                stu.print_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cout<<"Enter the student name: ";
            getline(cin,StuName);
            stu.setStudentName(StuName);
            cout<<"Enter the student year [1-3]: ";
            getline(cin,StuYear);
            stu.setYear(StuYear);
            cout<<"Enter the student gender [M,F]: ";
            getline(cin,StuGender);
            stu.setGender(StuGender);
            
            //insert the student
            studentTable.addItem(stu);
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 2:{//modify student
            Student stu;
            string StuID;
            string StuName;
            string StuYear;
            string StuGender;
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            stu.setStudentID(StuID);
            int index=studentTable.hashedIndex(stu);
            //check exist
            if(!studentTable.getTable().at(index).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                cout<<"Enter the student name ["<<studentTable.getItem(stu).getStudentName()<<"]: ";
                getline(cin,StuName);
                studentTable.getItem(stu).setStudentName(StuName);
                cout<<"Enter the student year ["<<studentTable.getItem(stu).getYear()<<"]: ";
                getline(cin,StuYear);
                studentTable.getItem(stu).setYear(StuYear);
                cout<<"Enter the student gender ["<<studentTable.getItem(stu).getGender()<<"]: ";
                getline(cin,StuGender);
                studentTable.getItem(stu).setGender(StuGender);
                studentTable.getItem(stu).print_modify_success();
                
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            
            break;
        }
        case 3:{//delete student
            Student stu;
            string StuID;
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            stu.setStudentID(StuID);
            int index=studentTable.hashedIndex(stu);
            //check exist
            if(!studentTable.getTable().at(index).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                deleteStudent(studentTable.getItem(stu), studentTable, courseSelection,pstudentTable, pcourseTable);
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }

            break;
        }
        case 4:{//query student
            Student stu;
            string StuID;
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            stu.setStudentID(StuID);
            int index=studentTable.hashedIndex(stu);
            //check exist
            if(!studentTable.getTable().at(index).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                studentTable.queryItem(stu);
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            break;
        }
        case 5:{//return to main menu
            main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        default:
            break;
    }
}

void course_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    //clear the screen first
    system("clear");
    //print the menu
    cout<<"HKUST Course Registration System  (Course Menu)"<<endl;
    cout<<"-----------------------------------------------"<<endl<<endl;
    cout<<"1. Insert Course Record"<<endl;
    cout<<"2. Modify Course Record"<<endl;
    cout<<"3. Delete Course Record"<<endl;
    cout<<"4. Query Course Record"<<endl;
    cout<<"5. Go back to main menu"<<endl<<endl;
    cout<<"Enter your choice (1-5): ";
    string schoice;
    getline(cin,schoice);
    while(!is_number(schoice)||stoi(schoice)>6||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-5): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{
            Course c;
            string CCode;
            string CName;
            string credit;
            
            
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            c.setCourseCode(CCode);
            int index=courseTable.hashedIndex(c);
            if(courseTable.getTable().at(index).checkInList(c)){
                c.print_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cout<<"Enter the course name: ";
            getline(cin,CName);
            c.setCourseName(CName);
            cout<<"Enter the course credit [0-5]: ";
            getline(cin,credit);
            c.setCredit(credit);
            
            //insert the course
            courseTable.addItem(c);
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 2:{//modify
            Course c;
            string CCode;
            string CName;
            string credit;
            
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            c.setCourseCode(CCode);
            int index=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(index).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                cout<<"Enter the course name ["<<courseTable.getItem(c).getCourseName()<<"]: ";
                getline(cin,CName);
                courseTable.getItem(c).setCourseName(CName);
                cout<<"Enter the course credit ["<<courseTable.getItem(c).getCredit()<<"]: ";
                getline(cin,credit);
                courseTable.getItem(c).setCredit(credit);
                courseTable.getItem(c).print_modify_success();
                
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            
            }
            break;
        }
        case 3:{//delete
            Course c;
            string CCode;
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            c.setCourseCode(CCode);
            int index=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(index).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                deleteCourse(courseTable.getItem(c),courseTable, courseSelection,pstudentTable, pcourseTable);
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            break;
        }
        case 4:{//query
            Course c;
            string CCode;
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            c.setCourseCode(CCode);
            int index=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(index).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            else{
                courseTable.queryItem(c);
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            break;
        }
        case 5:{//return to main menu
            main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        default:
            break;
    }
    
}

void course_selection_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    //clear the screen first
    system("clear");
    //print the menu
    cout<<"HKUST Course Registration System  (Registration Menu)"<<endl;
    cout<<"-----------------------------------------------------"<<endl<<endl;
    cout<<"1. Add Course"<<endl;
    cout<<"2. Drop Course"<<endl;
    cout<<"3. Modify Exam Mark"<<endl;
    cout<<"4. Query Registration"<<endl;
    cout<<"5. Go back to main menu"<<endl<<endl;
    cout<<"Enter your choice (1-5): ";
    string schoice;
    getline(cin,schoice);
    while(!is_number(schoice)||stoi(schoice)>6||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-5): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{//add(register) course(add courseRecord)
            CourseRecord cr;
            string StuID;
            string CCode;
            
            //check student exist and set student ID
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            Student stu;
            stu.setStudentID(StuID);
            int indexstu=studentTable.hashedIndex(stu);
            if(!studentTable.getTable().at(indexstu).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setStudentID(StuID, studentTable);
            
            //check course exist and set Course Code
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            Course c;
            c.setCourseCode(CCode);
            int indexcou=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(indexcou).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setCourseCode(CCode, courseTable);
            
            addCourseSelection(cr, courseTable, courseSelection, pstudentTable, pcourseTable);
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 2:{//drop course(delete courseRecord)
            CourseRecord cr;
            string StuID;
            string CCode;
            
            //check student exist and set student ID
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            Student stu;
            stu.setStudentID(StuID);
            int indexstu=studentTable.hashedIndex(stu);
            if(!studentTable.getTable().at(indexstu).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setStudentID(StuID, studentTable);
            
            //check course exist and set Course Code
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            Course c;
            c.setCourseCode(CCode);
            int indexcou=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(indexcou).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setCourseCode(CCode, courseTable);
            
            courseSelection.eraseItem(cr);
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 3:{//modify exam mark
            CourseRecord cr;
            string StuID;
            string CCode;
            string mark;
            
            //check student exist and set student ID
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            Student stu;
            stu.setStudentID(StuID);
            int indexstu=studentTable.hashedIndex(stu);
            if(!studentTable.getTable().at(indexstu).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setStudentID(StuID, studentTable);
            
            //check course exist and set Course Code
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            Course c;
            c.setCourseCode(CCode);
            int indexcou=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(indexcou).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setCourseCode(CCode, courseTable);
            
            if(!courseSelection.checkInList(cr)){
                cr.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            
            if(courseSelection.queryItem(cr).getExamMark()==-1){
                cout<<"Enter the exam mark [N/A]: ";
            }
            else{
                cout<<"Enter the exam mark ["<<courseSelection.queryItem(cr).getExamMark()<<"]: ";
            }
            getline(cin,mark);
            courseSelection.queryItem(cr).setExamMark(mark);
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 4:{//query(print) course Record
            CourseRecord cr;
            string StuID;
            string CCode;
            
            //check student exist and set student ID
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            Student stu;
            stu.setStudentID(StuID);
            int indexstu=studentTable.hashedIndex(stu);
            if(!studentTable.getTable().at(indexstu).checkInList(stu)){
                stu.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setStudentID(StuID, studentTable);
            
            //check course exist and set Course Code
            cout<<"Enter the course code: ";
            getline(cin,CCode);
            Course c;
            c.setCourseCode(CCode);
            int indexcou=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(indexcou).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            cr.setCourseCode(CCode, courseTable);
            
            courseSelection.queryAndPrintItem(cr);
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 5:{
            main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        default:
            break;
    }
    
}





