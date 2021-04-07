#ifndef LINKED_LISTV2_H
#define LINKED_LISTV2_H

#include <iostream>
#include <string.h>
#include <stdexcept>

namespace llst{

    void debug(string msg);


    /*
        A Node of an LinkedList. 

        Nodes are never returned by functions
    */
    struct Node {
            
        const char* label = NULL;
        Node* next = NULL;
    };


    /** Holds only one pointer to the first node
    */
    struct LinkedList {

        Node* head = NULL;
        Node* tail = NULL;
        int size = 0;
    };


    // LinkedList - eturns a NEW empty LinkedList
    LinkedList* init();


    /** Return true if the list is empty, false otherwise            
    */
    bool is_empty(LinkedList* ll);


    /** Adds item at the beginning of the list   
    */                
    void add(LinkedList* ll, const char * label);



    /** For potentially complex data structures like this one, having a to_string function 
     *  is essential to  quickly inspect the label by printing it. 
     * 
     *  Note string to return has c++ type  string 
     * 
     *  - To initialize a c++ string, you can just set it to some like
     * 
     *      string s = "some characters"
     * 
     *  - To augment the string, you can write:
     * 
     *      s += "some characters"
    */
    string to_string(LinkedList* ll);



    /**  Returns the size of the list 
     */
    int size(LinkedList* ll);



    /**
     *  Returns true if label is present in list, false otherwise              
    */
    bool search(LinkedList* ll, const char * label);


    /*
        Removes the last item of the list, and returns its label

        - If the list is empty, throw std::invalid_argument.      
    */        
    const char* pop(LinkedList* ll);



    /*
        Deletes all nodes in the chain    
        Careful about deletion order!
    */
    void destroy(LinkedList* ll);



    /** Appends label to the end of the list.
    */                
    void append(LinkedList* ll, const char* label);



    /**
        Remove first occurrence of item from the list

        - If label is not found, throw std::invalid_argument                    
    */
    void remove(LinkedList* ll, const char * label);



    /* Insert an item at a given position. 

        - if index is out of bounds, throw std::invalid_argument   
    */
    void insert(LinkedList* ll, int i, const char * e);

}

#endif