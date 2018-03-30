// Modulo 1
#include <stdio.h>
 
int main() {

	int i, N, mag;
	int magnitudes[10000];
	int countPicos = 0, bDescendo = 0, bSubindo = 0;
	
	
	scanf("%d", &N);
	
	while (N > 0) {
		for (i=0;i<N;i++) {
			scanf("%d", &mag);
			magnitudes[i] = mag;
		}
		bDescendo = 0;
		bSubindo = 0;
		
		
		if (magnitudes[0] < magnitudes[0+1]) {
			bSubindo = 1;
			if (magnitudes[N-1] > magnitudes[0])
				countPicos++;
		}
		else if (magnitudes[0] > magnitudes[0+1]) {
			bDescendo = 1;
			if (magnitudes[N-1] < magnitudes[0])
				countPicos++;
		}
			
		for (i=0;i<N;i++) {
			if (i < N-1) {
				if (magnitudes[i] < magnitudes[i+1] && bDescendo == 1) {
					countPicos++;
					bDescendo = 0;
					bSubindo = 1;
				}
				else if (magnitudes[i] > magnitudes[i+1] && bSubindo == 1) {
					countPicos++;
					bDescendo = 1;
					bSubindo = 0;
				}
			}
			else {
				if ((magnitudes[N-1] < magnitudes[0] && bDescendo == 1) || (magnitudes[N-1] > magnitudes[0] && bSubindo == 1))
					countPicos++;
				}
		}
		
		printf("%d\n",countPicos);
		countPicos = 0;
		scanf("%d", &N);

	}
    return 0;
}
