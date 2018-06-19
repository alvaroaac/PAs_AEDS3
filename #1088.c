// Bolhas e Baldes - 1088
#include <stdio.h>
#define MAX_SIZE 100000
 // utilizando algoritmo de contagem de inversoes
unsigned long int getInversions(int* a, int n) {
    unsigned long int countInversions = 0;
    int i, temp;
    for (i = 1; i <= n; i++) {
        if (a[i] != i) {
            temp = a[i];
            countInversions += (2 * positive(a[temp] - a[i])) - 1;
            a[i] = a[temp];
            a[temp] = temp;
            i--;
        }
    }
    return countInversions;
}

int positive(int a) {
    if (a<0)
        a*=-1;
    return a;
}

int main() {

    int N;
    int arr[MAX_SIZE];
    while (scanf("%d", &N) && N != 0) {

        int i;
        for (i = 1;i<=N;i++) {
            scanf("%d",&arr[i]);
        }
		unsigned long int result = getInversions(arr,N);
        if (result % 2 != 0) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }

    return 0;
}
