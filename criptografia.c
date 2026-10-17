#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LETRAS 15

/* ---------- Sequencias numericas ---------- */

void gerar_pa(int n, int seq[]) {          /* 1, 3, 5, 7...  (a1=1, r=2) */
    for (int i = 0; i < n; i++)
        seq[i] = 1 + i * 2;
}

void gerar_pg(int n, int seq[]) {          /* 1, 2, 4, 8...  (a1=1, q=2) */
    seq[0] = 1;
    for (int i = 1; i < n; i++)
        seq[i] = seq[i - 1] * 2;
}

void gerar_fibonacci(int n, int seq[]) {   /* 1, 1, 2, 3, 5, 8, 13... */
    for (int i = 0; i < n; i++)
        seq[i] = (i < 2) ? 1 : seq[i - 1] + seq[i - 2];
}

int eh_primo(int x) {
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return 0;
    return 1;
}

void gerar_primos(int n, int seq[]) {      /* 2, 3, 5, 7, 11... */
    int achados = 0, candidato = 2;
    while (achados < n) {
        if (eh_primo(candidato)) seq[achados++] = candidato;
        candidato++;
    }
}

void gerar_sequencia(int tipo, int n, int seq[]) {
    if (tipo == 1) gerar_pa(n, seq);
    else if (tipo == 2) gerar_pg(n, seq);
    else if (tipo == 3) gerar_fibonacci(n, seq);
    else gerar_primos(n, seq);
}

const char *nome_sequencia(int tipo) {
    if (tipo == 1) return "PA";
    if (tipo == 2) return "PG";
    if (tipo == 3) return "Fibonacci";
    return "Primos";
}

/* ---------- Entrada ---------- */

int palavra_valida(const char *p) {
    int tam = strlen(p);
    if (tam < 1 || tam > MAX_LETRAS) return 0;
    for (int i = 0; i < tam; i++)
        if (!isalpha((unsigned char)p[i])) return 0;
    return 1;
}

int main(void) {
    char palavra[64], cifrada[MAX_LETRAS + 1];
    int seq[MAX_LETRAS], shift, tipo;

    do {
        printf("Palavra: ");
        scanf("%63s", palavra);
    } while (!palavra_valida(palavra));
    for (int i = 0; palavra[i]; i++)
        palavra[i] = tolower((unsigned char)palavra[i]);

    do {
        printf("SHIFT: ");
        scanf("%d", &shift);
    } while (shift < 1 || shift > 25);

    do {
        printf("Sequencia (1-PA 2-PG 3-Fibonacci 4-Primos): ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 4);

    int n = strlen(palavra);
    gerar_sequencia(tipo, n, seq);

    /* log de execucao (so no arquivo, nada aparece na tela) */
    FILE *log = fopen("log_execucao.txt", "a");
    if (log) {
        time_t agora = time(NULL);
        fprintf(log, "=== Execucao: %s", ctime(&agora));
        fprintf(log, "Palavra: %s | SHIFT: %d | Sequencia: %s\n",
                palavra, shift, nome_sequencia(tipo));
    }

    for (int i = 0; i < n; i++) {
        int pos = palavra[i] - 'a';
        int total = shift + seq[i];
        int nova = (pos + total) % 26;
        cifrada[i] = 'a' + nova;
        if (log)
            fprintf(log, "  letra %2d: '%c' | %d + %d = %d | -> '%c'\n",
                    i + 1, palavra[i], shift, seq[i], total, cifrada[i]);
    }
    cifrada[n] = '\0';

    if (log) {
        fprintf(log, "Resultado: %s\n\n", cifrada);
        fclose(log);
    }

    FILE *res = fopen("resultado_criptografia.txt", "w");
    if (res) {
        fprintf(res, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
                cifrada, shift, tipo, n);
        fclose(res);
    }

    printf("\nPalavra criptografada: %s\n", cifrada);
    return 0;
}
