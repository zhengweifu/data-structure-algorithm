#include "data_structure_algorithm/binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

using namespace dsa;

int main(int argc, char const *argv[])
{
    BinaryTree<int> *tree = new BinaryTree<int>();

    BinaryTreeNode<int> rootNode(3);
    tree->setRoot(&rootNode);

    int test[] = {5, 6, 8, 10, 2, 1, -1};

    for(int &t : test)
    {
        BinaryTreeNode<int> *node = new BinaryTreeNode<int>(t);
        tree->insert(node);
    }

    // BinaryTreeNode<int> node1(2);
    // tree->insert(&node1);

    // BinaryTreeNode<int> node2(4);
    // tree->insert(&node2);

    tree->inOrder();

    // tree->preOrder();

    // tree->postOrder();

    delete tree;

    system("pause");
    return 0;
}