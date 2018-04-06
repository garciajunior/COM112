#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Criado o tipo Funcionarios  com atributos de Nome e salario
typedef struct func_sal
{
	char nome[100];
	double sal;
	
} funcionario;
// prototipo das funçoes para permitir a logica de  programação topDown
void preencheVetorFun(funcionario *f);
void bubleSortV2( funcionario *f, int n);
void bubleSortV2_String( funcionario *f, int n);
void imprimeVeorFun( funcionario *f, int n);
/*****************************************************************************************/
/** Função principal                                    */
/******************************************************************************/
int main(int argc, char const *argv[])
{
	int n = 10;
	funcionario f[n];
	preencheVetorFun(f);
	bubleSortV2(f,n);
	imprimeVeorFun(f,n);
	printf("-------------------------------------------------------------\n");
	bubleSortV2_String(f,n);
	imprimeVeorFun(f,n);

	return 0;
}

/*****************************************************************************************/
/** Preenche o vetor um  a um                                 */
/******************************************************************************/

void preencheVetorFun(funcionario *f)
{
	strcpy(f[0].nome,"Antonio");
	f[0].sal = 950.12;

	strcpy(f[1].nome,"Joao");
	f[1].sal = 900.17;

	strcpy(f[2].nome,"Maria");
	f[2].sal = 900.13;

	strcpy(f[3].nome,"Fernando");
	f[3].sal = 900.50;	

	strcpy(f[4].nome,"Viviane");
	f[4].sal = 930.19;

	strcpy(f[5].nome,"Jessica");
	f[5].sal = 980.14;

	strcpy(f[6].nome,"Francisco");
	f[6].sal = 970.15;

	strcpy(f[7].nome,"David");
	f[7].sal = 990.12;

	strcpy(f[8].nome,"Jorge");
	f[8].sal = 970.89;

	strcpy(f[9].nome,"Paola");
	f[9].sal = 940.16;
}
/*****************************************************************************************/
/** Função do bublesort versao 2                                   */
/******************************************************************************/
void bubleSortV2( funcionario *f, int n)
{
	// ordenando de forma decrescente
	int num = 1, i, troca = 1;
	double  aux = 0;
	while(num <= n && troca == 1)
	{		
		troca = 0;
		for( i = 0; i < n -1; i++)
		{
			if( f[i].sal < f[i+1].sal)
			{
				troca = 1;
				aux = f[i].sal;
				f[i].sal = f[i+1].sal;
				f[i+1].sal = aux;
			}
		}
		num++;
	}
}

void imprimeVeorFun( funcionario *f, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" O nome do funcionarios %s\n e o Salario %.2f\n",f[i].nome, f[i].sal );
	}
}

/*****************************************************************************************/
/**BubleSort para as strings ordenando-as pela menor string( ordem alfabetica)                                */
/******************************************************************************/
void bubleSortV2_String( funcionario *f, int n
){
	// ordenando de forma decrescente
	int num = 1, i, troca = 1;
	char aux[100];
	while(num <= n && troca == 1)
	{		
		troca = 0;
		for( i = 0; i < n -1; i++)
		{
			if( strcmp(f[i].nome,f[i+1].nome ) > 0)
			{
				troca = 1;
				strcpy (aux, f[i].nome);
				
				strcpy(f[i].nome,f[i+1].nome);
				strcpy(f[i+1].nome, aux);
			}
		}
		num++;
	}

}