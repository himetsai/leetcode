class FreqStack {
public:
    struct less{
        bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const{
            if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
            return get<1>(a) < get<1>(b);
        } 
    };

    unordered_map<int, int> freq;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less> q;
    int count = 0;

    FreqStack() {

    }
    
    void push(int val) {
        if (freq.find(val) == freq.end())
            freq[val] = 0;
        q.push(make_tuple(val, ++freq[val], ++count));
    }
    
    int pop() {
        int val = get<0>(q.top());
        q.pop();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */