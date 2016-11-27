#ifndef _COURSERECORD_H
#define _COURSERECORD_H
#include "objects.h"
#include "hashTable.h"
class CourseRecord
{
public:
    static CourseRecord notPrint;
    CourseRecord(string StuID="",string CCode=""){
        StudentID=StuID;
        CourseCode=StuID;
        canPrint=true;
        ExamMark=-1;//N/A
        notPrint.setcanPrintToFalse();
    }
    ~CourseRecord(){}
    //get functions
    string getStudentID() const{return StudentID;}
    string getCourseCode() const{return CourseCode;}
    int getExamMark() const{return ExamMark;}
    bool getCanPrint(){return canPrint;}
    //set functions
    void setcanPrintToFalse(){
        canPrint=false;
    }

    void setStudentID(string StuID){//no checking exist in table version, only use when sure about no except(internal use)
        StudentID=StuID;
    }
    void setStudentID(string StuID, HashTable<Student> stuTable){

        //check valid first and check if the student exist in the student table

        while(StuID.length()!=8||!is_number(StuID)){
            cout<<"Invalid input, re-enter again [student ID]: ";
            cin>>StuID;
        }

        Student virtualStuForChecking;
        virtualStuForChecking.setStudentID(StuID);
        if(stuTable.checkInTable(virtualStuForChecking)){
            StudentID=StuID;
        }
        else{
            virtualStuForChecking.print_not_exist();
            return;
        }
    }


    void setCourseCode(string CCode){//no checking exist in table version, only use when sure about no except(internal use)
        CourseCode=CCode;
    }
    void setCourseCode(string CCode,HashTable<Course> courTable){
        //check valid first and check exist
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

        Course virtualCourseForChecking;
        virtualCourseForChecking.setCourseCode(CCode);
        if(courTable.checkInTable(virtualCourseForChecking)){
            CourseCode=CCode;
        }
        else{
            virtualCourseForChecking.print_not_exist();
            return;
        }
    }

    void setExamMark(string mark){
        while(!is_number(mark)||(stoi(mark)>100||stoi(mark)<0)){
            cout<<"Invalid input, re-enter again [exam mark]: ";
            cin>>mark;
        }
        print_modify_success();
        ExamMark=stoi(mark);
        //cout<<"input: "<<mark<<endl;
        //cout<<"modified to: "<<ExamMark<<endl;
    }
    void setExamMarkNotPrint(string mark){
        while(!is_number(mark)||(stoi(mark)>100||stoi(mark)<0)){
            cout<<"Invalid input, re-enter again [exam mark]: ";
            cin>>mark;
        }
       // print_modify_success();
        ExamMark=stoi(mark);
        //cout<<"input: "<<mark<<endl;
        //cout<<"modified to: "<<ExamMark<<endl;
    }
    //check include course or student
    bool include(Student stu){
        if(this->getStudentID()==stu.getStudentID()){
            return true;
        }
        else
            return false;
    }
    bool include(Course cour){
        if(this->getCourseCode()==cour.getCourseCode()){
            return true;
        }
        else
            return false;
    }
    //print functions
    void print_exist(){
        cout<<"The student already registered the course"<<endl;
    }
    void print_insert_success(){
        cout<<"Add course successful"<<endl;
    }
    void print_delete_success(){
        if(canPrint){
            cout<<"Drop course successful"<<endl;
        }
    }
    void print_not_exist(){
        cout<<"The registration record not exist"<<endl;
    }
    void print_modify_success(){
        cout<<"Modification of exam mark successful"<<endl;
    }
    void print_Query(){
        if(!canPrint||StudentID==""){return;}
        cout<<"Student ID:  "<<StudentID<<endl;
        cout<<"Course Code: "<<CourseCode<<endl;

        if(ExamMark!=-1)
            cout<<"Exam Mark:   "<<ExamMark<<endl;
        else if(ExamMark==-1)
            cout<<"Exam Mark:   "<<"N/A"<<endl;
    }

    //overload operators
    /*primary sorting key: StudentID
     secondary sorting key: CourseCode
     */

    bool operator==(const CourseRecord& crec) const{//compare by studentID
        if(this->getCourseCode()==crec.getCourseCode()&&this->getStudentID()==crec.getStudentID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator<(const CourseRecord& crec) const{//compare by studentID, if the same, compare by coursecode
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getStudentID()[i]<crec.getStudentID()[i]){
                return true;
            }
        }
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getCourseCode()[i]<crec.getCourseCode()[i]){
                return true;
            }
        }

        return false;
    }
    // overload = :equal this to a student or course by setting the coresponding key
    CourseRecord operator=(Student stu){
        setStudentID(stu.getStudentID());
        return *this;
    }
    CourseRecord operator=(Course cour){
        setCourseCode(cour.getCourseCode());
        return *this;
    }

private:
    string StudentID;//length=8
    string CourseCode;//len=7 or 8,first four are upper letters
    int ExamMark;//0<=mark<=100 or unassigned
    bool canPrint;
};
CourseRecord CourseRecord::notPrint;

#endif
