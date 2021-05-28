class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> umap;
        for (auto c : jewels) {
            umap[c] = true;
        }
        int cnt = 0;
        for (auto c : stones) {
            if (umap[c]) ++cnt;
        }
        return cnt;
    }
};