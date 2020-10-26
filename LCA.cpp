#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
typedef long long tint;
 
const int INF = 1e6;
const int MOD = 1e9+7;
 
vector<int> adj[220000];
 
int n, l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
 
void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p) dfs(u, v);
    }
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v){
	if(is_ancestor(u,v)) return u;
	if(is_ancestor(v,u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
 
void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
 
int main(){
	NACHO;
	int q; cin >> n >> q;
	forn(i, n-1){
		int u; cin >> u;
		u--;
		adj[u].push_back(i+1);
		adj[i+1].push_back(u);
	}
	preprocess(0);
	forn(i, q){
		int a, b; cin >> a >> b;
		a--;b--;
		cout << lca(a,b)+1 << "\n";
	}
}
