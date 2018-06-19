// Modulo 1 PA 3
#include <stdio.h>
#include <string.h>

#define buffer 100
int main () {
	
	int N, L, C;
	int P, Lp, C_l;
	int i, tamPalavra;
	char palavra[buffer];
	
	while (scanf("%d %d %d", &N, &L, &C) == 3) {
		Lp = L; // numero de linhas na pagina
		C_l = C; // numero de caracteres na linha
		P = 1; // numero de paginas no conto
		for (i=0;i<N;i++) {
			if(Lp==0) {
				P++;
				Lp = L;
			}
			scanf("%s", palavra);
			tamPalavra = strlen(palavra);
			if (tamPalavra >= C_l) {
				Lp--;
				if (tamPalavra == C_l) {
					C_l = C;
				}
				else {
					if(Lp==0) {
						Lp=L;
						P++;						
					}

					C_l = C - (tamPalavra+1);
				}
				
			}
			else {
				C_l -= tamPalavra + 1;
			}
			//printf("C_l = %d\nLp = %d\nP = %d\n", C_l, Lp, P);
		}
		printf("%d\n", P);
	}
	
	
	return 0;
}
