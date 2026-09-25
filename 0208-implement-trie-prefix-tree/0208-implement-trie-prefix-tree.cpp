class Node{
    public:
    unordered_map<char , Node*> child;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
      root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
       for(int i = 0; i < word.size(); i++){
        if(temp->child.count(word[i]) == 0){
          temp->child[word[i]] = new Node();
        }
          temp = temp->child[word[i]];
       } 
          temp->endOfWord = true;

    }
    
    bool search(string word) {
     Node* temp = root;
     for(int i = 0; i < word.size(); i++){
      if(temp->child.count(word[i])){
        temp = temp->child[word[i]];
      }else{
        return false;
      }
    } 
    return temp->endOfWord;
    }
     bool startsWith(string prefix) {
         Node* temp = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(temp->child.count(prefix[i]) == 0) {
                return false;
            }

            temp = temp->child[prefix[i]];
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