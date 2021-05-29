class Solution {
public:
    int get_parent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = get_parent(parent[x]);
    }
    
    void union_provinces(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);
        if (x == y) return;
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }
    
    int count_num_provinces() {
        printf("### count_num_provinces \n");
        
        unordered_map<int, int> umap;
        int cnt = 0;
        for (int i=0 ; i<parent.size() ; ++i) {
            int x = get_parent(i);
            printf("parent[%d] = %d \n", i, x);
            if (umap.find(x) == umap.end()) {
                ++umap[x];
                ++cnt;
            }
            printf("umap[%d] = %d \n", x, umap[x]);
        }
        return cnt;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        parent.resize(N);
        for (int i=0 ; i<N ; ++i) {
            parent[i] = i;
        }
        
        for (int i=0 ; i<N ; ++i) {
            for (int j=0 ; j<N ; ++j) {
                if (isConnected[i][j])
                    union_provinces(i, j);
            }
        }
            
        return count_num_provinces();
    }
    
    vector<int> parent;
};