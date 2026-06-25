#include <iostream>
#include <queue>

typedef int tipo;
using namespace std;

class node{
    public:
    tipo val;
    node* left;
    node* right;
    node(tipo val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class tree{
    private:
        node *mother;
        int entries;
    public:
        tree(){
            mother = new node(-1);
        }
        void add(tipo val){
            node *curr = mother;
            queue<node*>q;
            q.push(curr);
            while(!q.empty()){
                if(curr->left != nullptr){
                    q.push(curr->left);
                }else{
                    curr->left = new node(val);
                    cout << "Node added" << endl;
                    return;
                }

                if(curr->right != nullptr){
                    q.push(curr->right);
                }else{
                    curr->right = new node(val);
                    cout << "Node added" << endl;
                    return;
                }
                
                q.pop();
                curr = q.front();
            }
        }
        void del(tipo val){
            node *curr = mother;
            node *temp;
            queue<node*>q;
            q.push(mother);
            while(!q.empty()){
                temp = curr;
                curr = q.front();
                if(curr->val == val && curr != mother){
                    if(temp->left == curr){
                        temp->left = nullptr;
                    }
                    if(temp->right == curr){
                        temp->right = nullptr;
                    }
                    delete(curr);
                    cout << "Node successfully deleted" << endl;
                    return;
                }
                
                if(curr->left != nullptr){
                    q.push(curr->left);
                }

                if(curr->right != nullptr){
                    q.push(curr->right);
                }
                q.pop();
            }
            cout << "Node not found" << endl;
        }
        void show(){
            node *curr = mother;
            queue<node*>q;
            q.push(curr);
            while(!q.empty()){
                curr = q.front();
                cout << curr->val << endl;
                if(curr->left != nullptr && curr->left->val < 100){
                    q.push(curr->left);   
                }
                if(curr->right != nullptr && curr->right->val < 100){
                    q.push(curr->right);
                }
                q.pop();
                
                
            }
            return;
        }

};

int main(){
    tree tri;
    for(int i = 0; i < 20; i++){
        tri.add(i);
    }
    tri.show();
    tri.del(3);
    tri.show();
}