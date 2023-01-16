#include <iostream>

using namespace std;
#define SPACE 10

class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode() {
            value = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode(int v) {
            value = v;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
        TreeNode* root;
        BST() {
            root = NULL;
        }

        bool isEmpty() {
            if(root == NULL) {
                return true;
            }
            return false;
        }

        // iterative insertion method
        void insertNode(TreeNode* new_node) {
            if(root == NULL) {
                root = new_node;
                cout << "Value Inserted" << endl;
            }else {
                TreeNode* temp = root;
                while(temp != NULL) {
                    if(new_node->value == temp->value) {
                        cout << "Value Already exists, Insert another value!" << endl;
                        return;
                    }else if ((new_node->value < temp->value) && (temp->left == NULL)) {
                        temp->left = new_node;
                        cout << "Value Inserted" << endl;
                        break;
                    }else if (new_node->value < temp->value) {
                        temp = temp->left;
                    }else if ((new_node->value > temp->value) && (temp->right == NULL)) {
                        temp->right = new_node;
                        cout << "Value Inserted" << endl;
                        break;
                    }else if (new_node->value > temp->value) {
                        temp = temp->right;
                    }
                }
            }
        }
        // recursive insertion method
        TreeNode* insertRecursive(TreeNode* root, TreeNode* new_node) {
            if(root == NULL) {
                root = new_node;
                return root;
            }

            if(new_node->value < root->value) {
                root->left = insertRecursive(root->left, new_node);
            }else if (new_node->value > root->value) {
                root->right = insertRecursive(root->right, new_node);
            } else {
                cout << "No duplicate values is allowed!!! \n";
                return root;
            }

            return root;
        }

        void print2D(TreeNode* root, int space) {
            if(root == NULL) return; // Base case 1
            space += SPACE; // Increase distance between levels 2
            print2D(root->right, space); // Process right child first 3
            cout << endl;
            for (int i = SPACE; i < space; i++) cout << " "; // 5

            cout << root->value << "\n"; // 6
            print2D(root->left, space); // Process left child 7

        }

        void printPreorder(TreeNode* root) // current node, left, right
         {
            if (root == NULL) return;
            
            // First print data of node
            cout << root->value << " ";
            
            // Then recur on the left subtree
            printPreorder(root->left);

            // now recur on the right subtree
            printPreorder(root->right);
        }

        void printInorder(TreeNode* root) // Left, current node, Right
        {
            if (root == NULL) return;

            // First recur on the left child
            printInorder(root->left);

            // then print the data of Node
            cout << root->value << " ";

            // now recur on the right child
            printInorder(root->right);
        }

        void printPostorder(TreeNode* root) // Left, Right, Root
        {
            if (root == NULL) return;

            // First recur on left subtree
            printPostorder(root->left);

            // Then recur on right subtree
            printPostorder(root->right);

            // Now deal with the node
            cout << root -> value << " ";
        }

        TreeNode* iterativeSearch(int value) {
            if (root == NULL) {
                return root;
            }else {
                TreeNode* temp = root;
                while (temp != NULL) {
                    if (value == temp -> value) {
                        return temp;
                    }else if ( value < temp->value) {
                        temp = temp -> left;
                    }else {
                        temp = temp -> right;
                    }
                }
                return NULL;
            }
        }

        TreeNode* recursiveSearch(TreeNode* root, int value) {
            if (root == NULL) return root;
            else if (root->value == value) return root;
            else if (value < root -> value) return recursiveSearch(root->left, value);
            else return recursiveSearch(root->right, value);
        }

        int height(TreeNode* root) {
            if (root == NULL) return -1;
            else{
                // compute the height of each subtree
                int left_height = height(root->left);
                int right_height = height(root->right);

                // use the larger one
                if (left_height > right_height) return left_height + 1;
                else return right_height + 1;
            }
        }

        /* print nodes at a given level */
        void printGivenLevel(TreeNode* root, int level) {
            if (root == NULL) return;
            else if (level == 0) cout << root -> value << " ";
            else // level > 0
            {
                printGivenLevel(root ->left, level -1);
                printGivenLevel(root->right, level-1);
            }
        }

        void printLevelOrderBFS(TreeNode* root) {
            int height = height(root);
            for (int i = 0; i <= height; i++) {
                printGivenLevel(root, i);
            }
        }

        TreeNode* minValueNode(TreeNode* root) {
            TreeNode* current = root;

            /* loop down to find the leftmost leaf */
            while (current->left != NULL) {
                current = current -> left;
            }

            return current;
        }

        TreeNode* deleteNode(TreeNode* root, int value) {
            // base case
            if (root == NULL) {
                return NULL;
            }

            // if the key to be deleted is smaller than the root's key
            // then it lies in the left subtree
            else if (value < root -> value) {
                root->left = deleteNode(root->left, value);
            }

            // if the key to be deleted is greater than the root's key
            // then it lies in the right subtree

            else if (value > root -> value) {
                root -> right = deleteNode(root->right, value);
            }

            // if the key is same as root's key, then this is the node to be deleted
            else {

                // node with only one child or no child
                if (root->left == NULL) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }else if (root->right == NULL) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }else {
                    // node with two children: get the inorder successor
                    // (smallest in the right subtree)

                    TreeNode* temp = minValueNode(root->right);

                    // copy the inorder successor's content to this node
                    root->value = temp->value;

                    // delete the inorder successor
                    root -> right = deleteNode(root->right, temp->value);
                }

                return root;
            }
        }

        // int getBalanceFactor(TreeNode* n) {
        //     if (n == NULL) {
        //         return -1;
        //     }
        //     return (height(n->left) - height(n->right));
        // }

        // void left_left_rotation() {
        //     if (root == NULL) return;
        //     if (root->left) {
        //         root->left->right = root;
        //         root = root->left;
        //     }
        // }

        // void right_right_rotation() {
        //     if(root == NULL) return;
        //     if(root->right) {
        //         root->right->left = root;
        //         root = root->right;
        //     }
        // }
};


int main () {
    BST obj;
    int option, val;
    
    do {
        cout << "What operation do you want to perform? \n"
            << "select Option number. Enter 0 to exit. \n";

        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit program" << endl;

        cin >> option;
        TreeNode* new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT \n";
            cout << "Enter Value of Tree node to Insert in BST: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insertRecursive(obj.root, new_node);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH \n";
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            system("clear");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
            break;
        }
    } while(option != 0);

    return 0;
}
