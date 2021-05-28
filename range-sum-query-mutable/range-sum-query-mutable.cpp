class NumArray {
public:
    NumArray(vector<int>& nums) {
        int N = nums.size();
        arr.resize(N+1);
        tree.resize(N+1);
        for (int i=0 ; i<N ; ++i) {
            arr[i+1] = nums[i];  
            _update(i+1, arr[i+1]);
        } 
    }
    
    void update(int index, int val) {
        int diff = val - arr[index+1];
        arr[index+1] = val;
        _update(index+1, diff);
    }
    
    void _update(int i, int diff) {
        while (i < arr.size()) {
            tree[i] += diff;
            i += (i & -i);
        }
    }
    
    int sumRange(int left, int right) {
        ++right; ++left;
        return _sum(right) - _sum(left-1);
    }
    
    int _sum(int i) {
        int ans = 0;
        while (i) {
            ans += tree[i];
            i -= (i & -i);
        }
        return ans;
    }
    
    vector<int> arr;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */