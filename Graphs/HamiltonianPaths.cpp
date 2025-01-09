// number of hamiltonian paths from node 1 to node N
// stress tested in: https://cses.fi/problemset/task/1690/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const int INF = 50000001;
const int MOD = 1000000007;
 
int dp[1+(1<<20)][21];
vector<int> adj[21];
 
int main(){
	NACHO;
    int n, m; cin >> n >> m;
    forn(i, m){
        int u, v; cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
    }
    forn(i, (1LL<<n)) forn(j,n) dp[i][j] = 0;
    forn(i, n){
		dp[1<<i][i] = 1;
	}
    forn(i, (1LL<<n)){
        forn(j, n){
			if((i&(1<<0)) == 0){ dp[i][j] = 0; continue;}
            else if(i&(1LL<<j) && __builtin_popcount(i) > 1){
                for(auto k : adj[j]){
                    if(i&(1LL<<k)){
                        dp[i][k] += dp[i^(1LL<<k)][j];
                        dp[i][k] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
}