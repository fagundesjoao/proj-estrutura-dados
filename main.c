#include <stdio.h>
#include <stdlib.h>
#include "ListaContatos.h"
#include<string.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    FILE* arquivo = fopen("arquivo.bin", "a+");

    int posicao;
    int x;
    Lista *li, cto;
    CONTATO ctt;

    li=criaLista();

    x=tamLista(li);
    printf("\nO tamanho da lista e: %d", x);

    while(!feof(arquivo)){
        fread(&ctt, sizeof(CONTATO), 1, arquivo);
        insere_lista_ordenada(li, ctt);
    }




      int valor;

    // ----- Menu em Loop -----------
do{
    system("cls");

    printf("\--------Desenvolvido por-------------------------\n \n João Victor Silva Fagundes          Matrícula: GU3005372\n\n\n Elizângela Vieira Roque             Matrícula: GU3006506\n\n");

    printf ("\n\n------Digite um valor de 0 a 6-------------------\n ");
    printf("\nInserir novo cliente: 1");
    printf("\nGerar e exibir relatório de contatos: 2");
    printf("\nGerar e exibir relatório com busca por código: 3");
    printf("\nGerar e exibir relatório com busca por nome: 4");
    printf("\nEdição de dados do contato: 5");
    printf("\nRemover contato: 6");
    printf("\nSair e encerrar o programa: 0\n\n--------------------------------------------------\n\n");

    scanf("%d", &valor);

switch (valor){

    case 1 :
      //----- Inserção de dados na lista ---------
    {


    int opcao;



    do{


        printf("\nDigite o código do cliente: ");
        scanf("%d", &ctt.codigo);
        getchar();
        printf("\nDigite o nome do cliente: ");
        fgets(ctt.nome,90,stdin );
        printf("\nDigite a empresa do cliente: ");
        fgets(ctt.empresa,90,stdin );
        printf("\nDigite o departamento do cliente: ");
        fgets(ctt.depart,90,stdin );
        printf("\nDigite o telefone do cliente: ");
        fgets(ctt.tel,20,stdin );
        printf("\nDigite o celular do cliente: ");
        fgets(ctt.cel,20,stdin );
        printf("\nDigite o e-mail do cliente: ");
        fgets(ctt.email,60,stdin );
        x = insere_lista_ordenada(li, ctt);

        fwrite(&ctt, sizeof(CONTATO), 1, arquivo);

        printf("\nDigite 1 para cadastrar um novo cliente ou 0 para sair: ");
        scanf("%d", &opcao);
        getchar();

    }

    while(opcao == 1);


    }

    break;

    case 2: {

    int oplista;

    do{


    listar(li);
    printf("\n\nDigite 0 para sair: ");
    scanf("%d", &oplista);

    }



    while(oplista != 0);

}


    break;



case 3 :{
        // ------ Busca na lista pelo código do cadastro

    int option;

    do{
    int codigo;
    printf("Digite o Código do cliente: ");
    scanf("%d",&codigo);
    x = consulta_lista_cod(li, codigo, &ctt);


    printf("\n\nPosição :%d", posicao);
    printf("\nCódigo :%d", ctt.codigo);
    printf("\nNome do cliente :%s", ctt.nome);
    printf("\nEmpresa :%s",ctt.empresa);
    printf("\nDepartamento :%s",ctt.depart);
    printf("\nTelefone :%s",ctt.tel);
    printf("\nCelular :%s",ctt.cel);
    printf("\nE-mail :%s",ctt.email);
    printf("\nDigite 1 para procurar um novo cliente ou 0 para sair: ");

    scanf("%d", &option);
    getchar();
    }
    while(option == 1);
    }
    break;


case 4 :{



    //------- Busca pelo nome do cliente
    {
     int opcliente;
    do{
        getchar();
        char nome[90];

        printf("Digite o Nome do cliente: ");
        fgets(nome,90,stdin);
        x = consulta_lista_nome(li, nome, &ctt);

        printf("\n\nPosição :%d", posicao);
        printf("\nCódigo :%d", ctt.codigo);
        printf("\nNome do cliente :%s", ctt.nome);
        printf("\nEmpresa :%s",ctt.empresa);
        printf("\nDepartamento :%s",ctt.depart);
        printf("\nTelefone :%s",ctt.tel);
        printf("\nCelular :%s",ctt.cel);
        printf("\nE-mail :%s",ctt.email);
        printf("\nDigite 1 para procurar um novo cliente ou 0 para sair: ");
        scanf("%d", &opcliente);


    }
    while(opcliente == 1);

}
}
    break;

case 5:{
    int opedit;

    do{
    getchar();
    int codigo, x, y, z, resp, novo_cod;
    printf("Digite o código do cliente a ser alterado: \n");
    scanf("%d", &codigo);
    x = consulta_lista_cod(li, codigo, &ctt);
    printf("\n\nPosição :%d", posicao);
    printf("\nCódigo :%d", ctt.codigo);
    printf("\nNome do cliente :%s", ctt.nome);
    printf("\nEmpresa :%s",ctt.empresa);
    printf("\nDepartamento :%s",ctt.depart);
    printf("\nTelefone :%s",ctt.tel);
    printf("\nCelular :%s",ctt.cel);
    printf("\nE-mail :%s",ctt.email);
    novo_cod = ctt.codigo;

    printf("Tem certeza que deseja fazer a edição?\n\n Digite 1 para sim e 2 para não.\n");
    scanf("%d", &resp);

    if(resp == 1){
       y = remove_lista(li, codigo);
    if(y){
        printf("Remoção realizada com sucesso!");
    }else{
        printf("Remoção não realizada!");
    }


    printf("Edite as informações do cliente: \n\n");
        ctt.codigo=novo_cod;
        getchar();
        printf("\nDigite o nome do cliente: ");
        fgets(ctt.nome,90,stdin );
        printf("\nDigite a empresa do cliente: ");
        fgets(ctt.empresa,90,stdin );
        printf("\nDigite o departamento do cliente: ");
        fgets(ctt.depart,90,stdin );
        printf("\nDigite o telefone do cliente: ");
        fgets(ctt.tel,20,stdin );
        printf("\nDigite o celular do cliente: ");
        fgets(ctt.cel,20,stdin );
        printf("\nDigite o e-mail do cliente: ");
        fgets(ctt.email,60,stdin );

    z = insere_lista_ordenada(li, ctt);

        printf("Edição realizada com sucesso! Pressione 0 para sair ou 1 para selecionar outro usuário para remoção");
        scanf("%d", &opedit);
    }
    if(resp == 2){
        printf("Edição não realizada. Pressione 0 para sair ou 1 para selecionar outro usuário para remoção");
        scanf("%d", &opedit);
    }

    }
    while(opedit == 1);




    }


    break;

    case 6 :{

    int opremove;
    do{
    //Remocao
    getchar();
    int codigo;
    int resposta;
    int x;
    int y;
    int n;

    printf("Digite o código do cliente para remoção: \n");
    scanf("%d", &codigo);

    y = consulta_lista_cod(li, codigo, &ctt);

    printf("\n\nPosição :%d", posicao);
    printf("\nCódigo :%d", ctt.codigo);
    printf("\nNome do cliente :%s", ctt.nome);
    printf("\nEmpresa :%s",ctt.empresa);
    printf("\nDepartamento :%s",ctt.depart);
    printf("\nTelefone :%s",ctt.tel);
    printf("\nCelular :%s",ctt.cel);
    printf("\nE-mail :%s",ctt.email);


    printf("Você tem certeza que deseja remover esse cadastro?\nDigite '1' para sim e '0' para não:\n");
    scanf("%d", &resposta);


    if(resposta == 1){
        x = remove_lista(li, codigo);
        printf("Remoção realizada com sucesso!\n\n");
        printf("Pressione 0 para sair ou 1 para selecionar outro usuário para remoção: \n");
        scanf("%d", &opremove);
    }
    else if(resposta == 0){
        printf("Remoção não realizada!\n\n");
        printf("Pressione 0 para sair ou 1 para selecionar outro usuário para remoção: \n");
        scanf("%d", &opremove);
    }else{

        printf("Digite o valor correto!\n");
        scanf("%d", &resposta);
    }


    }
    while(opremove == 1);


    break;

    case 0: {
    int opsair;

    do{

    printf("Tem certeza que deseja sair? Digite '1'!");
    scanf("%d", &opsair);

    fclose(arquivo);
    return 0;

    }
    while(opsair != 1);

    }
    break;

    default :
    printf ("Valor inválido!\n");
    system("pause");
  }
}



}
while(valor!=0);

}
