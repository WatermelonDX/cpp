#define groups 10000
#include <vector>
#include <iostream>

class node{
    public:
    int key, val;
    node *next;
    node(int key = -1, int val = -1, node *next = nullptr){
        this->val = val;
        this->next = next;
        this->key = key;
    }

};

class MyHashMap {
protected: 
    std::vector<node*> map;
public:
    MyHashMap(){
        map.resize(groups);
        for (int i = 0; i < groups; i++){
            map[i] = new node();
        }
    }

    int hasher(int key){
        key = key % groups;
        return key;
    }
    
    void put(int key, int val) {
        int hash = hasher(key);
        node *curr = map[hash];
        
        while(curr->next){
            if(curr->next->key == key){
                curr->next->val = val;
                return;
            }
            curr = curr->next;
        }
        curr->next = new node(key, val);
    }
    
    int get(int key) {
        int hash = hasher(key);
        node *curr = map[hash];
        
        while(curr->next){
            if(curr->next->key == key){
                return curr->next->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = hasher(key);
        node *curr = map[hash];
        
        while(curr->next){
            if(curr->next->key == key){
                node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};



