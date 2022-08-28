#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

#define TAM 30

Cliente *cadastraCliente(){
    Cliente *new = malloc(sizeof(Cliente));
    printf("Código do Cliente: ");
    scanf("%d", &new->codCliente);
    printf("Nome do Cliente: ");
    scanf("%s", new->nomeCliente);
    printf("CPF do Cliente: ");
    scanf("%d", &new->cpf);
    printf("Idade do Cliente: ");
    scanf("%d", &new->idade);
    printf("Pode vender fiado (SIM[1] NÃO[0]): ");
    scanf("%d", &new->fiado);
    printf("\n");
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int listaVaziaCliente(ListaCliente *listaCliente){
    return(listaCliente->first == NULL);
}


void adicionaCliente(ListaCliente *listaCliente, Cliente *new){
    Cliente *aux;
    if(listaVaziaCliente(listaCliente)){
        listaCliente->first = new; 
        listaCliente->last = new;  
        return;
    }
    if(new->idade <= listaCliente->first->idade){
        new->next = listaCliente->first;
        new->next->prev = new;
        listaCliente->first= new;
    }
    else if(new->idade >= listaCliente->last->idade){
        listaCliente->last->next=new;
        new->prev=listaCliente->last;
        listaCliente->last=new;
    }
    else{
        for(aux = listaCliente->first; aux != NULL; aux = aux->next){
            if(new->idade <= aux->idade){
                new->next = aux;
                aux->prev->next = new;
                new->prev = aux->prev;
                aux->prev = new;
                return;
            }
        }   
    }
}
 

void mostrarClientes(ListaCliente *listaCliente){
    Cliente *aux;
    if(listaVaziaCliente(listaCliente)){
        printf("Não existe clientes cadastrados\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("\n");
    for(aux = listaCliente->first; aux != NULL; aux=aux->next){
        printf("Código: %d\n", aux->codCliente);
        printf("Nome: %s\n", aux->nomeCliente);
        printf("CPF: %d\n", aux->cpf);
        printf("Idade: %d\n", aux->idade);
        if(aux->fiado == 1)
            printf("Vende fiado: SIM\n");
        else
            printf("Vende fiado: NÃO\n");
        printf("\n");
    }
    printf("-----------------------------------------------\n");
    printf("\n");
}

Cliente *buscaCliente(ListaCliente *listaCliente){
    int cpf;
    printf("CPF: ");
    scanf("%d", &cpf);
    Cliente *aux;
    for(aux = listaCliente->first; aux != NULL; aux = aux->next){
        if(aux->cpf == cpf){
            return aux;
        }
    }
    return NULL;
}

int freeListaCliente(ListaCliente *lista){
    Cliente *aux;
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