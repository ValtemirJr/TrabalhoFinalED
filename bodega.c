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

    int opcao;

    printf("1- Cadastrar bebida\n");
    printf("2- Mostrar bebidas\n");
    printf("3- Comprar bebida\n");
    printf("4- Vender Bebida\n");
    printf("5- Cadastrar Cliente\n");
    printf("6- Mostrar Clientes\n");
    printf("7- Sair\n");
    
    printf("Escolha a opção: ");
    scanf("%d", &opcao);

    while (1){
        if(opcao == 1){
            adicionaBebida(listaBebida, cadastrarBebida());
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 2){
            mostrarBebidas(listaBebida);
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 3){
            compraBebida(listaBebida, buscaBebida(listaBebida));
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 4){
            vendeBebida(listaBebida, listaCliente, buscaCliente(listaCliente));
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 5){
            adicionaCliente(listaCliente, cadastraCliente());
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 6){
            mostrarClientes(listaCliente);
            printf("Escolha a opção: ");
            scanf("%d", &opcao);
        }
        else if(opcao == 7){
            printf("Sistema finalizado\n");
            break;
        }
        else if(opcao > 7 || opcao < 1){
            printf("Escolha a opção correta: ");
            scanf("%d", &opcao);
        }
    }
    
    
/*     adicionaBebida(listaBebida, cadastrarBebida());
    adicionaBebida(listaBebida, cadastrarBebida());
    mostrarBebidas(listaBebida);

    adicionaCliente(listaCliente, cadastraCliente());
    adicionaCliente(listaCliente, cadastraCliente());
    mostrarClientes(listaCliente);

    vendeBebida(listaBebida, listaCliente, buscaCliente(listaCliente));
    vendeBebida(listaBebida, listaCliente, buscaCliente(listaCliente));
    mostrarBebidas(listaBebida); */
    
    
    
    return 0;
}