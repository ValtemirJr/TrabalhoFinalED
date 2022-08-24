struct _cliente{
    int codCliente;
    char nomeCliente[50];
    int cpf;
    short int idade;
    int fiado;
    struct _cliente *next;
    struct _cliente *prev;
};
typedef struct _cliente Cliente;

typedef struct _listaCliente{
    Cliente *first;
    Cliente *last;
}ListaCliente; 

Cliente *cadastraCliente();