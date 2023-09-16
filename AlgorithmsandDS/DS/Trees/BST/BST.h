#ifndef __BST__
#define __BST__

#include <iostream>

#include "/home/gag/AlgorithmsAndDS/DS/Trees/BinaryTree/BInaryTreeInterface.h"

namespace MYDS
{
    template <class X>
    class BST : BinaryTreeInterface<X>
    {
    public:
        // Ctor Dtor
        BST();
        BST(const X &rootItem);
        BST(const X &rootItem, BST *RightSubTree, BST *LeftSubTree);
        BST(const BST &other);
        virtual ~BST();

        // Inteface Functions
        bool isEmpty() const override;
        int getHeight() const override;
        int getNumberOfNodes() const override;
        X getRootData() const override;
        void setRootData(const X &item) override;
        bool add(const X &item) override;
        bool remove(const X &item) override;
        bool contains(const X &item) const override;
        void preorderTraverse(void visit(X &)) override;
        void inorderTraverse(void visit(X &)) override;
        void postorderTraverse(void visit(X &)) override;
        void clear() override;
        // End of Interface

        void printInorder();
        // Level Order Traversal

        virtual void levelOrderTraversal(void visit(X &));
        // Operator Overloadings
        BST &operator=(const BST &other);

    protected:
        // Node class
        struct TreeNode
        {
            // Member Data
            X data;
            TreeNode *left;
            TreeNode *right;
            // Ctor
            TreeNode();
            TreeNode(const X &item);
            TreeNode(const X &item, TreeNode *LeftChild, TreeNode *RightChild);
            // Other Functions
            bool isLeaf() const;
        };
        // Helper Functions
        int getHeightHelper(TreeNode *tree) const;
        int getNumberHelper(TreeNode *tree) const;
        void destroyTree(TreeNode *&tree);
        TreeNode *balancedAdd(TreeNode *tree, TreeNode *newNode);
        TreeNode *removeValue(TreeNode *tree, const X item, bool &success);
        TreeNode *find(TreeNode *tree, const X item, bool &success) const;
        TreeNode *copyTree(TreeNode *tree);
        TreeNode *getMinValueNode(TreeNode *tree);
        void preorder(void visit(X &), TreeNode *tree);
        void postorder(void visit(X &), TreeNode *tree);
        void inorder(void visit(X &), TreeNode *tree);
        void inorderPrinthelper(TreeNode* root);

    private:
        int m_elements_count;
        TreeNode *m_root;
    };
}

#include "BST.cpp"

#endif // End of BST header
