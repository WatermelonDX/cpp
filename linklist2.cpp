#include <iostream>
#include <string>

using namespace std;

class node{
    public:
        int id;
        string species;
        node *next;
        node *prev;
        node(int id, string species){
            this->id = id;
            this->species = species; 
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class list{
    private:
        node *head = nullptr;
        node *tail = nullptr;
        void tailadd(int id, string species){
            node *curr = tail;
            curr->next = new node(id, species);
            curr = curr->next;
            
            curr->prev = tail;
            tail = curr;
            cout << "Successfully added item" << endl;
            cout << "------------------------------------------------------" << endl;
        }
        void headadd(int id, string species){
            node *curr = head;
            curr->prev = new node(id, species);
            curr = curr->prev;

            curr->next = head;
            head = curr;
            cout << "Successfully added item" << endl;
            cout << "------------------------------------------------------" << endl;
        }
        void middleadd(int id, string species, node *curr){
            node *nx = curr->next;
            node *pv = curr;
            
            curr->next = new node(id, species);
            curr = curr->next;

            curr->next = nx;
            curr->prev = pv;
            nx->prev = curr;
        }
    public:
        list(int id, string species){
            node *curr = new node(id, species);
            head = curr;
            tail = curr;
            cout << "Successfully created first table node" << endl;
            cout << "------------------------------------------------------" << endl;
        }
    
        void add(int id, string species){
            node *curr = head;
            if(head == tail){
                if(id > curr->id){
                    tailadd(id, species);
                }else{
                    headadd(id, species);
                }
            }else{
                if(head->id > id){
                    headadd(id, species);
                    return;
                }

                node *nx = curr->next;
                while(nx != nullptr){
                    if(curr->id < id && nx->id > id){
                        middleadd(id, species, curr);
                        return;
                    }
                    curr = nx;
                    nx = curr->next;
                }
                tailadd(id, species);
            }
        }

        void del(int id){
            node *curr = head, *pv, *nx;
            nx = curr->next;
            pv = curr->prev;

            if(head == tail){
                cout << "Cannot delete from a list of one element" << endl;
                cout << "------------------------------------------------------" << endl;
                return;
            }

            ///DEL AT HEAD
            if(curr->id == id){
                head = nx;
                nx->prev = nullptr;
                delete(curr);
                cout << "Successfully deleted entry and remapped" << endl;
                cout << "------------------------------------------------------" << endl;
                return;
            }

            ///DEL AT MID
            while(nx != nullptr){
                if(curr->id == id){
                    delete(curr);
                    pv->next = nx;
                    nx->prev = pv;
                    cout << "Successfully deleted entry and remapped" << endl;
                    cout << "------------------------------------------------------" << endl;
                    return;
                }
                curr = nx;
                pv = curr->prev;
                nx = curr->next;
            }

            ///DEL AT TAIL
            if(curr->id == id){
                delete(curr);
                pv->next = nullptr;
                tail = pv;
                cout << "Successfully deleted entry and remapped" << endl;
                cout << "------------------------------------------------------" << endl;
            }else{
                cout << "ID not found" << endl;
                return;
            }


        }

        void printlist(){
            node *curr = head;
            while(curr != nullptr){
                cout << "Pokédex #" << curr->id << " | Species: " << curr->species << endl;  
                curr = curr->next;
            }
            cout << "------------------------------------------------------" << endl;
        }
};


int main(){
    
    int sw, id;
    string species;

    cout << "Add the first element of the list" << endl;
    cout << "Enter ID" << endl;
    cin >> id;
    cout << "Enter species name" << endl;
    cin >> species;
    list mydex(id, species);
    while(true){
        cout << "Select an option: " << endl << "1. Add item | 2. Delete item | 3. Print list | 4. Exit" << endl;
        cin >> sw;
        cout << "------------------------------------------------------" << endl;
        switch(sw){
            case 1:
                cout << "Enter ID" << endl;
                cin >> id;
                cout << "Enter species name" << endl;
                cin >> species;
                mydex.add(id, species);
                cout << "------------------------------------------------------" << endl;
                break;
            case 2:
                cout << "Enter ID" << endl;
                cin >> id;
                mydex.del(id);
                cout << "------------------------------------------------------" << endl;
                break;
            case 3:
                mydex.printlist();
                cout << "------------------------------------------------------" << endl;
                break;
            case 4:
                exit(-1);
            default:
                cout << "Not an option" << endl;
                cout << "------------------------------------------------------" << endl;
                break;
        }
    }
}
