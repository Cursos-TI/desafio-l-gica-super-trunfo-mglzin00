#include <stdio.h>

typedef enum {
    ATR_POPULACAO,
    ATR_AREA,
    ATR_PIB,
    ATR_DENSIDADE,
    ATR_PIB_PER_CAPITA
} Atributo;

// Troque aqui o atributo que será comparado:
#define ATRIBUTO_ESCOLHIDO ATR_PIB_PER_CAPITA
// opções: ATR_POPULACAO, ATR_AREA, ATR_PIB, ATR_DENSIDADE, ATR_PIB_PER_CAPITA

int main(void) {
    char estado1[10];
    char codigo1[5];
    char nome1[50];
    unsigned long long populacao1;
    double area1;
    double pib1;
    int pontos_turisticos1;

    char estado2[10];
    char codigo2[5];
    char nome2[50];
    unsigned long long populacao2;
    double area2;
    double pib2;
    int pontos_turisticos2;

    printf("===  Jogo Do Super Trunfo ===\n");

    printf("Digite o Estado da Carta 1: ");
    scanf(" %9s", estado1); // até 9 chars + '\0'

    printf("Codigo da primeira carta: ");
    scanf(" %4s", codigo1); // até 4 chars + '\0'

    printf("Cidade da primeira carta: ");
    scanf(" %49[^\n]", nome1);

    printf("Populacao: ");
    scanf(" %llu", &populacao1);

    printf("Area (em km²): ");
    scanf(" %lf", &area1);

    printf("PIB (em bilhoes de R$): ");
    scanf(" %lf", &pib1);

    printf("Pontos Turisticos: ");
    scanf(" %d", &pontos_turisticos1);

    printf("\n-------------------------\n");

    printf("Digite o Estado da Carta 2: ");
    scanf(" %9s", estado2);

    printf("Codigo da segunda carta: ");
    scanf(" %4s", codigo2);

    printf("Cidade da segunda carta: ");
    scanf(" %49[^\n]", nome2);

    printf("Populacao: ");
    scanf(" %llu", &populacao2);

    printf("Area (em km²): ");
    scanf(" %lf", &area2);

    printf("PIB (em bilhoes de R$): ");
    scanf(" %lf", &pib2);

    printf("Pontos Turisticos: ");
    scanf(" %d", &pontos_turisticos2);

    // === Calculos ===
    double densidade1 = (area1 > 0.0) ? ( (double)populacao1 / area1 ) : 0.0;
    double densidade2 = (area2 > 0.0) ? ( (double)populacao2 / area2 ) : 0.0;
    double pibPerCapita1 = (populacao1 > 0ULL) ? ((pib1 * 1e9) / (double)populacao1) : 0.0; // bilhoes -> reais
    double pibPerCapita2 = (populacao2 > 0ULL) ? ((pib2 * 1e9) / (double)populacao2) : 0.0;

    // === Saida das Cartas ===
    printf("\n== Carta 1 ==\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", nome1);
    printf("Populacao: %llu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de R$\n", pib1);
    printf("Pontos turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f R$\n", pibPerCapita1);

    printf("\n------------------------\n");

    printf("\n== Carta 2 ==\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", nome2);
    printf("Populacao: %llu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de R$\n", pib2);
    printf("Pontos turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f R$\n", pibPerCapita2);

    // === Comparacao unica (atributo escolhido) ===
    double v1 = 0.0, v2 = 0.0;
    const char *nomeAtr = "";
    int menor_vence = 0; // regra especial para densidade

    switch (ATRIBUTO_ESCOLHIDO) {
        case ATR_POPULACAO:
            nomeAtr = "Populacao";
            v1 = (double)populacao1; v2 = (double)populacao2;
            break;
        case ATR_AREA:
            nomeAtr = "Area (km²)";
            v1 = area1; v2 = area2;
            break;
        case ATR_PIB:
            nomeAtr = "PIB (bilhoes)";
            v1 = pib1; v2 = pib2;
            break;
        case ATR_DENSIDADE:
            nomeAtr = "Densidade Populacional (hab/km²)";
            v1 = densidade1; v2 = densidade2;
            menor_vence = 1; // menor vence
            break;
        case ATR_PIB_PER_CAPITA:
            nomeAtr = "PIB per Capita (R$)";
            v1 = pibPerCapita1; v2 = pibPerCapita2;
            break;
    }

    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2
    if (v1 == v2) {
        vencedor = 0;
    } else if (menor_vence) {
        vencedor = (v1 < v2) ? 1 : 2;
    } else {
        vencedor = (v1 > v2) ? 1 : 2;
    }

    // === Saida do resultado ===
    printf("\n=================================\n");
    printf("Comparacao de cartas (Atributo: %s)\n", nomeAtr);
    printf("Carta 1 - %s (%s): ", nome1, estado1);
    if (ATRIBUTO_ESCOLHIDO == ATR_POPULACAO)
        printf("%.0f\n", v1);
    else
        printf("%.2f\n", v1);

    printf("Carta 2 - %s (%s): ", nome2, estado2);
    if (ATRIBUTO_ESCOLHIDO == ATR_POPULACAO)
        printf("%.0f\n", v2);
    else
        printf("%.2f\n", v2);

    if (vencedor == 0)
        printf("Resultado: Empate!\n");
    else
        printf("Resultado: Carta %d (%s) venceu!\n",
               vencedor, vencedor == 1 ? nome1 : nome2);
    printf("=================================\n");

    return 0;
}