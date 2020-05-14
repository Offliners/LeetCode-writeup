#define ALPHABET 26

typedef struct {
    void *child[ALPHABET];
    int leaf;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *root = calloc(1, sizeof(Trie));
    
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node;
    
    while(*word)
    {
        node = obj->child[*word - 'a'];
        
        if(!node)
        {
            node = calloc(1, sizeof(Trie));
            obj->child[*word - 'a'] = node;
        }
        
        obj = node;
        word++;
    }
    
    obj->leaf = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    
    while(*word)
    {
        node = node->child[*word - 'a'];
        if(!node) 
            return false;
        
        word++;
    }
    
    return node->leaf ? true : false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    
    while(*prefix)
    {
        node = node->child[*prefix - 'a'];
        if(!node)
            return false;
        
        prefix++;
    }
    
    return true;
}

void trieFree(Trie* obj) {
    Trie *node;

    for(int i = 0; i < ALPHABET; i++) {
        node = obj->child[i];
        
        if(node) 
            trieFree(node);
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
