// https://leetcode.com/problems/implement-trie-prefix-tree/

#define ALPHA_SIZE 26
typedef struct trieNode {
    struct trieNode *children[26];
    bool isWord;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* obj = (Trie *)malloc(sizeof(Trie));
    for(int i = 0; i < ALPHA_SIZE; ++i)
        obj -> children[i] = NULL;
    obj -> isWord = false;
    return obj;
    //return calloc(1, sizeof(Trie));
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    if(obj == NULL)
        obj = trieCreate();
    
    while(*word){
        if(obj -> children[*word - 'a'] == NULL)
            obj -> children[*word - 'a'] = trieCreate();
        obj = obj -> children[*word - 'a'];
        word++;
    }
    obj -> isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    if(obj == NULL)
        return false;
    
    while(*word){
        if(!obj -> children[*word - 'a'])
            return false;
        obj = obj -> children[*word - 'a'];
        ++word;
    }
    return obj -> isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    if(obj == NULL)
        return false;
    
    while(*prefix){
        if(obj -> children[*prefix - 'a'] == NULL)
            return false;
        obj = obj -> children[*prefix - 'a'];
        ++prefix;
    }
    return true;
}

void trieFree(Trie* obj) {
    for(int i = 0; i < 26; ++i)
        if(obj -> children[i]){
            trieFree(obj -> children[i]);
            obj -> children[i] = NULL;
        }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
