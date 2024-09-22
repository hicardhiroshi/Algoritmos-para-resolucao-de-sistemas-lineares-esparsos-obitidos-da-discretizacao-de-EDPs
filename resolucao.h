#ifndef RESOLUCAO_H_INCLUDED
#define RESOLUCAO_H_INCLUDED

void divideLinha(double **matriz, int M, double *b, int pos);

void operaLinhas(double **matriz, int M, double *b, int pos1, int pos2);

void eliminacaoSeletiva(double **matriz, int n, int N, int M, double *b);

void substituicaoRegressiva(double **matriz, int n, int N, int M, double *u, double *b);

#endif // RESOLUCAO_H_INCLUDED