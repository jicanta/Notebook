// given a polygon, test whether a point is outside, inside or in the boundary of the polygon
// stress tested here: https://cses.fi/problemset/task/2192/

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
 
struct Pt{
	tint x, y;
	
	tint operator %(const Pt& o) const{
		return x*o.y - y*o.x;
	}
	
	Pt operator -(const Pt& o) const{
		return {x - o.x, y - o.y};
	}
};
 
tint sgn(tint x){
	if(x == 0) return 0;
	else if(x > 0) return 1;
	return -1;
}
 
tint side(Pt a, Pt b, Pt c){
	return sgn((b-a) % (c-a));
}
 
bool intersect(Pt a, Pt b, Pt c, Pt d){
	if((b-a) % (d-c) == 0){
		if(side(a, b, c) == 0 || side(a, b, d) == 0){
			if(max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)){
				return 0;
			}
			if(max(c.x, d.x) < min(a.x, b.x) || max(c.y, d.y) < min(a.y, b.y)){
				return 0;
			}
			return 1;
		}
		return 0;
	}else{
		if(side(a, b, c) != side(a, b, d) && side(c, d, a) != side(c, d, b)){
			return 1;
		}
		return 0;
	}
}
 
int main(){
	int n, m; cin >> n >> m;
	vector<Pt> a(n);
	F0R(i, n) cin >> a[i].x >> a[i].y;
	F0R(assa, m){
		Pt cur;
		cin >> cur.x >> cur.y;
		bool bound = 0;
		int isects = 0;
		F0R(i, n){
			if(intersect(a[i], a[(i+1)%n], cur, cur)) bound = 1;
			if(intersect(a[i], a[(i+1)%n], cur, {inf + 1, cur.y + 1})) ++isects;
		}
		if(bound) cout << "BOUNDARY" << "\n";
		else if(isects & 1) cout << "INSIDE" << "\n";
		else cout << "OUTSIDE" << "\n";
	}
}