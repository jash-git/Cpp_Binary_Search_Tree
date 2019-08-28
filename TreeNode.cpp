#include "TreeNode.h"

TreeNode::TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element("")
{
}

TreeNode::TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b)
{
}

int TreeNode::GetKey()
{
    return key;
}

string TreeNode::GetElement()
{
    return element;
}
