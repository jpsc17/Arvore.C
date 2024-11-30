#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função de busca iterativa
int iterativeSearch(const struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return 1; // Encontrado
        }
        root = (key < root->data) ? root->left : root->right;
    }
    return 0; // Não encontrado
}

// Função para contar o número de nós na árvore
int iterativeCount(const struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* stack[100];
    size_t top = 0; // Usar size_t para o índice da pilha

    stack[top++] = root;

    while (top > 0) {
        struct Node* current = stack[--top];
        count++;

        if (current->right != NULL) {
            stack[top++] = current->right;
        }
        if (current->left != NULL) {
            stack[top++] = current->left;
        }
    }

    return count;
}

// Função para imprimir a árvore em ordem
void iterativePrint(const struct Node* root) {
    struct Node* stack[100];
    size_t top = 0; // Usar size_t para o índice da pilha
    const struct Node* current = root;

    while (current != NULL || top > 0) {
        while (current != NULL) {
            stack[top++] = current;
            current = current->left;
        }

        current = stack[--top];
        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {
    struct Node* root = NULL;

    // Inserindo valores na árvore
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 40;
    printf("Busca pelo valor %d: %s\n", key, iterativeSearch(root, key) ? "Encontrado" : "Não encontrado");

    printf("Número total de nós: %d\n", iterativeCount(root));

    printf("Árvore em ordem: ");
    iterativePrint(root);
    printf("\n");

    return 0;
}
