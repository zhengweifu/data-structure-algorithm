#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>

namespace dsa
{

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode
{
private:
    BinaryTreeNode()
    {
    }

public:
    T data;
    BinaryTreeNode *leftNode;
    BinaryTreeNode *rightNode;

public:
    BinaryTreeNode(T data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};

template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *rootNode;

public:
    void setRoot(BinaryTreeNode<T> *root);

    BinaryTreeNode<T> *getRoot();

    void insert(BinaryTreeNode<T> *node);

private:
    void visit(BinaryTreeNode<T> *node, int level);

    void inOrder(BinaryTreeNode<T> *node, int level);

    void preOrder(BinaryTreeNode<T> *node, int level);

    void postOrder(BinaryTreeNode<T> *node, int level);

public:
    void inOrder()
    {
        inOrder(rootNode, 1);
    }

    void preOrder()
    {
        preOrder(rootNode, 1);
    }

    void postOrder()
    {
        postOrder(rootNode, 1);
    }
};

template <class T>
void BinaryTree<T>::setRoot(BinaryTreeNode<T> *root)
{
    this->rootNode = root;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot()
{
    return rootNode;
}

template <class T>
void BinaryTree<T>::insert(BinaryTreeNode<T> *node)
{
    if (rootNode == NULL)
    {
        rootNode = node;
        return;
    }

    BinaryTreeNode<T> *pNode;
    pNode = rootNode;

    while (pNode != NULL)
    {
        if (pNode->data > node->data)
        {
            if (pNode->leftNode == NULL)
            {
                pNode->leftNode = node;
                break;
            }
            pNode = pNode->leftNode;
        }
        else
        {
            if (pNode->rightNode == NULL)
            {
                pNode->rightNode = node;
                break;
            }

            pNode = pNode->rightNode;
        }
    }
}

template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T> *node, int level)
{
    std::cout << "data: " << node->data << " level: " << level << std::endl;
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *node, int level)
{
    if (node != NULL)
    {
        inOrder(node->leftNode, level + 1);
        visit(node, level);
        inOrder(node->rightNode, level + 1);
    }
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *node, int level)
{
    if (node != NULL)
    {
        visit(node, level);
        preOrder(node->leftNode, level + 1);
        preOrder(node->rightNode, level + 1);
    }
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *node, int level)
{
    if (node != NULL)
    {
        postOrder(node->leftNode, level + 1);
        postOrder(node->rightNode, level + 1);
        visit(node, level);
    }
}

} // namespace dsa

#endif //__BINARY_TREE_H__