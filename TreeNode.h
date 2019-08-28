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
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b){};

    int GetKey(){return key;}              // ���F�bmain()�n����˵�node�O�_���T
    string GetElement(){return element;}   // �~�ݭn�o���member functionŪ��private data

    // ��l���p, �]��class BST�Oclass TreeNode��friend class
    // �bclass BST��member function��, �i�H�����s��class TreeNode��private data

    friend class BST;   // ��b private �� public ���i�H
};

#endif // TREENODE_H
