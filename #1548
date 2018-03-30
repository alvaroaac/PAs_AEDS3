// Modulo 1
#include <stdio.h>

int main () {
	
	int numTestes;
	scanf("%d", &numTestes);
	
	int numAlunos;
	
	int notas[1000];
	int notasSort[1000];
	int testeAtual, i, alunosNoLugar;
	
	for (testeAtual = 0; testeAtual < numTestes; testeAtual++) {
		scanf("%d", &numAlunos);
		
		alunosNoLugar = numAlunos;
		
		for (i = 0; i<numAlunos; i++) {
			scanf("%d", &notas[i]);
			notasSort[i] = notas[i];
		}
		
		bubbleSortDescending(notasSort, numAlunos);
		for (i=0;i<numAlunos;i++) {
			if (notas[i] != notasSort[i]) {
				alunosNoLugar--;
			}
		}
		printf("%d\n", alunosNoLugar);
	}
	
	return 0;
}

void bubbleSortDescending(int *v, int sizeV) {

	int i, temp, finished = 0;
	while (!finished) {
		finished = 1;
		for (i=0; i < sizeV - 1; i++) {
			if (v[i] < v[i+1]) {
				finished = 0;
				temp = v[i];
				v[i] = v[i+1];
				v[i+1] = temp;
			}
		}
	}
}
