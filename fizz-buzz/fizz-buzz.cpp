class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        
        for (int i=1 ; i<=n ; ++i) {
            if (0 == i % 15) v.emplace_back("FizzBuzz");
            else if (0 == i % 3) v.emplace_back("Fizz");
            else if (0 == i % 5) v.emplace_back("Buzz");
            else v.emplace_back(to_string(i));
        }

        return v;
    }
};