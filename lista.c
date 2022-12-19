#include<stdio.h>
#include<stdlib.h>
#include "ListaContatos.h"

typedef struct elemento{
    CONTATO dados;
    struct elemento *prox;
}ELEM;


Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL){
        *li = NULL;
    }




    return li;
}

int tamLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}



int insere_lista_ordenada(Lista *li, CONTATO ctt){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = ctt;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo<ctt.codigo){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}


int remove_lista(Lista *li, int cod){

    if(li == NULL)
        return 0;
    ELEM *ant, *no = *li;


    while(no != NULL && no->dados.codigo != cod){
      ant = no;
      no = no->prox;
    }

    if(no == NULL)
      return 0;

    if(no == *li){
        *li = no->prox;
    }else{
    ant->prox = no->prox;
    free(no);
    return 1;
    }

}

int consulta_lista_pos(Lista *li, int posicao, CONTATO *ctt){
    if(li == NULL || posicao <= 0){
        return 0;
    }
    ELEM *no = *li;
    int i = 1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }else{
        *ctt = no->dados;
        return 1;
    }

}



int consulta_lista_cod(Lista *li, int codigo, CONTATO *ctt){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *ctt = no->dados;
        return 1;
    }

}

//Função consulta por nome

int consulta_lista_nome(Lista *li, char nome[90] , CONTATO *ctt){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.nome != nome){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *ctt = no->dados;
        return 1;
    }

}

// --- Função que percorre a lista até o fim e exibe todos os elementos cadastrados

void listar(Lista *li){
    ELEM *no = *li;
  while(no != NULL){
    printf("Código:%d\n",no->dados.codigo);
    printf("Nome:%s\n",no->dados.nome);
    printf("Departamento:%s\n",no->dados.depart);
    printf("Empresa:%s\n",no->dados.empresa);
    printf("Telefone:%s\n",no->dados.tel);
    printf("Celular:%s\n",no->dados.cel);
    printf("E-mail:%s\n\n\n",no->dados.email);


    no = no->prox;
  }
}
