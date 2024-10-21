#include "queue.h"
#include <time.h>


void jackpot(int n, int r) {
    // Cria os n carretéis
    Queue *carreteis[n];
    for (int i = 0; i < n; i++) {
        carreteis[i] = create(r);  // Cria um carretel de tamanho r

        // Inicializa cada carretel com r números aleatórios entre 1 e 9
        for (int j = 0; j < r; j++) {
            int num = (rand() % 9) + 1;  // Gera números aleatórios entre 1 e 9
            enqueue(carreteis[i], num);  // Enfileira o número no carretel
        }
    }

    int ganhou = 0;

    // Simula o jogo até o jogador ganhar
    while (!ganhou) {
        // Gira cada um dos carretéis
        for (int i = 0; i < n; i++) {
            int num_giros = rand() % r;  // Número aleatório de giros

            // Realiza o número aleatório de giros no carretel
            for (int j = 0; j < num_giros; j++) {
                int num = dequeue(carreteis[i]);  // Remove o elemento da frente
                enqueue(carreteis[i], num);  // Coloca o elemento de volta na traseira
            }
        }

        // Imprime o estado atual dos carretéis
        printf("\nEstado atual dos carretéis:\n");
        for (int i = 0; i < n; i++) {
            printf("Carretel %d: ", i + 1);

            // Imprime cada elemento da fila
            int tamanho = getsize(carreteis[i]);
            for (int j = 0; j < tamanho; j++) {
                int num = dequeue(carreteis[i]);
                printf("%d ", num);
                enqueue(carreteis[i], num);  // Reenfileira o número
            }
            printf("\n");
        }

        // Verifica se o jogador ganhou
        int primeiro = front(carreteis[0]);
        ganhou = 1;  // Inicializa como ganho

        // Verifica se todos os carretéis têm o mesmo valor na frente
        for (int i = 1; i < n; i++) {
            int atual = front(carreteis[i]);
            if (atual != primeiro) {
                ganhou = 0;  // Se algum valor for diferente, o jogador não ganhou
                break;
            }
        }

        if (ganhou) {
            printf("\nParabéns! Você ganhou!\n");
        } else {
            printf("\nTente novamente...\n");
        }
    }

    // Libera a memória alocada para os carretéis
    for (int i = 0; i < n; i++) {
        destroy(carreteis[i]);
    }
}

int main() {
    srand(time(NULL));	
    int n = 3;  // Número de carretéis
    int r = 10; // Tamanho de cada carretel

    // Chama a função jackpot
    jackpot(n, r);

    return 0;
}
