class Trie {
public:
    /** Initialize your data structure here. */
    typedef struct _node {
        bool isEnd;
        struct _node* children[26];
    } Node;
    Node* root;
    
    Trie() {
        root = get_node();
    }
    
    Node* get_node() {
        Node* node = new Node();
        node->isEnd = false;
        for (int i=0 ; i<26 ; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* ptr = root;
        for (int i=0 ; i<word.length() ; ++i) {
            char c = word[i];
            int idx = c - 'a';
            if (!ptr->children[idx])
                ptr->children[idx] = get_node();
            ptr = ptr->children[idx];
        }
        ptr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* ptr = root;
        for (int i=0 ; i<word.length() ; ++i) {
            int idx = word[i] - 'a';
            if (!ptr->children[idx]) return false;
            ptr = ptr->children[idx];
        }
        return ptr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* ptr = root;
        for (int i=0 ; i<prefix.length() ; ++i) {
            int idx = prefix[i] - 'a';
            if (!ptr->children[idx]) return false;
            ptr = ptr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */