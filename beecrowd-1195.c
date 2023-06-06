#include <stdio.h>

typedef struct arvbin {
	int chave;
	struct arvbin *esq;
	struct arvbin *dir;
} arv;

void imprimeIn (arv *arvore) {
	imprimeIn (arv->esq);
	printf ("%d ", arvore->chave);
	imprimeIn (arv->dir);
}

void imprimePre (arv *arvore) {
	printf ("%d ", arvore->chave);
	imprimePre (arv->esq);
	imprimePre (arv->dir);
}

void imprimePos (arv *arvore) {
	imprimePos (arv->esq);
	imprimePos (arv->dir);
	printf ("%d ", arvore->chave);
}

arv insere (arv *arvore, int valor) {
	arv *f, *p, *novo;

	novo = (arv) malloc (sizeof (arv));
	novo->chave=valor;
	if (arvore == NULL) return novo;
	f = arvore;
	while (f != NULL) {
		p = f;
		if (f->chave > novo->chave) f = f->esq;
		else f = f->dir;
	}
	if (p->chave > novo->chave) p->esq = novo;
	else p->dir = novo;
	
	return arvore;
}

int main () {
	arv *arvore[1000];
	int c, n, i, j, valor;

	scanf ("%d", &c);
	for (i=0; i<c; i++) {
		scanf ("%d", &n);
		for (j=0; j<n; j++) {
			scanf ("%d", &valor);
			insere(arvore, valor);
		}
		printf ("Case %d:\n\n", c);
		printf ("Pre.: ");
		imprimePre (arvore[n]);
		printf ("In..: ");
		imprimeIn (arvore[n]);
		printf ("Post: ");
		imprimePos (arvore[n]);
		printf ("\n\n");
	}

	return 0;
}
