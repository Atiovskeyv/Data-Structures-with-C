#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
        int studentID;
        char studentName[20];
        struct node *next;
};

struct node *head = NULL;  // global

void addToHead(const int id, const char *name) {
        struct node *newNode = malloc(sizeof(struct node));
        if (newNode == NULL) return;
        newNode->studentID = id;
        strcpy(newNode->studentName,name);
        newNode->next = head;
        head = newNode;
}

void list() {
        if (head == NULL) {
                printf("List is empty\n");
                return;
        }
        struct node *pointer = head;
        while (pointer != NULL) {
                printf("Student ID: %d , student name: %s\n",pointer->studentID,pointer->studentName);
                pointer = pointer->next;
        }
}

int deleteNode(const int id){
        struct node *currentNode = head;
        struct node *previousNode = NULL;
        if (currentNode == NULL) {
                printf("Empty List\n");
                return 0;
        }
        if (currentNode->studentID == id){
                head = currentNode->next;
                free(currentNode);
                return 1;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;

        while (currentNode != NULL) {
                if (currentNode->studentID == id) {
                        previousNode->next = currentNode->next;
                        free(currentNode);
                        return 1;
                }
                previousNode = currentNode;
                currentNode = currentNode->next;
        }
        return 0;
}

void freeList() {
        struct node *temp;
        while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
        }
}

void findById(const int id) {
        struct node *pointer = head;
        if (pointer == NULL) {
                printf("Empty List\n");
                return;
        }
        while (pointer != NULL) {
                if (pointer->studentID == id) {
                        printf("Student Name: %s, Student ID: %d",pointer->studentName,pointer->studentID);
                        return;
                }
                pointer = pointer->next;
        }
        printf("Student not found\n");
}

void addToTail(const int id, const char *name)
{
        struct node *newNode = malloc(sizeof(struct node));
        if (newNode == NULL) return;

        newNode->studentID = id;
        strcpy(newNode->studentName, name);
        newNode->next = NULL;

        if (head == NULL){
                head = newNode;
                return;
        }

        struct node *tmpNode = head;

        while (tmpNode->next != NULL){
                tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
}

int main() {
        addToHead(1540,"Atilla Alper");
        addToHead(1541,"Yunus Emre");
        addToHead(1542,"Naz");
        addToHead(1543,"Ahmet");
        list();printf("\n");
        deleteNode(1540);
        list();printf("\n");
        addToHead(1540,"Atilla Alper");
        deleteNode(1543);
        list();printf("\n");
        addToTail(1544,"Baris");
        list();printf("\n");
        findById(1541);
        freeList();
        return 0;
}