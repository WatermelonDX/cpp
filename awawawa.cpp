#include <iostream>
#include <string>
#include <list>
using namespace std;

class hashtable{
    private: 
        static const int groups = 25;
        list<pair<int, string>> table[groups];
    public:
        bool emptiness() const;
        int hasher(int key);
        void newitem(int key, string value);
        void killitime(int key);
        void searchitem(int key);
        void printtable();
};

void hashtable::searchitem(int key){
    int hash = hasher(key);
    auto &cell = table[hash];
    auto iterate = begin(cell);
    bool exists = false;
    for (; iterate != end(cell); iterate++){
        if(iterate->first == key){
            exists = true;
            cout << "Key: " << iterate->first << " Value: " << iterate->second << endl;
            break;
        }
    }
    if (!exists){
        cout << "there's nun here bru" << endl;
    }
}


bool hashtable::emptiness() const{
    for(int i = 0; i < groups; i++){
        if (table[i].size() != 0){
            return false;
        }
    }
    return true;
}
int hashtable::hasher(int key){
    return key % groups;
}
void hashtable::newitem(int key, string value){
    int hash = hasher(key);
    auto &cell = table[hash];
    auto iterate = begin(cell);
    bool exists = false;
    for (; iterate != end(cell); iterate++){
        if(iterate->first == key){
            exists = true;
            iterate->second = value;
            cout << "LMAO KILL YOURSELF, idk bru im replacing the key, fuck you" << endl;
            break;
        }
    }
    if (!exists){
        cell.emplace_back(key, value);
    }
}
void hashtable::killitime(int key){
    int hash = hasher(key);
    auto &cell = table[hash];
    auto iterate = begin(cell);
    bool exists = false;
    for (; iterate != end(cell); iterate++){
        if(iterate->first == key){
            exists = true;
            iterate = cell.erase(iterate);
            cout << "Element assasinated" << endl;
            break;
        }
    }
    if (!exists){
        cout << "there's nun here bru" << endl;
    }
}
void hashtable::printtable(){
    for(int i = 0; i < groups; i++){
        if (table[i].size()==0) continue;
        auto iterate = table[i].begin();
        for(; iterate != table[i].end(); iterate++){
            cout << "Key: " << iterate->first << " Value: " << iterate->second << endl;
        }
    }
}



int main(){
    hashtable HT; 
    if (HT.emptiness()){
        cout << "theres no table bru" << endl;
    }else{
        cout << "hi" << endl;
    }

    HT.newitem(666, "Jimmy");
    HT.newitem(341, "Timmy");
    HT.newitem(636, "Mimi");
    HT.newitem(634, "Larry");
    HT.newitem(623, "Marry");
    HT.newitem(241, "Garry");
    HT.killitime(634);

    HT.printtable();
    HT.searchitem(623);
}
