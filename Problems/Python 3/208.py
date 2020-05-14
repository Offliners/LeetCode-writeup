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
