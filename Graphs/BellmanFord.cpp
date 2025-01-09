// finds negative cycle in graph

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define dbg cout << "hu" << endl;
 
const tint INF = 5000000000001;
const int MOD = 1000000007;
 
struct edge{
	int a, b; tint w;
};
 
int n, m, node;
vector<edge> e;
 
void bellmanFord(){
	vector<tint> d (n, INF);
	d[node] = 0;
	vector<int> pa (n, -1);
	int x ;
	forn(i, n){
		x = -1;
		forn(j, m){
			if(d[e[j].a]+e[j].w < d[e[j].b]){
				d[e[j].b] = d[e[j].a]+e[j].w;
				pa[e[j].b] = e[j].a;
				x = e[j].b;
			}
		}
	}
	if(x != -1){
		cout << "YES" << "\n";
		forn(i, n){
			x = pa[x];
		}
		vector<int> cyc;
		for(int v=x;;v = pa[v]){
			cyc.push_back(v);
			if(v == x && int(cyc.size()) > 1) break;
		}
		reverse(all(cyc));
		forn(i, cyc.size()){
			cout << cyc[i]+1 << " ";
		}
	}else{
		cout << "NO" << "\n";
	}
}
 
int main(){
	cin >> n >> m;
	node = 0;
	forn(i, m){
		int u, v, w; cin >> u >> v >> w;
		u--;v--;
		e.push_back({u,v,w});
	}
	bellmanFord();
}
