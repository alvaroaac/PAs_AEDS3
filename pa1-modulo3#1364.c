// Emoticons - 1364
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

int lerFrase(char * sentence) {
	char aux;
	return scanf("%101[^\n]%c", sentence, &aux);
}

int main() {

    int N, M;
    char stringToRead[MAX_SIZE];
    while (scanf("%d%d", &N,&M) == 2 && N != 0) {
        char forbidden[N][16];

        //char textToRead[M][MAX_SIZE];
        int i, j, k;
        for (i = 0;i<N;i++) {
            scanf("%s",forbidden[i]);
        }
        int result = 0;
        int tamString;
        getchar(); // \n
		for (i=0;i<M;i++) {
            lerFrase(stringToRead);
            //printf("string=%s\n",stringToRead);
            tamString = strlen(stringToRead);
            for (j=0;j<tamString;j++) {
                for(k=0; k < N; k++) {
                    if(stringToRead[j] == forbidden[k][strlen(forbidden[k])-1]) {
                        if (j >= strlen(forbidden[k])-1) {
							int match = 0, iter;
							for (iter = j-1; iter >= (j - (strlen(forbidden[k]) - 1)); iter--) {
								match = stringToRead[iter] == forbidden[k][strlen(forbidden[k])-1-(j-iter)];
								if (!match) {
									break;
								}
							}
							if (match) {
								stringToRead[j] = ' ';
								result++;
							}
                        }
                    }
                }
            }
        }
        printf("%d\n",result);
    }

    return 0;
}
