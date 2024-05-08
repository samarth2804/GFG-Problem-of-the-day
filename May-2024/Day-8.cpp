// Root to Leaf Paths
// Problem Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

vector<int> printArray(int ints[], int len)
{
    vector<int> path;
    for (int i=0; i<len; i++) {
        path.push_back(ints[i]);
    }
    return path;
}

// Utility function to print all paths from root to leaf nodes
void printPathsUtil(struct Node* node, int path[], int len, vector<vector<int>> &paths)
{
    // If node is NULL, return
    if (node==NULL)return;
    
    // Add current node's data to the path
    path[len] = node->data;
    len++;
    
    // If node is leaf node, add path to paths vector
    if (node->left==NULL && node->right==NULL) {
        paths.push_back(printArray(path, len));
    }
    else {
        // Recursively call printPathsUtil for left and right child
        printPathsUtil(node->left, path, len, paths);
        printPathsUtil(node->right, path, len, paths);
    }
}

// Main function to find all paths from root to leaf nodes
vector<vector<int>> Paths(struct Node* root)
{
    int path[200005];
    
    // Create an empty vector to store all paths
    vector<vector<int>> paths;
    
    // Call the utility function to find paths from root to leaf nodes
    printPathsUtil(root, path, 0, paths);
    
    // Return all the paths
    return paths;
}