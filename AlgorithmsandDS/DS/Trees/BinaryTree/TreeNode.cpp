#ifndef __Implementation_Tree_Node__
#define __Implementation_Tree_Node__
#include "TreeNode.h"
template <class X>
TreeNode<X>::TreeNode() : data {NULL}, left {nullptr}, right {nullptr} {}
template <class X>
TreeNode<X>::TreeNode(const X& item) : data {item}, left {nullptr}, right {nullptr} {}
template <class X>
TreeNode<X>::TreeNode(const X& item, TreeNode* LeftChild, TreeNode* RightChild) : data {item},
left {LeftChild}, right {RightChild} {}
template <class X>
void TreeNode<X>::setData(const X& item) { data = item; }
template <class X>
void TreeNode<X>::setLeft(TreeNode* LeftChild) { left = LeftChild; }
template <class X>
void TreeNode<X>::setRight(TreeNode* RightChild) { right = RightChild; }
template <class X>
X TreeNode<X>::getData() const { return data; }
template <class X>
TreeNode<X>* TreeNode<X>::getLeft() const { return left; }
template <class X>
TreeNode<X>* TreeNode<X>::getRight() const { return right; }
template <class X>
bool TreeNode<X>::isLeaf() const { return !left && !right; }
#endif
