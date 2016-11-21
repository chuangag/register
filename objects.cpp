#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
const int LENOFSTUID=8;

/*TODO:
 overload ==, <
 
 void print_not_exist
 void print_insert_success
 void print_delete_success
 void print_modify_success
 void print_Query(datatype)
 
 
 remember delete function should both delete the type table and the course selection linked list
 
 remember the existence is checked when getting from sorted list so not mind it
 
 *****set functions should include checking valid input
 */

/*check if a string is number*/
bool is_number(const string& s)//????????is a float number?????????? minor bug tentative
{
    return !s.empty() && find_if(s.begin(),s.end(), [](char c) { return !isdigit(c); }) == s.end();
}


//class Student
class Student
{
public:
    Student(string StuID){
        StudentID="";
    }
    ~Student();
    //get functions
    string getStudentID(){return StudentID;}
    string getStudentName(){return StudentName;}
    int getYear(){return Year;}
    char getGender(){return Gender;}
    string getHashKey(){return HashKey;}
    //set functions(include checking)
    void setStudentID(string StuID){
        while(StuID.length()!=8||!is_number(StuID)){
            cout<<"Invalid input, re-enter again [student ID]: ";
            cin>>StuID;
        }
        StudentID=StuID;
        HashKey=StudentID;
    }
    
    void setStudentNae(string StuName){
        while(StuName.length()>32||StuName.length()<1){
            cout<<"Invalid input, re-enter again [student name]: ";
            cin>>StuName;
        }
        StudentName=StuName;
    }
    
    void setYear(string y){
        while(!is_number(y)||(stoi(y)>3||stoi(y)<1)){
            cout<<"Invalid input, re-enter again [student year]: ";
            cin>>y;
        }
        Year=stoi(y);
    }
    
    void setGender(string g){
        while(g!="M"&&g!="F"){
            cout<<"Invalid input, re-enter again [M,F]: ";
            cin>>g;
        }
        Gender=g[0];
    }
    //overload operators
    bool operator==(Student& stu){//compare by studentID
        if(this->getStudentID()==stu.getStudentID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator<(Student& stu){//compare by studentID
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getStudentID()[i]<stu.getStudentID()[i]){
                return true;
            }
        }
        return false;
    }
    //print functions
    void print_not_exist(){
        cout<<"Student not exist"<<endl;
    }
    
    void print_exist(){
        cout<<"Student already exist"<<endl;
    }
    
    void print_insert_success(){
        cout<<"Creation of student record successful"<<endl;
    }
    
    void print_delete_success(){
        cout<<"Deletion of student record successful"<<endl;
    }
    
    void print_modify_success(){
        cout<<"Modification of student record successful"<<endl;
    }
    
    void print_Query(){
        cout<<"ID:     "<<StudentID<<endl;
        cout<<"Name:   "<<StudentName<<endl;
        cout<<"Year:   "<<Year<<endl;
        if(Gender=='M'){
            cout<<"Gender: "<<"Male"<<endl;
        }
        else if(Gender=='F'){
            cout<<"Gender: "<<"Female"<<endl;
        }
    }
private:
    string StudentID;//length=8
    string StudentName;//1<=length<=32
    int Year;//{1,2,3}
    char Gender;//M or F
    string HashKey;//StudentID
};






//class Course
class Course
{
public:
    Course(string CCode){
        CourseCode="";
    }
    ~Course();
    //get functions
    string getCourseCode(){return CourseCode;}
    string getCourseName(){return CourseName;}
    int getCredit(){return Credit;}
    string getHashKey(){return HashKey;}
    //set functions
    void setCourseCode(string CCode){
        while((CCode.length()!=8&&CCode.length()!=7)||(!isupper(CCode[0])||!isupper(CCode[1])||!isupper(CCode[2])||!isupper(CCode[3]))){
            if(CCode.length()==8&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_number(CCode.substr(4,7))){
                break;
            }
            if(CCode.length()==7&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_number(CCode.substr(4,6))){
                break;
            }

            cout<<"Invalid input, re-enter again [course code]: ";
            cin>>CCode;
        }
        CourseCode=CCode;
        HashKey=CourseCode;
    }
    void setCourseName(string CName){
        while(CName.length()>50||CName.length()<1){
            cout<<"Invalid input, re-enter again [course name]: ";
            cin>>CName;
        }
        CourseName=CName;
    }
    void setCredit(string credit){
        while(credit!="0"&&credit!="1"&&credit!="2"&&credit!="3"&&credit!="4"&&credit!="5"){
            cout<<"Invalid input, re-enter again [course credit]: ";
            cin>>credit;
        }
        Credit=stoi(credit);
    }
    
    //print functions
    void print_not_exist(){
        cout<<"Course not exist"<<endl;
    }
    
    void print_exist(){
        cout<<"Course already exist"<<endl;
    }
    
    void print_insert_success(){
        cout<<"Creation of course record successful"<<endl;
    }
    
    void print_delete_success(){
        cout<<"Deletion of course record successful"<<endl;
    }
    
    void print_modify_success(){
        cout<<"Modification of course record successful"<<endl;
    }
    
    void print_Query(){
        cout<<"Code:   "<<CourseCode<<endl;
        cout<<"Name:   "<<CourseName<<endl;
        cout<<"Credit: "<<Credit<<endl;
    }

private:
    string CourseCode;//len=7 or 8,first four are upper letters
    string CourseName;//1<=len<=50
    int Credit;//{0,1,2,3,4,5}
    string HashKey;//CourseCode
};

//class CourseRecord
class CourseRecord
{
public:
    CourseRecord(string StuID,string CCode){
        StudentID="";
        CourseCode="";
    }
    ~CourseRecord();
    //get functions
    string getStudentID(){return StudentID;}
    string getCourseCode(){return CourseCode;}
    int getExamMark(){return ExamMark;}
    //set functions
    void setStudentID(string StuID){
        while(StuID.length()!=8||!is_number(StuID)){
            cout<<"Invalid input, re-enter again [student ID]: ";
            cin>>StuID;
        }
        StudentID=StuID;
    }

    void setCourseCode(string CCode){
        while((CCode.length()!=8&&CCode.length()!=7)||(!isupper(CCode[0])||!isupper(CCode[1])||!isupper(CCode[2])||!isupper(CCode[3]))){
            if(CCode.length()==8&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_number(CCode.substr(4,7))){
                break;
            }
            if(CCode.length()==7&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_number(CCode.substr(4,6))){
                break;
            }
            
            cout<<"Invalid input, re-enter again [course code]: ";
            cin>>CCode;
        }
        CourseCode=CCode;
    }
    
    void setExamMark(string mark){
        while(!is_number(mark)||(stoi(mark)>100||stoi(mark)<0)){
            cout<<"Invalid input, re-enter again [student year]: ";
            cin>>mark;
        }
        ExamMark=stoi(mark);
    }
    //print functions
    void print_already_register(){
        cout<<"The student already registered the course"<<endl;
    }
    void print_add_success(){
        cout<<"Add course successful"<<endl;
    }
    void print_drop_success(){
        cout<<"Drop course successful"<<endl;
    }
    void print_modify_success(){
        cout<<"Modifucation of exam mark successful"<<endl;
    }
    
    
private:
    string StudentID;//length=8
    string CourseCode;//len=7 or 8,first four are upper letters
    int ExamMark;//0<=mark<=100 or unassigned
};

#endif
