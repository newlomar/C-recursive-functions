#include <stdio.h>
#include <stdlib.h>

typedef struct no * ptrno;

struct no {
	int info;
	struct no *prox;
};

int maiores(ptrno l, int n);

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
	int numeroASerComparado = 4;
	int MaioresQueNumeroComparado = maiores(lista, numeroASerComparado);
	printf("Numero da lista maiores que %d: %d", numeroASerComparado, MaioresQueNumeroComparado);
  return 0;
}

int maiores(ptrno l, int n) {
	if(l == NULL) {
		return 0;
	}
	else {
		if (l->info > n) {
			return (1 + maiores(l->prox, n));
		}
		else {
			return (maiores(l->prox, n));
		}
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