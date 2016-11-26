//
//  main.cpp
//  registerxcode
//
//  Created by HUANG CHIA HUNG on 2016/11/20.
//  Copyright © 2016年 HUANG CHIA HUNG. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "hashTable.h"
#include "doublySortedLinkedList.h"
#include "objects.h"
#include "courseRecord.h"
using namespace std;
/*
 BUGS:
 1. when inserting course record, first time input wrong coursecorde , then invalid message will print twice, check the while loop and maybe the sequence of cout!!!!!!!! fixed: double valid checking and not passed by reference
 
2. after deletion of student, the html will still print empty table(might need to fix the return virtual student and course problem, see the terminal)
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
void course_report_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable);

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


//input of main menu should be 1-6 
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
            course_report_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
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
    while(!is_number(schoice)||stoi(schoice)>5||stoi(schoice)<1){
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
    while(!is_number(schoice)||stoi(schoice)>5||stoi(schoice)<1){
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
    while(!is_number(schoice)||stoi(schoice)>5||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-5): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{//add(register) course(add courseRecord)
            CourseRecord cr;
            string StuID;
            string CCode;
            Student stu;
            Course c;
            
            //check student exist and set student ID
            cout<<"Enter the student ID: ";
            getline(cin,StuID);
            
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

void course_report_menu(HashTable<Student> &studentTable,HashTable<Course> &courseTable,DoublySortedLinkedList<CourseRecord> &courseSelection,HashTable<CourseRecord*> &pstudentTable,HashTable<CourseRecord*> &pcourseTable){
    //clear the screen first
    system("clear");
    //print the menu
    cout<<"HKUST Course Registration System  (Report Generation Menu)"<<endl;
    cout<<"----------------------------------------------------------"<<endl<<endl;
    cout<<"1. List all student information"<<endl;
    cout<<"2. List all course information"<<endl;
    cout<<"3. List all courses of a student"<<endl;
    cout<<"4. List all students of a course"<<endl;
    cout<<"5. Go back to main menu"<<endl<<endl;
    cout<<"Enter your choice (1-5): ";
    string schoice;
    getline(cin,schoice);
    while(!is_number(schoice)||stoi(schoice)>5||stoi(schoice)<1){
        cout<<"Invalid input, re-enter again (1-5): ";
        getline(cin,schoice);
    }
    int choice=stoi(schoice);
    switch (choice) {
        case 1:{//list all student info
            ofstream stuInfo ("Students.html",ios::out | ios::trunc);
            if (stuInfo.is_open())
            {
                stuInfo<<"<html><head><head><title>All Students List</title></head><body bgColor=#ffffcc><h1><font color=#6600ff>HKUST Course Registration System</font></h1><h2>All Students List</h2><p><table cellSpacing=1 cellPadding=1 border=1>";
                stuInfo<<"<tr><td>Student ID</td><td>Student Name</td><td>Year</td><td>Gender</td></tr>";
                vector<Student>stuList=studentTable.traverseAllInHashTable();
                for(int i=0;i<stuList.size();i++){
                    if(stuList.at(i).getStudentID()!=""){
                        stuInfo<<"<tr><td>"<<stuList.at(i).getStudentID()<<"</td><td>"<<stuList.at(i).getStudentName()<<"</td><td>"<<stuList.at(i).getYear()<<"</td><td>"<<stuList.at(i).getGender()<<"</td></tr>";
                    }
                }
                
                stuInfo<<"</table></p></body></html>";
                stuInfo.close();
                cout<<"Output Successful"<<endl;
            }
            else cout << "Unable to open file"<<endl;
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 2:{//list all course info
            ofstream cInfo ("Courses.html",ios::out | ios::trunc);
            if (cInfo.is_open())
            {
                cInfo<<"<html><head><head><title>All Course List</title></head><body bgColor=#ffffcc><h1><font color=#6600ff>HKUST Course Registration System</font></h1><h2>All Course List</h2><p><table cellSpacing=1 cellPadding=1 border=1>";
                cInfo<<"<tr><td>Course Code</td><td>Course Name</td><td>Credit</td></tr>";
                vector<Course> cList=courseTable.traverseAllInHashTable();
                for(int i=0;i<cList.size();i++){
                    if(cList.at(i).getCourseCode()!=""){
                        cInfo<<"<tr><td>"<<cList.at(i).getCourseCode()<<"</td><td>"<<cList.at(i).getCourseName()<<"</td><td>"<<cList.at(i).getCredit()<<"</td></tr>";
                    }
                }
                
                cInfo<<"</table></p></body></html>";
                cInfo.close();
                cout<<"Output Successful"<<endl;
            }
            else cout << "Unable to open file"<<endl;
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 3:{//list all courses of a student
            string StuID;
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
            vector<CourseRecord> crList=pstudentTable.getTable().at(indexstu).traverseAllCourseOfStudent(stu);
            
            ofstream scInfo (stu.getStudentID()+".html",ios::out | ios::trunc);
            if (scInfo.is_open())
            {
                scInfo<<"<html><head><head><title>Course Records for Student "<<studentTable.getItem(stu).getStudentID()<<"</title></head><body bgColor=#ffffcc><h1><font color=#6600ff>HKUST Course Registration System</font></h1><h2>Course Records for Student: "<<studentTable.getItem(stu).getStudentName()<<" ("<<studentTable.getItem(stu).getStudentID()<<")</h2><p><table cellSpacing=1 cellPadding=1 border=1>";
                if(crList.size()==0)
                    scInfo<<"No course taken";
                else{
                    scInfo<<"<tr><td>Course Code</td><td>Course Name</td><td>Credit</td><td>Exam Mark</td></tr>";
                
                    for(int i=0;i<crList.size();i++){
                        if(crList.at(i).getCourseCode()!=""){
                            Course c;
                            string CCode=crList.at(i).getCourseCode();
                            c.setCourseCode(CCode);
                            //re check existence
                            int indexc=courseTable.hashedIndex(c);
                            if(!courseTable.getTable().at(indexc).checkInList(c)){
                                continue;
                            }
                            scInfo<<"<tr><td>"<<crList.at(i).getCourseCode()<<"</td><td>"<<courseTable.getItem(c).getCourseName()<<"</td><td>"<<courseTable.getItem(c).getCredit()<<"</td><td>";
                            if(crList.at(i).getExamMark()==-1)
                                scInfo<<"N/A";
                            else
                                scInfo<<crList.at(i).getExamMark();
                            scInfo<<"</td></tr>";
                        }
                    }
                }
                scInfo<<"</table></p></body></html>";
                scInfo.close();
                cout<<"Output Successful"<<endl;
            }
            else cout << "Unable to open file"<<endl;
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 4:{//list all students of a course
            string CCode;
            cout<<"Enter the Course Code: ";
            getline(cin,CCode);
            Course c;
            c.setCourseCode(CCode);
            int indexc=courseTable.hashedIndex(c);
            if(!courseTable.getTable().at(indexc).checkInList(c)){
                c.print_not_exist();
                return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
                break;
            }
            vector<CourseRecord> crList=pcourseTable.getTable().at(indexc).traverseAllStudentOfCourse(c);
            
            ofstream scInfo (c.getCourseCode()+".html",ios::out | ios::trunc);
            if (scInfo.is_open())
            {
                scInfo<<"<html><head><head><title>Student Records for Course "<<courseTable.getItem(c).getCourseCode()<<"</title></head><body bgColor=#ffffcc><h1><font color=#6600ff>HKUST Course Registration System</font></h1><h2>Student Records for Course: "<<courseTable.getItem(c).getCourseName()<<" ("<<courseTable.getItem(c).getCourseCode()<<")</h2><p><table cellSpacing=1 cellPadding=1 border=1>";
                cout<<"size:"<<crList.size()<<endl;
                if(crList.size()==0)
                    scInfo<<"No student registered";
                else{
                    scInfo<<"<tr><td>Student ID</td><td>Student Name</td><td>Year</td><td>Gender</td><td>Exam Mark</td></tr>";
                    
                    for(int i=0;i<crList.size();i++){
                        if(crList.at(i).getStudentID()!=""){
                            Student stu;
                            string StuID=crList.at(i).getStudentID();
                            stu.setStudentID(StuID);
                            //re check existence
                            int indexstu=studentTable.hashedIndex(stu);
                            if(!studentTable.getTable().at(indexstu).checkInList(stu)){
                                continue;
                            }
                            scInfo<<"<tr><td>"<<crList.at(i).getStudentID()<<"</td><td>"<<studentTable.getItem(stu).getStudentName()<<"</td><td>"<<studentTable.getItem(stu).getYear()<<"</td><td>"<<studentTable.getItem(stu).getGender()<<"</td><td>";
                            if(crList.at(i).getExamMark()==-1)
                                scInfo<<"N/A";
                            else
                                scInfo<<crList.at(i).getExamMark();
                            scInfo<<"</td></tr>";
                        }
                    }
                }
                scInfo<<"</table></p></body></html>";
                scInfo.close();
                cout<<"Output Successful"<<endl;
            }
            else cout << "Unable to open file"<<endl;
            
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        case 5:{
            return_main_menu(studentTable,courseTable,courseSelection,pstudentTable,pcourseTable);
            break;
        }
        default:
            break;

    }
}



