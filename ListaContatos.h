typedef struct contato{
    int codigo;
    char nome[90];
    char empresa[90];
    char depart[90];
    char tel[20];
    char cel[20];
    char email[60];
}CONTATO;

typedef struct elemento* Lista;

Lista *criaLista();

int tamLista(Lista *li);

int listaVazia(Lista *li);

int insere_inicio_lista(Lista *li, CONTATO ctt);

int insere_final_lista(Lista *li, CONTATO ctt);

int insere_lista_ordenada(Lista *li, CONTATO ctt);

int remove_inicio_lista(Lista *li);

int remove_final_lista(Lista *li);

int remove_lista(Lista *li, int cod);

int consulta_lista_pos(Lista *li, int posicao, CONTATO *ctt);

int consulta_lista_cod(Lista *li, int codigo, CONTATO *ctt);

void listar(Lista *li);



