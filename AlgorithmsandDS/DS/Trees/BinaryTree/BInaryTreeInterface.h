#ifndef __Binalry_Tree_Iterface__
#define __Binalry_Tree_Iterface__
template <class X>
class BinaryTreeInterface {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;
        virtual int getNumberOfNodes() const = 0;
        virtual X getRootData() const = 0;
        virtual void setRootData(const X& item) = 0;
        virtual bool add(const X& item) = 0;
        virtual bool remove(const X& item) = 0;
        virtual bool contains(const X& item) const = 0;
        virtual void preorderTraverse(void visit(X&)) = 0;
        virtual void postorderTraverse(void visit(X&)) = 0;
        virtual void inorderTraverse(void visit(X&)) = 0;
        virtual void clear() = 0;   
};
#endif