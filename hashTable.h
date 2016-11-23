#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include <vector>
#include "doublySortedLinkedList.h"//.h
#include <string>
#include "math.h"
using namespace std;

//to get the value of a char according to the rule in the project description
int valueOf(char c){
    int val;
    //c is digit
    if(c>47&&c<58){
        val=c-48;
        return val;
    }
    //c is upper letter
    else if(c>64&&c<91){
        val=c-53;//A=11,B=12.....
        return val;
    }
    else
        return 0;
}

template <class T>
class HashTable{
private:
    vector<DoublySortedLinkedList<T> > table;
    int numBuckets;
    int base;
public:
    HashTable(int n,int b):numBuckets(n),base(b){
        table.resize(n);
    }
    ~HashTable(){}
    //return the index after hashing
    int hashedIndex(T Item){//HashKey is a string, and initialize when Item constructed
        string key;
        key=Item.getHashKey();
        int index;
        int sum=0;
        int len=key.length();
        /*hash function
         *Sum_i{key[i]*(base^i)}%numBuckets
         */
        
        //big number mod???????????????????????????
        
        
        
        int basePow=1;
        for(int i=0;i<len;i++){
            sum+=(valueOf(key[i])*basePow)%numBuckets;//avoid too large then overflow
            basePow*=base;
        }
        //cout<<"sum: "<<sum<<endl;
        index=sum%numBuckets;
        //cout<<"index: "<<index<<endl;
        return index;
    }
    
    void addItem(T Item){
        /*get hashed index = index
         checkInList in table.at(index), which is a DoublySortedLinkedList
         if exist, Item.print_exist
         if not exist yet, table.at(index).insertItem(Item)
         */
        int index=hashedIndex(Item);
        if(table.at(index).checkInList(Item)){
            Item.print_exist();
        }
        else{
            table.at(index).insertItem(Item);
        }
    }
    void removeItem(T Item){
        /*
         get hashed index = index
         this is include in erasefunction（checkInList in table.at(index), which is a DoublySortedLinkedList
         table.at(index).eraseItem(Item)
         
         and also when remove a course or Student, remove the CourseRecord in the CourseSelection table if exist
         */
        
        int index=hashedIndex(Item);
        table.at(index).eraseItem(Item);
        
        
    }
    void queryItem(T Item){
        /*
         get hashed index = index
          table.at(index).queryItem(Item).print_Query();
         */
        int index=hashedIndex(Item);
        table.at(index).queryItem(Item).print_Query();
    }
    
    bool checkInTable(T Item){
        /*
         get hashed index = index
         table.at(index).checkInList(Item);
         */
        int index=hashedIndex(Item);
        return table.at(index).checkInList(Item);
    }
    
    /*TODO:
     output all function for html and file IO
        traverse all buckets, if table.at(i).size()==0, skip
        or traverse the list using table.at(i).traverseAll()
     */
    vector<T> traverseAllInHashTable(){
        vector<T> result;
        result.resize(0);
        for(int i=0;i<numBuckets;i++){
            vector<T> tmp=table.at(i).traverseAll();
            result.reserve(result.size()+tmp.size());
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        sort(result.begin(),result.end());
        return result;
    }
    
};

#endif