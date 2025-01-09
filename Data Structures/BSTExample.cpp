// Binary search tree example https://dmoj.ca/problem/ds4.
// I use pairs for I could have repeated elements.
// Handles following operations:
// insert a number
// erase a single number
// output the nth smallest element in the structure
// output the index of the first occurence of a number if the number is in the structure.

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
const int mod = 998244353;
const int MX = 2e6+5;
const tint INF = 1e18; 
const int inf = 2e8;
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
	int n, q; cin >> n >> q;
	Tree<pi> s;
	map<int, int> id;
	F0R(i, n){
		int x; cin >> x;
		++id[x];
		s.ins(mp(x, id[x]));
	}
	F0R(i, q){
		char a; int x; cin >> a >> x;
		if(a == 'I'){
			++id[x];
			s.ins(mp(x, id[x]));
		}else if(a == 'R'){
			if(id[x] == 0) continue;
			s.erase(s.find(mp(x, id[x])));
			--id[x];
		}else if(a == 'S'){
			cout << s.find_by_order(x-1)->f << "\n";
		}else{
			if(id[x] == 0){
				cout << -1 << "\n"; continue;
			}
			cout << s.order_of_key(mp(x, 1))+1 << "\n";
		}
	}
	trav(u, s){
		if(u == *s.begin()) cout << u.f;
		else cout << " " << u.f;
	}
	cout << "\n";
}


