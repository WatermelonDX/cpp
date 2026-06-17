#include <iostream>
#include <string>
#include <map>
#include <vector>
#define wav 100

using namespace std;
class node{
    public:
        node(int gen = -1, string name = " ", string key = " ", node *next = nullptr){
            this->gen = gen;
            this->name = name;
            this->key = key;
            this->next = next;
        }
        string name;
        int gen;
        string key;
        node *next;
};

class dex{
    protected:
        vector<node*>mp;
        int hasher(string key){
            int numeric, sum = 0;
            for(char c: key){
                numeric = int(c);
                sum = sum + numeric%wav;
            }
            return numeric % wav;
        }
    public:
        dex(){
            mp.resize(wav);
            for(int i = 0; i < wav; i++){
                mp[i] = new node();
            }
        }
        void printhash(string key){
            cout << "Hash: " << hasher(key) << endl;
        }
        void add(string key, string name, int gen){
            int hash = hasher(key);
            node *curr = mp[hash];

            if(curr->key == " "){
                curr->key = key;
                curr->name = name;
                curr->gen = gen;
                cout << "New mon added" << endl;
            }else{
                if(curr->key == key){
                        curr->gen = gen;
                        curr->name = name;
                        cout << "Same existing key found - replacing data" << endl;
                        return;
                    }else{
                        while(curr->next != nullptr){
                            curr = curr->next;
                            if(curr->key == key){
                                curr->gen = gen;
                                curr->name = name;
                                cout << "Same existing key found - replacing data" << endl;
                                return;
                            }
                        }
                    }
                    curr->next = new node();
                    curr = curr->next;
                    curr->gen = gen;
                    curr->key = key;
                    curr->name = name;
                    cout << "New mon added (Other))" << endl;
                }
        }
        void remove(string key){
            int hash = hasher(key);
            node *curr = mp[hash];
            if(curr->key == key){
                delete curr;
                cout << "Mon deleted" << endl;
                return;
            }
            while(curr->next != nullptr){
                    curr = curr->next;
                if(curr->key == key){
                    delete curr;
                    cout << "Mon deleted" << endl;
                    return;
                }
            }
            cout << "No one found under that name" << endl;
        }
        void printmon(string key){
            int hash = hasher(key);
            node *curr = mp[hash];
            if(curr->key == key){
                cout << "Nickname: " << curr->key << " | Species: " << curr->name << " | Generation: " << curr->gen << endl;
                return;
            }
            while(curr->next != nullptr){
                    curr = curr->next;
                if(curr->key == key){
                    cout << "Nickname: " << curr->key << " | Species: " << curr->name << " | Generation: " << curr->gen << endl;
                    return;
                }
            }
            cout << "No one found under that name" << endl;
        }




        
};


int main(){
    dex mydex;
    string name, key;
    int gen, sw;
    mydex.add("Mitre", "Lucario", 4);
    mydex.add("Ziro", "Zoroark", 5);
    mydex.add("Swirlu", "Lycanroc (Midnight)", 7);
    mydex.add("Chip", "Pikachu", 1);
    mydex.add("Carmie", "Lucario", 4);
    mydex.add("Malapie", ":v", 4);

    while(true){
        cout << "Choose an option: " << endl << "1. Add | 2.Delete | 3.Search | 4. Exit" << endl;
        cin >> sw;
        switch(sw){
            case 1:
                cout << "Input name (Unique)" << endl;
                cin >> key;
                cout << "Input species" << endl;
                cin >> name;
                cout << "Input generation" << endl;
                cin >> gen;
                mydex.add(key,name,gen);
                break;
            case 2:
                cout << "Input name to delete" << endl;
                cin >> key;
                mydex.remove(key);
                break;
            case 3:
                cout << "Input name to search" << endl;
                cin >> name;
                mydex.printmon(name);
                break;
            case 4:
                exit(-1);
            default: 
                cout << "Invalid option" << endl;

        }
    }
}