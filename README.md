Implementação de Árvore Binária de Busca
 A árvore binária de busca é uma estrutura de dados que permite armazenar e organizar dados de forma eficiente, possibilitando operações rápidas de inserção, busca e travessia. Abaixo estão descritas as principais funções e suas funcionalidades.

Funcionalidades
Criação de Nós
Função: struct Node* createNode(int data)
Descrição: Cria um novo nó para a árvore binária de busca, alocando memória e inicializando o valor com o dado fornecido (data). Os ponteiros para os filhos esquerdo e direito são configurados como NULL.
Inserção de Nós
Função: struct Node* insert(struct Node* root, int data)
Descrição: Insere um novo valor na árvore. Se a árvore estiver vazia (root é NULL), chama createNode para criar um novo nó. Caso contrário, compara o valor a ser inserido com o valor do nó atual para decidir a posição correta.
Busca Iterativa
Função: int iterativeSearch(const struct Node* root, int key)
Descrição: Realiza uma busca iterativa na árvore para encontrar um valor específico (key). Percorre a árvore e retorna 1 se o valor for encontrado ou 0 caso contrário, evitando o uso de recursão.
Contagem de Nós
Função: int iterativeCount(const struct Node* root)
Descrição: Conta o número total de nós na árvore utilizando uma abordagem iterativa com uma pilha, incrementando um contador a cada nó visitado.
Impressão em Ordem
Função: void iterativePrint(const struct Node* root)
Descrição: Imprime os valores dos nós da árvore em ordem (in-order traversal), garantindo que os valores sejam apresentados em sequência crescente, utilizando uma pilha para armazenar os nós.
Execução do Programa
Função: int main()
Descrição: Serve como ponto de entrada do programa, criando uma árvore binária de busca, inserindo valores, realizando buscas, contando nós e imprimindo os valores da árvore em ordem. Demonstra as funcionalidades implementadas e exemplifica o uso da árvore.
