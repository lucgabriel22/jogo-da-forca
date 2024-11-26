#include <stdio.h>
#include <string.h>

int main() {
    char palavra[20] = "programacao"; // Define a palavra a ser adivinhada
    char chute;                       // Variável para armazenar o chute do jogador
    int tamanho = strlen(palavra);    // Armazena o tamanho da palavra
    char display[20];                 // Array para exibir a palavra com as letras adivinhadas
    int tentativas = 5;               // Número de tentativas permitidas
    int acertos = 0;                  // Contador para o número de letras acertadas

    // Inicializando a palavra oculta com underscores
    for (int i = 0; i < tamanho; i++) {
        display[i] = '_'; // Preenche o array display com underscores
    }
    display[tamanho] = '\0'; // Adiciona o caractere nulo ao final da string display

    // Loop principal do jogo
    while (tentativas > 0 && acertos < tamanho) { // Executa enquanto há tentativas e a palavra não foi adivinhada
        printf("Palavra: %s\n", display);          // Exibe a palavra com os underscores e letras acertadas
        printf("Tentativas restantes: %d\n", tentativas); // Exibe o número de tentativas restantes
        printf("Digite uma letra: ");              // Solicita ao jogador que insira uma letra
        scanf(" %c", &chute);                      // Lê a letra digitada pelo jogador

        int encontrou = 0; // Variável para verificar se a letra foi encontrada na palavra
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == chute) { // Verifica se a letra digitada está na palavra
                display[i] = chute;    // Atualiza o array display com a letra acertada
                acertos++;             // Incrementa o contador de acertos
                encontrou = 1;         // Marca que a letra foi encontrada
            }
        }

        if (!encontrou) {               // Se a letra não foi encontrada
            tentativas--;               // Decrementa o número de tentativas
            printf("Letra incorreta!\n"); // Informa ao jogador que a letra está incorreta
        }
    }

    if (acertos == tamanho) { // Verifica se todas as letras foram acertadas
        printf("Parabéns, você venceu! A palavra era: %s\n", palavra); // Exibe mensagem de vitória
    } else { // Caso contrário, o jogador perdeu
        printf("Você perdeu! A palavra era: %s\n", palavra); // Exibe mensagem de derrota
    }

    return 0; // Finaliza o programa
}