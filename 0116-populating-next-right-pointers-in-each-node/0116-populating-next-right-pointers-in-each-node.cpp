class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            vector<Node*> level;
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                level.push_back(curr);

                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            for (int i = 0; i < level.size() - 1; i++) {
                level[i]->next = level[i + 1];
            }
            level[level.size() - 1]->next = NULL;
        }

        return root;
    }
};
