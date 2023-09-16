#include <iostream>
#include "BST.h" // Include your BST header file

int main() {
    // Create an instance of your BST
    MYDS::BST<int> myBST;

    // Test isEmpty
    std::cout << "Is BST empty? " << (myBST.isEmpty() ? "Yes" : "No") << std::endl;

    // Test add
    myBST.add(50);
    myBST.add(30);
    myBST.add(70);
    myBST.add(20);
    myBST.add(40);
    myBST.add(60);
    myBST.add(80);

    // Test isEmpty after adding elements
    std::cout << "Is BST empty? " << (myBST.isEmpty() ? "Yes" : "No") << std::endl;

    // Test getHeight
    std::cout << "BST Height: " << myBST.getHeight() << std::endl;

    // Test getNumberOfNodes
    std::cout << "Number of nodes in BST: " << myBST.getNumberOfNodes() << std::endl;

    // Test getRootData
    std::cout << "Root data: " << myBST.getRootData() << std::endl;

    // Test setRootData
    myBST.setRootData(55);
    std::cout << "Updated root data: " << myBST.getRootData() << std::endl;

    // Test contains
    int searchValue = 40;
    std::cout << "BST contains " << searchValue << "? " << (myBST.contains(searchValue) ? "Yes" : "No") << std::endl;

    // Test preorderTraverse
    std::cout << "Preorder traversal: ";
    myBST.preorderTraverse([](int& val) { std::cout << val << " "; });
    std::cout << std::endl;

    // Test inorderTraverse
    std::cout << "Inorder traversal: ";
    myBST.inorderTraverse([](int& val) { std::cout << val << " "; });
    std::cout << std::endl;

    // Test postorderTraverse
    std::cout << "Postorder traversal: ";
    myBST.postorderTraverse([](int& val) { std::cout << val << " "; });
    std::cout << std::endl;

    // Test remove
    int removeValue = 30;
    myBST.remove(removeValue);
    std::cout << "Removed value " << removeValue << std::endl;
    // Test clear
    myBST.clear();
    std::cout << "BST cleared" << std::endl;

    return 0;
}
