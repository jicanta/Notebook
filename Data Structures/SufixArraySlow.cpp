#include <bits/stdc++.h>
 
using namespace std;
 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
using tint = long long;
using db = double;
using ld = long db;
 
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
const int MX = 1e5+5;
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

int main(){
	NACHO();
	string s; cin >> s;
	s += '$';
	int n = sz(s);
	// order of strings, equivalence classes
	vi p(n), c(n);
	// first iteration: strings of length 2^0=1
	// sort individual characters
	vector<pair<char, int>> a(n);
	F0R(i, n) a[i] = mp(s[i], i);
	sort(all(a));
	// assign order
	F0R(i, n) p[i] = a[i].s;
	// assign equivalence class
	c[a[0].s] = 0;
	FOR(i, 1, n){
		if(a[i].f == a[i-1].f) c[a[i].s] = c[a[i-1].s];
		else c[a[i].s] = c[a[i-1].s] + 1;
	}
	int k = 0;
	while((1<<k) < n){
		// transition from 2^k to 2^(k+1)
		vector<pair<pi, int>> a(n);
		F0R(i, n) a[i] = mp(mp(c[i], c[(i + (1<<k)) % n]), i);
		sort(all(a));
		F0R(i, n) p[i] = a[i].s;
		c[a[0].s] = 0;
		FOR(i, 1, n){
			if(a[i].f == a[i-1].f) c[a[i].s] = c[a[i-1].s];
			else c[a[i].s] = c[a[i-1].s] + 1;
		}
		++k;
	}
	F0R(i, n) cout << p[i] << " ";
}

