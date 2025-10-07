#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk menghitung jumlah total node dalam tree
int countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0; // Tree kosong
    }
    int total = 1;                    // Hitung node saat ini
    total += countNodes(root->left);  // Hitung node di subtree kiri
    total += countNodes(root->right); // Hitung node di subtree kanan
    return total;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // Harusnya output: 4
    return 0;
}