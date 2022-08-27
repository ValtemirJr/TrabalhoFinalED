#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bebida.h"
#include "cliente.h"

#define TAM 30

Bebida *cadastrarBebida(){
    Bebida *new = malloc(sizeof(Bebida));
    printf("Codigo da Bebida: ");
    scanf("%d", &new->codBebida);
    printf("Nome da Bebida: ");
    scanf("%s", new->nomeBedida);
    printf("Quantidade da bebida em ml: ");
    scanf("%lf", &new->quantMl);
    printf("Quantidade em estoque: ");
    scanf("%d", &new->estoque);
    printf("Bebida alcoolica (SIM[1]  NÃO[0]): ");
    scanf("%d", &new->alcoolica);
    printf("Preço da Bebida: ");
    scanf("%lf", &new->preco);
    printf("\n");
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int listaVazia(ListaBebida *listaBebida){
    return(listaBebida->first == NULL);
}

void adicionaBebida(ListaBebida *listaBebida, Bebida *new){
    if(listaVazia(listaBebida)){
        listaBebida->first =  new;
        listaBebida->last = new;
        return;
    }
    new->prev = listaBebida->last;
    new->prev->next = new;
    listaBebida->last= new; 
    return;
}

void mostrarBebidas(ListaBebida *listaBebida){
    Bebida *aux;
    for(aux = listaBebida->first; aux != NULL; aux=aux->next){
        printf("Código: %d\n", aux->codBebida);
        printf("Bebida: %s\n", aux->nomeBedida);
        printf("Quantidade em ml: %.2lf\n", aux->quantMl);
        printf("Alcoolica: %d\n", aux->alcoolica);
        printf("Preço: R$ %.2lf\n", aux->preco);
        printf("Estoque disponível: %d\n", aux->estoque);
        printf("\n");
    }
}
