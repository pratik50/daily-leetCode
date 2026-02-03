/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

int countNodes(Node* root){
    
    if(root == NULL)
        return 0;
    
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int count){
    
    if(root == NULL)    
        return true;
        
    if(index >= count)
        return false;

    bool left = isCBT(root->left, 2*index+1, count);
    bool right = isCBT(root->right, 2*index+2, count);
    return (left && right);
}


bool isMaxHeap(Node* root){
    
    if (root == NULL)
        return true;
        
    if(root->left == NULL && root->right == NULL)   
        return true;
    
    if(root->right == NULL)
        return (root->data > root->left->data);

    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
        
    return (left && right && 
            root->data > root->left->data && 
            root->data > root->right->data);
    
}

class Solution {
  public:
    bool isHeap(Node* root) {
        // code here
        
        int count = countNodes(root);
        int index = 0;
        
        if(isCBT(root, index, count) && isMaxHeap(root) )
            return true;
        
        return false;
    }
};


// Step 1: Tree me total number of nodes count karo
// Step 2: Check karo tree Complete Binary Tree hai ya nahi (index method se)
// Step 3: Check karo Max Heap property follow ho rahi hai ya nahi
//         (parent ka data children se bada hona chahiye)
// Step 4: Agar dono condition true ho to tree Heap hai,
//         warna Heap nahi hai