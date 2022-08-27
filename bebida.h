struct _bebida{
    int codBebida;
    char nomeBedida[30];
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
void adicionaBebida(ListaBebida *listaBebida, Bebida *new);
void *compraBebida(ListaBebida *listaBebida, Bebida *bebida);
void mostrarBebidas(ListaBebida *listaBebida);
//Bebida *vendeBebida(ListaBebida *list, Cliente *cliente);

