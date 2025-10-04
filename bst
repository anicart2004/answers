#include <stdio.h>
#include <stdlib.h>

typedef struct TreeType {
    int Data;                    // Node value
    struct TreeType *Left;       // Left child
    struct TreeType *Right;      // Right child
} TREENODE;

TREENODE *Root;  // Root of BST

// Function prototypes
void InitTree();
void InsertTreeNode(int num);
void Inorder(TREENODE *Root);
void Preorder(TREENODE *Root);
void Postorder(TREENODE *Root);
int SearchTreeNode(int num);
void Menu(int *choice);

// Main function
int main() {
    int choice, num;
    InitTree();  // Initialize the BST

    while (1) {
        Menu(&choice);  // Display menu

        switch (choice) {
            case 1:  // Insert
                printf("Enter a number: ");
                scanf("%d", &num);
                InsertTreeNode(num);
                printf("Number inserted successfully.\n");
                break;

            case 2:  // Display traversals
                if (Root == NULL)
                    printf("No Tree\n");
                else {
                    printf("Inorder (LEFT -> ROOT -> RIGHT): ");
                    Inorder(Root);
                    printf("\n");

                    printf("Preorder (ROOT -> LEFT -> RIGHT): ");
                    Preorder(Root);
                    printf("\n");

                    printf("Postorder (LEFT -> RIGHT -> ROOT): ");
                    Postorder(Root);
                    printf("\n");
                }
                break;

            case 3:  // Search
                printf("Enter number to search: ");
                scanf("%d", &num);
                if (SearchTreeNode(num))
                    printf("Found\n");
                else
                    printf("Not found\n");
                break;

            case 4:  // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

// Initialize the BST
void InitTree() {
    Root = NULL;
}

// Insert a number into BST
void InsertTreeNode(int Num) {
    TREENODE *Prev, *Curr, *Node;

    // Create new node
    Node = (TREENODE *)malloc(sizeof(TREENODE));
    Node->Data = Num;
    Node->Left = Node->Right = NULL;

    if (Root == NULL) {  // If tree is empty
        Root = Node;
        return;
    }

    Prev = Curr = Root;

    // Find correct position
    while (Curr != NULL) {
        Prev = Curr;
        if (Num < Curr->Data)
            Curr = Curr->Left;
        else
            Curr = Curr->Right;
    }

    // Insert as left or right child
    if (Num < Prev->Data)
        Prev->Left = Node;
    else
        Prev->Right = Node;
}

// Inorder traversal
void Inorder(TREENODE *Root) {
    if (Root) {
        Inorder(Root->Left);
        printf("%d\t", Root->Data);
        Inorder(Root->Right);
    }
}

// Preorder traversal
void Preorder(TREENODE *Root) {
    if (Root) {
        printf("%d\t", Root->Data);
        Preorder(Root->Left);
        Preorder(Root->Right);
    }
}

// Postorder traversal
void Postorder(TREENODE *Root) {
    if (Root) {
        Postorder(Root->Left);
        Postorder(Root->Right);
        printf("%d\t", Root->Data);
    }
}

// Search in BST
int SearchTreeNode(int Num) {
    TREENODE *Curr = Root;

    while (Curr != NULL) {
        if (Curr->Data == Num)
            return 1;  // Found
        else if (Num < Curr->Data)
            Curr = Curr->Left;
        else
            Curr = Curr->Right;
    }

    return 0;  // Not found
}

// Display menu
void Menu(int *choice) {
    printf("\n----- Menu -----\n");
    printf("1. Enter a number\n");
    printf("2. Display (Inorder, Preorder, Postorder)\n");
    printf("3. Search\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}
