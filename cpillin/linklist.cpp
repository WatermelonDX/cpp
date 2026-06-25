#include <iostream>
#include <string>

using namespace std;

class node{
    public:
        string val;
        int id;
        node *prev;
        node *next;
        node(int id,string val, node *prev = nullptr, node *next = nullptr){
            this->val = val;
            this->id = id;
            this->prev = prev;
            this->next = next;
        }
};

class list{
    private:
        node *head;
        node *tail;
    public:
        list(int id, string val){
            head = new node(id,val);
            tail = head;
        }
        void create(int id, string val){
            int sw = 3;
            if(id > tail->id) sw = 1;
            if(id < head->id) sw = 2;
            switch(sw){
                node *curr;
                case 1:
                    tail->next = new node(id,val, tail);
                    tail = tail->next;
                    if(tail != NULL){
                        cout << "Added at end" << endl;
                    }else{
                        exit(-1);
                    }
                break;
                case 2:
                    head->prev = new node(id, val, nullptr, head);
                    head = head->prev;
                    if(head != NULL){
                        cout << "Added at start" << endl;
                    }else{
                        exit(-1);
                    }
                break;
                case 3:
                    curr = head;
                    while(curr->next != nullptr){
                        if(id >= curr->id && id < curr->next->id){
                            curr->next = new node(id, val, curr, curr->next);
                            curr->next->next->prev = curr->next;
                            cout << "Added in middle" << endl;
                            return;
                        }
                        curr = curr->next;
                    }
                break;
                default:
                    exit(-1);
            }
        }
        void del(int id){
            node *curr = head;
            while(curr->next != nullptr){
                if(curr->id == id){
                    curr->next->prev = curr->prev;
                    curr->prev->next = curr->next;
                    delete(curr);
                    cout << "deleted" << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "Nothing found to delete" << endl;
        }

        void show(){
            node *curr = head;
            cout <<"Name: "<<  curr->val << "|  ID: "<< curr->id << endl;
            while(curr->next != nullptr){
                curr = curr->next;
                cout <<"Name: "<<  curr->val << "|  ID: "<< curr->id << endl;
            }
        }
};


int main(){
    list mylist(1,"wawa");
    mylist.create(2, "pepe");
    mylist.create(4, "wash");
    mylist.create(3, "potaxio");
    mylist.create(7, "waska");
    mylist.create(0, "whiskas");
    mylist.create(1, "cpp");
    mylist.del(3);
    mylist.del(1);
    mylist.del(2);
    mylist.show();
}