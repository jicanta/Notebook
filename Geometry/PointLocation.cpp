// Given a line, determine whether a given point is located to the left, right or is in the line
// stress teste in: https://cses.fi/problemset/task/2189
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
 
const int MOD = 998244353; 
const int mod = 1e9+7;
const int MX = 4005;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
 
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } 
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } 
  
struct Pt{
	tint x, y;
	
	tint operator %(const Pt& o) const{
		return x*o.y - y*o.x;
	}
	
	Pt operator -(const Pt& o) const{
		return {x - o.x, y - o.y};
	}
};
 
int main(){
	int tc; cin >> tc;
	while(tc--){
		Pt a, b, c;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		tint ret = (b - a) % (c - a);
		if(ret > 0) cout << "LEFT" << "\n";
		else if(ret < 0) cout << "RIGHT" << "\n";
		else cout << "TOUCH" << "\n";
	}
}