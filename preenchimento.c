#include <stdio.h>
#include <stdlib.h>


void inicializaCondicoesIniciais(int n, double *baixo, double *esquerda, double *direita, double *cima) {
	int i;
	
	for(i=0; i<n; i++) {
		baixo[i] = 0.0;
		esquerda[i] = 0.0;
		direita[i] = 100.0*(i+1)/(n+1);
		cima[i] = 100.0*(i+1)/(n+1);
	}
}

double *preencheVetorIndependente(int n, int N, double *baixo, double *esquerda, double *direita, double *cima) {
	int i;
	double *b = (double*)malloc(N*sizeof(double));
	
	for(i=1; i<N-1; i++){
		//laterais
		if(i>0 && i<(n-2))
			b[i]=-baixo[i];
		else if(i%(n-1)==0 && i!=(N-n+1))
			b[i]=-esquerda[i/(n-1)];
		else if((i+1)%(n-1)==0 && i!=(n-2))
			b[i]=-direita[(i+1)/(n-1)-1];
		else if(i>(N-n+1) && i<(N-1))
			b[i]=-cima[i-N+n-1];
		
		//internos
		else
			b[i]=0.0;
	}
	
	//cantos
	b[0]=-baixo[0]-esquerda[0];
	b[n-2]=-baixo[n-2]-direita[0];
	b[N-n+1]=-esquerda[n-2]-cima[0];
	b[N-1]=-direita[n-2]-cima[n-2];
	
	return b;
}

void preencheMatriz(double **matriz, int n, int N, int M) {
	int i;

	for(i=0; i<N; i++) {
		matriz[i][0] = (i<n-1)?0.0:1.0;

		matriz[i][M/2-1] = (i%(n-1)==0)?0.0:1.0;

		matriz[i][M/2] = -4.0;

		matriz[i][M/2+1] = ((i+1)%(n-1)==0)?0.0:1.0;

		matriz[i][M-1] = (i<=N-n)?1.0:0.0;
	}
}
