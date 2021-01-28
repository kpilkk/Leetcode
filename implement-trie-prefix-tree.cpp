// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    Trie *children[26];
    bool isWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        this -> isWord = false;
        for(int i = 0; i < 26; ++i)
            this -> children[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(int i = 0; i < word.length(); ++i){
            int index = word[i] - 'a';
            if(root -> children[index] == NULL)
                root -> children[index] = new Trie();
            root = root -> children[index];
        }
        root -> isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(this == NULL)
            return false;
        Trie *root = this;
        for(int i = 0; i < word.length(); ++i){
            int index = word[i] - 'a';
            if(root -> children[index] == NULL)
                return false;
            root = root -> children[index];
            //else return false;
        }
        return root -> isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(this == NULL)
            return false;
        Trie *root = this;
        for(int i = 0; i < prefix.length(); ++i){
            int index = prefix[i] - 'a';
            if(root -> children[index] == NULL)
                return false;
            root = root -> children[index];
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
