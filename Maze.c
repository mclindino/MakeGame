#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NADA 0
#define PAREDE 1
#define TETO 2
#define OBSTACULO 3
#define PREMIO 4
#define CHAO 5

int mapa[22][38] = {
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,3,0,0,3,0,0,0,0,0,3,3,3,3,3,0,0,0,0,1,
1,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,0,3,0,0,3,0,0,0,0,0,3,0,0,0,3,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,3,0,0,3,3,3,3,3,3,3,0,0,0,3,0,0,0,0,1,
1,3,3,3,0,0,0,3,0,0,3,3,3,3,3,3,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,1,
1,3,3,3,0,3,3,3,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,3,3,3,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,3,3,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,3,3,3,3,0,0,0,0,3,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,3,3,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,3,3,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};


int i, j, k;
int linha_atual = 2;
int coluna_atual = 2;
int vida = 2;
char comecar;

void escrever_mapa() {	
	for(i = 0; i < 22; i++) {
		for(j = 0; j < 38; j++) {
			if(i == linha_atual && j == coluna_atual) {
				printf("$");
				continue;
			}
			if(mapa[i][j] == NADA)
				printf(" ");
			if(mapa[i][j] == PAREDE)
				printf("|");
			if(mapa[i][j] == TETO)
				printf("_");
			if(mapa[i][j] == OBSTACULO)
				printf("*");
			if(mapa[i][j] == PREMIO)
				printf("†");
			if(mapa[i][j] == CHAO)
				printf("¯");
		}
		printf("\n");
	}
	printf("\n VIDAS : %d\n", vida); 
}

int fim_bom() {
	int like[9][12] = {
	0,0,0,0,0,0,1,1,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,
	0,0,0,0,1,0,0,0,1,0,0,0,
	0,1,1,1,0,0,0,0,1,1,1,0,
	0,0,0,0,0,0,0,0,1,1,1,0,
	0,0,0,0,0,0,0,0,1,1,1,0,
	0,1,1,1,0,0,0,0,1,1,1,0,
	0,0,0,0,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,};
	printf("\n		PARABÉNS!!		\n\n");
	printf("		");
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 12; j++) {
			if(like[i][j] == 0)
				printf(" ");
			if(like[i][j] == 1)
				printf("▀");
		}
		printf("\n");
		printf("		");
	}
	printf("\n");
}

int fim_ruim() {
	int caveira[9][12] = {
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,0,0,0,0,
	0,1,1,1,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,0,1,1,1,0,
	0,0,0,0,0,0,0,0,1,1,1,0,
	0,1,1,1,0,0,0,0,1,1,1,0,
	0,0,0,0,1,0,0,0,1,1,1,0,
	0,0,0,0,0,1,0,0,1,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,};
	printf("\n		GAME OVER		\n\n");
	printf("		");
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 12; j++) {
			if(caveira[i][j] == 0)
				printf(" ");
			if(caveira[i][j] == 1)
				printf("▀");
		}
		printf("\n");
		printf("		");
	}
	printf("\n");
}

int main () {
	system("clear");
	char controle;
	printf("------------------------------------------------------------------------------\n			MAZE TERROR \n------------------------------------------------------------------------------\n");
	printf("			E -> Começar.\n			Q -> Sair\n------------------------------------------------------------------------------\n");
	comecar = getche();
	if(comecar == 'e') {
	recomeca:
	if(vida != 0) {
	linha_atual = 2;
	coluna_atual = 2;
	while(mapa[linha_atual][coluna_atual] != PREMIO) {
	printf("\n");
	system("clear");
	escrever_mapa();
	comecar = getche();
	switch (controle) {
		case 'w':
			linha_atual = linha_atual - 1;
			if(mapa[linha_atual][coluna_atual] == PAREDE || mapa[linha_atual][coluna_atual] == CHAO || mapa[linha_atual][coluna_atual] == TETO)
				linha_atual = linha_atual + 1;
			if(mapa[linha_atual][coluna_atual] == OBSTACULO) {
				vida = vida - 1;
				goto recomeca;
			}
		break;
		case 'a':
			coluna_atual = coluna_atual - 1;
			if(mapa[linha_atual][coluna_atual] == PAREDE || mapa[linha_atual][coluna_atual] == CHAO || mapa[linha_atual][coluna_atual] == TETO)
				coluna_atual = coluna_atual + 1;
			if(mapa[linha_atual][coluna_atual] == OBSTACULO) {
				vida = vida - 1;
				goto recomeca;	
			}		
		break;
		case 'd':
			coluna_atual = coluna_atual + 1;
			if(mapa[linha_atual][coluna_atual] == PAREDE || mapa[linha_atual][coluna_atual] == CHAO || mapa[linha_atual][coluna_atual] == TETO)
				coluna_atual = coluna_atual - 1;
			if(mapa[linha_atual][coluna_atual] == OBSTACULO) {
				vida = vida - 1;
				goto recomeca;
			}
		break;
		case 's':
			linha_atual = linha_atual + 1;
			if(mapa[linha_atual][coluna_atual] == PAREDE || mapa[linha_atual][coluna_atual] == CHAO || mapa[linha_atual][coluna_atual] == TETO)
				linha_atual = linha_atual - 1;
			if(mapa[linha_atual][coluna_atual] == OBSTACULO) {
				vida = vida - 1;
				goto recomeca;
			}
		break;
		case '\n':
			return 0;
		break;
	}
}
	system("clear");
	fim_bom();
} else {
	system("clear");
	fim_ruim();
}
}
	if(comecar == 'q') {
		system("clear");
		printf("			MEDROSO\n");
		return 0;
	}

	return 0;
}
