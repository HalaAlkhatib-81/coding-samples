#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX = 1e8;

int main(){
    int x, y, n;
    while(cin >> x >> y>> n){
        unordered_map<int, int> v;
        int pos = 0;
        int t = 0;
        bool repe = false;        
        v.insert({n, 0});
        while(repe == false and n <= MAX){
            if(n%2 == 0) n = n/2 + x;
            else n = 3*n + y;
            ++pos;
            unordered_map<int, int>:: iterator it = v.find(n);
            if(it == v.end()) v.insert({n, pos});
            else{
                repe = true;
                t = it ->second;
            }                    
        }
        if(repe) cout << pos - t <<  endl;
        else cout << n << endl;

    }
}