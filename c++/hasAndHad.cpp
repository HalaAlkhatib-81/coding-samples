#include <iostream>
#include <set>
#include <algorithm>


using namespace std;


struct compare {//struct to use for comparasion
	bool operator()(const string& a, const string& b) {
		if (a.length() == b.length()) return a < b;
		return a.length() < b.length();
	}
};


int main(){
    set<string> s;
    set<string, compare> g;
    string w;
    bool quit = 0; 
    bool first = true;
    int t = 1;
    cin >> w;
    while(not quit){
            while(not(w == "END" or w == "QUIT")){
                if(s.count(w)) {       
                    s.erase(w);
                    g.insert(w);
                }   
                else{
                    g.erase(w);
                    s.insert(w);
                }
                cin >> w;    
            }
        if(not first) cout << endl;
        first = false;

        cout << "GAME #" << t << endl;
        cout << "HAS:" << endl;
        for(string h: s) cout << h << endl;        
        cout << endl <<"HAD:" << endl;
        for(string j: g) cout << j << endl;               
          
        ++t;
        s.erase(s.begin(), s.end());
        g.erase(g.begin(), g.end());
           
        if(w == "QUIT") quit = 1;
        else cin >> w;
        

    }
}
