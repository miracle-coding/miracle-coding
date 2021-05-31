class Solution {
public:
    typedef struct _node {
        char c;
        bool is_end;
        struct _node* children[26];
    } Node;
    
    Solution() {
        root = get_node('\0');
    }
    
    ~Solution() {
        for (int i=0 ; i<26 ; ++i)
            if (root->children[i]) delete root->children[i];
        delete root;
    }

    Node* get_node(char c) {
        Node* node = new Node();
        node->c = c;
        node->is_end = false;
        for (int i=0 ; i<26 ; ++i) node->children[i] = nullptr;
        return node;
    }
     
    void insert(string& word, string& ans) {
        Node* node = root;
        for (int i=0 ; i<word.length() ; ++i) {
            char c = word[i];
            int idx = c - 'a';
            if (!node->children[idx]) {
                if (node != root && !node->is_end) return;
                node->children[idx] = get_node(c);
            }
            node = node->children[idx];
        }
        node->is_end = true;
        if (word.length() > ans.length())
            ans = word;
        else if (word.length() == ans.length())
            ans = min(ans, word);
    }
    
    string longestWord(vector<string>& words) {
        string ans = "";
        sort(words.begin(), words.end());
        
        for (auto& word : words)
            insert(word, ans);
        
        return ans;
    }

    Node* root;
};