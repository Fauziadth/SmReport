Node * insert(Node * root, int data) {
        if(root==NULL){
            Node* tmp = (Node*)malloc(sizeof(Node)); //Allocation when we reach NULL / make a new node for the data
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
        } else if(root->data > data) {
            root->left = insert(root->left, data); //Recursion put it into the left node
        }else if(root->data < data){
            root->right = insert(root->right, data); //Recursion put it into the right node
        }

        return root;
    }