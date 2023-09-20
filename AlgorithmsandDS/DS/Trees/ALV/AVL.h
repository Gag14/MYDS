#ifndef __AVL__
#define __AVL__

#include <iostream>
#include <algorithm>
#include <queue>

#include "/home/gag/MYDS/AlgorithmsandDS/DS/Trees/BinaryTree/BInaryTreeInterface.h"

namespace MYDS
{
    template <class X>
    class AVL : public BinaryTreeInterface<X>
    {
    public:
        // Ctor Dtor
        AVL()
        {
            m_root = nullptr;
        }
        AVL(const X &rootItem)
        {
            m_root = new TreeNode(rootItem);
        }
        AVL(const X &rootItem, AVL *RightSubTree, AVL *LeftSubTree)
        {
            m_root = new TreeNode(rootItem, RightSubTree->m_root, LeftSubTree->root);
        }
        AVL(const AVL &other)
        {
            m_root = copyTree(other.m_root);
        }
        virtual ~AVL()
        {
            destroyTree(m_root);
        }

        // Inteface Functions
        bool isEmpty() const override
        {
            return !m_root;
        }
        int getHeight() const override
        {
            return getHeightHelper(m_root);
        }
        int getNumberOfNodes() const override
        {
            return getNumberHelper(m_root);
        }
        X getRootData() const override
        {
            return !m_root ? -1 : m_root->data;
        }
        void setRootData(const X &val) override {}
        bool add(const X &val) override
        {
            TreeNode *newnode = new TreeNode(val);
            m_root = balancedAdd(m_root, newnode);
            return true;
        }
        bool remove(const X &val) override
        {
            bool success = 0;
            m_root = removeValue(m_root, val, success);
            return success;
        }
        bool contains(const X &val) const override
        {
            bool success = 0;
            TreeNode *tmp = find(m_root, val, success);
            return success;
        }
        void preorderTraverse(void visit(X &)) override
        {
            postorder(visit, m_root);
        }
        void inorderTraverse(void visit(X &)) override
        {
            inorder(visit, m_root);
        }
        void postorderTraverse(void visit(X &)) override
        {
            postorder(visit, m_root);
        }
        void clear() override
        {
            destroyTree(m_root);
        }
        // End of Interface

        void printInorder() {}
        // Level Order Traversal

        virtual void levelOrderTraversal(void visit(X &))
        {
            levelOrder(visit, m_root);
        }
        // Operator Overloadings
        AVL &operator=(const AVL &other)
        {
            if (other.m_root == m_root)
            {
                return *this;
            }
            m_root = copyTree(other.m_root);
            return *this;
        }
        void LevelOrderPrint()
        {
            std::vector<std::vector<X>> levels = levelOrderBottom(m_root);
            for (auto &level : levels)
            {
                printvector(level);
            }
        }

    protected:
        // Node class
        struct TreeNode
        {
            // Member Data
            X data;
            TreeNode *left;
            TreeNode *right;
            // Ctor
            TreeNode() : right(nullptr), left(nullptr) {}
            TreeNode(const X &val) : data(val), right(nullptr), left(nullptr) {}
            TreeNode(const X &val, TreeNode *LeftChild, TreeNode *RightChild) : data(val), right(RightChild), left(LeftChild) {}
            // Other Functions
            bool isLeaf() const { return !left && !right; }
        };
        // Helper Functions
        int getHeightHelper(TreeNode *root) const
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
        int getNumberHelper(TreeNode *root) const
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
        void destroyTree(TreeNode *&root)
        {
            if (root)
            {
                destroyTree(root->left);
                destroyTree(root->right);

                // std::cout << root->data << " \n";
                delete root;
                root = nullptr; // Set the pointer to null after deleting the node
            }
        }

        TreeNode *balancedAdd(TreeNode *root, TreeNode *newNode)
        {
            if (!root)
            {
                return newNode; // Create a new node if the tree is empty
            }

            if (newNode->data < root->data)
            {
                root->left = balancedAdd(root->left, newNode);
            }
            else if (newNode->data > root->data)
            {
                root->right = balancedAdd(root->right, newNode);
            }

            // Update the height of the current node
            root = balanceTree(root, newNode->data);

            return root;
        }

