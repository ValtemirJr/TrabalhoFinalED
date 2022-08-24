#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

#define TAM 30

Cliente *cadastraCliente(){
    Cliente *new = malloc(sizeof(Cliente));
    printf("Codigo: ");
    scanf("%d", &new->codCliente);
    printf("Nome do Cliente: ");
    scanf("%s", new->nomeCliente);
    printf("CPF do Cliente: ");
    scanf("%d", &new->cpf);
    printf("Idade do Cliente: ");
    scanf("%d", &new->idade);
    printf("Pode vender fiado(SIM[1] NÃO[0]): ");
    scanf("%d", &new->fiado);
    new->next = NULL;
    new->prev = NULL;
    return new;
}