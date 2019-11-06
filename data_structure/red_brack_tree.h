// 特点：
// 1.每个节点不是红色就是黑色
// 2.不可能有连在一起的红色节点
// 3.根节点都是黑色
// 4.每个红色节点的两个字节点都是黑色

// 变颜色情况：插入的节点为红色，当前节点的父节点是红色，且它的父节点的兄弟节点也是红色。
// 1.把父节点设为黑色
// 2.把父节点的兄弟节点也设为黑色
// 3.祖父节点设为红色
// 4.把指针定位到祖父节点上

// 左旋： 当前父节点是红色，父节点的兄弟节点是黑色，且当前的节点是右子树。以父节点作左旋。

// 右旋：当前父节点是红色，父节点的兄弟节点是黑色，且当前的节点是左子树。
// 1.把父节点变为黑色
// 2.把祖父节点变为红色
// 3.以祖父节点旋转

#ifndef __RED_BRACK_TREE_H__
#define __RED_BRACK_TREE_H__
namespace dsa
{

enum RBTNColor 
{
    Brack,
    Red
}

template<class T>
class RBTNode
{
public:
    T data;
    RBTNColor color = RBTNColor::Red;

    RBTNode *left, *right, parent;

    RBTNode(T data) 
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

template<class T>
class RedBrackTree
{
    void insert();

};
    
} // namespace name


#endif // __RED_BRACK_TREE_H__