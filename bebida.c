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
    int key;
    printf("Código da Bebida: ");
    scanf("%d", &key);
    for(aux = listaBebida->first; aux != NULL; aux = aux->next){
        if(aux->codBebida == key){
            return aux;
        }
    }
    return NULL;
}


void compraBebida(ListaBebida *listaBebida, Bebida *bebida){
    int quantBebida;
    if (bebida == NULL){
        printf("Bebida não encontrada\n");
    }
    printf("Bebida: %s\n", bebida->nomeBebida); 
    printf("Quantidade em estoque: %d\n", bebida->estoque);
    printf("Adicionar em estoque: ");
    scanf("%d", &quantBebida);
    bebida->estoque += quantBebida;
    printf("Estoque atualizado: %d\n", bebida->estoque);
}


//Verificar integridade
void vendeBebida(ListaBebida *listaBebida, ListaCliente *listaCliente, Cliente *cliente){
    int quantBebida;
    Bebida *bebida;
    bebida = buscaBebida(listaBebida);
    while(bebida == NULL){
        printf("Bebida não encontrada\n");
        bebida = buscaBebida(listaBebida);
    }
    if (bebida->alcoolica){
        if (cliente->idade < 18){
            printf("Venda não autorizada\n");
            return;
        }
        printf("Quantidade a ser comprada: ");
        scanf("%d", &quantBebida);
        while(bebida->estoque < quantBebida){
            printf("Estoque insuficiente\n");
            printf("Quantidade a ser comprada: ");
            scanf("%d", &quantBebida);
        }
    }
    bebida->estoque -= quantBebida;
}