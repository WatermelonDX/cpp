#include <iostream>
#include <string>

using namespace std;

class node{
    public:
        string dato;
        node *next;
        node *prev;
        node(string dato = "default", node *next = nullptr, node *prev = nullptr){
            this->dato = dato;
            this->next = next;
            this->prev = prev;
        }
};
class list{
    private:
        node *head = nullptr;
        node *tail = nullptr;
    public: 
        list(string dato = "default"){
            head = new node(dato);
            head = tail;
        }
        void addhead(string dato){
            node *temp = new node(dato);
            head = temp;
        }
        void addtail(string dato){
            node *prevlastnode = head;
            while(prevlastnode->next != nullptr){
                prevlastnode = prevlastnode->next;
            }
            node *temp = new node(dato);
            prevlastnode->next = temp;
            temp->prev = prevlastnode;
            tail = temp;
        }
        void add(string dato){
            if (head == nullptr){
                addhead(dato);
            }else{
                addtail(dato);
            }
        }
        void printlist(){
            int i = 1;
            node *temp = head;
            while (temp != nullptr){
                cout << "#" << i << " " <<  temp->dato << endl;
                temp = temp->next;
                i++;
            }
        }
};

int main(){
    list mylist("Wawa");
    mylist.add("el pepe");
    mylist.add("ete sech");
    mylist.add("potaxio");
    mylist.add("tilin");
    mylist.printlist(); 
}

