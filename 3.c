#include <stdio.h>
#include <stdlib.h>

typedef struct no * ptrno;

struct no {
	int info;
	struct no *prox;
};

ptrno concatena(ptrno l, ptrno l2);

int insere_fim(ptrno * L, int elem);

int main(void) {

	//criando as listas:
	ptrno lista;
	ptrno lista2;

	//prenchendo-as
	for(int i=0; i < 10; i++) {
		insere_fim(&lista, i);
	}
	
	for(int i=10; i < 20; i++) {
		insere_fim(&lista2, i);
	}

	concatena(lista, lista2);
	
	ptrno aux = lista;
	while (aux != NULL) {
		printf("%d\n", aux->info);
		aux = aux->prox;
	}
  return 0;
}

ptrno concatena(ptrno l, ptrno l2) {
	if(l->prox == NULL) {
		l->prox = l2;
		return l;
	}
	else {
		return (concatena(l->prox, l2));
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