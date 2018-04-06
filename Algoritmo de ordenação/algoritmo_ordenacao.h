/* Estamos usando LONG INT  pois o vetor de numero grande sendo lido de um arquivo*/

// Cria um arquivo com com qualquer quantidade de numeros
void gera_numeros_aleatorios();

// Essa função salva num arquivo os dados de execução do algoritmo 
void armazena_Arq(double final_time,  int qtd_vetor, char string[30]);

// Apenas imprime o vetor ordenado
void imprimeVetor( long int *v, int n);

//Usa o metoto de buble sorte como metodo de ordenação
void bubleSort( long int *v, int n);

//Primeira versao do buble sort sem verificar os numeros ordenados no fim do vetor
void bubleSortV1(long int *v, int n);

// Segunda versao do Buble  que verifica a cada momento se  o vetor esta ordenado  com uma variavel controlando a ordenação com uma variavel troca
void bubleSortV2( long int *v, int n);

// Ordena na inserção
void insertionsort(long int *v, int n);

///
void selection_sort (long int vetor[],int max);