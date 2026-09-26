class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;
    Node() { 
        isEnd = false;
         }
};

class trie {
    Node* root;

public:
    trie() {
         root = new Node(); 
     }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {

            if (temp->child.count(key[i]) == 0) {
                temp->child[key[i]] = new Node();
            }

            temp = temp->child[key[i]];
        }

        temp->isEnd = true;
    }

    void search(string key, vector<string>& ans) {
        Node* temp = root;
        string x = "";

        for (int i = 0; i < key.size(); i++) {

            if (temp->child.count(key[i]) == 0) {
                ans.push_back(key);
                return;
            }

            temp = temp->child[key[i]];
            x += key[i];

            if (temp->isEnd == true) {
                ans.push_back(x);
                return;
            }
        }

        ans.push_back(key);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> s;
        sentence += " ";
        string temp = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                s.push_back(temp);
                temp = "";
            } else {
                temp += sentence[i];
            }
        }
        vector<string> ans;

        trie t;
        for (int i = 0; i < dictionary.size(); i++) {
            t.insert(dictionary[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            t.search(s[i], ans);
        }
        string result = "";
        for (int i = 0; i < ans.size(); i++) {
            result += ans[i];

            if (i != ans.size() - 1) {
                result += ' ';
            }
        }
        return result;
    }
};
