class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len < 2) return;
        int left = 0, right = len-1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};