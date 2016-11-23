#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "objects.h"
using namespace std;

template <class T>
class DoublySortedLinkedList{
public:
    DoublySortedLinkedList(){}
    ~DoublySortedLinkedList(){}
    //sort the list
    void sortList();
    //operation with an Item
    bool checkInList(T item);
    void eraseItem(T item);
    T& queryItem(T item);
    void queryAndPrintItem(T item);
    void insertItem(T item);
    void delete_all_include(T item);
    void delete_all_courses(Course cour);
    void delete_all_students(Student stu);
    void setExamMarkFor(T item,string mark);
    vector<T> traverseAll();
    /*TODO:
     void traverseAll()
        traverse all item in the list and print using item(i).print_Query();
     */
private:
    list<T> doublySortedLinkedList;
    
};

template <class T>
void DoublySortedLinkedList<T>::sortList(){
    /*sort the list using default sort function
     compare function is given by the overloaded < of different datatype*/
    doublySortedLinkedList.sort();
    //cout<<"sorted"<<endl;
}

template <class T>
//true if in list
bool DoublySortedLinkedList<T>::checkInList(T item){
    /*traverse the list and check if T already exist,
     compare using ==, == is overloaded for different data type repectively*/
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(*i==item){
            return true;
        }
    }
    return false;
}

template <class T>
void DoublySortedLinkedList<T>::eraseItem(T item){
    /*traverse the list and find item == T,
     if found, erase it,
     else T.print_not_exist*/
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(*i==item){
            i->print_delete_success();
            doublySortedLinkedList.erase(i);
            return;
        }
    }
   item.print_not_exist();
    
}

template <class T>
T& DoublySortedLinkedList<T>::queryItem(T item){//CourseSelection need to be modify since there might be same StuID
    /*traverse the list and find item ==T
     if found, return it,
     else T.print_not_exist,return null*/
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(*i==item){
            
            return *i;
        }
    }
    item.print_not_exist();
    T notPrint;
    notPrint.setcanPrintToFalse();
    return notPrint;
}

template <class T>
void DoublySortedLinkedList<T>::queryAndPrintItem(T item){//CourseSelection need to be modify since there might be same StuID
    /*traverse the list and find item ==T
     if found, print it,
     else T.print_not_exist,return null*/
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(*i==item){
            i->print_Query();
            return;
        }
    }
    item.print_not_exist();
}

template <class T>
void DoublySortedLinkedList<T>::insertItem(T item){
    /*check if item already exist using checkInList
     push_back the item
     sort the list using sortList()*/
    if(checkInList(item)){
        item.print_exist();
    }
    else{
        doublySortedLinkedList.push_back(item);
        sortList();
        item.print_insert_success();
    }
}

/*these functions are only for CourseRecord since only that datatype has ability to check inculde(by StuID or CCode)*/
//NO USE
/*
template <class T>
void DoublySortedLinkedList<T>::delete_all_include(T item){
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(i->include(item)){
            //no need to print success delete from the courseSelection table according to the sample
            eraseItem(*i);
        }
    }
}*/

template <class T>
void DoublySortedLinkedList<T>::delete_all_courses(Course cour){
    /*traverse the list and
     if(*i.include(item))
     delete *i
     */
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(i->include(cour)){
            //no need to print success delete from the courseSelection table according to the sample
            i->setcanPrintToFalse();
            eraseItem(*i);
        }
    }
}

template <class T>
void DoublySortedLinkedList<T>::delete_all_students(Student stu){
    /*traverse the list and
     if(*i.include(item))
     delete *i
     */
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        if(i->include(stu)){
            //no need to print success delete from the courseSelection table according to the sample
            i->setcanPrintToFalse();
            eraseItem(*i);
        }
    }
}


template <class T>
void DoublySortedLinkedList<T>::setExamMarkFor(T item,string mark){
    queryItem(item).setExamMark(mark);
}

template <class T>
vector<T> DoublySortedLinkedList<T>::traverseAll(){
    vector<T> result;
    result.resize(doublySortedLinkedList.size());
    typename list<T>::iterator i;
    for(i=doublySortedLinkedList.begin();i!=doublySortedLinkedList.end();++i){
        result.push_back(*i);
    }
    sort(result.begin(),result.end());
    return result;
}




//template-specialization for pointer
template <class T>
class DoublySortedLinkedList<T*>{
public:
    DoublySortedLinkedList(){}
    ~DoublySortedLinkedList(){}
    //sort the list
    void sortList(){
        /*sort the list using default sort function
         compare function is given by the overloaded < of different datatype*/
        pdoublySortedLinkedList.sort();
        //cout<<"sorted"<<endl;
    }
    //operation with an Item
    bool checkInList(T* item){
        /*traverse the list and check if T already exist,
         compare using ==, == is overloaded for different data type repectively*/
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if(*i==item){
                return true;
            }
        }
        return false;
    }

    void eraseItem(T* item){
        /*traverse the list and find item == T,
         if found, erase it,
         else T.print_not_exist*/
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if(*i==item){
                pdoublySortedLinkedList.erase(i);
                return;
            }
        }
    }
    
    T& queryItem(T* item){
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if(*i==item){
                return **i;
            }
        }
        item->print_not_exist();
        T notPrint;
        notPrint.setcanPrintToFalse();
        return notPrint;
    }

    void queryAndPrintItem(T* item){//CourseSelection need to be modify since there might be same StuID
        /*traverse the list and find item ==T
         if found, print it,
         else T.print_not_exist,return null*/
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if(*i==item){
                *i->print_Query();
                return;
            }
        }
        item->print_not_exist();
    }

    void insertItem(T* item){
        /*check if item already exist using checkInList
         push_back the item
         sort the list using sortList()*/
        if(checkInList(item)){
            //item.print_exist();
        }
        else{
            pdoublySortedLinkedList.push_back(item);
            sortList();
            //item.print_insert_success();
        }
    }

    void delete_all_courses(Course cour){
        /*traverse the list and
         if(*i.include(item))
         delete *i
         */
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if((*i)->include(cour)){
                //no need to print success delete from the courseSelection table according to the sample
                eraseItem(*i);
            }
        }
    }

    void delete_all_students(Student stu){
        /*traverse the list and
         if(*i.include(item))
         delete *i
         */
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            if((*i)->include(stu)){
                //no need to print success delete from the courseSelection table according to the sample
                eraseItem(*i);
            }
        }
    }
    vector<T> traverseAll(){
        vector<T> result;
        result.resize(pdoublySortedLinkedList.size());
        typename list<T*>::iterator i;
        for(i=pdoublySortedLinkedList.begin();i!=pdoublySortedLinkedList.end();++i){
            result.push_back(**i);
        }
        sort(result.begin(),result.end());
        return result;
    }
    /*TODO:
     void traverseAll()
     traverse all item in the list and print using item(i).print_Query();
     */
private:
    list<T*> pdoublySortedLinkedList;
    
};

#endif
