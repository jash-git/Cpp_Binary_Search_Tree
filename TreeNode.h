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

    int GetKey(){return key;}              // 為了在main()要能夠檢視node是否正確
    string GetElement(){return element;}   // 才需要這兩個member function讀取private data

    // 其餘情況, 因為class BST是class TreeNode的friend class
    // 在class BST的member function中, 可以直接存取class TreeNode的private data

    friend class BST;   // 放在 private 或 public 都可以
};

#endif // TREENODE_H
