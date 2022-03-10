#include <stdio.h>
#include <stdlib.h>

typedef struct no * ptrno;

struct no {
	int info;
	struct no *prox;
};

ptrno retira_n(ptrno *l, int n, ptrno *anterior);

int insere_fim(ptrno * L, int elem);

int main(void) {

	//criando as listas:
	ptrno lista = NULL;

	//prenchendo-as
	for(int i=0; i < 10; i++) {
		insere_fim(&lista, i);
	}

	retira_n(&lista, 4, NULL);
	
	ptrno aux = lista;
	printf("\n");
	while (aux != NULL) {
		printf("%d\n", aux->info);
		aux = aux->prox;
	}
  return 0;
}

ptrno retira_n(ptrno *l, int n, ptrno *anterior) {	
	if(*l == NULL) {
		return (*l);
	}
	else {
		if((*l)->info == n) {
			if(!(*anterior == NULL)) {
				(*anterior)->prox = (*l)->prox;
			}
			ptrno apaga = *l;
			*l = (*l)->prox;
			free(apaga);
			return (retira_n((&(*l)), n, (&(*anterior))));
		}
		
		anterior = l;
		return (retira_n((&(*l)->prox), n, (&(*anterior))));
	}
}

int insere_fim(ptrno * L, int elem) { 
	ptrno novono=(struct no *)malloc(sizeof(struct no));
	novono->prox = NULL;
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