//URI #2588 Jogo dos Palíndromos
// Alvaro Carvalho


/*
Uma string podera formar um palindromo se existir no maximo 1 caractere com numero impar de ocorrencias, 
e todos os outros caracteres com numero par de ocorrencias.
*/
#include <stdio.h>
#include <string.h>


#define buffer 250 // numero max de letras nao especificado

void initializeArrayToZero(int * array, int sizeArr) {
	int i;
	for (i=0; i < sizeArr; i++) {
		array[i] = 0;
	}
}

int main () {
	
	char wordToRead[buffer];
	int frequence[buffer];
	int i;
	int missingLetters;
	
	while (scanf("%s", wordToRead) > 0) {
		initializeArrayToZero(frequence,buffer);
		missingLetters = 0;
		
		for (i=0;i<strlen(wordToRead);i++) {
			frequence[(int)wordToRead[i]]++;
		}
		
		for (i=0;i<buffer;i++) {
			if (frequence[i] % 2 > 0) {
				missingLetters++;
			}
		}
		if (missingLetters > 0) { // apenas 1 caractere pode ter numero impar de ocorrencias.
			missingLetters--;
		}
		printf("%d\n", missingLetters); 
	}
	
		
	return 0;
}

