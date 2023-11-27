#pragma once

#include <iostream>
#pragma once

#include <iostream>
#include "Humanidad.h"  // Incluye el archivo de encabezado de Humanidad

#define SPACE 10

using namespace std;
int AVLTree::height(TreeNode * r) {
    if (r == NULL)
        return -1;
    else {
        /* compute the height of each subtree */
        int lheight = height(r -> left);
        int rheight = height(r -> right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

// Get Balance factor of node N
int AVLTree::getBalanceFactor(TreeNode * n) {
    if (n == NULL)
        return -1;
    return height(n -> left) - height(n -> right);
}

TreeNode * AVLTree::rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;

    // Perform rotation
    x -> right = y;
    y -> left = T2;

    return x;
}

TreeNode * AVLTree::leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;

    // Perform rotation
    y -> left = x;
    x -> right = T2;

    return y;
}

TreeNode * AVLTree::insert(TreeNode * r, TreeNode * new_node) {
    if (r == NULL) {
        r = new_node;
        cout << "humano inserted successfully" << endl;
        return r;
    }

    if (new_node -> humano->ID < r -> humano->ID ) {
        r -> left = insert(r -> left, new_node);
    } else if (new_node->humano->ID > r->humano->ID ) {
        r -> right = insert(r -> right, new_node);
    } else {
        cout << "No duplicate humanos allowed!" << endl;
        return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case
    if (bf > 1 && new_node -> humano->ID  < r -> left -> humano->ID )
        return rightRotate(r);

    // Right Right Case
    if (bf < -1 && new_node -> humano->ID  > r -> right -> humano->ID )
        return leftRotate(r);

    // Left Right Case
    if (bf > 1 && new_node -> humano->ID  > r -> left -> humano->ID ) {
        r -> left = leftRotate(r -> left);
        return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && new_node -> humano->ID  < r -> right -> humano->ID ) {
        r -> right = rightRotate(r -> right);
        return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

}

void AVLTree::print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
        return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
        cout << " "; // 5.1
    cout << r -> humano->ID  << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
}

void AVLTree::printInorder(TreeNode * r) //  (Left, current node, Right)
{
    if (r == NULL)
        return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> humano->ID  << " ";
    /* now recur on right child */
    printInorder(r -> right);
}

/* Print nodes at a given level */
void AVLTree::printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
        return;
    else if (level == 0)
        cout << r -> humano->ID  << " ";
    else // level > 0
    {
        printGivenLevel(r -> left, level - 1);
        printGivenLevel(r -> right, level - 1);
    }
}
void AVLTree::printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
        printGivenLevel(r, i);
}
