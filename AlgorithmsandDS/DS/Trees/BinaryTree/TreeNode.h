#ifndef __TreeNode__
#define __TreeNode__
#include <iostream>
template <class X>
class TreeNode {
    private:
        X data;
        TreeNode<X> *left;
        TreeNode<X> *right;
    public:
        TreeNode<X>();
        TreeNode<X>(const X& item);
        TreeNode<X>(const X& item, TreeNode* LeftChild, TreeNode* RightChild);
        void setData(const X& item);
        void setLeft(TreeNode* LeftChild);
        void setRight(TreeNode* RightChild);
        X getData() const;
        TreeNode* getRight() const;
        TreeNode* getLeft() const;
        bool isLeaf() const;
};
#include "TreeNode.cpp"
#endif
