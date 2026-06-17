#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int curr = 0, last = 0, gponumero = 0, i = 0;
        for (char c : s){
            if(c == 'I'){curr = 1;}
            if(c == 'V'){curr = 5;}
            if(c == 'X'){curr = 10;}
            if(c == 'L'){curr = 50;}
            if(c == 'C'){curr = 100;}
            if(c == 'D'){curr = 500;}
            if(c == 'M'){curr = 1000;}

            if(i == 0){
                gponumero = gponumero + curr;
            }else{
                if(curr <= last){
                    gponumero = gponumero + curr;
                }else{
                    gponumero = gponumero + curr;
                    gponumero = gponumero - (last*2);
                }
            }
            last = curr;
            i++;
        }
        return gponumero;
    }
};
int main(){
    Solution sol;
    string wawa = "MCVXII";
    char *s = &wawa[0];
    cout << sol.romanToInt(s) << endl;
}