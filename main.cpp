#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include "BST.h"

using namespace std;

void Pause()
{
    printf("Press Enter key to continue…");
    fgetc(stdin);
}
int main()
{
    BST T;

    T.InsertBST(8,"龜仙人");
    T.InsertBST(1000,"悟空");
    T.InsertBST(2,"克林");
    T.InsertBST(513,"比克");


    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl << endl;

    T.DeleteBST(8);         // 刪除龜仙人(8), 確認比克(513)會成為新的root

    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl << endl;

    TreeNode *node = T.Search(1000);
    if(node != NULL)
    {
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else
    {
        cout << "no element with Key(1000)" << endl;
    }

    node = T.Search(8);
    if(node != NULL)
    {
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else
    {
        cout << "no element with Key(8)" << endl;
    }

    Pause();
    return 0;
}
