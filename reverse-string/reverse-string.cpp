class Solution {
public:
    void rec(int left, int right, vector<char>& s) {
        if (left >= right) return;
        swap(s[left], s[right]);
        rec(left+1, right-1, s);
    }
    
    void reverseString(vector<char>& s) {
        rec(0, s.size()-1, s);
    }
};