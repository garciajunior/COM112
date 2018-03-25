#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tproduto
{
	char descricao[500];
	double preco;
	int cod;
	
} prod;

void preencheVetorProd(prod *p);
void bubleSortV2_String( prod *p, int n);
void imprimeVetorprod( prod *p, int n);
int buscaSequencial(prod *p, int n);



int main(int argc, char const *argv[])
{
	int n = 10;
	prod p[n];
	preencheVetorProd(p);
	bubleSortV2_String(p,n);
	imprimeVetorprod(p,n);
	printf("A quantidade de comparaçoes que foram encontradas e : %d.\nPara achar o produto %s com o codigo %d e o preco %.2f\n",buscaSequencial(p,n),p[9].descricao,p[9].cod,p[9].preco);

	return 0;
}



void preencheVetorProd(prod *p)
{
	strcpy(p[0].descricao,"Espatula");
	p[0].preco = 50.12;
	p[0].cod = 100; 

	strcpy(p[1].descricao,"Colher de pedreiro");
	p[1].preco = 80.17;
	p[1].cod = 362;

	strcpy(p[2].descricao,"Prumo");
	p[2].preco = 60.13;
	p[2].cod = 874;

	strcpy(p[3].descricao,"Talhadeira");
	p[3].preco = 63.50;	
	p[3].cod = 761;

	strcpy(p[4].descricao,"Linha de pedreiro");
	p[4].preco = 30.19;
	p[4].cod = 632;

	strcpy(p[5].descricao,"Desempenadeira lisa ");
	p[5].preco = 80.14;
	p[5].cod = 534;

	strcpy(p[6].descricao,"Sarrafo");
	p[6].preco = 70.15;
	p[6].cod = 462;

	strcpy(p[7].descricao,"Filtro");
	p[7].preco = 90.12;
	p[7].cod = 331;

	strcpy(p[8].descricao,"Esquadro");
	p[8].preco = 20.89;
	p[8].cod = 271;

	strcpy(p[9].descricao,"Marreta");
	p[9].preco = 40.16;
	p[9].cod = 132;
}
void imprimeVetorprod( prod *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Codigo %d Descricao '%s' Preco R$ %.2f\n", p[i].cod, p[i].descricao,p[i].preco);
	}
}
void bubleSortV2_String( prod *p, int n)
{
	// ordenando de forma decrescente
	int num = 1, i, troca = 1;
	char aux[500];
	while(num <= n && troca == 1)
	{		
		troca = 0;
		for( i = 0; i < n -1; i++)
		{
			if( strcmp(p[i].descricao,p[i+1].descricao ) > 0)
			{
				troca = 1;
				strcpy (aux, p[i].descricao);				
				strcpy(p[i].descricao,p[i+1].descricao);
				strcpy(p[i+1].descricao, aux);
			}
		}
		num++;
	}

}
int buscaSequencial(prod *p, int n)
{
	int i, x = 132;

	for (i=0; i<n; i++)
		if (p[i].cod == x)
			return(i); /*chave encontrada*/
	return(-1); /*chave não encontrada*/
}
