class Solution {
public:
    int get_parent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = get_parent(parent[x]);
    }
    
    void merge(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);
        if (x == y) return;
        int idx = x;
        if (x < y) {
            idx = x;
            parent[y] = x;
            group[idx] += group[y];
            group[y] = 0;
        } else {
            idx = y;
            parent[x] = y;
            group[idx] += group[x];
            group[x] = 0;
        }
        if (longest_size < group[idx])
            longest_size = group[idx];
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (1 == nums.size()) return 1;
        longest_size = 1;
        for (int& num : nums) {
            if (parent.find(num) != parent.end()) continue;
            parent[num] = num;
            group[num] = 1;
            
            if (parent.find(num+1) != parent.end() && group[num+1]) {
                merge(num, num+1);
            }
            
            if (parent.find(num-1) != parent.end()) {
                merge(num-1, num);
            }
        }
        return longest_size;
    }
    
    unordered_map<int, int> parent;
    unordered_map<int, int> group;
    int longest_size;
};