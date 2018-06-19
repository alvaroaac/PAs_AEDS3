//URI #1234 Sentenca dancante
// Alvaro Carvalho

#include <stdio.h>
#include <string.h>

#define buffer 100

int main () {
	
	char sentence[buffer];
	int i, j=0;
	int tamString;
	int isLower; // booleano
	
	while ( lerFrase(sentence) > 0) {
		j = 0;
		tamString = strlen(sentence);
		
		for(i=0; i < tamString; i++) {
			if(sentence[i] != ' ') {
				isLower = j%2;
				if((int)sentence[i] <= 90 && isLower) {
					sentence[i] = sentence[i] + 32;
				}
				else if((int)sentence[i] > 90 && !isLower) {
					sentence[i] = sentence[i] - 32;
				}
				j++;
			}
		}
		printf("%s\n", sentence);
	}
	
	return 0;
}

int lerFrase(char * sentence) {
	char aux;
	return scanf("%2000[^\n]%c", sentence, &aux);
}