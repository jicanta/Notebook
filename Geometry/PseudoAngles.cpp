// tested on https://atcoder.jp/contests/abc442/tasks/abc442_e
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for(int i = (int)b-1; i >= a; i--)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vb = vector<bool>;
using ld = long double;

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;
const int MX = 2e5+5;

struct Pt {
	ll x, y;
	int sgnPlus = y >= 0 ? 1 : -1;
	Pt(ll x = 0, ll y = 0) : x(x), y(y) {}
};

struct PseudoAngle {
	ll num, den;
	int id;
	// pseudoAngle /  pseudo arg is commonly defined as
	// sgn+(y)*(1-x/(abs(x)+abs(y))
	// to avoid using float-precision arithmetic, we can directly work with fractions
	// sgn+(y) * (abs(x)+abs(y)+x)/(abs(x)+abs(y))
	// I multiply the denominator to avoid (possible) overflow
	PseudoAngle(Pt p = Pt(), int id=0) : num(abs(p.x)+abs(p.y)+p.x), den(p.sgnPlus*(abs(p.x)+abs(p.y))), id(id) {}
	bool operator<(const PseudoAngle &ot) const {
		return num*ot.den < ot.num*den;
	}
	bool operator==(const PseudoAngle &ot) const {
		return num*ot.den == ot.num*den;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	vector<PseudoAngle> a(n);
	rep(i, 0, n) {
		ll x, y; cin >> x >> y;
		Pt p = Pt(x, y);
		a[i] = PseudoAngle(p, i);
	}
	
	sort(all(a));
	
	vi l(n), r(n);
	rep(i, 0, n) l[i] = r[i] = i;
	rep(i, 1, n) if(a[i] == a[i-1])
		l[a[i].id] = l[a[i-1].id];
	per(i, 0, n-1) if(a[i] == a[i+1])
		r[a[i].id] = r[a[i+1].id];
	vi pos(n);
	rep(i, 0, n)
		pos[a[i].id] = i;
	rep(_, 0, q) {
		int x, y; cin >> x >> y;
		x--, y--;
		x = pos[l[x]], y = pos[r[y]];
		if(x <= y) cout << y-x+1 << '\n';
		else cout << y+1+n-x << '\n';
	}
		
	return 0;
}
