class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        // Edge case check
        if (nums1.empty() || nums2.empty() || k <= 0) return res;

        // Use greater<vector<int>> to turn the priority queue into a Min-Heap.
        // It will automatically compare the first element (the sum) to keep the smallest at the top.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Step 1: Initialize the heap with pairs of (nums1[i], nums2[0])
        // We only need to go up to k, because we only care about the k smallest.
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        // Step 2: Extract the k smallest pairs
        while (k > 0 && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            int i = p[1]; // Index in nums1
            int j = p[2]; // Index in nums2
            
            res.push_back({nums1[i], nums2[j]});
            k--;

            // Step 3: Only increment the index for nums2 to prevent duplicates.
            // Check bounds before pushing to avoid segfaults.
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna