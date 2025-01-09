// given a polygon, calculate the number of lattice points inside the polygon and on its boundary
// lattice point = integer coordinates
// stress tested in: https://cses.fi/problemset/task/2193/
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
		return {x-o.x, y-o.y};
	}
	
	bool operator <(const Pt& o) const{
		if(x == o.x) return y < o.y;
		return x < o.x;
	}
};
 
tint area(vector<Pt>& p){
	int n = sz(p);
	tint ret = 0;
	FOR(i, 1, n){
		ret += ((p[i] - p[0]) % (p[(i+1) % n] - p[i]));
	}
	return abs(ret) / 2;
}
 
int main(){
	int n; cin >> n;
	vector<Pt> a(n);
	F0R(i, n) cin >> a[i].x >> a[i].y;
	tint bound = 0;
	F0R(i, n){
		tint dX = abs(a[(i+1)%n].x - a[i].x), dY = abs(a[(i+1)%n].y - a[i].y); 
		bound += __gcd(dY, dX);
	}
	cout << area(a) - bound / 2 + 1 << " " << bound << "\n";
}