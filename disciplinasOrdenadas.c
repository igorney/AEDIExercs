#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tDisciplina {
 int cod;
 char *nome;
 int creditos;
 struct tDisciplina *requisito;
} Disciplina;
Disciplina * criaDisciplina (int cod, char *nome, int creditos){
    Disciplina *n = (Disciplina*)malloc(sizeof(Disciplina));
    n->cod = cod;
    n->nome = nome;
    n->creditos = creditos;
    n->requisito == NULL;
    return n;
}
typedef struct tCurso {
 int cod_curso;
 char *nome_curso;
 Disciplina *ultima_disciplina;
} Curso;
Curso * criaCurso (int cod_curso, char *nome_curso){
    Curso *n = (Curso*)malloc(sizeof(Curso));
    n->cod_curso = cod_curso;
    n->nome_curso = nome_curso;
    n->ultima_disciplina = NULL;
    return n;
}
void insereDisciplina (Curso *curso, Disciplina *nova_disciplina){
    if(curso->ultima_disciplina == NULL){ //se ultima disciplina é null o curso está vázio
        curso->ultima_disciplina = nova_disciplina; //insere nova disciplina na ultima do curso
    }
    else
    {
        // procurar posicao de insercao
        Disciplina *atu = curso->ultima_disciplina, *ant = NULL;
        while (atu != NULL && strcmp(nova_disciplina->nome, atu->nome) < 0)
        {
            ant = atu;
            atu = atu->requisito;
        }
        // caso 2: inicio da lista
        if (ant == NULL) {
            nova_disciplina->requisito = curso->ultima_disciplina;
            curso->ultima_disciplina = nova_disciplina;
        }
        // caso 3: fim da lista
        else if (atu == NULL) {
            ant->requisito = nova_disciplina;
        }
        // caso 4: meio da lista
        else if (strcmp(nova_disciplina->nome, atu->nome) != 0) {
            ant->requisito = nova_disciplina;
            nova_disciplina->requisito = atu;
        }
    }
    
}
void imprime (Curso *c) {
    printf ("Disciplinas do curso: cod=%d nome=%s\n",
    c->cod_curso, c->nome_curso);
    Disciplina *d = c->ultima_disciplina;
    while (d != NULL) {
        printf ("cod=%d nome=%s cred=%d\n", d->cod, d->nome, d->creditos);
        d = d->requisito;
    }
}
int main () {
    int cod_curso;
    char nome_curso[100];
    scanf ("%d", &cod_curso);
    scanf ("%s", nome_curso);
    Curso *c = criaCurso (cod_curso, nome_curso);

    int cod, creditos;
    char *nome = NULL;
    while (scanf ("%d", &cod) != EOF) {
        nome = malloc (100);
        scanf ("%s %d", nome, &creditos);
        Disciplina *d = criaDisciplina (cod, nome, creditos);
        insereDisciplina (c, d);
    }
    imprime (c);
    free(c);
    return 0;
}