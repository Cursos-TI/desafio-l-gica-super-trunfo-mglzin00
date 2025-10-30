#include <stdio.h>
#include <string.h>

// ===== Escolha do atributo diretamente no código =====
// 1 - Populacao
// 2 - Area
// 3 - PIB
// 4 - Pontos turisticos
// 5 - Densidade demografica
#define ATRIBUTO_ESCOLHIDO 3   // << mude aqui se quiser comparar outro atributo

int main() {
    // --- Carta 1 ---
    char estado1[10];
    char codigo1[5];
    char nome1[50];
    unsigned long long populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;

    // --- Carta 2 ---
    char estado2[10];
    char codigo2[5];
    char nome2[50];
    unsigned long long populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    printf("=== Jogo do Super Trunfo (2 cartas) ===\n\n");

    // ===== Entrada CARTA 1 =====
    printf("--- CARTA 1 ---\n");
    printf("Pais (sigla ou nome curto): ");
    scanf("%9s", estado1);

    printf("Codigo da carta: ");
    scanf("%4s", codigo1);

    printf("Nome do pais (apenas exibicao): ");
    scanf(" %49[^\n]", nome1);

    printf("Populacao: ");
    scanf("%llu", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\n");

    // ===== Entrada CARTA 2 =====
    printf("--- CARTA 2 ---\n");
    printf("Pais (sigla ou nome curto): ");
    scanf("%9s", estado2);

    printf("Codigo da carta: ");
    scanf("%4s", codigo2);

    printf("Nome do pais (apenas exibicao): ");
    scanf(" %49[^\n]", nome2);

    printf("Populacao: ");
    scanf("%llu", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // ===== Calculos derivados =====
    float dens1 = 0.0f, dens2 = 0.0f;
    float pibpc1 = 0.0f, pibpc2 = 0.0f;

    if (area1 > 0.0f) dens1 = (float)populacao1 / area1;
    if (area2 > 0.0f) dens2 = (float)populacao2 / area2;

    if (populacao1 > 0ULL) pibpc1 = pib1 / (float)populacao1;
    if (populacao2 > 0ULL) pibpc2 = pib2 / (float)populacao2;

    // ===== Soma total dos atributos =====
    float soma1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 + dens1 + pibpc1;
    float soma2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + dens2 + pibpc2;

    // ===== Exibir calculos e somas =====
    printf("\n=== Medidas calculadas ===\n");
    printf("Carta 1 (%s): Densidade = %.2f hab/km2 | PIB per capita = %.6f | Soma total = %.2f\n", nome1, dens1, pibpc1, soma1);
    printf("Carta 2 (%s): Densidade = %.2f hab/km2 | PIB per capita = %.6f | Soma total = %.2f\n", nome2, dens2, pibpc2, soma2);

    // ===== Comparacao (com empate correto e sem perda de precisao) =====
    int vencedora = 0;                 // 1, 2 ou 0 (empate)
    const char *atributo_txt = "";
    float v1f = 0.0f, v2f = 0.0f;      // para exibir o valor comparado
    const float EPS = 1e-6f;           // tolerancia para igualdade de floats

    switch (ATRIBUTO_ESCOLHIDO) {
        case 1: { // Populacao (inteiro)
            atributo_txt = "Populacao";
            unsigned long long a = populacao1, b = populacao2;
            if (a > b) vencedora = 1;
            else if (a < b) vencedora = 2;
            else vencedora = 0;
            v1f = (float)a; v2f = (float)b; // apenas para exibicao
        } break;

        case 2: { // Area (float)
            atributo_txt = "Area (km2)";
            v1f = area1; v2f = area2;
            if (v1f > v2f + EPS) vencedora = 1;
            else if (v2f > v1f + EPS) vencedora = 2;
            else vencedora = 0;
        } break;

        case 3: { // PIB (float)
            atributo_txt = "PIB";
            v1f = pib1; v2f = pib2;
            if (v1f > v2f + EPS) vencedora = 1;
            else if (v2f > v1f + EPS) vencedora = 2;
            else vencedora = 0;
        } break;

        case 4: { // Pontos turisticos (inteiro)
            atributo_txt = "Pontos turisticos";
            int a = pontos_turisticos1, b = pontos_turisticos2;
            if (a > b) vencedora = 1;
            else if (a < b) vencedora = 2;
            else vencedora = 0;
            v1f = (float)a; v2f = (float)b; // apenas para exibicao
        } break;

        case 5: { // Densidade (float) — menor vence
            atributo_txt = "Densidade demografica";
            v1f = dens1; v2f = dens2;
            if (v2f + EPS < v1f) vencedora = 2;        // v2 bem menor
            else if (v1f + EPS < v2f) vencedora = 1;   // v1 bem menor
            else vencedora = 0;
        } break;

        default: { // fallback: Populacao
            atributo_txt = "Populacao";
            unsigned long long a = populacao1, b = populacao2;
            if (a > b) vencedora = 1;
            else if (a < b) vencedora = 2;
            else vencedora = 0;
            v1f = (float)a; v2f = (float)b;
        } break;
    }

    // ===== Resultado =====
    printf("\n=== Resultado da comparacao (Atributo: %s) ===\n", atributo_txt);
    printf("Valores comparados -> Carta 1: %.2f | Carta 2: %.2f\n", v1f, v2f);

    if (vencedora == 1) {
        printf("Carta 1 - %s (%s) venceu!\n", nome1, estado1);
    } else if (vencedora == 2) {
        printf("Carta 2 - %s (%s) venceu!\n", nome2, estado2);
    } else {
        printf("Resultado: EMPATE!\n");
    }

    // ===== Comparativo geral (ajuda a conferir) =====
    printf("\n=== Comparativo geral de atributos ===\n");
    printf("Populacao               | C1: %llu | C2: %llu\n", populacao1, populacao2);
    printf("Area (km2)              | C1: %.2f | C2: %.2f\n", area1, area2);
    printf("PIB                     | C1: %.2f | C2: %.2f\n", pib1, pib2);
    printf("Pontos turisticos       | C1: %d | C2: %d\n", pontos_turisticos1, pontos_turisticos2);
    printf("Densidade (hab/km2)     | C1: %.2f | C2: %.2f\n", dens1, dens2);
    printf("PIB per capita          | C1: %.6f | C2: %.6f\n", pibpc1, pibpc2);
    printf("Soma total dos atributos| C1: %.2f | C2: %.2f\n", soma1, soma2);

    return 0;
}