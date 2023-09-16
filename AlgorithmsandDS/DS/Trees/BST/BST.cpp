#ifndef __BSTIMPL__
#define __BSTIMPL__

#include <iostream>
#include <algorithm>

#include "BST.h"

// Node Implementation

template <typename X>
MYDS::BST<X>::TreeNode::TreeNode() : right(nullptr), left(nullptr) {}

template <typename X>
MYDS::BST<X>::TreeNode::TreeNode(const X &val) : data(val), right(nullptr), left(nullptr) {}

template <typename X>
MYDS::BST<X>::TreeNode::TreeNode(const X &val, TreeNode *RightChild, TreeNode *LeftChild) : data(val), right(RightChild), left(LeftChild) {}

template <typename X>
bool MYDS::BST<X>::TreeNode::isLeaf() const { return !right && !left; }

// BST Ctor Dtors

template <typename X>
MYDS::BST<X>::BST() : m_root(nullptr) {}

template <typename X>
MYDS::BST<X>::BST(const X &rootitem) { m_root = new TreeNode(rootitem); }

template <typename X>
MYDS::BST<X>::BST(const X &rootitem, BST *RightTree, BST *LeftTree) { m_root = new TreeNode(rootitem, RightTree->m_root, LeftTree->m_root); }

template <typename X>
MYDS::BST<X>::BST(const BST &other) { m_root = copyTree(other.m_root); }

template <typename X>
MYDS::BST<X>::~BST()
{
    if (m_root)
    {
        destroyTree(m_root);
    }
}

// Binary Tree INterface Functions

template <typename X>
bool MYDS::BST<X>::isEmpty() const { return !m_root; }

template <typename X>
int MYDS::BST<X>::getHeight() const { return getHeightHelper(m_root); }

template <typename X>
int MYDS::BST<X>::getNumberOfNodes() const { return getNumberHelper(m_root); }

template <typename X>
X MYDS::BST<X>::getRootData() const { return m_root->data; }

template <typename X>
void MYDS::BST<X>::setRootData(const X &val) {}

template <typename X>
bool MYDS::BST<X>::add(const X &val)
{
    TreeNode *newnode = new TreeNode(val);
    m_root = balancedAdd(m_root, newnode);
    return true;
}

template <typename X>
bool MYDS::BST<X>::remove(const X &val)
{
    bool success = 0;
    //   std::cout << "Remove " << val << " from rooted tree : " << m_root->data << std::endl;
    m_root = removeValue(m_root, val, success);
    return success;
}

template <typename X>
bool MYDS::BST<X>::contains(const X &val) const
{
    bool success = 0;
    TreeNode *tmp = find(m_root, val, success);
    return success;
}
// Traversals

template <typename X>
void MYDS::BST<X>::postorderTraverse(void visit(X &))
{
    postorder(visit, m_root);
}

template <typename X>
void MYDS::BST<X>::inorderTraverse(void visit(X &))
{
    inorder(visit, m_root);
}

template <typename X>
void MYDS::BST<X>::preorderTraverse(void visit(X &))
{
    preorder(visit, m_root);
}

template <typename X>
void MYDS::BST<X>::levelOrderTraversal(void visit(X &)) {}

// End of Traversals

template <typename X>
void MYDS::BST<X>::clear() { destroyTree(m_root); }

// Operator overloadings

template <typename X>
MYDS::BST<X> &MYDS::BST<X>::operator=(const BST<X> &other)
{
    if (other.m_root == m_root)
    {
        return *this;
    }
    m_root = copyTree(other.m_root);
    return *this;
}

// Internal Helper functions

template <class X>
int MYDS::BST<X>::getHeightHelper(TreeNode *root) const
{
    if (!root)
    {
        return -1;
    }
    else
    {
        int leftHeight = getHeightHelper(root->left);
        int rightHeight = getHeightHelper(root->right);

        return 1 + std::max(leftHeight, rightHeight);
    }
}

template <typename X>
int MYDS::BST<X>::getNumberHelper(TreeNode *root) const
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return 1 + getNumberHelper(root->right) + getNumberHelper(root->left);
    }
}

