#include <stdio.h>
#include <stdlib.h>

typedef struct no * ptrno;

struct no {
	int info;
	struct no *prox;
};

int comprimento(ptrno l);

int insere_fim(ptrno * L, int elem);

int main(void) {

	//criando a lista:
	ptrno lista;
	
	for(int i=0; i < 10; i++) {
		insere_fim(&lista, i);
	}

	//para mostrar cada elemento da lista na tela, a titulo de teste
	// ptrno aux = lista;
	// while(aux != NULL) {
	// 	printf("%d\n", aux->info);
	// 	aux = aux->prox;
	// }
	
	//medindo tamanho:
	int comprimentoDaLista = comprimento(lista);
	printf("Comprimento da lista: %d", comprimentoDaLista);
  return 0;
}

int comprimento(ptrno l) {
	if(l == NULL) {
		return 0;
	}
	else {
		return(1 + comprimento(l->prox));
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