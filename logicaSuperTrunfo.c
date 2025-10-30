#include <stdio.h>

int main(void) {
    // --- Dados da Carta 1 ---
    char pais1[20];
    char codigo1[5];
    char nome1[50]; // nome do país (apenas exibição)
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;

    // --- Dados da Carta 2 ---
    char pais2[20];
    char codigo2[5];
    char nome2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    printf("=== Jogo do Super Trunfo (2 cartas) ===\n");

    // -------- Entrada Carta 1 --------
    printf("\n--- CARTA 1 ---\n");
    printf("Pais (sigla ou nome curto): ");
    scanf(" %19s", pais1);

    printf("Codigo da carta: ");
    scanf(" %4s", codigo1);

    printf("Nome do pais (apenas exibicao): ");
    scanf(" %49[^\n]", nome1);

    printf("Populacao (int): ");
    scanf(" %d", &populacao1);

    printf("Area (km2, float): ");
    scanf(" %f", &area1);

    printf("PIB (bilhoes, float): ");
    scanf(" %f", &pib1);

    printf("Pontos turisticos (int): ");
    scanf(" %d", &pontos_turisticos1);

    // -------- Entrada Carta 2 --------
    printf("\n--- CARTA 2 ---\n");
    printf("Pais (sigla ou nome curto): ");
    scanf(" %19s", pais2);

    printf("Codigo da carta: ");
    scanf(" %4s", codigo2);

    printf("Nome do pais (apenas exibicao): ");
    scanf(" %49[^\n]", nome2);

    printf("Populacao (int): ");
    scanf(" %d", &populacao2);

    printf("Area (km2, float): ");
    scanf(" %f", &area2);

    printf("PIB (bilhoes, float): ");
    scanf(" %f", &pib2);

    printf("Pontos turisticos (int): ");
    scanf(" %d", &pontos_turisticos2);

    // --- Calculos auxiliares ---
    float dens1 = (area1 > 0.0f) ? ( (float)populacao1 / area1 ) : 0.0f;
    float dens2 = (area2 > 0.0f) ? ( (float)populacao2 / area2 ) : 0.0f;

    // --- Menu interativo ---
    int opcao;
    printf("\n=== MENU: escolha o atributo para comparar ===\n");
    printf("1 - Populacao (maior vence)\n");
    printf("2 - Area (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos turisticos (maior vence)\n");
    printf("5 - Densidade demografica (menor vence)\n");
    printf("Opcao: ");
    scanf(" %d", &opcao);

    // --- Preparar comparacao ---
    float v1 = 0.0f, v2 = 0.0f;
    const char *nomeAtr = "";
    int menor_vence = 0; // regra especial para densidade

    switch (opcao) {
        case 1: // Populacao
            nomeAtr = "Populacao";
            v1 = (float)populacao1; v2 = (float)populacao2;
            break;
        case 2: // Area
            nomeAtr = "Area (km2)";
            v1 = area1; v2 = area2;
            break;
        case 3: // PIB
            nomeAtr = "PIB (bilhoes)";
            v1 = pib1; v2 = pib2;
            break;
        case 4: // Pontos turisticos
            nomeAtr = "Pontos turisticos";
            v1 = (float)pontos_turisticos1; v2 = (float)pontos_turisticos2;
            break;
        case 5: // Densidade demografica (menor vence)
            nomeAtr = "Densidade demografica (hab/km2)";
            v1 = dens1; v2 = dens2;
            menor_vence = 1;
            break;
        default:
            printf("\nOpcao invalida. Encerrando.\n");
            return 0;
    }

    // --- Decide vencedor ---
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2
    if (v1 == v2) {
        vencedor = 0;
    } else if (menor_vence) {
        vencedor = (v1 < v2) ? 1 : 2;
    } else {
        vencedor = (v1 > v2) ? 1 : 2;
    }

    // --- Exibicao solicitada ---
    printf("\n========== RESULTADO ==========\n");
    printf("Paises: %s  x  %s\n", nome1, nome2);
    printf("Atributo usado: %s\n", nomeAtr);
    printf("Valor Carta 1 (%s): %.2f\n", nome1, v1);
    printf("Valor Carta 2 (%s): %.2f\n", nome2, v2);

    if (vencedor == 0)
        printf("Resultado: Empate!\n");
    else
        printf("Resultado: Carta %d (%s) venceu!\n",
               vencedor, vencedor == 1 ? nome1 : nome2);

    printf("================================\n");
    return 0;
}