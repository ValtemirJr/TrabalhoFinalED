#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "bebida.h"
#include "empresa.h"

#define TAM 30


int main(){
    ListaBebida *listaBebida = malloc(sizeof(ListaBebida));
    listaBebida->first = NULL;
    listaBebida->last = NULL;
    ListaCliente *listaCliente = malloc(sizeof(ListaCliente));
    listaCliente->first = NULL; 
    listaCliente->last = NULL;
    
    
/*     adicionaBebida(listaBebida, cadastrarBebida());
    adicionaBebida(listaBebida, cadastrarBebida());
    adicionaBebida(listaBebida, cadastrarBebida());
    mostrarBebidas(listaBebida); */


    adicionaCliente(listaCliente, cadastraCliente());
    adicionaCliente(listaCliente, cadastraCliente());
    adicionaCliente(listaCliente, cadastraCliente());
    adicionaCliente(listaCliente, cadastraCliente());
    adicionaCliente(listaCliente, cadastraCliente());
    mostrarClientes(listaCliente);
    
    
    
    return 0;
}