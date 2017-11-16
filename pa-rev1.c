#include <stdio.h>
#include <stdlib.h>

 // Implementacao de FILA // ref: Notas de aula
 // http://www2.dcc.ufmg.br/livros/algoritmos/cap3/slides/c/completo1/cap3.pdf secao 3.3.2
 struct Node {
	int item;
	struct Node *next;
 };

 struct Fila {
	struct Node *head;
	struct Node *tail;
 };


 struct Fila* criaFilaVazia() {
    struct Fila* Fila = (struct Fila *) malloc(sizeof(struct Fila));
    Fila->head = Fila->tail = NULL;
	return Fila;
 }

 int Vazia(struct Fila* Fila) {
	 return (Fila->head==NULL);
 }

 void enfileira(int item, struct Fila* Fila) {
     struct Node * celula = (struct Node *) malloc(sizeof(struct Node));
	 celula->item = item;
	 celula->next = NULL;

	 if (Fila->tail) {
        Fila->tail->next = celula;
        Fila->tail = Fila->tail->next;
	 }
	 else {
        Fila->head = celula;
        Fila->tail = celula;
	 }

 }
 int desenfileira(struct Fila* Fila) {
     //printf("desenfileirando\n");
     int item;

	 if (Vazia(Fila)) {
		 printf("Erro. Fila ja esta vazia.\n");
		 return -1;
	 }

	 struct Node* node = (struct Node*) malloc(sizeof(struct Node));

	 node = Fila->head;
     item = node->item;
	 Fila->head = node->next;

     if (Fila->head == NULL)
        Fila->tail = NULL;
	 free(node);
     //printf("saindo do desenfileira\n");
	 return item;
 }

int main() {

    int N, i;
    int descarta;
    int item;
    //printf("here\n");
    //printf("outofhere\n");
    struct Fila* Fila = criaFilaVazia();

    scanf("%d",&N);
    while (N>0) {

        for (i=1;i<=N;i++) {
            enfileira(i,Fila);
        }
        printf("Discarded cards: ");
        descarta = 1;
        while (Fila->head->next != NULL) {
            if (descarta==1) {
                item = desenfileira(Fila);
                if (Fila->head->next == NULL)
                    printf("%d\n",item);
                else
                    printf("%d, ", item);
                descarta = 0;
            }
            else if (descarta==0) {
                item = desenfileira(Fila);
                enfileira(item, Fila);
                descarta = 1;
            }
        }
        printf("Remaining card: %d\n",Fila->head->item);
        while (!Vazia(Fila)) {
            item = desenfileira(Fila);
        }
        //free(Fila);
        scanf("%d",&N);
    }
    return 0;
}
