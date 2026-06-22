#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class node{
    public:
        string val;
        node *right;
        node *left;
        node(string val){
            this->val = val;
            this->right = nullptr;
            this->left = nullptr;
        }
};

class tree{
    private:
        node *root;
    public:
        tree(string val){
            root = new node(val);
            cout << "Barrier initialized!" << endl;
        }
        void add(string val){
            queue<node*>q;
            q.push(root);
            node *curr;

            while (true){
                curr = q.front();
                if(curr->left == nullptr){
                    curr->left = new node(val); 
                    cout << "Node added succesfully" << endl;
                    return;
                }else{
                    q.push(curr->left);
                }

                if(curr->right == nullptr){
                    curr->left = new node(val);
                    cout << "Node added succesfully" << endl;
                    return;
                }else{
                    q.push(curr->right);
                }
                q.pop();
            }

        }
        void show(){
            queue<node*>qe;
            qe.push(root);
            node *curr;
            
            while (!(qe.empty())){
                curr = qe.front();
                cout << curr->val << endl;
                if(curr->left != nullptr){
                    qe.push(curr->left);
                }
                if(curr->right != nullptr){
                    qe.push(curr->right);
                }
                qe.pop();
            }
        }
        
};


int main(){
    tree mytree("bazinga");
    mytree.add("el pepe");
    mytree.add("ete sech");
    mytree.add("potaxio");
    mytree.add("XD");
    mytree.show();
}