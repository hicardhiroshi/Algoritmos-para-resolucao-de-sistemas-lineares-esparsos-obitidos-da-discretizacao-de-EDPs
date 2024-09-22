#include <stdio.h>

void divideLinha(double **matriz, int M, double *b, int pos) {
	int i;
	double divisor;

	divisor = matriz[pos][M/2];

	for(i=M/2; i<M; i++)
		matriz[pos][i] = matriz[pos][i]/divisor;

	b[pos] = b[pos]/divisor;
}

void operaLinhas(double **matriz, int M, double *b, int pos1, int pos2) {
	int i, dist;
	double multiplicador;

	dist = pos2 - pos1;
	multiplicador = matriz[pos2][M/2 - dist];
	
	for(i=0; i<M-1; i++)
		matriz[pos2][i] = matriz[pos2][i]-multiplicador*matriz[pos1][i+dist];

	b[pos2] = b[pos2]-multiplicador*b[pos1];
}

void eliminacaoSeletiva(double **matriz, int n, int N, int M, double *b) {
	int i, j, cont1=0, cont2=0;

	for(i=0; i<N-1; i++) {
		divideLinha(matriz, M, b, i);
		
		operaLinhas(matriz, M, b, i, i+1);
		for(j=cont1; j>=cont2; j--)
			operaLinhas(matriz, M, b, i, i+n-1-j);
		
		if(i<n-3) cont1++;
		else if(i>=N-n) cont2++;
	}
	
	divideLinha(matriz, M, b, N-1);
}

void substituicaoRegressiva(double **matriz, int n, int N, int M, double *u, double *b) {
	int i, j, cont=0;
	double soma;
	
	for(i=N-1; i>=0; i--) {
		soma = 0;
		for(j=1; j<=cont; j++)
			soma += matriz[i][M/2+j]*u[i+j];
		u[i] = b[i] - soma;
		if(cont<n-1) cont++;
	}
}
