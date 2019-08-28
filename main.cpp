#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include "BST.h"

using namespace std;

void Pause()
{
    printf("Press Enter key to continue�K");
    fgetc(stdin);
}
int main()
{
    BST T;

    T.InsertBST(8,"�t�P�H");
    T.InsertBST(1000,"����");
    T.InsertBST(2,"�J�L");
    T.InsertBST(513,"��J");


    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl << endl;

    T.DeleteBST(8);         // �R���t�P�H(8), �T�{��J(513)�|�����s��root

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
