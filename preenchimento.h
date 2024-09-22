#ifndef PREENCHIMENTO_H_INCLUDED
#define PREENCHIMENTO_H_INCLUDED

void inicializaCondicoesIniciais(int n, double *baixo, double *esquerda, double *direita, double *cima);

double *preencheVetorIndependente(int n, int N, double *baixo, double *esquerda, double *direita, double *cima);

void preencheMatriz(double **matriz, int n, int N, int M);

#endif // PREENCHIMENTO_H_INCLUDED