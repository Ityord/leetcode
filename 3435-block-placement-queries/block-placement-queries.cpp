class Solution {
public:
    vector<int> segmentTree;
    int n = 50001;
    void CST(){
        segmentTree.resize(4*n,0);
    }
    void updateST(int idx, int val, int i, int l, int r){

        if (l == r ){
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;

        if (idx <= mid){
            updateST(idx, val, 2*i+1, l, mid);
        } else {
            updateST(idx, val, 2*i+2,mid+1, r);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }
    int queryST(int start, int end, int i, int l, int r){
        if (l > end || r < start){
            return 0;
        }
        if (l >= start && r <= end){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return max(queryST(start, end, 2*i+1, l, mid),queryST(start, end, 2*i+2, mid+1, r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        CST();
        set<int> st;
        st.insert(0);
        vector<bool> result;
        for (auto& query : queries){
            if (query[0] == 1){
                int x = query[1];
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                updateST(x, x-pre, 0,0,n-1);
                updateST(nxt, nxt-x, 0, 0, n-1);

                st.insert(x);
            }
            else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);
                int maxgap = queryST(0,pre,0,0,n-1);
                int best = max(maxgap, x-pre);
                
                result.push_back(best >= sz);
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna