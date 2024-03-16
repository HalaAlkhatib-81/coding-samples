#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*this program takes an integer matrix and compares all its elements, returning the k-th smallest element in it
the first elements of each subvector are compared and inserted to a map, where they are ordered. Then the k-th element is printed*/

    typedef vector<int> VE;
    typedef vector<VE> VVE;

int k_esim(int k, const VVE& V){
  map<int,int> a; //map where we store the following. first = the element we'll compare; second = the row where said element is located
  for(int i = 0; i < V.size(); ++i){
    if(not V[i].empty()) 
        a[V[i][0]] = i; //the first integer of each subvector is stored in the map
  }  
  pair<int, int> res; //the result is stored in this pair
  VE it(V.size(), 1); 

  while(k--){
    res = *a.begin(); //the smallest element in the map
    if(V[res.second].size() > it[res.second])
      a[V[res.second][it[res.second]++]] = res.second; // if any integer remain in the subvector where this integer was, they're stored in the map
      a.erase(a.begin());
  } // this iteration will be executed until the k-th element is at the beginning. The value will then be the return value of this function
  return res.first;
}


int main() {
  int n;
  while (cin >> n) {
    VVE V(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      total += m;
      V[i] = VE(m);
      for (int j = 0; j < m; ++j) cin >> V[i][j];
    }

    int i1, i2, k;
    while (cin >> i1 >> i2 >> k, i1 != -1) {
      if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
        cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n
             << ' ' << total << endl;
        return 0;
      }

      swap(V[i1], V[i2]);
      cout << k_esim(k, V) << endl;
    }
  }
}
