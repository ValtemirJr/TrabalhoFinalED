#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "bebida.h"

#define TAM 30

Bebida *cadastrarBebida(){
    Bebida *new = malloc(sizeof(Bebida));
    printf("Código da Bebida: ");
    scanf("%d", &new->codBebida);
    printf("Nome da Bebida: ");
    scanf("%s", new->nomeBebida);
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

int listaVaziaBebida(ListaBebida *listaBebida){
    return(listaBebida->first == NULL);
}

void adicionaBebida(ListaBebida *listaBebida, Bebida *new){
    if(listaVaziaBebida(listaBebida)){
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
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("\n");
    for(aux = listaBebida->first; aux != NULL; aux=aux->next){
        printf("Código: %d\n", aux->codBebida);
        printf("Bebida: %s\n", aux->nomeBebida);
        printf("Quantidade em ml: %.2lf\n", aux->quantMl);
        if(aux->alcoolica == 1)
            printf("Alcoólica: SIM\n");
        else
            printf("Alcoólica: NÃO\n");
        printf("Preço: R$ %.2lf\n", aux->preco);
        printf("Estoque disponível: %d\n", aux->estoque);
        printf("\n");
    }
    printf("-----------------------------------------------\n");
    printf("\n");
}

Bebida *buscaBebida(ListaBebida *listaBebida){
    Bebida *aux;
    int cod;
    printf("Código da Bebida: ");
    scanf("%d", &cod);
    for(aux = listaBebida->first; aux != NULL; aux = aux->next){
        if(aux->codBebida == cod){
            return aux;
        }
    }
    return NULL;
}

void compraBebida(ListaBebida *listaBebida){
    int quantBebida;
    Bebida *bebida;
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n");
        return;
    }
    bebida = buscaBebida(listaBebida);
    if (bebida == NULL){
        printf("Bebida não encontrada\n");
    }
    else{
        printf("Bebida: %s\n", bebida->nomeBebida); 
        printf("Quantidade em estoque: %d\n", bebida->estoque);
        printf("Adicionar em estoque: ");
        scanf("%d", &quantBebida);
        bebida->estoque += quantBebida;
        printf("Estoque atualizado: %d\n", bebida->estoque);
    }
}

void vendeBebida(ListaBebida *listaBebida, ListaCliente *listaCliente){
    int quantBebida;
    Bebida *bebida;
    Cliente *cliente = buscaCliente(listaCliente);
    if(cliente == NULL){
        printf("Cliente não encontrado\n");
        return;
    }
    printf("Cliente: %s\n", cliente->nomeCliente);
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n");
        return;
    }
    bebida = buscaBebida(listaBebida);
    while(bebida == NULL){
        printf("Bebida não encontrada\n");
        return;
    }
    printf("Bebida: %s\n", bebida->nomeBebida);
    if(bebida->alcoolica){
        if (cliente->idade < 18){
            printf("Menor de idade, venda não autorizada!\n");
            return;
        }
        printf("Quantidade a ser comprada: ");
        scanf("%d", &quantBebida);
        if(bebida->estoque == 0){
            printf("Sem estoque!\n");
            return;
        }
        while(bebida->estoque < quantBebida){
            printf("Estoque insuficiente\n");
            printf("Quantidade a ser comprada: ");
            scanf("%d", &quantBebida);
        }
    }
    bebida->estoque -= quantBebida;
}

int freeListaBebida(ListaBebida *lista){
    Bebida *aux;
    aux = lista->first;
    int i = 0;
    while(aux != NULL){
        lista->first = lista->first->next;
        free(aux);
        aux = lista->first;
        i++;
    }
    return i;
}
