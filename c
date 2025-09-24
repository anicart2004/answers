//link list_1
#include <stdio.h>
#include <stdlib.h>

// Structure for the linked list
typedef struct ListNode {
    int Data;
    struct ListNode *Next;
} LISTNODE;

// Global variable
LISTNODE *Head = NULL;

// Function prototypes
void Menu();
void InputNode(int num);
void PrintList();
int DeleteFirstNode();
int DeleteLastNode();
int SearchNum(int num);
int Maximum();
int DeleteNode(int num);

int main() {
    int choice, n, num, i;

    while (1) {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Input numbers
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &num);
                    InputNode(num);
                }
                break;

            case 2: // Print list
                PrintList();
                break;

            case 3: // Delete first node
                num = DeleteFirstNode();
                if (num != -1) printf("Deleted first node: %d\n", num);
                break;

            case 4: // Delete last node
                num = DeleteLastNode();
                if (num != -1) printf("Deleted last node: %d\n", num);
                break;

            case 5: // Display number of nodes
            {
                LISTNODE *temp = Head;
                int count = 0;
                while (temp) { count++; temp = temp->Next; }
                printf("Number of nodes: %d\n", count);
                break;
            }

            case 6: // Maximum value
                num = Maximum();
                if (num != -1) printf("Maximum value: %d\n", num);
                break;

            case 7: // Search a number
                printf("Enter number to search: ");
                scanf("%d", &num);
                if (SearchNum(num)) printf("%d found in the list.\n", num);
                else printf("%d not found.\n", num);
                break;

            case 8: // Delete a given number
                printf("Enter number to delete: ");
                scanf("%d", &num);
                num = DeleteNode(num);
                if (num != -1) printf("Deleted number: %d\n", num);
                break;

            case 9: // Exit
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void Menu() {
    printf("\n--- MENU ---\n");
    printf("1. Input numbers\n");
    printf("2. Print the list\n");
    printf("3. Delete first node\n");
    printf("4. Delete last node\n");
    printf("5. Display number of nodes\n");
    printf("6. Maximum number\n");
    printf("7. Search a number\n");
    printf("8. Delete a given number\n");
    printf("9. Exit\n");
}

void InputNode(int num) {
    LISTNODE *Node = (LISTNODE*)malloc(sizeof(LISTNODE));
    Node->Data = num;
    Node->Next = NULL;

    if (!Head) { // Empty list
        Head = Node;
        return;
    }

    LISTNODE *temp = Head;
    while (temp->Next) temp = temp->Next;
    temp->Next = Node;
}

void PrintList() {
    if (!Head) {
        printf("List is empty!\n");
        return;
    }
    LISTNODE *temp = Head;
    while (temp) {
        printf("%d -> ", temp->Data);
        temp = temp->Next;
    }
    printf("NULL\n");
}

int DeleteFirstNode() {
    if (!Head) return -1;
    LISTNODE *temp = Head;
    int num = temp->Data;
    Head = Head->Next;
    free(temp);
    return num;
}

int DeleteLastNode() {
    if (!Head) return -1;
    LISTNODE *temp = Head, *prev = NULL;
    while (temp->Next) {
        prev = temp;
        temp = temp->Next;
    }
    int num = temp->Data;
    if (prev) prev->Next = NULL;
    else Head = NULL; // Only one node
    free(temp);
    return num;
}

int SearchNum(int num) {
    LISTNODE *temp = Head;
    while (temp) {
        if (temp->Data == num) return 1;
        temp = temp->Next;
    }
    return 0;
}

int Maximum() {
    if (!Head) return -1;
    int max = Head->Data;
    LISTNODE *temp = Head->Next;
    while (temp) {
        if (temp->Data > max) max = temp->Data;
        temp = temp->Next;
    }
    return max;
}

int DeleteNode(int num) {
    if (!Head) return -1;
    if (Head->Data == num) {
        LISTNODE *temp = Head;
        Head = Head->Next;
        free(temp);
        return num;
    }
    LISTNODE *curr = Head->Next, *prev = Head;
    while (curr) {
        if (curr->Data == num) {
            prev->Next = curr->Next;
            free(curr);
            return num;
        }
        prev = curr;
        curr = curr->Next;
    }
    printf("%d not found!\n", num);
    return -1;
}


