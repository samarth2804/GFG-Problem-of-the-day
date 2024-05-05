// Vertical sum
// Problem Link: https://www.geeksforgeeks.org/problems/vertical-sum/1

void verticalSumUtil(Node *node, int hd, 
                        map<int, int> &Map) 
{ 
    // Base case 
    if (node == NULL) return; 
    
    // Recur for left subtree 
    verticalSumUtil(node->left, hd-1, Map); 
    
    // Add val of current node to 
    // map entry of corresponding hd 
    Map[hd] += node->data; 
    
    // Recur for right subtree 
    verticalSumUtil(node->right, hd+1, Map); 
} 
// Function to find vertical sum 
vector<int> verticalSum(Node *root) 
{ 
    vector <int> res;
    // a map to store sum of nodes for each  
    // horizontal distance 
    map < int, int> Map; 
    map < int, int> :: iterator it; 
    
    // populate the map 
    verticalSumUtil(root, 0, Map); 
    
    // Prints the values stored by VerticalSumUtil() 
    for (it = Map.begin(); it != Map.end(); ++it) 
    { 
        res.push_back (it->second);
    } 
    return res;
} 