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

int main(int argc, char const *argv[])
{

	// Inicio da função que marca o tempo de execução
	clock_t time;
	time = clock();
	double tempo = 0;
	// fim da função tempo, mas o printf esta no fim do programa 
	// declaração de variaveis 
	char buble[30];
	int n = 100000;
	int  opcao , cont = 0;
	int qtd_menu = 4;
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
		printf("4. Sair \n");
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
				break;
			default:
				break;
		}
		if ( opcao != qtd_menu)
		{
			printf("entrei no if\n");
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
	 int i = 4;
	 if( !arq)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(1);
	}

	fprintf(arq,"%d.) O Algoritmo executado %s, o TEMPO gasto em segundos %f, e a quantidade de numeros do vetor %d\n.",i++,string,final_time,qtd_vetor );
}
// *********************inicio do bublesort normal***************************************
void bubleSort( long int *v, int n)
{
	int aux = 0;
	// laço com a quantidade de elementos do vetor
	for (int i = 0; i < n; i++)
	{
		// laço que percorre da primeira a penultima posição do vetor
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
		for( i = 0; i < n -1; i++)
		{
			if( v[i] < v[i+1])
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








