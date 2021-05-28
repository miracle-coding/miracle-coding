class Trie {
public:
    /** Initialize your data structure here. */
    typedef struct _node {
        char c;
        bool end_word;
        struct _node* children[26];
    } Node;
    
    Node* root;
    Node* get_node(char c) {
        Node* node = new Node();
        node->c = c;
        node->end_word = false;
        for (int i=0 ; i<26 ; ++i) node->children[i] = nullptr;
        return node;
    }
    Trie() {
        root = get_node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (int i=0 ; i<word.length() ; ++i) {
            char c = word[i];
            if (!node->children[c-'a']) {
                node->children[c-'a'] = get_node(c);
            }
            node = node->children[c-'a'];
        }
        node->end_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for (int i=0 ; i<word.length() ; ++i) {
            char c = word[i];
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
        }
        return node->end_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i=0 ; i<prefix.length() ; ++i) {
            char c = prefix[i];
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
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