/*
The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {  //The function in main body
		return check(root, -1, 10001); //Because constraint 0<data<10^4
	}

    bool check(Node* nod, int datamin, int datamax){ //function helper
        if (nod == NULL) return true;
        if ((nod->data <= datamin) || (nod->data >= datamax)) return false;
        return (check(nod->left, datamin, nod->data) && check(nod->right, nod->data, datamax));
    }