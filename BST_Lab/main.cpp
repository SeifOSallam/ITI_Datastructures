#include <iostream>

using namespace std;

struct Node {
    Node* leftNode;
    Node* rightNode;
    int value;
    Node() {
        leftNode = NULL;
        rightNode = NULL;
    }
    Node(int val) {
        value = val;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class BST {

public:
    Node* root;
    BST() {
        root = NULL;
    }
    void insertNode(int val) {
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* currNode = root;
            while (true) {
                if (currNode->value > newNode->value) {
                    if (currNode->leftNode == NULL) {
                        currNode->leftNode = newNode;
                        break;
                    }
                    else {
                        currNode = currNode->leftNode;
                    }
                }
                else {
                    if (currNode->rightNode == NULL) {
                        currNode->rightNode = newNode;
                        break;
                    }
                    else {
                        currNode = currNode->rightNode;
                    }
                }
            }
        }
    }

    Node* getParent(int val) {
        Node* currNode = root;
        while (currNode != NULL) {
            if (currNode->leftNode != NULL) {
                if (currNode->leftNode->value == val) {
                    return currNode;
                }
            }
            if (currNode->rightNode != NULL) {
                if (currNode->rightNode->value == val) {
                    return currNode;
                }
            }
            if (currNode->value > val) {
                currNode = currNode->leftNode;
            }
            else currNode = currNode->rightNode;
        }
        return NULL;
    }

    int countNodes(Node* node) {
        if (node != NULL) {
            return 1+countNodes(node->leftNode)+countNodes(node->rightNode);
        }
    }

    void printTree() {
        cout<<"InOrder: ";inOrder(root);cout<<endl;
        cout<<"PreOrder: ";preOrder(root);cout<<endl;
        cout<<"PostOrder: ";postOrder(root);cout<<endl;
    }

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->leftNode);
            cout<<node->value<<" ";
            inOrder(node->rightNode);
        }
    }

    void preOrder(Node* node) {
        if (node != NULL) {
            cout<<node->value<<" ";
            preOrder(node->leftNode);
            preOrder(node->rightNode);
        }
    }

    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->leftNode);
            postOrder(node->rightNode);
            cout<<node->value<<" ";
        }
    }

    void deleteNode(int val) {
        root = bstDelete(root, val);
    }
    Node* bstDelete(Node* node, int val) {
        if (node == NULL) {
            return node;
        }
        if (node->value > val) {
            node->leftNode = bstDelete(node->leftNode, val);
            return node;
        }
        if (node->value < val) {
            node->rightNode = bstDelete(node->rightNode, val);
            return node;
        }

        if (node->leftNode == NULL) {
            Node* temp = node->rightNode;
            delete node;
            return temp;
        }
        else if (node->rightNode == NULL) {
            Node* temp = node->leftNode;
            delete node;
            return temp;
        }
        else {
            Node* succParent = node;

            // Find successor
            Node* succ = root->rightNode;
            while (succ->leftNode != NULL) {
                succParent = succ;
                succ = succ->leftNode;
            }
            if (succParent != node)
                succParent->leftNode = succ->rightNode;
            else
                succParent->rightNode = succ->rightNode;

            // Copy Successor Data to root
            node->value = succ->value;

            // Delete Successor and return root
            delete succ;
            return node;
        }

    }

};

int main()
{
    BST myBST;
    myBST.insertNode(3);
    myBST.insertNode(6);
    myBST.insertNode(10);
    myBST.insertNode(7);
    myBST.insertNode(8);
    myBST.insertNode(11);
    myBST.insertNode(15);
    myBST.printTree();
    Node* pNode = myBST.getParent(11);
    if (pNode == NULL) {
        cout<<"This node has no parent (Might be root or not exist)!"<<endl;
    }
    else {
        cout<<"Parent of node is "<<pNode->value<<endl;
    }
    cout<<"Number of nodes in root = "<<myBST.countNodes(myBST.root)<<endl;
    cout<<"Deleted Node 7"<<endl;
    myBST.deleteNode(7);
    cout<<endl<<endl<<"After deletion:"<<endl;
    myBST.printTree();
}
