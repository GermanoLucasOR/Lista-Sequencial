#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Definindo um tamanho máximo para a lista

typedef struct {
    int data[MAX_SIZE];
    int size;
} List;

void createList(List *list) {
    list->size = 0;
}

int isEmpty(List *list) {
    return list->size == 0;
}

int isFull(List *list) {
    return list->size == MAX_SIZE;
}

int getSize(List *list) {
    return list->size;
}

int getElement(List *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Posição inválida!\n");
        return -1; // 
    }
    return list->data[position];
}

void setElement(List *list, int position, int value) {
    if (position < 0 || position >= list->size) {
        printf("Posição inválida!\n");
    } else {
        list->data[position] = value;
    }
}

void insertElement(List *list, int position, int value) {
    if (isFull(list)) {
        printf("Lista cheia!\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = list->size; i > position; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position] = value;
    list->size++;
}

void removeElement(List *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = position; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

int main() {
    List list;
    createList(&list);

    insertElement(&list, 0, 10); 
    insertElement(&list, 1, 20); 
    insertElement(&list, 1, 15); 

    printf("Tamanho da lista: %d\n", getSize(&list)); 

    for (int i = 0; i < getSize(&list); i++) {
        printf("Elemento na posição %d: %d\n", i+1, getElement(&list, i)); 
    }

    setElement(&list, 1, 25);

    printf("\nApós modificação:\n");
    for (int i = 0; i < getSize(&list); i++) {
        printf("Elemento na posição %d: %d\n", i+1, getElement(&list, i));
    }

    removeElement(&list, 1); 

    printf("\nApós remoção:\n");
    for (int i = 0; i < getSize(&list); i++) {
        printf("Elemento na posição %d: %d\n", i+1, getElement(&list, i)); 
    }

    printf("Tamanho da lista: %d\n", getSize(&list));

    return 0;
}