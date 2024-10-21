#include "queue.h"
#include <time.h>

int main () {
  int i, n = 10;	
  // a questão 1 eh so uma manipulaçao de arquivos, vou chamar as funcoes na main para fazer as duas filas
  srand(time(NULL));
  // vamos criar as duas filas fila
  Queue *filapares= create(n);
  Queue *filaimpares= create(n);
  //vamos gerar os numeros aleatorios com uma while, nesse caso vamos gerar 10n
  while(n!=0){
      i = rand() % 100;  
      printf("numero aleatorio gerado: %d\n", i);
      //verifica se é par ou impar
      if (i % 2 == 0) 
      {
        printf("Par\n");
        //insere na fila para pares
        enqueue(filapares, i);
      }
      else 
      {
        printf("Impar\n");
        //insere na fila para impares
        enqueue (filaimpares, i);
      }

      n--;
    }
    printf("\nConteudo da fila par:\n");
    print(filapares);


    printf("\nconteudo da fila Impar:\n");
    print (filaimpares);


  // por fim desalocar as filas que alocamos
  destroy (filaimpares);
  destroy (filaimpares);

  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
   system("pause");
  return 0;
}

