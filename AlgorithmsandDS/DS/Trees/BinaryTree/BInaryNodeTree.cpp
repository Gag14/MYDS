#ifndef __BinaryNodeTreeImplementation__
#define __BinaryNodeTreeImplementation__
#include <algorithm>
#include "BInaryNodeTree.h"
#include "BInaryTreeInterface.h"
#include "TreeNode.h"
// Constructors
template <class X>
BinaryTree<X>::BinaryTree() : root {nullptr} {}
template <class X>
BinaryTree<X>::BinaryTree(const X& rootItem) {
    root = new TreeNode<X>(rootItem);
}
template <class X>
BinaryTree<X>::BinaryTree(const X& rootItem, BinaryTree* RightSubTree, BinaryTree* LeftSubTree){
    root = new TreeNode<X>(rootItem, copyTree(LeftSubTree->root), copyTree(RightSubTree->root));
}
template <class X>
BinaryTree<X>::BinaryTree(const BinaryTree& other) {
    root = copyTree(other.root);
}
// Destructor
template <class X>
BinaryTree<X>::~BinaryTree(){
    destroyTree(root);
}
// Helper Protected Methods
template <class X>
int BinaryTree<X>::getHeightHelper(TreeNode<X>* tree) {
    if(!tree)  { return 0; }
    return 1 + max(getHeightHelper(tree->getLeft), getHeightHelper(tree->getRight));
}
template <class X>
int BinaryTree<X>::getNumberHelper(TreeNode<X>* tree) {
    if(!tree) { return 0; }
    return 1 + getNumberHelper(tree->getLeft()) + getNumberHelper(tree->getRight());
}
template <class X>
void BinaryTree<X>::destroyTree(TreeNode<X>* tree) {
    if(tree) {
        destroyTree(tree->getLeft());
        destroyTree(tree->getRight());
        delete tree;
    }    
}
template <class X>
TreeNode<X>* BinaryTree<X>::copyTree(TreeNode<X>* tree) {
    TreeNode<X>* newTree = nullptr;
    if(tree) {
        newTree = new TreeNode<X>(tree->getData());
        newTree->setLeft(copyTree(tree->getLeft()));
        newTree->setRight(copyTree(tree->getRight())); 
    }
    return newTree;
}
template <class X>
TreeNode<X>* BinaryTree<X>::balancedAdd(TreeNode<X>* tree, TreeNode<X>* newNode) {
    if(!tree) { return newNode; }
    TreeNode<X>* leftTree = tree->getLeft();
    TreeNode<X>* rightTree = tree->getRight();
    if(getHeightHelper(leftTree) < getHeightHelper(rightTree)) {
        leftTree = balancedAdd(leftTree);
        tree->setLeft(leftTree);
    }
    else {
        rightTree = balancedAdd(rightTree);
        tree->setRight(rightTree);
    }
    return tree;
}
template <class X>
TreeNode<X>* BinaryTree<X>::find(TreeNode<X>* tree, const X item, bool& success) {
    if(!tree) { success = 0; return nullptr; }
    if(item == tree->getData()) { success = 1; return tree; }
    TreeNode<X>* neededNode = find(tree->getLeft(), item, success);
    if(neededNode) { return neededNode; }
    neededNode = find(tree->getRight(), item, success);
    return neededNode;
}
template <class X>
TreeNode<X>* BinaryTree<X>::removeValue(TreeNode<X>* tree, const X item, bool& success) {
    TreeNode<X>* needed = find(tree, item, success);
    if(!needed) { success = 0; return tree; }
    if(needed->isLeaf()) { success = 1; delete needed; needed = nullptr; std::cout<<"Is Leaf\n"; return tree; }
    if(!needed->getRight()) {
        TreeNode<X>* leftchild = needed->getLeft();
        needed->setData(leftchild->getData());
        needed->setLeft(leftchild->getLeft());
        needed->setRight(leftchild->getRight());
        delete leftchild;
        leftchild = nullptr;
        success = 1;
    }
    if(!needed->getLeft()){
        TreeNode<X>* rightchild = needed->getRight();
        needed->setData(rightchild->getData());
        needed->setLeft(rightchild->getLeft());
        needed->setRight(rightchild->getRight());
        delete rightchild;
        rightchild = nullptr;
        success = 1;
    }
    TreeNode<X>* leftchild = needed->getLeft();
    needed->setData(leftchild->getData());
    leftchild->setData(item);
    return removeValue(leftchild, item, success);
}
template <class X>
BinaryTree<X>& BinaryTree<X>::operator=(const BinaryTree<X>& other){
    return BinaryTree(other);    
}
// Travers helpers
template <class X>
void BinaryTree<X>::preorder(void visit(X& item), TreeNode<X>* tree) {
    if(tree) {
        visit(tree->getData());
        preorder(visit, tree->getLeft());
        preorder(visit, tree->getRight());
    }
}
template <class X>
void BinaryTree<X>::postorder(void visit(X& item), TreeNode<X>* tree) {
    if(tree) {
        postorder(visit, tree->getLeft());
        postorder(visit, tree->getRight());
        visit(tree->getData());
    }
}
template <class X>
void BinaryTree<X>::inorder(void visit(X& item), TreeNode<X>* tree) {
    if(tree) {
        inorder(visit, tree->getLeft());
        visit(tree->getData());
        inorder(visit, tree->getRight());
    }
}
// Public Methods from Interface
template <class X>
bool BinaryTree<X>::isEmpty() const { return !root; }
template <class X>
int BinaryTree<X>::getHeight() const {
    return getHeightHelper(root);
}
template <class X>
int BinaryTree<X>::getNumberOfNodes() const {
    return getNumberHelper(root);
}
template <class  X>
X BinaryTree<X>::getRootData() const {
    return root->getData;
}
template <class X>
void BinaryTree<X>::setRootData(const X& item) {
    root->setData(item);
}
template <class X>
bool BinaryTree<X>::add(const X& item){
    TreeNode<X> *newNode = new TreeNode<X>(item);
    root = balancedAdd(root, newNode);
    return 1;
}
template <class X>
bool BinaryTree<X>::remove(const X& item) {
    bool success = 0;
    root = removeValue(root, item, success);
    return success;
}
template <class X>
bool BinaryTree<X>::contains(const X& item) {
    bool success = 0;
    TreeNode<X> *tmp = find(root, item, success);
    return success;
}
template <class X>
void BinaryTree<X>::preorderTraverse(void visit(X&)) {
    preorder(visit, root);
}
template <class X>
void BinaryTree<X>::inorderTraverse(void visit(X&)) {
    inorder(visit, root);
}
template <class X>
void BinaryTree<X>::postorderTraverse(void visit(X&)){
    postorder(visit, root);
}
template <class X>
void BinaryTree<X>::clear() {
    destroyTree(root);
}
#endif