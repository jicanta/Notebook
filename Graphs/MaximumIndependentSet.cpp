#include <bits/stdc++.h>

// maximum independent set in a general graph.
// takes advantage of the duality
// max. ind. set = max clique in complemenatry graph.
// works in O(2^(n/2) * (n/2)^2) with bitmask dp and meet in the middle.
 
using namespace std;
 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)	
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vl = vector<tint>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
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
const int MX = 41;
const tint INF = 1e18; 
const int inf = 1e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;
 
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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = ""){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

bool has[MX][MX];
int dp1[1<<21], dp2[1<<21];
vi ret1[1<<21], ret2[1<<21];

int main(){
	NACHO();
	int n, M; cin >> n >> M;
	F0R(i, M){
		int u, v; cin >> u >> v;
		has[u][v] = 1;
		has[v][u] = 1;
	}
	F0R(m, 1<<(n/2)){
		F0R(i, n/2){
			if((m&(1<<i)) == 0) continue;
			if(ckmax(dp1[m], dp1[m^(1<<i)])) ret1[m] = ret1[m^(1<<i)];
			bool ok = 1;
			F0R(j, n/2){
				if(m&(1<<j) && has[i][j]) ok = 0;
			}
			if(ok){
				if(ckmax(dp1[m], dp1[m^(1<<i)] + 1)) ret1[m] = ret1[m^(1<<i)], ret1[m].pb(i);
			}
		}
	}
	F0R(m, 1<<(n - n/2)){
		F0R(i, n - n/2){
			if((m&(1<<i)) == 0) continue;
			if(ckmax(dp2[m], dp2[m^(1<<i)])) ret2[m] = ret2[m^(1<<i)];
			bool ok = 1;
			F0R(j, n - n/2){
				if(m&(1<<j) && has[i + n/2][j + n/2]) ok = 0;
			}
			if(ok){
				if(ckmax(dp2[m], dp2[m^(1<<i)] + 1)) ret2[m] = ret2[m^(1<<i)], ret2[m].pb(i + n/2);
			}
		}
	}
	int ret = 0;
	vi rr;
	F0R(m, 1<<(n/2)){
		int otM = (1<<(n - n/2)) - 1;
		F0R(i, n/2){
			if((m&(1<<i)) == 0) continue;
			F0R(j, n - n/2){
				if(has[i][j + n/2]) otM &= ((1<<(n - n/2)) - 1) ^ (1<<j);
			}
		}
		if(ckmax(ret, dp1[m] + dp2[otM])){
			rr = ret1[m];
			trav(u, ret2[otM]) rr.pb(u);
		}
	}
	cout << ret << "\n";
	trav(u, rr) cout << u << " ";
}