        TreeNode *removeValue(TreeNode *root, const X val, bool &success)
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
                success = true;

                if (root->isLeaf())
                {
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
                    TreeNode *minValueNode = nullptr;
                    if (root && root->right)
                    {
                        minValueNode = getMinValueNode(root->right);
                    }
                    if (minValueNode)
                    {
                        root->data = minValueNode->data;
                    }
                    else
                    {

                        std::cout << "Min val node is null" << std::endl;
                    }
                    root->right = removeValue(root->right, minValueNode->data, success);
                }
            }
            root = balanceTree(root, val);
            return root;
        }
        TreeNode *find(TreeNode *root, const X val, bool &success) const
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
        TreeNode *copyTree(TreeNode *root)
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
        TreeNode *getMinValueNode(TreeNode *root)
        {
            TreeNode *node = root;
            while (node && node->left)
            {
                node = node->left;
            }
            return node;
        }
        void preorder(void visit(X &), TreeNode *root)
        {
            if (root)
            {
                visit(root->data);
                preorder(visit, root->left);
                preorder(visit, root->right);
            }
        }
        void postorder(void visit(X &), TreeNode *root)
        {
            if (root)
            {
                postorder(visit, root->left);
                postorder(visit, root->right);
                visit(root->data);
            }
        }
        void inorder(void visit(X &), TreeNode *root)
        {
            if (root)
            {
                inorder(visit, root->left);
                visit(root->data);
                inorder(visit, root->right);
            }
        }
        void levelOrder(void visit(X &), TreeNode *root)
        {
            if (!root)
            {
                std::cout << "Empty Tree" << std::endl;
                return;
            }

            std::queue<TreeNode *> level;
            level.push(root);

            while (!level.empty())
            {
                TreeNode *current = level.front();
                level.pop();

                if (current)
                {
                    visit(current->data);

                    if (current->left)
                    {
                        level.push(current->left);
                    }

                    if (current->right)
                    {
                        level.push(current->right);
                    }
                }
            }
        }

        int getBF(TreeNode *node)
        {
            int bf = 0;
            if (node)
            {
                bf = getHeightHelper(node->left) - getHeightHelper(node->right);
            }
            return bf;
        }
        TreeNode *rightRotation(TreeNode *node)
        {
            TreeNode *mid = node->left;
            TreeNode *subTree = mid->right;
            mid->right = node;
            node->left = subTree;
            return mid;
        }
        TreeNode *leftRotate(TreeNode *node)
        {
            TreeNode *mid = node->right;
            TreeNode *subTree = mid->left;
            mid->left = node;
            node->right = subTree;
            return mid;
        }
        TreeNode *balanceTree(TreeNode *root, const X &val)
        {
            if (!root)
            {
                return root;
            }
            int bf = getBF(root);
            if (bf > 1 && val < root->left->data)
            {
                return rightRotation(root);
            }
            if (bf > 1 && val > root->left->data)
            {
                root->left = leftRotate(root);
                return rightRotation(root);
            }
            if (bf < -1 && val > root->right->data)
            {
                return leftRotate(root);
            }
            if (bf < -1 && val < root->right->data)
            {
                root->right = rightRotation(root);
                return leftRotate(root);
            }
            return root;
        }
        std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
        {
            std::vector<std::vector<int>> res;
            if (!root)
            {
                return res;
            }
            std::queue<TreeNode *> qu;
            qu.push(root);
            while (!qu.empty())
            {
                int size = qu.size();
                std::vector<int> level;
                for (int i = 0; i < size; ++i)
                {
                    TreeNode *tmp = qu.front();
                    qu.pop();

                    if (!tmp)
                    {
                        continue;
                    }
                    level.push_back(tmp->data);
                    if (tmp->left)
                    {
                        qu.push(tmp->left);
                    }
                    if (tmp->right)
                    {
                        qu.push(tmp->right);
                    }
                }
                res.push_back(level);
            }
            // std::reverse(res.begin(), res.end());
            return res;
        }
        void printvector(const std::vector<X> vec)
        {
            for (auto &i : vec)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }

    private:
        TreeNode *m_root;
    };
}

#endif // End OF AVL.h