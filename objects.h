#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
const int LENOFSTUID=8;

/*TODO:
 overload ==, < ok
 
 okv
 void print_not_exist
 void print_insert_success
 void print_delete_success
 void print_modify_success
 void print_Query(datatype)
 ok^
 
 remember delete function should both delete the type table and the course selection linked list ok
 
 remember the existence is checked when getting from sorted list so not mind it ok
 
 *****set functions should include checking valid input ok
 */

/*check if a string is int number*/
bool is_number(const string& s)
{   if(s.empty())
        return false;
    for(int i=0;i<s.length();i++){
        if(s[i]>57||s[i]<48){
            return false;
        }
    }
    return true;
}


//-------------------class Student

class Student
{
public:
    static Student notPrint;
    Student(string StuID=""){
        StudentID=StuID;
        canPrint=true;
        Year=0;
        notPrint.setcanPrintToFalse();
    }
    ~Student(){}
    //get functions
    string getStudentID() const{return StudentID;}
    string getStudentName() const{return StudentName;}
    int getYear() const{return Year;}
    char getGender()const{return Gender;}
    string getFullGender()const{
        if(Gender=='M'){
            return "Male";
        }
        else
            return "Female";
    }
    string getHashKey()const{return HashKey;}
    bool getCanPrint(){return canPrint;}
    //set functions(include checking)
    void setcanPrintToFalse(){
        canPrint=false;
    }
    void setStudentID(string &StuID){
        while(StuID.length()!=8||!is_number(StuID)){
            cout<<"Invalid input, re-enter again [student ID]: ";
            getline(cin,StuID);
        }
        StudentID=StuID;
        HashKey=StudentID;
    }
    
    void setStudentName(string &StuName){
        while(StuName.length()>32||StuName.length()<1){
            cout<<"Invalid input, re-enter again [student name]: ";
            getline(cin,StuName);
        }
        StudentName=StuName;
    }
    
    void setYear(string &y){
        while(!is_number(y)||(stoi(y)>3||stoi(y)<1)){
            cout<<"Invalid input, re-enter again [student year]: ";
            getline(cin,y);
        }
        Year=stoi(y);
    }
    
    void setGender(string &g){
        while(g!="M"&&g!="m"&&g!="F"&&g!="f"){
            cout<<"Invalid input, re-enter again [M,F]: ";
            getline(cin,g);
        }
        if(g=="f")
            Gender='F';
        if(g=="m")
            Gender='M';
        Gender=g[0];
    }
    //overload operators
    bool operator==(const Student& stu) const{//compare by studentID
        if(this->getStudentID()==stu.getStudentID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator<(const Student& stu) const{//compare by studentID
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getStudentID()[i]<stu.getStudentID()[i]){
                return true;
            }
            else if(this->getStudentID()[i]>stu.getStudentID()[i])
                return false;
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
        if(!canPrint||Year==0){return;}
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
    bool canPrint;
};

 Student Student::notPrint;




//class Course
class Course
{
public:
    static Course notPrint;
    Course(string CCode=""){
        CourseCode=CCode;
        canPrint=true;
        Credit=-1;
        notPrint.setcanPrintToFalse();
    }
    ~Course(){}
    //get functions
    string getCourseCode() const{return CourseCode;}
    string getCourseName() const{return CourseName;}
    int getCredit() const{return Credit;}
    string getHashKey() const{return HashKey;}
    bool getCanPrint(){return canPrint;}
    //set functions
    void setcanPrintToFalse(){
        canPrint=false;
    }
    void setCourseCode(string &CCode){
        while((CCode.length()!=8&&CCode.length()!=7)||(!isupper(CCode[0])||!isupper(CCode[1])||!isupper(CCode[2])||!isupper(CCode[3]))){
            if(CCode.length()==8&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])/*last 4 or 3 char dont matter*/){
                break;
            }
            if(CCode.length()==7&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])/*last 4 or 3 char dont matter*/){
                break;
            }

            cout<<"Invalid input, re-enter again [course code]: ";
            getline(cin,CCode);
        }
        CourseCode=CCode;
        HashKey=CourseCode;
    }
    void setCourseName(string &CName){
        while(CName.length()>50||CName.length()<1){
            cout<<"Invalid input, re-enter again [course name]: ";
            getline(cin,CName);
        }
        CourseName=CName;
    }
    void setCredit(string &credit){
        while(credit!="0"&&credit!="1"&&credit!="2"&&credit!="3"&&credit!="4"&&credit!="5"){
            cout<<"Invalid input, re-enter again [course credit]: ";
            getline(cin,credit);
        }
        Credit=stoi(credit);
    }
    //overload operators
    bool operator==(const Course& cour) const{//compare by CourseCode
        if(this->getCourseCode()==cour.getCourseCode()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator<(const Course& cour) const{//compare by CourseCode
        for(int i=0;i<8;i++){
            if(this->getCourseCode()[i]<cour.getCourseCode()[i]){
                return true;
            }
            else if(this->getCourseCode()[i]>cour.getCourseCode()[i])
                return false;
        }
        return false;
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
        if(!canPrint||Credit==-1){return;}
        cout<<"Code:   "<<CourseCode<<endl;
        cout<<"Name:   "<<CourseName<<endl;
        cout<<"Credit: "<<Credit<<endl;
    }

private:
    string CourseCode;//len=7 or 8,first four are upper letters
    string CourseName;//1<=len<=50
    int Credit;//{0,1,2,3,4,5}
    string HashKey;//CourseCode
    bool canPrint;
};

Course Course::notPrint;




#endif
