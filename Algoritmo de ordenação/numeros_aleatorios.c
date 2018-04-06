#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	FILE *arc;

	arc = fopen( "junior_1000000_aleatorios com srands.txt", "w+");
	if( !arc)
	{
		printf("Nao foi possivel abrir arquivo\n");
		exit (1);
	}
	int li = 1000, col = 100;
	long int mat[li][col];
	srand(time(NULL));

	for (int i = 0; i < li; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[li][col] = rand() %100000;
			fprintf(arc, "%ld\n",mat[li][col] );
		}
	}
	fclose(arc);

	return 0;
}