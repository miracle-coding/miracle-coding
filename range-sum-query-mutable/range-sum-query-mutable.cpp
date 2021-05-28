class NumArray {
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        arr.resize(N);
        for (int i=0 ; i<N ; ++i)
            arr[i] = nums[i];
        
        int h = ceil(log2(N));
        int tree_size = 1 << (h+1);
        tree.resize(tree_size);
        init(0, 0, N-1);
    }
    
    int init(int node, int start, int end) {
        if (start == end) return tree[node] = arr[start];
        int mid = (start+end)/2;
        return tree[node] = init(2*node+1, start, mid) + init(2*node+2, mid+1, end);
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        _update(0, 0, N-1, index, diff);
    }

    void _update(int node, int start, int end, int index, int diff) {
        if (index < start || end < index) return;
        tree[node] += diff;
        if (start == end) return;
        int mid = (start+end)/2;
        _update(2*node+1, start, mid, index, diff);
        _update(2*node+2, mid+1, end, index, diff);
    }
    
    int sumRange(int left, int right) {
        return _sum(0, 0, N-1, left, right);
    }
    
    int _sum(int node, int start, int end, int qleft, int qright) {
        if (qright < start || end < qleft) return 0;
        if (qleft <= start && end <= qright) return tree[node];
        int mid = (start+end)/2;
        return _sum(2*node+1, start, mid, qleft, qright) +
            _sum(2*node+2, mid+1, end, qleft, qright);
    }
    
    vector<int> arr;
    vector<int> tree;
    int N;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */