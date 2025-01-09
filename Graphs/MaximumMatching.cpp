// maximum matching in general graph
// stress tested in: https://cses.fi/problemset/task/1696/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
const tint INF = 2e14+1;
const long double PI = 3.141592;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios_base::sync_with_stdio(0);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
 
vector<bool> visited (1001, 0);
vector<int> match (1001, -1);
 
bool dfs(int node, vector<vector<int>> &adj){
	for(const auto &x : adj[node]){
		if(!visited[x]){
			visited[x] = 1;
			if(match[x] == -1 || dfs(match[x], adj)){
				match[x] = node;
				match[node] = x;
				return 1;
			}
		}
	}
	return 0;
}
 
int main(){
	 int n, m, k; cin >> n >> m >> k;
	 vector<vector<int>> adj (n);
	 forn(i, k){
		 int u, v; cin >> u >> v;
		 u--; v--;
		 adj[u].push_back(n+v);
	 }
	 int cont = 0;
	 forn(i, n){
		 visited.assign(n+m, 0);
		 if(dfs(i, adj)) cont++;
	 }
	 cout << cont << "\n";
	 forn(i, n){
		 if(match[i] != -1) cout << i+1 << " " << match[i]-n+1 << "\n";
	 }
}
