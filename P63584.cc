#include <iostream>
#include <vector>
#include <map>
using namespace std;

    typedef vector<int> VE;
    typedef vector<VE> VVE;

int k_esim(int k, const VVE& V){
  map<int,int> a; //mapa donde guardamos: first = elemento a comparar; second = fila del elemento
  for(int i = 0; i < V.size(); ++i){
    if(not V[i].empty()) 
        a[V[i][0]] = i; //los elementos de cada fila se guardan de menor a mayor en a
  }  
  pair<int, int> res; //pair que usaremos para guardar el resultado
  VE it(V.size(), 1);

  while(k--){
    res = *a.begin(); //elemento más pequeño de a
    if(V[res.second].size() > it[res.second])
      a[V[res.second][it[res.second]++]] = res.second; // si siguen habiendo elementos en la fila, se añade el siguiente elemento a a
      a.erase(a.begin());
  } // esta operación se realiza hasta el el k-esimo elemento quede en el principio. cuando ya quede ahí, retornamos res.first
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
