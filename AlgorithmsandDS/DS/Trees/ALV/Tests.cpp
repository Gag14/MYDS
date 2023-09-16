#include <iostream>
#include "AVL.h" // Include your AVL tree header

int main() {
    // Create an AVL tree instance
    MYDS::AVL<int> avlTree;

    // Test isEmpty() on an empty tree
    if (avlTree.isEmpty()) {
        std::cout << "AVL tree is empty.\n";
    } else {
        std::cerr << "Error: AVL tree should be empty.\n";
    }

    // Test add() function
    avlTree.add(10);
    avlTree.add(5);
    avlTree.add(15);
    avlTree.add(3);
    avlTree.add(7);
    avlTree.add(12);
    avlTree.add(20);

    // Test contains()
    if (avlTree.contains(12)) {
        std::cout << "AVL tree contains 12.\n";
    } else {
        std::cerr << "Error: AVL tree should contain 12.\n";
    }

    // Test getHeight()
    int height = avlTree.getHeight();
    std::cout << "AVL tree height: " << height << "\n";

    // Test getNumberOfNodes()
    int numNodes = avlTree.getNumberOfNodes();
    std::cout << "Number of nodes in AVL tree: " << numNodes << "\n";

    // Test getRootData()
    int rootData = avlTree.getRootData();
    std::cout << "Root data of AVL tree: " << rootData << "\n";

    // Test remove()
    bool removed = avlTree.remove(15);
    if (removed) {
        std::cout << "Successfully removed 15 from AVL tree.\n";
    } else {
        std::cerr << "Error: Failed to remove 15 from AVL tree.\n";
    }

    // Test clear()
    avlTree.clear();
    if (avlTree.isEmpty()) {
        std::cout << "AVL tree is empty after clear.\n";
    } else {
        std::cerr << "Error: AVL tree should be empty after clear.\n";
    }

    return 0;
}
