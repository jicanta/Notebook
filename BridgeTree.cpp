#include <bits/stdc++.h>

// finds bridge tree of a general graph.
// useful to find minimum number of edges to add st there are no bridges,
// add a single edge to minimize the number of bridges,
// basically problems involving bridges.
// Eg: https://codeforces.com/contest/652/problem/E
// https://codeforces.com/contest/1000/problem/E
// https://codeforces.com/contest/732/problem/F
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vpl = vector<pl>;
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
const tint mod = 998244353;
const int MX = 3e5+5;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
tint cdiv(tint a, tint b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
tint fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vpi adj[MX];
vi tree[MX];
pi edges[MX];
bool vis[MX], bridge[MX];
int cur = 0;
int tin[MX], low[MX], comp[MX];
int t = 1;

void dfs(int node, int pa){
	tin[node] = low[node] = t++;
	vis[node] = 1;
	trav(u, adj[node]){
		if(u.f == pa) continue;
		if(vis[u.f]){
			ckmin(low[node], tin[u.f]);
		}else{
			dfs(u.f, node);
			ckmin(low[node], low[u.f]);
			if(low[u.f] > tin[node]){
				bridge[u.s] = 1;
			}
		}
	}
}

void dfss(int node, int pa){
	vis[node] = 1;
	comp[node] = cur;
	trav(u, adj[node]){
		if(bridge[u.s] || vis[u.f]) continue;
		dfss(u.f, node);
	}
}

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
		edges[i] = mp(u, v);
 	}
	dfs(0, -1);
	F0R(i, n) vis[i] = 0;
	F0R(i, n){
		if(!vis[i]){
			dfss(i, -1);
			++cur;
		}
	}
	F0R(i, m){
		if(bridge[i]){
			int u = edges[i].f, v = edges[i].s;
			tree[comp[u]].pb(comp[v]);
			tree[comp[v]].pb(comp[u]);
		}
	}
}
 
