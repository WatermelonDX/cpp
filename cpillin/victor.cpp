#include <iostream>
#include <cstdlib>

using namespace std;
typedef int tipo;

class item{
    public: 
        tipo val;
        item(){
            this->val = val;
        }
};

class vector{
    private:
        item *vic;
        int cap = 10, curr = 0;
    public:
        vector(){
            vic = (item *)malloc(sizeof(item)*cap);
            if(vic == NULL){
                cout << "error" << endl;
                exit(-1);
            }
        }
        void add(tipo val){
            if(cap <= curr){
                cap = cap+10;
                vic = (item*)realloc(vic, sizeof(item)*cap);
                if (vic == NULL){
                    cout << "resize error" << endl;
                }else{
                    cout << "resize" << endl;
                }
            }
            vic[curr].val = val;
            curr++;
        }
        void show(){
            for(int i = 0; i<cap; i++){
                if(vic[i].val != -1 && vic[i].val != NULL)
                    cout << vic[i].val << endl;
            }
        }
        void del(int pos){
            if(vic+pos != NULL){
                vic[pos].val = -1;
                cout << "eteled" << endl;
            }else{
                cout << "fym" <<endl;
            }
        }
};

int main(){
    vector victor;
    for(int i=0; i<51; i++){
        victor.add(i);
    }
    victor.del(3);
    victor.show();

}