#include <stdio.h>
#include <stdlib.h>

/*Conteúdo: 
	- Alocação dinâmica e Memória Heap...
	- realloc()
	- calloc()
*/

void manipulacaoVetorHeap(){
	int i, qtdade;
	
	//construindo um vetor de "qtdade" posições de inteiros na memoria heap
	printf("Digite a quantidade de números a serem armazenados no vetor: ");
	scanf("%i", &qtdade);
	
	int *vetorHeap = malloc(qtdade * sizeof(int));
	
	printf("Vetor apos atribuicao:\n");
	for(i=0;i<qtdade;i++){
		*(vetorHeap+i) = i*10;
		printf("%i ", *(vetorHeap+i));
	}
	printf("\n");
	
	//modificando o espaço de memória alocado anteriormente:
	int novaQuantidade = 2 * qtdade;
	vetorHeap = realloc(vetorHeap, novaQuantidade * sizeof(int));
	
	printf("Vetor apos realocacao:\n");
	for(i=0;i<novaQuantidade;i++){
		printf("%i ", *(vetorHeap+i));
	}
	printf("\n");
	
	printf("Desalocando o vetor na Memoria Heap\n");
	free(vetorHeap);
	printf("***********************************\n\n");
	
	//realloc() possui as funções malloc() e free() embutidas:
	
	//segunda forma de alocar dinamicamente certa quantidade de bytes, malloc():
	//int *vetorHeap = realloc(NULL, qtdade * sizeof(int));
	
	//terceira forma de alocar dinamicamente certa quantidade de bytes, malloc():
	//int *vetorHeap = NULL;
	//vetorHeap = realloc(vetorHeap, qtdade * sizeof(int));
	
	//para desalocar, free()
	//vetorHeap = realloc(vetorHeap, 0);
}

void manipulacaoVetorHeapCalloc(){
	int i, qtdade=10;
	
	//todos os valores são inicializados com zero
	printf("Vetor de inteiros com calloc():\n");
	
	//int *vetorHeap = malloc(qtdade * sizeof(int));
	int *vetorHeap = calloc(qtdade, sizeof(int)); 
	
	for(i=0;i<qtdade;i++)
		printf("%i ", *(vetorHeap+i));
	printf("\n");
		
	*(vetorHeap+5) = 7;
	for(i=0;i<qtdade;i++)
		printf("%i ", *(vetorHeap+i));
	
	free(vetorHeap);
	printf("\n***********************************\n\n");
}

void manipulacaoMatrizHeap(){
	int i, j, nLinhas, nColunas;
	
	//construindo uma matriz[nLinhas][nColunas] de inteiros na memoria heap
	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%i", &nLinhas);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%i", &nColunas);
	
	int **matrizHeap = malloc(nLinhas * sizeof(int *));
	for (i=0; i<nLinhas; i++)
		matrizHeap[i] = malloc(nColunas * sizeof(int));
	
	printf("Matriz apos atribuicao:\n");
	for(i=0;i<nLinhas;i++){
		for(j=0;j<nColunas;j++){
			*(matrizHeap[i]+j) = i*j;
			printf("%i ", *(matrizHeap[i]+j));
		}
		printf("\n");
	}
	
	//modificando o espaço de memória alocado anteriormente:
	int novasLinhas = nLinhas + 2;
	int novasColunas = nColunas + 1;
	
	matrizHeap = realloc(matrizHeap, novasLinhas * sizeof(int *));
	for (i=0; i<novasLinhas; i++){
		if (i < nLinhas)
			matrizHeap[i] = realloc(matrizHeap[i], novasColunas * sizeof(int));
		else
			matrizHeap[i] = malloc(novasColunas * sizeof(int));
	}
		
	printf("Matriz apos realocacao ([%i][%i]):\n", novasLinhas, novasColunas);
	for(i=0;i<novasLinhas;i++){
		for(j=0;j<novasColunas;j++){
			*(matrizHeap[i]+j) = i*j;
			printf("%i ", *(matrizHeap[i]+j));
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Desalocando a matriz na Memoria Heap\n");
	for (i=0; i<novasColunas; i++)
		free(matrizHeap[i]);
	free(matrizHeap);
	printf("***********************************\n\n");
}

int main(){
	//manipulacaoVetorHeap();
	//manipulacaoVetorHeapCalloc();
	manipulacaoMatrizHeap();
	
	return 0;
}
