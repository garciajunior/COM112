#include "algoritmo_ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Prototipos das funçoes dos algoritmos de ordenação
void armazena_Arq(double final_time,  int qtd_vetor, char string[30]);
void imprimeVetor( long int *v, int n);
void bubleSort( long int *v, int n);
void bubleSortV1(long int *v, int n);
void bubleSortV2( long int *v, int n);
void insertionsort(long int *v, int n);
void selection_sort (long int vetor[],int max);


//**********************Função de impressao de vetor*************
void imprimeVetor( long int *v, int n)
{
	// mostrando o vetor ordenado
			printf("O vetor esta ordenado\n");
			for (int i = 0; i < n; i++)
			{
				
				printf("%ld\t",v[i] );
			}
}
/************ Funao que armazena no arquivo os resultados dos tempos**********/
void armazena_Arq(double final_time, int qtd_vetor, char string[30])
{
	FILE *arq;
	 arq = fopen( "ArmazenaDados.txt","a+");
	 

	 if( !arq)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(1);
	}
	
	fprintf(arq,"\nO Algoritmo executado %s, o TEMPO gasto em segundos %f, e a quantidade de numeros do vetor %d.\n",string,final_time,qtd_vetor );
}
// *********************inicio do bublesort normal***************************************
void bubleSort( long int *v, int n)
{
	int aux = 0;
	// laço com a quantidade de elementos do vetor
	for (int i = 0; i < n; i++)
	
{		// laço que percorre da primeira a penultima posição do vetor
		for (int j = 0; j <= n-2; j++)
		{
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				
			}
		}
	}
}
//**************************** fim bubleSort normal**************************************
// ****************************Inicio buble sort versao melhorada 1 ************************
void bubleSortV1(long int *v, int count)
{// o vetor de numeros vem do arquivo
	int i, aux = 0;
	
	// for com quantidade de numeros do vetor menos um
	for (int j = 0; j <= count-1; j++)
	{// percorre da ultima posição i do vetor

		for (i = count; i >= j; i--)
		{
			if ( v[i] < v[i-1])
			{
				
				// troca simples
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
			}
		}
	}
}
//***************************** bubleSort sort versao melhorada 1****************************
//***************************** BUBLESORT 	VERSAO MELHORADA 2*******************************
void bubleSortV2( long int *v, int n)
{
	// ordenando de forma decrescente
	int num = 1, i, aux, troca =1;

	while(num <= n && troca == 1)
	{
		troca = 0;
		for( i = 0; i < (n - 1); i--)
		{
			if( v[i] > v[i+1])
			{
				troca = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		num++;
	}
}

void insertionsort(long int *v, int n)
{

  int eleito, j;  
  
  // laço com a quantidade de elementos do vetor - 1
  for(int i=0;i<=(n-1);i++)
  {
    eleito = v[i];
    j = i - 1;
    
    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    while(j >= 0 && v[j] < eleito)
    {
      v[j+1] = v[j];
      j--;
    }
    
    v[j+1] = eleito;
  }
}

void selection_sort (long int vetor[],int max) 
{
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) 
  {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < max; j++) 
    {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) 
      {
   		min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) 
    {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }
}




