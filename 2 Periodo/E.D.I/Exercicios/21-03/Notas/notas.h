#ifndef NOTAS_H
#define NOTAS_H

typedef struct {
    char nome[20];
    float nota[3];
    float media;
} aluno;

aluno ler() {
    int i;
    aluno aux;
    printf("\nInforme o nome do aluno: ");
    scanf("%s", aux.nome);
    for (i = 0; i < 3; i++) {
        printf("Informe a nota %d: ", i + 1);
        scanf("%f", &aux.nota[i]);
    }
    return aux;
}

aluno media() {
    int i;
    aluno aux;
    float media = 0;
    for (i = 0; i < 3; i++) {
        media += aux.nota[i];
    }
    aux.media = media / 3;
    return aux;
}

void imprimir(aluno aux) {
    int i;
    printf("\nALUNO: %s", aux.nome);
    for (i = 0; i < 3; i++) {
        printf("\nNOTA %d: %.2f", i + 1, aux.nota[i]);
    }
    printf("\nMEDIA: %.2f\n", aux.media);
}
#endif // NOTAS_H

