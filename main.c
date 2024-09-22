#include <stdio.h>
#include <stdlib.h>
#include "preenchimento.h"
#include "resolucao.h"

int main() {
	int n, N, M, i, j;
	double **matriz, *u, *baixo, *esquerda, *direita, *cima, *b;

	scanf("%d", &n);

	N = (n-1)*(n-1);
	M = 2*(n-3)+5;

	// INICIALIZA VETOR INDEPENDENTE
	baixo = (double*)malloc((n-1)*sizeof(double));
	esquerda = (double*)malloc((n-1)*sizeof(double));
	direita = (double*)malloc((n-1)*sizeof(double));
	cima = (double*)malloc((n-1)*sizeof(double));
	
	inicializaCondicoesIniciais(n-1, baixo, esquerda, direita, cima);
	
	b = preencheVetorIndependente(n, N, baixo, esquerda, direita, cima);

	// INICIALIZA VETOR SOLUÇÃO ZERADO
	u = (double*)malloc(N*sizeof(double));
	for(i=0; i<N; i++) u[i] = 0.0;

	// INICIALIZA MATRIZ DOS COEFICIENTES
	matriz = (double**)malloc(N*sizeof(double*));
	for(i=0; i<N; i++)
		matriz[i] = (double*)malloc(M*sizeof(double));

	preencheMatriz(matriz, n, N, M);

	// TRANSFORMA A MATRIZ EM TRIANGULAR INFERIOR
	eliminacaoSeletiva(matriz, n, N, M, b);

	// DETERMINA A SOLUÇÃO POR SUBSTITUIÇÃO REGRESSIVA
	substituicaoRegressiva(matriz, n, N, M, u, b);

	// CALCULA A RELAÇÃO ENTRE O ELEMENTO u[k] E O PONTO u{i,j} E IMPRIME A SOLUÇÃO 
	printf("SOLUCAO:\n");
	for(j=n-2; j>=0; j--) {
		for(i=0; i<n-1; i++)
			printf("u[%d,%d]=%0.2lf\t", (i+1), (j+1), u[i+j*(n-1)]);
		printf("\n");
	}
	
	// LIBERAÇÃO DE MEMÓRIA
	free(baixo);
	free(esquerda);
	free(direita);
	free(cima);
	free(b);
	free(u);
	for(i=0; i<N; i++)
		free(matriz[i]);
	free(matriz);

	return 0;
}