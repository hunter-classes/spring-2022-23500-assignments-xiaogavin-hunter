#pragma once

class ONode { 
    private: 
        int data;
        ONode *next; 

    public: 
        ONode();
        ONode(int data); 
        ONode(int data, ONode *next); 

        void setData(int data); 
        void setNext(ONode *next); 

        int getData();
        ONode *getNext();
    
};