#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H
#include <iostream>
#include <list>
#include <string>
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
    T queryItem(T item);
    void insertItem(T item);
    
private:
    list<T> doublySortedLinkedList;
    
};

template <class T>
void DoublySortedLinkedList<T>::sortList(){
    /*sort the list using default sort function
     compare function is given by the overloaded < of different datatype*/
    doublySortedLinkedList.sort();
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
            *i.print_delete_success();
            doublySortedLinkedList.erase(i);
            return;
        }
    }
   item.print_not_exist();
    
}

template <class T>
T DoublySortedLinkedList<T>::queryItem(T item){
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
    return 0;
}

template <class T>
void DoublySortedLinkedList<T>::insertItem(T item){
    /*push_back the item
     sort the list using sortList()*/
    doublySortedLinkedList.push_back(item);
    doublySortedLinkedList.sortList();
    item.print_insert_success();
}


#endif
