#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarConfiguracao(int m, int q) { 
  int min = 0, max = m-1;

  char tabuleiro[m][m];

  // produzir o tabuleiro com ---- sem nenhuma rainha
  for (int i = 0; i < m; i++){
     for (int j = 0; j < m; j++){
       tabuleiro[i][j] = '-';
     }
  }

  int it = 0;

  //inserir q rainhas (D) segundo nos indices gerados aleatoriamente
  while (it < q){
    // i: indice linha
    int i = (rand() % (max - min + 1)) + min;

    // j: indice coluna
    int j = (rand() % (max - min + 1)) + min;

    //caso nao haja rainha D nos endereco tabuleiro[i][j]
    // insira a rainha
    if (tabuleiro[i][j] != 'D'){
      tabuleiro[i][j] = 'D';
      it++;
    }
  }

  //imprimir a configuracao (tabuleiro)
  for (int i = 0; i < m; i++){
     for (int j = 0; j < m; j++){
       printf("%3c", tabuleiro[i][j]);
     }
     printf("\n");
  }
  printf("\n");

}


int main(int argc, char *argv[]) {
  int m, n, q;

  //a seed que utiliza o tempo para permitir gerar numeros aleatorios
  srand((unsigned)time(NULL));

  if (argc == 4) { //Caso tenha fornecido seguintes argumentos: ./random M N Q
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    q = atoi(argv[3]);
  }
  else if (argc == 2) { //Caso tenha fornecido seguintes argumentos: ./random M 
    m = atoi(argv[1]);
    n = atoi(argv[1]);
    q = atoi(argv[1]);   
  }
  else if (argc < 2 || argc == 3 || argc < 4) { //Caso nao tenha fornecido nenhum argumento 
    printf("Usage: ./main m n q\n");
    return 3;
  }

  //gerar n configuracao de m x m, cada configuracao contendo q rainhas (D)
  for (int i = 0; i < n; i++){
    printf("Configuracao #%2d: \n", i+1);
    //gerar configiracao
    gerarConfiguracao(m, q);
    printf("\n\n");
  }
  
  return 0;
}