//order link list2
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode *head = NULL;

/* Function prototypes */
void insertNumber(int num);
void displayList();
void deleteNumber(int num);
void reverseList();
void menu();

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int num;
        switch(choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                insertNumber(num);
                break;
            case 2:
                printf("Linked List: ");
                displayList();
                break;
            case 3:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                deleteNumber(num);
                break;
            case 4:
                reverseList();
                printf("List reversed.\n");
                displayList();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 5);

    return 0;
}

/* Display menu */
void menu() {
    printf("\n=== ORDERED LINKED LIST MENU ===\n");
    printf("1. Input a number\n");
    printf("2. Display the Linked List\n");
    printf("3. Delete a given number\n");
    printf("4. Reverse the Linked List\n");
    printf("5. Exit\n");
}

/* Insert number in ascending order */
void insertNumber(int num) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = num;
    newNode->next = NULL;

    if(head == NULL || num <= head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode *curr = head;
    while(curr->next != NULL && curr->next->data < num) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

/* Display linked list */
void displayList() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    ListNode *curr = head;
    while(curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/* Delete a given number */
void deleteNumber(int num) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    ListNode *curr = head, *prev = NULL;

    if(head->data == num) {
        head = head->next;
        free(curr);
        return;
    }

    while(curr != NULL && curr->data != num) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("%d not found in the list.\n", num);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

/* Reverse the linked list */
void reverseList() {
    ListNode *prev = NULL, *curr = head, *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}


//Queue program3
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

/* Function prototypes */
void enqueue(int num);
void dequeue();
void displayQueue();
void menu();

int main() {
    int choice, num;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:  // Enqueue
                printf("Enter number to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:  // Dequeue
                dequeue();
                break;
            case 3:  // Display
                displayQueue();
                break;
            case 4:  // Exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}

/* Display menu */
void menu() {
    printf("\n=== QUEUE MENU ===\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
}

/* Enqueue element */
void enqueue(int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if(rear == NULL) {  // Empty queue
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* Dequeue element */
void dequeue() {
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;

    if(front == NULL) rear = NULL;  // Queue becomes empty
    free(temp);
}

/* Display queue */
void displayQueue() {
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node *curr = front;
    printf("Queue: ");
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

//circular queue 4
/*-----------------------------------
CirQueue.c
A program to implement menu driven Circular Queue
----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct CirQueType {
    int Data;
    struct CirQueType *Next;
} CIRQUEUENODE;

CIRQUEUENODE *Front = NULL, *Rear = NULL;

/* Function prototypes */
void Menu(int *choice);
void Initialize();
void Enqueue(int num);
int Dequeue();
void Display();

int main() {
    int n, num, i, choice;
    Initialize();

    do {
        Menu(&choice);

        switch(choice) {
            case 1:
                printf("Enter the number of elements to enqueue: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for(i = 0; i < n; i++) {
                    scanf("%d", &num);
                    Enqueue(num);
                }
                break;

            case 2: {
                int del_no = Dequeue();
                if(del_no != -1) {
                    printf("%d is dequeued from the queue.\n", del_no);
                }
                break;
            }

            case 3:
                printf("The elements in the queue are: ");
                Display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid Choice! Try again.\n");
        }

    } while(1);

    return 0;
}

/* Display menu */
void Menu(int *choice) {
    printf("\n=== CIRCULAR QUEUE MENU ===\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}

/* Initialize queue */
void Initialize() {
    Front = Rear = NULL;
}

/* Enqueue element */
void Enqueue(int num) {
    CIRQUEUENODE *Node = (CIRQUEUENODE*)malloc(sizeof(CIRQUEUENODE));
    Node->Data = num;
    Node->Next = NULL;

    if(Front == NULL) {  // Empty queue
        Front = Rear = Node;
        Rear->Next = Front;  // Circular link
        return;
    }

    Rear->Next = Node;
    Rear = Node;
    Rear->Next = Front;  // Maintain circular link
}

/* Dequeue element */
int Dequeue() {
    if(Front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    int num = Front->Data;

    if(Front == Rear) {  // Only one element
        free(Front);
        Front = Rear = NULL;
    } else {
        CIRQUEUENODE *temp = Front;
        Front = Front->Next;
        Rear->Next = Front;  // Maintain circular link
        free(temp);
    }

    return num;
}

/* Display queue elements */
void Display() {
    if(Front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    CIRQUEUENODE *Curr = Front;
    do {
        printf("%d ", Curr->Data);
        Curr = Curr->Next;
    } while(Curr != Front);

    printf("\n");
}


//5.......binary search tree 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Display leaf nodes
void displayLeafNodes(struct Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);
        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}

// Check if node is leaf
void checkLeaf(struct Node* root, int key) {
    struct Node* node = search(root, key);
    if (node == NULL) {
        printf("%d not found in BST\n", key);
    } else if (node->left == NULL && node->right == NULL) {
        printf("%d is a leaf node\n", key);
    } else {
        printf("%d is not a leaf node\n", key);
    }
}

// Main Menu
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a number\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Search for a number\n");
        printf("6. Display all Leaf Nodes\n");
        printf("7. Search and check if Leaf Node\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter how many numbers you want to insert: ");
                int n, i;
                scanf("%d", &n);
                printf("Enter %d numbers: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter number to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("%d found in BST\n", value);
                else
                    printf("%d not found in BST\n", value);
                break;
            case 6:
                printf("Leaf Nodes: ");
                displayLeafNodes(root);
                printf("\n");
                break;
            case 7:
                printf("Enter number to check if leaf: ");
                scanf("%d", &value);
                checkLeaf(root, value);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


//................6 working of stack 
#include <stdio.h>
#define SIZE 5  // You can change stack size

typedef struct StackType {
    int A[SIZE];
    int Top;
} STACK;

STACK S;

// Initialize the stack
void InitStack() {
    S.Top = -1;
}

// Push element into the stack
void Push(int Num) {
    if (S.Top == SIZE - 1) {
        printf("Stack is full\n");
        return;
    } else {
        S.Top++;
        S.A[S.Top] = Num;
    }
}

// Pop element from the stack
int Pop() {
    int Num;
    if (S.Top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        Num = S.A[S.Top];
        S.Top--;
        return Num;
    }
}

// Display all elements in the stack
void Display() {
    int i;
    if (S.Top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("Stack elements (top to bottom): ");
        for (i = S.Top; i >= 0; i--) {
            printf("%d\t", S.A[i]);
        }
        printf("\n");
    }
}

// Main function with simplified menu
int main() {
    int choice, num;

    InitStack();

    printf("\n=== Stack Menu (Single Run) ===\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter number: ");
        scanf("%d", &num);
        Push(num);
    } 
    else if (choice == 2) {
        num = Pop();
        if (num != -1)
            printf("Popped: %d\n", num);
    } 
    else if (choice == 3) {
        Display();
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}

/*-------------------------------------------------------
reversestring.c
A program to reverse a string using a stack 7
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 20

typedef struct Stack {
    int Top;
    char Oprnd[MAXNUM];
} STACK;

STACK S;

/* Stack functions */
void Push(char C);
char Pop();
void InitStack();
int StackEmpty();

int main() {
    char rev[20];
    char str[40];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    InitStack();

    /* Push all characters onto stack */
    for(i = 0; i < len; i++) {
        Push(str[i]);
    }

    /* Pop characters to reverse */
    for(i = 0; i < len; i++) {
        rev[i] = Pop();
    }
    rev[len] = '\0';  // Null terminate the reversed string

    printf("Reversed string: %s\n", rev);
    return 0;
}

/* Initialize stack */
void InitStack() {
    S.Top = -1;
}

/* Push character onto stack */
void Push(char C) {
    if(S.Top == MAXNUM-1) {
        printf("\nSTACK IS FULL\n");
    } else {
        S.Top++;
        S.Oprnd[S.Top] = C;
    }
}

/* Pop character from stack */
char Pop() {
    if(S.Top == -1) {
        printf("\nSTACK IS EMPTY\n");
        return '\0';  // Return null character if stack empty
    } else {
        char c = S.Oprnd[S.Top];
        S.Top--;
        return c;
    }
}

/* Check if stack is empty */
int StackEmpty() {
    return S.Top == -1;
}


//.......palindrome stack 8
#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX], rev[MAX];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Push all characters to stack
    for(i = 0; i < len; i++)
        push(str[i]);

    // Pop to get reversed string
    for(i = 0; i < len; i++)
        rev[i] = pop();
    rev[len] = '\0';

    // Check palindrome
    if(strcmp(str, rev) == 0)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}

//............9 fibonacci
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct StackType{
int Fib[SIZE];
int Top;
}STACK;
STACK S;
//Function Prototypes
void Push(int Fib);
int Pop();
void InitStack();
void Display();
int main()
{
int i , n, F1 = 0 , F2 = 1 , F3;
printf("Enter the value of n:");
scanf("%d" , &n);
InitStack();
Push(F1);
Push(F2);
i = 1;
while(i < n){
F2 = Pop();
F1 = Pop();
F3 = F1 + F2;
Push(F1);
Push(F2);
Push(F3);
i++;
}
Display();
return 0;
}
void Push(int Fib){
if(S.Top == SIZE-1){
printf("Stack is full");
return;
}else{
S.Top++;
S.Fib[S.Top] = Fib;
return;
}
}
int Pop(){
int num;
if(S.Top == -1){
printf("StackEmpty");
return 0;
}else{
num = S.Fib[S.Top];
S.Top--;
return num;
}
}
void Display(){
int i;
if(S.Top == -1){
printf("Stack Empty");
return;
}else{
printf("Stack elements: ");
for (i = 0; i <= S.Top; i++){
printf("%d\t", S.Fib[i]);
}
printf("\n");
}
}
void InitStack(){
S.Top = -1;
}



//............10. FACTORIAL
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct StackType{
float Fact[SIZE];
int Top;
}STACK;
STACK S;
void Push(float F);
float Pop();
int main(){
int i , n , num;
float Fact;
printf("Enter the value of n:");
scanf("%d" , &n);
i = 1;
Push(1);
while(i<=n){
num = Pop();
Push(num*i);
i++;
}
Fact = Pop();
printf("Factorial:%0.2f" , Fact);
return 0;
}
void Push(float F){
if(S.Top == SIZE-1){
printf("Stack is full");
return;
}else{
S.Top++;
S.Fact[S.Top] = F;
return;
}
}
float Pop(){
int num;
if(S.Top == 0){
printf("StackEmpty");
return 0;
}else{
num = S.Fact[S.Top];
S.Top--;
  

//11. input some numbers into an array and sort them using BUBBLE SORT.
#include <stdio.h>

/* Function prototypes */
void inputArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    inputArray(arr, n);
    bubbleSort(arr, n);

    printf("Sorted array in ascending order: ");
    displayArray(arr, n);

    return 0;
}

/* Function to input array elements */
void inputArray(int arr[], int n) {
    int i;
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

/* Function to sort array using Bubble Sort */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                /* Swap arr[j] and arr[j+1] */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Function to display array elements */
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


//12//e strings into a character matrix and sort them using BUBBLE SORt )
#include <stdio.h>
#include <string.h>

/* Function prototypes */
void inputStrings(char arr[][50], int n);
void bubbleSortStrings(char arr[][50], int n);
void displayStrings(char arr[][50], int n);

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][50];  // Character matrix to store strings

    inputStrings(arr, n);
    bubbleSortStrings(arr, n);

    printf("Sorted strings:\n");
    displayStrings(arr, n);

    return 0;
}

/* Function to input strings */
void inputStrings(char arr[][50], int n) {
    int i;
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);  // Read string (no spaces)
    }
}

/* Function to sort strings using Bubble Sort */
void bubbleSortStrings(char arr[][50], int n) {
    int i, j;
    char temp[50];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap strings
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

/* Function to display strings */
void displayStrings(char arr[][50], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}
