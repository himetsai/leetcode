class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct comp{
            bool operator()(const pair<int, int>& a,const pair<int, int>& b) const{ 
                return a.second < b.second;
            }
        };

        unordered_map<int, int> umap;
        vector<int> ans;

        for (int n : nums) {
            if (umap.find(n) == umap.end()) umap[n] = 0;
            umap[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq(umap.begin(), umap.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};