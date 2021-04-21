// solucion de https://codeforces.com/contest/1514/problem/D en O(n log n)
// se usa para este tambien: https://www.spoj.com/problems/PATULJCI/
// este segtree nos permite dado un rango,
// determinar cual es el elemento candidato a aparecer mas de ceil(n/2) veces.
// (n es el largo del rango). Es candidato porque podria no haber ningun elemento
// que cumpla esto.
// La idea es guardar (val, freq). Para mergear, si los valores son iguales, solo aumento freq.
// sino, tomo el de mayor freq y le resto la freq del menos (porque es como que se cancelan).
// Ejemplo: 1 1 1 1 1 2 2 3
// supongamos que mergeamos (1, 5) con (2, 2). Nos quedaria (1, 3).

#include <bits/stdc++.h>
 
using namespace std;
 
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
const int MX = 20000005;
const tint INF = 1e18; 
const int inf = 2e9;
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

struct Node{
	int val, quan;
};

Node merge(Node a, Node b){ // ver que pasa si le pones &!
	if(a.val == b.val) return {a.val, a.quan+b.quan};
	if(a.quan > b.quan) return {a.val, a.quan-b.quan};
	return {b.val, b.quan-a.quan};
}

struct SegTree{
	int size;
	vector<Node> st;
	
	void init(int n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		st.assign(2*size, {-1, 0});
	}
	
	void build(int node, int tl, int tr, vi &a){
		if(tr-tl == 1){
			if(tl < sz(a)){
				st[node] = {a[tl], 1};
			}
			return;
		}
		int tm = (tl+tr)/2;
		build(2*node+1, tl, tm, a);
		build(2*node+2, tm, tr, a);
		st[node] = merge(st[2*node+1], st[2*node+2]);
	}
	
	void build(vi &a){ build(0, 0, size, a); }
	
	Node query(int node, int tl, int tr, int l, int r){
		if(tl >= r || tr <= l) return {-1, 0};
		if(l <= tl && tr <= r) return st[node];
		int tm = (tl+tr)/2;
		return merge(query(2*node+1, tl, tm, l, r), query(2*node+2, tm, tr, l, r));
	}
	
	Node query(int l, int r){ return query(0, 0, size, l, r); }
};

vi pos[300005];

int main(){
	NACHO();
	int n, q; cin >> n >> q;
	vi a (n); F0R(i, n) cin >> a[i], pos[a[i]].pb(i);
	SegTree st; st.init(n+1); st.build(a);
	F0R(i, q){
		int l, r; cin >> l >> r;
		--l;
		Node ret = st.query(l, r+1);
		if(ret.val < 0){ cout << 1 << "\n"; continue; }
		int L = lower_bound(all(pos[ret.val]), l)-pos[ret.val].begin();
		int R = upper_bound(all(pos[ret.val]), r-1)-pos[ret.val].begin();
		--R;
		if(L == sz(pos[ret.val])){ cout << 1 << "\n"; continue; }
		if(R-L+1 < (r-l)/2+1) cout << 1 << "\n";
		else{
			cout << 2*(R-L+1)-(r-l) << "\n";
		}
	}
}

