#ifndef BST_H
#define BST_H

#include "TreeNode.h"

class BST
{
    private:
        TreeNode *root;
        TreeNode* Leftmost(TreeNode *current);
        TreeNode* Successor(TreeNode *current);
    public:
        BST():root(0){};
        TreeNode* Search(int key);
        void InsertBST(int key, string element);
        void InorderPrint();
        void Levelorder();
        void DeleteBST(int key);
};

#endif // BST_H
