// Criado em 16/03/2018
#include "stdio.h"
#include "stdlib.h"


/*****************************************************************************************/
/** Prototipos                                                                           */
/*****************************************************************************************/
void bubblesort(int *V, int n);
void insertionsort(int *V, int n);


/*****************************************************************************************/
/** Programa principal                                                                   */
/*****************************************************************************************/
int main(void) {
  
  int n = 5;
  int V[n], i, metodo;
  
  // carregando os números no vetor
  for(i=0;i<=(n-1);i++)
  {
    printf("Digite o %iº número: ", i+1);
    scanf("%i", &V[i]);
  }
  
  // menu
  do{
    printf("\n\nEscolha o método de ordenação: \n");
    printf("1. Bubble Sort \n");
    printf("2. Insertion Sort \n");
    printf("3. Sair \n\n Método: ");
    scanf("%i", &metodo);
    
    // ordenando em ordem crescente
    switch(metodo)
    {
      case 1: bubblesort(V, n);
              break;
      case 2: insertionsort(V, n);
              break;    
      default:
              break;
    }
    
    if(metodo != 3)
    {  
      //mostrando o vetor ordenado
      printf("\nVetor ordenado: ");
      for(i=0;i<=4;i++)
      {
        printf("%i ", V[i]);
      }
    }
  }while(opcao != 3);
  
  return 0;
}



/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort (ordem crescente)                                    */
/*****************************************************************************************/
void bubblesort(int *V, int n){

  int aux;  
  
  // laço com a quantidade de elementos do vetor
  for(int i=0;i<=n;i++)
  {
    // laço que percorre da primeira à penúltima posição do vetor
    for(int j=0;j<=(n-2);j++)
    {
      if(V[j] > V[j+1]){
        aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
    }
  }
}



/*****************************************************************************************/
/** Metodo de ordenacao Insertion Sort (ordem crescente)                                    */
/*****************************************************************************************/
void insertionsort(int *V, int n){

  int eleito, j;  
  
  // laço com a quantidade de elementos do vetor - 1
  for(int i=0;i<=(n-1);i++)
  {
    eleito = V[i];
    j = i - 1;
    
    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    while(j >= 0 && V[j] > eleito)
    {
      V[j+1] = V[j];
      j--;
    }
    
    V[j+1] = eleito;
  }
}