#include <stdio.h>
#define TAMANHO 3 /* usado para evitar números mágicos */

/*
 * Este programa cria um jogo da velha em um array bidimensional,
 * exibe o estado do jogo, recebe input em linhas e colunas(x, y)
 * e checa para estados de vitória.
 */

char l[TAMANHO][TAMANHO];
/* retorna 'o' para par e 'x' para impar */
char flip(int x)
{
	char jogador;
	jogador = 'o';
	if ( x%2 )
		jogador = 'x';
	return jogador;
}


/* Popula os arrays */
void inicializa(void)
{
	int y, z;
	for ( y = 0 ; y < TAMANHO ; y++ ) {
		for ( z = 0 ; z < TAMANHO ; z++ ) {
			if ( y < TAMANHO-1 )
				l[y][z] = '_';
			else
				l[y][z] = ' ';
		}	
	}
}

/* Exibe o jogo na tela */
void print_jogo(void)
{
	int y, z;

	printf("\n#");

	for ( y = 0 ; y < TAMANHO ; y++ )
		printf(" %d", y+1);

	for ( y = 0 ; y < 3 ; y++ ) {
		printf ("\n%d ", y+1);

		for ( z = 0 ; z < TAMANHO ; z++ ) {
			printf("%c", l[y][z]);
			if ( z != TAMANHO-1 )
				printf("|");
		}
	}
}

/* 
 * Verifica se existem 3 caracteres maiores ou iguais a 'o' 
 * em sequência nas horizontais, verticais e diagonais.
 */
int vitoria(int c)
{
	int y;
	for ( y = 0 ; y < TAMANHO ; y++ ) {
		if ( l[0][y] == l[1][y] && l[0][y] == l[2][y] && ( l[0][y] >= 'o' ) )
			c = 10;
		else if ( l[y][0] == l[y][1] && l[y][0] == l[y][2] && ( l[y][0] >= 'o' ) )
			c = 10;
		else if( ( l[0][0] == l[1][1] && l[0][0] == l[2][2] ) | ( l[0][2] == l[1][1] && l[0][2] == l[2][0]) )
			c = 10;	
	}
	return c;
}

void main()
{
	int cnt, lin, col;

	inicializa();
	print_jogo();

	for ( cnt = 0 ; cnt <= (TAMANHO*TAMANHO)-1 ; cnt = vitoria(cnt) ) {
		printf("\nVez de %c", flip(cnt));

		printf("\nLinha: ");
		lin = getchar() - 49;
		getchar();
		printf("\nColuna: ");
		col = getchar() - 49;
		getchar();
		
		if (l[lin][col] < 'x' && col+1 <= TAMANHO && col+1 > 0 ) {
			l[lin][col] = flip(cnt);
			cnt++;
		}
	print_jogo();
	}
	if ( cnt == 10 )
		printf("\nVitória de %c!\n", flip(cnt));
	else
		printf("\nEmpate...\n");
} 
