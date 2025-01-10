// calculates girth (length of shortest cycle) of a general graph
// stress tested in: https://cses.fi/problemset/task/1707/

#include <bits/stdc++.h>
 
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
const int MX = 2505; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
  
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
vi adj[MX];
 
int main(){
	int n, m; cin >> n >> m;
	F0R(i, m){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ret = inf;
	F0R(i, n){
		queue<int> q;
		vi dist (n, inf);
		dist[i] = 0;
		q.push(i);
		while(sz(q)){
			int u = q.front();
			q.pop();
			trav(v, adj[u]){
				if(dist[v] == inf){
					dist[v] = dist[u]+1;
					q.push(v);
				}else if(dist[v] >= dist[u]){
					ckmin(ret, dist[u]+dist[v]+1);
				}
			}
		}
	}
	cout << (ret == inf ? -1 : ret) << "\n";
}
