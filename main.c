#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PEDRA 0
#define TESOURA 1
#define PAPEL 2

void print_menu() {
    printf("\nJOGADOR 1, Escolha uma das opções:\n");
    printf("0. Pedra\n");
    printf("1. Tesoura\n");
    printf("2. Papel\n\n");
    printf("Digite sua opção: \n");
}

int check_type(int option, int type) {
    return option == type;
}

char * convert_int_to_string(int option) {
    if (check_type(option, PEDRA)) return "PEDRA";
    else if (check_type(option, PAPEL)) return "PAPEL";
    else if (check_type(option, TESOURA)) return "TESOURA";
    return "ERROR";
}

int check_winner(int option_1, int option_2) {
    if (option_1 == option_2) return -1; // se for empate retorna -1

    if (check_type(option_1, PEDRA) && check_type(option_2, TESOURA)) return 1;
    else if (check_type(option_1, PEDRA) && check_type(option_2, PAPEL)) return 2;
    else if (check_type(option_1, TESOURA) && check_type(option_2, PAPEL)) return 1;
    else if (check_type(option_1, TESOURA) && check_type(option_2, PEDRA)) return 2;
    else if (check_type(option_1, PAPEL) && check_type(option_2, TESOURA)) return 2;
    else if (check_type(option_1, PAPEL) && check_type(option_2, PEDRA)) return 1;

    return 0;
}

int main(void) {
    // Inicia o número randômico
    srand(time(NULL));

    while(1) {
        print_menu();

        int option_1;
        scanf("%d", &option_1);

        int option_2 = rand() % 3;
        
        printf("\n✅  Jogador 1: %s\n", convert_int_to_string(option_1));
        printf("🖥️  PC: %s\n", convert_int_to_string(option_2));
        
        int winner_option = check_winner(option_1, option_2);

        if(winner_option == -1) printf("☢️  Empate!!\n");
        else {
            printf("\n\n%s", winner_option == 1 ? "✅  Jogador 1": "🖥️  PC");
            printf(" venceu!!!!!\n"); 
            break;
        }
    } 

    return 0;
}
