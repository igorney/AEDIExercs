#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node {
   char data;
   Node *next;
};

void inserir(Node **primeiro, char valor) {
	Node *novo = malloc(sizeof(Node));
	novo->data = valor ;
	novo->next = NULL;

	if (*primeiro == NULL) {
		*primeiro = novo;
	} else {
		Node *atual = *primeiro;
		while (atual->next != NULL) {
			atual = atual->next;
		}
		atual->next = novo;
	}
}

Node *aguaDNA(Node *atual){

    while(atual->data == 'C' || atual->data == 'G')//(atual->data != '0') 
	{
		// if (atual->data == 'C' || atual->data == 'G')
		// {
			
		// }
		free(atual);
		atual = atual->next;
    }
    if(atual->data == '0')
        return atual;

    Node *inicio = atual; //salvaria o inicio atualizado
    Node *prox = atual->next;

    while(prox->data != '0') {
        if(prox->data == 'C' || prox->data == 'G') {
            Node *tmp = prox;
            atual->next = prox->next;
            prox = prox->next;
            free(tmp);
        }
        else {
            atual = prox;
            prox = prox->next;
        }
    }
    return inicio;
}
void imprimir(Node *primeiro) {
	Node *atual;
	for (atual = primeiro; atual != NULL; atual = atual->next) {
		printf("%c ", atual->data);
	}
	printf("\n");
}

int main() {
	Node *p2 = NULL;

	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'T');
	inserir(&p2, 'G');
	inserir(&p2, 'C');
	inserir(&p2, 'A');
	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'A');
	inserir(&p2, 'G');
	inserir(&p2, '0');
	imprimir(p2);
    aguaDNA(p2);
	imprimir(p2);

	return 0;
}
