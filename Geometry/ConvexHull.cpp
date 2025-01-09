// computes the convex hull of a set of N 2D points
// stress tested here: https://cses.fi/problemset/task/2195/

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
 
tint sgn(tint x){
	if(x > 0) return 1;
	else if(x < 0) return -1;
	return 0;
}
 
tint side(Pt a, Pt b, Pt c){
	return sgn(((b-a) % (c-a)));
}
 
int main() {
	int n; cin >> n;
	vector<Pt> a(n);
	F0R(i, n) cin >> a[i].x >> a[i].y;
	sort(all(a));
	vector<Pt> upper, lower;
	Pt fst = a[0], lst = a[n-1];
	upper.pb(fst); lower.pb(fst);
	FOR(i, 1, n){
		// upper hull, must be in clockwise order
		if(side(fst, a[i], lst) <= 0 || i == n-1){
			while(sz(upper) >= 2 && side(upper[sz(upper)-2], upper[sz(upper)-1], a[i]) > 0){
				upper.pop_back();
			}
			upper.pb(a[i]);
		}
		if(side(fst, a[i], lst) >= 0 || i == n-1){
			while(sz(lower) >= 2 && side(lower[sz(lower)-2], lower[sz(lower)-1], a[i]) < 0){
				lower.pop_back();
			}
			lower.pb(a[i]);
		}
	}
	cout << sz(upper) + sz(lower) - 2 << "\n";
	F0R(i, sz(upper)) cout << upper[i].x << " " << upper[i].y << "\n";
	ROF(i, 1, sz(lower)-1) cout << lower[i].x << " " << lower[i].y << "\n";
}