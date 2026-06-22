#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
    public:
        char c;
        vector<node*>next;
        node(char c = '\0'){
            this->c = c;
        }
};

class tree{
    private: 
        node *mother;
    public:
        tree(){
            mother = new node();
        };
        void add(string str){
            node *curr = mother;
            for(char ci: str){
                for(node *n:curr->next){
                    if(n->c == ci){
                        curr = n;
                    }
                }
                curr->next.push_back(new node(ci));
                curr = curr->next.back();
            }
        }
        void del(string str);
        void search(string str){
            node *curr = mother;
            for(char ci: str){
                for(node *n:curr->next){
                    if(n->c == ci){
                        cout << n->c << endl;
                        curr = n;
                    }
                }
            }
        }
        void show();
};


int main(){
    tree arbol;
    arbol.add("wawa");
    arbol.add("waska");
    arbol.add("whiskas");
    arbol.search("whiskas");
}