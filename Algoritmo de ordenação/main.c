#include "algoritmo_ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(int argc, char const *argv[])
{	//***************gera arquivo de numeros aleatorios************
	// nao sendo necessario chama-la a toda execução da ordenação apenas quando desejar mudar a quantidade de codigo
	void gera_numeros_aleatorios();
	//********************************
	// Inicio da função que marca o tempo de execução
	clock_t time;
	time = clock();
	double tempo = 0;
	// fim da função tempo, mas o printf esta no fim do programa 
	// declaração de variaveis 
	char buble[30] = "Erro";
	int n = 100000;
	int  opcao , cont = 0;
	int qtd_menu = 6;
	//  abertura do arquivo
	/* Temos dois arquivos 
		1) para trazer os numeros do arquivo para nao inserir na mao.
		2) para armazenar os resultados dos tempos de execução por cada vez que o algoritmo for executado.
		*/
	FILE *arq;
	arq = fopen( "junior_1000000_aleatorios com srands.txt", "r+");
	if( !arq)
	{
		printf("Nao foi possivel abrir arquivo\n");
		exit (1);
	}
	
	// fim abertura do arquivo
	//alocação dinaminca do vetor
 
	long int *v = (long int*) calloc ( n,sizeof (long int));
	// fim da alocação dinamica do arquivo

	// leitura do arquivo com os vetores de numeros.
	

	while( (fscanf(arq,"%ld", &v[cont])) != EOF)
	{
		
		printf("%ld\t", v[cont]);
		cont++;
	}
	// fim da leitua do arquivo de numeros
	
	do
	{
		system("clear");
		printf("\nInforme a opção desejada:\n");
		printf("1. BubleSort: \n");
		printf("2. BubleSort VERSAO melhorada 1:\n");
		printf("3. BubleSort VERSAO melhorada 2:\n");
		printf("4. Insertion Sort \n");
		printf("5. Select Sort \n");
		printf("6. Sair \n");
		scanf("%d", &opcao);

	

		switch( opcao)
		{
			case 1 : 
				bubleSort(v, n);
				strcpy(buble,"BubleSort");
				break;
			case 2 :			
				bubleSortV1(v,n);
				strcpy(buble,"BubleSort V1");
				break;
			case 3: 
				bubleSortV2(v,n);
				strcpy(buble,"BubleSort V2");
				break;
			case 4: 
				insertionsort(v,n);
				strcpy(buble, "insertion Sort");
				break;
			case 5: 
				selection_sort(v,n);
				strcpy(buble, "Select Sort");
				break;
			case 6: 
				break;
			default:
				break;
		}
		if ( opcao != qtd_menu)
		{
			imprimeVetor(v,n);
		}

	}while( opcao != qtd_menu);

	printf("\n\n*******************TIME**************************\n");
	// variavel recebe o valor do tempo de execução do programa
	tempo = (clock() - time)/(double)CLOCKS_PER_SEC;
	printf("Tempo de execucao e %f\n", tempo);
	armazena_Arq(tempo,n,buble);

	return 0;
}