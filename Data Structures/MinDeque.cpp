template<class T> struct MinDeque { 
    int lo = 0, hi = -1;
    deque<pair<T,int>> d;
    void ins(T x){ 
        while (!d.empty() && d.back().first >= x) d.pop_back();
        d.push_back({x,++hi});
    }
    
    void del(){ 
        if (d.front().second == lo++) d.pop_front();
    }
    
    T get() { 
        return !d.empty() ? d.front().first : INF; 
    }
};
