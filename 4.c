#include <stdio.h>
#include <stdlib.h>

typedef struct no * ptrno;

struct no {
	int info;
	struct no *prox;
};

ptrno retira_n(ptrno l, int n);

int insere_fim(ptrno * L, int elem);

int main(void) {

	//criando as listas:
	ptrno lista;

	//prenchendo-as
	for(int i=0; i < 10; i++) {
		insere_fim(&lista, i);
	}

	retira_n(lista, 3);
	
	ptrno aux = lista;
	while (aux != NULL) {
		printf("%d\n", aux->info);
		aux = aux->prox;
	}
  return 0;
}

ptrno retira_n(ptrno l, int n) {
	ptrno aux;
	if(l->info == n) {
		
	}
	
	if(l->prox == NULL) {
		return l;
	}
	else {
		return (retira_n(l->prox, n));
	}
}

int insere_fim(ptrno * L, int elem) { 
	ptrno novono=(struct no *)malloc(sizeof(struct no));
	ptrno aux = *L;
	if(novono==NULL)
		return 0;
	else {
		novono->info=elem;
		if(*L==NULL)
			*L=novono;
		else { 
			while(aux->prox!=NULL) { 
				aux=aux->prox;
			}
			aux->prox=novono;
		}
		return 1;
	}
}