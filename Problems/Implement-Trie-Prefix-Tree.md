# Implement Trie (Prefix Tree)
Implement a trie with `insert`, `search`, and `startsWith` methods.

#### Example
```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```

### Python 3
```python
class TrieNode(object):
    def __init__(self):
        self.child = {}
        self.flag = False

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        self.root.flag = True
        
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        
        for i in word:
            if i not in node.child:
                node.child[i] = TrieNode()
            
            node = node.child[i]
        
        node.flag = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        
        for i in word:
            if i in node.child:
                node = node.child[i]
            else:
                return False
            
        return node.flag
    
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        
        for i in prefix:
            if i in node.child:
                node = node.child[i]
            else:
                return False
        
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
[code](Python%203/208.py)

#### Result
```
Runtime: 176 ms, faster than 75.28% of Python3 online submissions for Implement Trie (Prefix Tree).
Memory Usage: 31.2 MB, less than 11.11% of Python3 online submissions for Implement Trie (Prefix Tree).
```

### C
```C
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
```
[code](C/208.c)

#### Result
```
Runtime: 60 ms, faster than 66.33% of C online submissions for Implement Trie (Prefix Tree).
Memory Usage: 38.4 MB, less than 100.00% of C online submissions for Implement Trie (Prefix Tree).
```