template <typename X>
void MYDS::BST<X>::destroyTree(TreeNode *&root)
{
    if (root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = nullptr; // Set the pointer to null to avoid any dangling references
    };
}

template <typename X>
typename MYDS::BST<X>::TreeNode *MYDS::BST<X>::balancedAdd(TreeNode *root, TreeNode *newNode)
{
    if (!root)
    {
        root = newNode;
    }
    if (newNode->data > root->data)
    {
        root->right = balancedAdd(root->right, newNode);
    }
    if (newNode->data < root->data)
    {
        root->left = balancedAdd(root->left, newNode);
    }
    return root;
}

template <typename X>
typename MYDS::BST<X>::TreeNode *MYDS::BST<X>::removeValue(TreeNode *root, const X val, bool &success)
{
    if (!root)
    {
        success = false; // Value not found
        return nullptr;
    }

    if (val < root->data)
    {
        root->left = removeValue(root->left, val, success);
    }
    else if (val > root->data)
    {
        root->right = removeValue(root->right, val, success);
    }
    else
    {
        // Value found
        std::cout << "Value is found in remove" << std::endl;
        success = true;

        if (root->isLeaf())
        {
            std::cout << "leaf" << std::endl;
            // Case 1: Node is a leaf
            delete root;
            root = nullptr; // Set the pointer to null
        }
        else if (!root->left)
        {
            // Case 2: Node has only a right child
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            // Case 3: Node has only a left child
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            // Case 4: Node has two children
            std::cout << "Swap with min data" << std::endl;
            TreeNode *minValueNode = nullptr;
            if (root && root->right)
            {
                minValueNode = getMinValueNode(root->right);
            }
            if (minValueNode)
            {
                std::cout << minValueNode->data << "Min Val node Data" << std::endl;
                root->data = minValueNode->data;
            }
            else
            {

                std::cout << "Min val node is null" << std::endl;
            }
            root->right = removeValue(root->right, minValueNode->data, success);
        }
    }

    return root;
}

template <typename X>
typename MYDS::BST<X>::TreeNode *MYDS::BST<X>::find(TreeNode *root, const X val, bool &success) const
{
    if (!root)
    {
        success = 0;
        return nullptr;
    }
    if (root->data == val)
    {
        success = 1;
        return root;
    }
    TreeNode *neededNode = find(root->left, val, success);
    if (neededNode)
    {
        success = 1;
        return neededNode;
    }
    neededNode = find(root->right, val, success);
    return neededNode;
}

template <typename X>
typename MYDS::BST<X>::TreeNode *MYDS::BST<X>::copyTree(TreeNode *root)
{
    if (root)
    {
        TreeNode *newroot = new TreeNode(root->data, root->left, root->right);
        newroot->left = copyTree(newroot->left);
        newroot->right = copyTree(newroot->right);
        return newroot;
    }
    else
    {
        return root;
    }
}

template <typename X>
typename MYDS::BST<X>::TreeNode *MYDS::BST<X>::getMinValueNode(TreeNode *root)
{
    TreeNode *node = root;
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

template <typename X>
void MYDS::BST<X>::preorder(void visit(X &), TreeNode *root)
{
    if (root)
    {
        visit(root->data);
        preorder(visit, root->left);
        preorder(visit, root->right);
    }
}

template <typename X>
void MYDS::BST<X>::inorder(void visit(X &), TreeNode *root)
{
    if (root)
    {
        inorder(visit, root->left);
        visit(root->data);
        inorder(visit, root->right);
    }
}

template <typename X>
void MYDS::BST<X>::postorder(void visit(X &), TreeNode *root)
{
    if (root)
    {
        postorder(visit, root->left);
        postorder(visit, root->right);
        visit(root->data);
    }
}
template <typename X>
void MYDS::BST<X>::inorderPrinthelper(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inorderPrinthelper(root->left);
        std::cout << root->data << std::endl;
        inorderPrinthelper(root->right);
    }
}

template <typename X>
void MYDS::BST<X>::printInorder()
{
    inorderPrinthelper(m_root);
}
#endif // End Of BST.cpp