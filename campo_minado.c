#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

const int L = 7;
const int C = 7;
int m[L][C];
int pontos, numColuna, numLinha;
int x, y;
char op[3];

void matriz();
void campo();
void mostrarMatriz();

void matriz() {
  int i, j;
  srand(time(NULL));
  for(i = 0; i < L; i++) {
    for(j = 0; j < C; j++) {
      m[i][j] = rand() % 2;
    }
  }
}

void mostrarMatriz() {
  int i, j;
  numLinha = 0;
  numColuna = 0;
  for(i = 0; i < L; i++) {
    for(j = 0; j < C; j++) {
      if(i == 0 && j == 0) {
        printf("--");
      }
      else if(i == 0 && j > 0) {
        printf(" %d ", numColuna + 1);
        numColuna++;
      }
      else if(i > 0 && j == 0) {
        printf(" %d", numLinha + 1);
        numLinha++;
      }
      else if(m[i][j] == 2) {
        printf(" 0 ");
      }
      else {
        printf(" * ");
      }
    }
    printf("\n");
  }
}

void campo() {
  pontos = 0;
  do {
    mostrarMatriz();
    printf("Digite uma linha e uma coluna: \n");
    printf("Linha: ");
    scanf("%d", &x);
    printf("\nColuna: ");
    scanf("%d", &y);
    if(m[x][y] == 0) {
      m[x][y] = 2;
      pontos++;
    }
    else if(m[x][y] == 2) {
      printf("\nCasa já visitada!\n\n");
      continue;
    }
    if(x >= L || y >= C) {
      printf("Por favor digite uma linha e uma coluna válida!\n\n");
      continue;
    }
  } while(m[x][y] != 1);
  printf("---------VOCÊ PERDEU!-----------\n\nPontos = %d\n\n", pontos);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  matriz();
  campo();
  printf("Deseja jogar de novo? Digite \"sim\" para jogar novamente; digite \"não\" para encerrar: ");
  scanf("%s", &op);
  while(!strcmp("sim", op) || !strcmp("SIM", op)) {
    matriz();
    campo();
    printf("Deseja jogar de novo? Digite \"sim\" para jogar novamente; digite \"não\" para encerrar: ");
    scanf("%s", &op);
  }
  printf("-----Obrigado por jogar!---------");
  return 0;
}
