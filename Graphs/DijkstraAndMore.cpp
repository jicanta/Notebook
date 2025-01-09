// calculates in a general graph the following:
// I: the minimum cost of a path between node 1 and N (could be easily changed)
// II: the number of minimum cost paths, mod 10^9+7 between nodes 1 and N
// III: the minimum number of edges in a minimum cost path between nodes 1 and N
// IV: the maximum number of edges in a maximum cost path between nodes 1 and N
// stress testes in: https://cses.fi/problemset/task/1202/

#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 1e5+1;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "puesto"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
	NACHO();
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> adj (n), jda (n);
	forn(i, m){
		tint u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		adj[u].pb(mp(v,w));
		jda[v].pb(mp(u, w));
	}
	function<vi(int, bool)> dijkstra = [&](int node, bool type){
		vi distance (n, INF); distance[node] = 0;
		vector<bool> visited (n, 0);
		priority_queue<pi> q; q.push(mp(0, node));
		while(!q.empty()){
			auto u = q.top().s;
			q.pop();
			if(visited[u]) continue;
			visited[u] = 1;
			for(auto v : (type == 0 ? adj[u] : jda[u])){
				if(distance[v.f] > distance[u]+v.s){
					distance[v.f] = distance[u]+v.s;
					q.push(mp(-distance[v.f], v.f));
				}
			}
		}
		return distance;
	};
	vi A = dijkstra(0, 0);
	vi B = dijkstra(n-1, 1);
	vector<vector<pi>> sp (n);
	forn(i, n){
		for(auto u : adj[i]){
			if(A[i]+B[u.f]+u.s == A[n-1]) sp[i].pb(u);
		}
	}
	vi topo;
	vector<bool> visited (n, 0);
	function<void(int)> dfs = [&](int node){
		visited[node] = 1;
		for(auto u : sp[node]){
			if(!visited[u.f]) dfs(u.f);
		}
		topo.pb(node);
	};
	dfs(0);
	tint minP = A[n-1];
	vi quan (n, 0);
	vi maxe (n, 0);
	vi mine (n, INF);
	mine[0] = 0;
	quan[0] = 1;
	bool seen = 0;
	reverse(all(topo));
	forn(i, sz(topo)){
		if(topo[i] == 0) seen = 1;
		if(seen){
			for(auto u : sp[topo[i]]){
				quan[u.f] =  quan[u.f] % MOD+quan[topo[i]] % MOD;
				mine[u.f] = min(mine[u.f], mine[topo[i]]+1);
				maxe[u.f] = max(maxe[u.f], maxe[topo[i]]+1);
			}
		}
	}
	tint paths = quan[n-1];
	cout << minP << " " << paths << " " << mine[n-1] << " " << maxe[n-1] << "\n";
}