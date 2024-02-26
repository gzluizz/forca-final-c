#include <stdio.h>
#include <string.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 8

void exibirForca(int tentativas);
void exibirPalavraEscondida(char palavra[], char letrasCorretas[]);
int verificarPalavra(char palavra[], char letrasCorretas[], char letra);

int main() {
    char palavra[TAMANHO_PALAVRA];
    char letrasCorretas[TAMANHO_PALAVRA];
    char letra;
    int tentativas = 0;

    printf("Digite a palavra secreta: ");
    scanf("%s", palavra);
    
    system("cls");
    
    memset(letrasCorretas, '_', strlen(palavra));

    while (tentativas < MAX_TENTATIVAS && strcmp(palavra, letrasCorretas) != 0) {
        printf("\n");
        exibirForca(tentativas);
        exibirPalavraEscondida(palavra, letrasCorretas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (verificarPalavra(palavra, letrasCorretas, letra)) {
            printf("Letra correta!\n");
        } else {
            printf("Letra incorreta. Tente novamente.\n");
            tentativas++;
    }

    }
    if (strcmp(palavra, letrasCorretas) == 0) {
        printf("\nParabens! Voce acertou a palavra! \n");
    	printf("\nA palavra correta era: %s\n", palavra);

    }

    if (tentativas ==MAX_TENTATIVAS) {
        printf("\nVoce perdeu! A palavra correta era: %s\n", palavra);
    }

    return 0;
}

void exibirForca(int tentativas) {
    printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);

    switch (tentativas) {
        case 0:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 1:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 2:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |      |\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 3:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 4:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 5:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     /\n");
            printf(" |\n");
            break;
        case 6:
            printf("  _______\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     / \\\n");
            printf(" |\n");
            break;
    }
}

void exibirPalavraEscondida(char palavra[], char letrasCorretas[]) {
    int i;

    for (i = 0; i < strlen(palavra); i++) {
        if (letrasCorretas[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", letrasCorretas[i]);
        }
    }

    printf("\n");
}

int verificarPalavra(char palavra[], char letrasCorretas[], char letra) {
    int i;
    int encontrou = 0;

    for (i = 0; i < strlen(palavra); i++) {
        if (palavra[i] == letra) {
            letrasCorretas[i] = letra;
            encontrou = 1;
        }
    }
    return encontrou;
}
