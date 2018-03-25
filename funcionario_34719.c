#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubleSortV2( int *v, int n, int *comp, int *mov);
void imprimeVetor(int *v, int n);


int main(int argc, char const *argv[])
{
	//inicializando o vetor com o pior e melhor caso
	int v[7] = {7,6,5,4,3,2,1};
  //int v[7] = {1,2,3,4,5,6,7};
	int n = 7, mov = 0, comp = 0; 
	bubleSortV2( v,n,&comp,&mov);
	imprimeVetor( v,n);
	printf("\nA quantidades de troca e %d\n",comp );
	printf("A quantidades de movimentos e %d\n", mov);

	return 0;
}


void imprimeVetor( int *v, int n)
{
	// mostrando o vetor ordenado
			printf("O vetor esta ordenado\n");
			for (int i = 0; i < n; i++)
			{
				
				printf("%d\t",v[i] );
			}
}

void bubleSortV2( int *v, int n, int *comp, int *mov)
{
	// ordenando de forma decrescente
	int num = 1, i, aux, troca =1;

	while(num <= n && troca == 1)
	{
		// acrescenta 1 comparação
      (*comp)++; 

		troca = 0;
		for( i = 0; i < n -1; i++)
		{
			if( v[i] < v[i+1])
			{
				// acrescenta 1 movimentação
        		(*mov)++;
				troca = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		num++;
	}
}




