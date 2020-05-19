class Trie {
    struct TrieNode
    {
        TrieNode* links[26];
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            for(int i = 0 ; i < 26 ; i++)
            {
                links[i] = NULL;
            }
        }
    };
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            if(curr->links[word[i]-'a'] == NULL)
            {
                curr->links[word[i]-'a'] = new TrieNode();
            }
            curr = curr->links[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            if(curr->links[word[i]-'a'] != NULL)
            {
                curr = curr->links[word[i]-'a'];
            }
            else
            {
                return NULL;
            }
        }
        return (curr != NULL) && curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0 ; i < prefix.size(); i++)
        {
            if(curr->links[prefix[i]-'a'] != NULL)
            {
                curr = curr->links[prefix[i]-'a'];
            }
            else
            {
                return NULL;
            }
            
        }
        return curr != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
