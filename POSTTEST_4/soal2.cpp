#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void push(Node *&top, char data)
{
    Node *newNode = new Node{data, top};
    top = newNode;
}

char pop(Node *&top)
{
    if (top == nullptr)
        return '\0'; // Return null character jika stack kosong
    Node *temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr)
{
    Node *stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    for (char c : expr)
    {
        // Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        if (c == '(' || c == '{' || c == '[')
        {
            push(stackTop, c); // 2. Push karakter kurung buka ke stack
        }
        // Jika karakter adalah kurung tutup ')', '}', ']', cek
        else if (c == ')' || c == '}' || c == ']')
        {
            // Apakah stack kosong
            if (stackTop == nullptr)
                return false; // 3a. Stack kosong saat menemukan kurung tutup

            char topChar = pop(stackTop); // 3b. Pop karakter dari stack

            // Apakah kurung tutup cocok dengan kurung buka
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
            {
                return false; // Tidak cocok
            }
        }
    }
    return true; // 4. Jika stack kosong, return true; jika tidak, return false
}

int main()
{
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}