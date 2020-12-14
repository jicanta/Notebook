//Only works if data is random QAQ https://codeforces.com/contest/896/problem/C

#define IT set<node>::iterator
struct node {
    int ll, rr;
    mutable tint val;
    node(int L, int R = -1, tint V = 0): ll(L), rr(R), val(V) {}
    bool operator < (const node& other) const{
        return ll < other.ll;
    }
};
set<node> tree;
IT split(int pos) {
    IT it = tree.lower_bound(node(pos));
    if((it != tree.end()) && (it->ll == pos)) return it;
    --it;
    int ll = it->ll, rr = it->rr;
    tint val = it->val;
    tree.erase(it);
    tree.insert(node(ll, pos - 1, val));
    return tree.insert(node(pos, rr, val)).first;
}
inline void assign(int ll, int rr, tint val){
    IT itr = split(rr + 1), itl = split(ll);
    tree.erase(itl, itr);
    tree.insert(node(ll, rr, val));
}
inline tint kth(int ll, int rr, tint k) {
    vector<pair<tint, int> > vec;
    IT itr = split(rr + 1), itl = split(ll);
    for(; itl != itr; itl++) {
        vec.push_back(pair<tint, int>(itl->val, itl->rr - itl->ll + 1));
    }
    sort(vec.begin(), vec.end());
    for(vector<pair<tint, int> > :: iterator it = vec.begin(); it != vec.end(); it++) {
        k -= it->second;
        if(k <= 0) return it->first;
    }
    return -1;
}
inline void add(int ll, int rr, tint xx) {
    IT itr = split(rr + 1), itl = split(ll);
    for(; itl != itr; itl++) {
        itl->val += xx;
    }
}
inline tint query(int ll, int rr) {
    tint ret = 0;
    IT itr = split(rr + 1), itl = split(ll);
    for(; itl != itr; itl++) {
        ret += (itl->rr - itl->ll + 1)*itl->val;
    }
    return ret;
}
int main(){
	NACHO();
	int n, q; cin >> n >> q;
	vi b (n);
	forn(i, n){
		cin >> b[i];
		tree.insert(node(i+1, i+1, b[i]));
	}
	tree.insert(node(n+1, n+1, 0));
	//answer queries...
}
