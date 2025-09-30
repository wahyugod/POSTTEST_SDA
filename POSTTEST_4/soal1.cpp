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

string reverseString(string s)
{
    Node *stackTop = nullptr;
    string reversed = "";

    // 1. Push setiap karakter dari string s ke dalam stack.
    for (char c : s)
    {
        push(stackTop, c); // Tumpuk karakter ke dalam stack
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // Loop selama stack tidak kosong
    while (stackTop != nullptr)
    {
        reversed += pop(stackTop); // Ambil karakter dari paling atas stack
    }

    return reversed;
}

int main()
{
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurtS
    return 0;
}
