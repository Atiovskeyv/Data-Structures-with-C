#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node* addNode(int sayi, struct Node *rootNode) {
    if (rootNode == NULL) {
        rootNode = malloc(sizeof(struct Node));
        rootNode->data = sayi;
        rootNode->leftNode = NULL;
        rootNode->rightNode = NULL;
        return rootNode;
    }
    else if (sayi < rootNode->data) {
        rootNode->leftNode = addNode(sayi, rootNode->leftNode);
    }
    else if (sayi > rootNode->data) {
        rootNode->rightNode = addNode(sayi, rootNode->rightNode);
    }
    return rootNode;
}

void inOrderTraversal(struct Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }

    inOrderTraversal(rootNode->leftNode);
    printf("%d ", rootNode->data);
    inOrderTraversal(rootNode->rightNode);
}

void preOrderTraversal(struct Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }

    printf("%d ", rootNode->data);
    preOrderTraversal(rootNode->leftNode);
    preOrderTraversal(rootNode->rightNode);
}

void postOrderTraversal(struct Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }

    postOrderTraversal(rootNode->leftNode);
    postOrderTraversal(rootNode->rightNode);
    printf("%d ", rootNode->data);
}

void minValue(struct Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }
    while (rootNode->leftNode != NULL) {
        rootNode = rootNode->leftNode;
    }
    printf("%d ", rootNode->data);
}

void maxValue(struct Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }
    while (rootNode->rightNode != NULL) {
        rootNode = rootNode->rightNode;
    }
    printf("%d ", rootNode->data);
}

int main(){
    struct Node *rootNode = NULL;
    rootNode = addNode(50,rootNode);
    rootNode = addNode(30,rootNode);
    rootNode = addNode(70,rootNode);
    rootNode = addNode(20,rootNode);
    rootNode = addNode(40,rootNode);
    rootNode = addNode(60,rootNode);
    rootNode = addNode(80,rootNode);

    printf("Inorder: ");
    inOrderTraversal(rootNode);
    printf("\n");

    printf("Preorder: ");
    preOrderTraversal(rootNode);
    printf("\n");

    printf("Postorder: ");
    postOrderTraversal(rootNode);
    printf("\n");

    free(rootNode);
    return 0;
}