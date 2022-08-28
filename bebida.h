struct _bebida{
    int codBebida;
    char nomeBebida[30];
    double quantMl;
    int alcoolica;
    double preco;
    int estoque;
    struct _bebida *next;
    struct _bebida *prev;
};
typedef struct _bebida Bebida;

typedef struct _listaBebida{
    Bebida *first;
    Bebida *last;
}ListaBebida;

Bebida *cadastrarBebida();
Bebida *buscaBebida(ListaBebida *listaBebida);
void adicionaBebida(ListaBebida *listaBebida, Bebida *new);
void compraBebida(ListaBebida *listaBebida);
void mostrarBebidas(ListaBebida *listaBebida);
void vendeBebida(ListaBebida *listaBebida, ListaCliente *listaCliente);
int freeListaBebida(ListaBebida *lista);
