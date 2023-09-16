#ifndef __Binary_Node_Tree__
#define __Binary_Node_Tree__
#include "BInaryTreeInterface.h"
#include "TreeNode.h"
template <class X>
class BinaryTree : public BinaryTreeInterface<X> {
    private:
        TreeNode<X> *root;
    protected:
        int getHeightHelper(TreeNode<X>* tree);
        int getNumberHelper(TreeNode<X>* tree);
        void destroyTree(TreeNode<X>* tree);
        TreeNode<X>* balancedAdd(TreeNode<X>* tree, TreeNode<X>* newNode);
        TreeNode<X>* removeValue(TreeNode<X>* tree, const X item, bool& success);
        TreeNode<X>* find(TreeNode<X>* tree, const X item, bool& success);
        TreeNode<X>* copyTree(TreeNode<X>* tree);
        void preorder(void visit(X&), TreeNode<X>* tree);
        void postorder(void visit(X&), TreeNode<X>* tree);
        void inorder(void visit(X&), TreeNode<X>* tree);
    public:
        BinaryTree();
        BinaryTree(const X& rootItem);
        BinaryTree(const X& rootItem, BinaryTree* RightSubTree, BinaryTree* LeftSubTree);
        BinaryTree(const BinaryTree& other);
        virtual ~BinaryTree();
        // Inteface Functions
        bool isEmpty() const override;
        int getHeight() const override;
        int getNumberOfNodes() const override;
        X getRootData() const override;
        void setRootData(const X& item) override;
        bool add(const X& item) override;
        bool remove(const X& item) override;
        bool contains(const X& item) override;
        void preorderTraverse(void visit(X&)) override;
        void inorderTraverse(void visit(X&)) override;
        void postorderTraverse(void visit(X&)) override;
        void clear() override;
        // Operator Overloadings
        BinaryTree& operator=(const BinaryTree& other);
};
#include "BInaryNodeTree.cpp"
#endif
