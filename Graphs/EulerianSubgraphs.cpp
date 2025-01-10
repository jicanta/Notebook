// counts the number of eulerian subgraphs of a general graph in O(V+E).
// a subgraph is called eulerian if each node has even degree.

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <utility>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vl = vector<tint>;
using vb = vector<bool>;
 
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
 
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int mod = 998244353;
const int MX = 1005; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
  
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
bool visited[100005];
vi adj[100005];
int ret = 0;
 
void dfs(int node){
	visited[node] = 1;
	trav(u, adj[node]){
		if(!visited[u]){
			dfs(u);
			++ret;
		}
	}
}
 
int main(){
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	F0R(i, n){
		if(!visited[i]) dfs(i);
	}
	tint cur = 1;
	ret = m - ret;	
	F0R(i, ret) cur = (cur * 2) % MOD;
	cout << ((cur % MOD) + MOD) %MOD << "\n";
}