#include <stdio.h>

void hash () {
    char array[270];
	int n_de_linhas, tamanho, res, i=0, j, k;

	scanf("%d",&n_de_linhas);
	while (i < n_de_linhas) {
		scanf("%d%*c", &tamanho);
		res = 0;
        for (j=0; j < tamanho; j++) {
			scanf("%[^\n]%*c",&array);
			for(k = 0; array[k] != '\0'; k++) {
			    res += array[k] - 65 + j + k;
			}
		}

		printf("%d\n", res);
        i++;
	}
}

int main() {

    hash ();

	return 0;
}
