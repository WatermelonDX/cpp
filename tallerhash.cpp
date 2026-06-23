#include <hashtable.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include <fstream>
#define method 3
#define max 45402

using namespace std;
typedef uint8_t tipo;

class item{
    public:
        string key;
        int val;
        item *next;
        item(string key, int val){
            this->key = key;
            this->val = val;
            this->next = nullptr;
        }
};

class table{
    protected:
        vector<item*>tb;
    public:
        table(){
            tb.resize(max);
            for(int i = 0; i < max; i++){
                tb[i] = nullptr;
            }
        };
        tipo hashify(string key, int sw){
            tipo hash;
            int factor = 31;
            string h1;
            switch(sw){
                case 1:
                    hash = 0;
                    for(char c: key){
                        hash = hash + (tipo(c));
                    }
                    return hash;
                break;

                case 2:
                    hash = 1;
                    for(char c: key){
                        hash = hash * (tipo(c));
                    }
                    return hash;
                break;
                
                case 3:
                    hash = 0;
                    for (char c: key){
                        hash ^= tipo(c);
                    }
                    return hash;
                break;
                
                //Test
                case 4:
                    hash = 0;
                    for(char c: key){
                        hash = hash + ((tipo(c)*factor)%max);
                        factor = ((factor % __INT8_MAX__)* (31 % __INT8_MAX__)) % __INT8_MAX__;
                    }
                    hash = hash % max;
                    return hash;
                break;

                default:
                exit(-1);
            }
        }

        tipo add(string key,int val, int sw){
            item *novo = new item(key, val);
            tipo hash = hashify(key, sw);
            hash = hash % max;
            if(tb[hash] != nullptr){
                item *curr = tb[hash];
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = novo;
                return 1;
            }else{
                tb[hash] = novo;
                return 0;
            }
        }

        int show(){
            item *curr;
            int total = 0;
            for(int i = 0; i < tb.size(); i++){
                curr = tb[i];
                if(curr != nullptr){
                    cout << "Key: " <<  curr->key << "Value: " << curr->val << endl;
                    total++;
                    while(curr->next != nullptr){
                        curr = curr->next;
                        cout << "Key: " <<  curr->key << " | Value: " << curr->val << endl;
                        total++;
                    }
                }
            }
            return total;
        }
        
};


int main(){
    fstream file("thewords.txt");
    string val;
    table mytable;
    int i = 0;
    int coll = 0;
    
    if(!file.is_open()){
        cout << "Couldn't open file, retry" << endl;
        exit(-1);
    }

    while(file >> val){
        coll = coll + mytable.add(val, i, method);
        i++;
    }

    int total = mytable.show();
    cout << "Coliisions: " << coll  << "| Total entries: "<< total << endl; 
}



