class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    int medium;
    int size = 0;
    MedianFinder() {}
    
    void addNum(int num) {
        if (size == 0) {
            medium = num;
            size++;
            return;
        }
        if (size % 2) {
            int s = min(medium, num);
            int l = max(medium, num);
            small.push(s);
            big.push(l);
        }
        else {
            if (num > big.top()) {
                big.push(num);
                medium = big.top();
                big.pop();
            }
            else if (num < small.top()) {
                small.push(num);
                medium = small.top();
                small.pop();
            }
            else
                medium = num;
        }
        size++;
    }
    
    double findMedian() {
        return (size % 2) ? medium : ((double) big.top() + (double) small.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */