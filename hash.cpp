#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

// STRUCTS STRUCTS STRUCTS STRUCTS STRUCTS STRUCTS STRUCTS STRUCTS 
struct node{
    string key;
    string val;
    struct node* next;
};

typedef struct{
    int alive, cap;
    struct node** arr;
}hashmap;


//RECURSIVE FUNCTIONS FUNCTIONS FUNCTIONS FUNCTIONS FUNCTIONS FUNCTIONS FUNCTIONS 
// NODE CONSTRUCTOR
void fillnode(struct node *node, string key, string val){
    node->key = key;
    node->val = val;
    node->next = NULL;
}
// TABLE CONSTRUCTOR
void inithashmap(hashmap* mp){
    mp->cap = 100;
    mp->alive = 0;
    mp->arr = (struct node**)calloc(mp->cap, sizeof(struct node*));
}
// BALATRO
int balatro (int cap){
    if(cap >= 10 && cap%10 == 0){
        cap = cap/10;
    }else{
        cap = 3;
    }
    return cap;
}
//HASHER - YOU'VE GOT MAIL! YOU'VE GOT MAIL! YOU'VE GOT MAIL! YOU'VE GOT MAIL! 
int hashify (string key, hashmap *mp){
    int hash = 0, factor = 31;
    for (char c :key) {
        hash = ((hash % mp->cap)+((int(c)) * factor) % mp->cap) % mp->cap;
        factor = ((factor % __INT16_MAX__)* (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    cout << hash << endl;
    return hash;
}
//OTHER FUNCTIONS OTHER FUNCTIONS OTHER FUNCTIONS OTHER FUNCTIONS OTHER FUNCTIONS 
void newelement(hashmap* mp, string key, string value){
    int hash = hashify(key, mp);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    fillnode(newnode, key, value);

    if(mp->arr[hash] == NULL){
        mp->arr[hash] = newnode;
    }else{
        newnode->next = mp->arr[hash];
        mp->arr[hash] = newnode;
    }
    mp->alive++;
}
string search(hashmap *mp, string key){
    int hash = hashify(key, mp);
    struct node *head = mp->arr[hash];
    while (head != NULL){
        if (key.compare(head->key) == 0){
            return head->val;
        }
        head = head->next;
    }

    string errormsg = "Not found";
    return errormsg;
}

//MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN 
int main(){
    hashmap *mp = (hashmap*)malloc(sizeof(hashmap));    
    inithashmap(mp);

    newelement(mp, "TWOH", "The world: Over heaven");
    newelement(mp, "SPOH", "Star platinum: Over heaven");
    newelement(mp, "D4C", "Dirty deeds done dirt cheap");
    newelement(mp, "SP", "Star platinum");
    newelement(mp, "TCAU", "Triangle crimson: Alternative universe");

    cout << search(mp, "TWOH") << endl;
    cout << search(mp, "D4C") << endl;
    cout << search(mp, "SP") << endl;
    cout << search(mp, "TCAU") << endl;
    cout << search(mp, "wawa") << endl;
}