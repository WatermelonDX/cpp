#include <iostream>
#include <string>
#include <queue>

using namespace std;
template <typename t>

class node{
    public: 
        t value;
        node *left;
        node *right;
        node(t value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};


template <typename t>
class tree{ 
    public: 
        node<t> *root;
        tree(t value){
            root = new node<t>(value);
        }
        void add(t value){
            node<t> *curr = root;
            queue<node<t>*> q;
            q.push(curr);
            while(true){
                curr = q.front();
                if(curr->left == nullptr){
                    curr->left = new node<t>(value);
                    cout << "Node added successfully" << endl;
                    return;
                }else{
                    q.push(curr->left);
                }

                if(curr->right == nullptr){
                    curr->right = new node<t>(value);
                    cout << "Node added successfully" << endl;
                    return;
                }else{
                    q.push(curr->right);
                }

                q.pop();
            }
        }

        void show(){
            queue<node<t>*> q;
            q.push(root);

            while(!q.empty()){
                node<t>* curr = q.front();
                cout << curr->value << endl;
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
                q.pop();
            }
        }


};


int main(){
        tree mytree("jason");
        mytree.add("wawa");
        mytree.add("gaga");
        mytree.add("fafa");
        mytree.add("gaga");
        mytree.add("xd");
        mytree.add("gaga");

        cout <<  "Node 1" << " " << mytree.root->value << " " << mytree.root->right->value <<" " << mytree.root->left->value << endl;
        cout <<  "Node 2" << " " << mytree.root->left->value << " " << mytree.root->left->left->value <<" " << mytree.root->left->right->value << endl;

        mytree.show();
}