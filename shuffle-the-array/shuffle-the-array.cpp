class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        v.resize(2*n);
        for (int i=0, l=0, r=n ; l<n ; ++l, ++r) {
            v[i++] = nums[l];
            v[i++] = nums[r];
        }
        return v;
    }
};