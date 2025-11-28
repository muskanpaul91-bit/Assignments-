#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;
};
Node* createNode(int value) {
Node* newnode = (Node*)malloc(sizeof(Node));
newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

Node* insertBST(Node* root, int value) {
if (root == NULL) {
cout << " Book ID stored successfully.\n";
return createNode(value);
}
if (value < root->data) {
root->left = insertBST(root->left, value);
}
else if (value > root->data) {
root->right = insertBST(root->right, value);
}
 else {
 cout << "\n Book ID already returned earlier. Duplicate not added.\n";
}

return root;
}
bool searchNode(Node* root, int value) {
if (root == NULL)
 return false;

if (root->data == value)
return true;
else if (value < root->data)
return searchNode(root->left, value);
else
return searchNode(root->right, value);
}

void inorder(Node* root)
{
if (root == NULL)
return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

int main() {
Node* root = NULL;
int choice, id;
while (true) {
cout << "\n\n====== Smart Book Tracking System ======\n";
cout << "1. Add Returned Book ID\n";
cout << "2. Check if Book ID has been returned\n";
cout << "3. Display all Book IDs in ascending order\n";
cout << "4. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {

case 1:
cout << "Enter Book ID to add: ";
cin >> id;
if (id <= 0)
 {
cout << " Invalid! Book ID must be a positive integer.\n";
break;
 }

root = insertBST(root, id);
break;

case 2:
cout << "Enter Book ID to search: ";
cin >> id;

if (searchNode(root, id))
cout << " Book ID WAS returned.\n";
else
cout << " Book ID NOT returned yet.\n";
break;

case 3:
cout << "Book IDs in sorted order:\n";
 inorder(root);
cout << endl;
 break;

case 4:
cout << "Exiting program...\n";

return 0;
}
}
}

