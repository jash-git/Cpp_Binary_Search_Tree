#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::endl;

class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode();
    TreeNode(int a, string b);

    int GetKey();// ���F�bmain()�n����˵�node�O�_���T
    string GetElement();// �~�ݭn�o���member functionŪ��private data

    // ��l���p, �]��class BST�Oclass TreeNode��friend class
    // �bclass BST��member function��, �i�H�����s��class TreeNode��private data

    friend class BST;   // ��b private �� public ���i�H
};

#endif // TREENODE_H
