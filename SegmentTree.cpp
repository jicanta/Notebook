template<class T> struct SegTree{
	int size;
	vector<T> st;	
	
	void init(int n){
		size = 1;
		while(size < n){
			size*=2;
		}
		st.assign(2*size, 0);
	}
	
	void build(int node, int tl, int tr, vector<T> &a){
		if(tr-tl == 1){
			if(tl < sz(a)) st[node] = a[tl];
			return;
		}
		int tm = (tl+tr)/2;
		build(2*node+1, tl, tm, a);
		build(2*node+2, tm, tr, a);
		st[node] = st[2*node+1]+st[2*node+2];	
	}
	
	void build(vector<T> &a){ build(0, 0, size, a);  }
	
	void update(int node, int tl, int tr, int pos, int val){
		if(tr-tl == 1){
			st[node] = val;
			return;
		}
		int tm = (tl+tr)/2;
		if(pos < tm) update(2*node+1, tl, tm, pos, val);
		else update(2*node+2, tm, tr, pos, val);
		st[node] = st[2*node+1]+st[2*node+2];
	}
	
	void update(int pos, int val){ update(0, 0, size, pos, val);  }
	
	T query(int node, int tl, int tr, int l, int r){
		if(tr <= l || tl >= r) return 0;
		if(l <= tl && tr <= r) return st[node];
		int tm = (tl+tr)/2;
		return query(2*node+1, tl, tm, l, r)+query(2*node+2, tm, tr, l, r);
	}
	
	T query(int l, int r){ return query(0, 0, size, l, r); }
	
	int find_kth(int node, int tl, int tr, int k){
		if(tr-tl == 1) return tl;
		int tm = (tl+tr)/2;
		if(k < st[2*node+1]){
			return find_kth(2*node+1, tl, tm, k);
		}else{
			return find_kth(2*node+2, tm, tr, k-st[2*node+1]);
		}
	}
	
	int find_kth(int k){
		return find_kth(0, 0, size, k);
	}
	
	int first_greater(int node, int tl, int tr, T val, int l){ //first j s.t. j>=l && a[j] > val
		if(st[node] < val) return -1;
		if(tr <= l) return -1;
		if(tr-tl == 1) return tl;
		int tm = (tl+tr)/2;
		int x = find(2*node+1, tl, tm, val, l);
		if(x == -1) x = find(2*node+2, tm, tr, val, l);
		return x;
	}
	
	int first_greater(T val, int l){
		return first_greater(0, 0, size, val, l);
	}
};
