// DSU that allows queries of the form:
// check whether a connected component is bipartite
// determine the first edge that makes the graph non-bipartite
// check whether two nodes have the same color (if you paint the graph bipartite-like)
// two nodes have the same color if they are in the same component
// and the distance to its representative is the same.

struct DSU{
	vpi e; vb bi; void init(int N){ e = vpi(N, mp(-1, 0)); bi = vb(N, 1); }
	pi get(int x){
		if(e[x].f < 0) return mp(x, 0);
		else{
			int len = e[x].s;
			e[x] = get(e[x].f);
			e[x].s ^= len;
			return e[x];
		}
	}
	bool sameSet(int x, int y){ return (get(x) == get(y)); }
	bool unite(int x, int y){
		pi X = get(x), Y = get(y);
		x = X.f, y = Y.f;
		if(x == y){
			if(X.s == Y.s) bi[x] = 0;
			return 0;
		}else{
			if(e[x] > e[y]) swap(X, Y);
			x = X.f, y = Y.f;
			e[x].f += e[y].f;
			e[y] = mp(x, X.s^Y.s^1);
			bi[x] = bi[x] && bi[y];
			return 1;
		}
	}
}; 
