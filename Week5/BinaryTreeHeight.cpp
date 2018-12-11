int height(Node* root) {
        //don't have children
        if (root == NULL) return -1;

        int left, right;

        //calculating from both side children
        left = 1 + height(root->left);
        right = 1 + height(root->right);

        //comparing to take the highest
        if (left>right) {
            return left;
        } else {
            return right;
        }

    }