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

    printf("\--------Desenvolvido por-------------------------\n \n Jo�o Victor Silva Fagundes          Matr�cula: GU3005372\n\n\n Eliz�ngela Vieira Roque             Matr�cula: GU3006506\n\n");

    printf ("\n\n------Digite um valor de 0 a 6-------------------\n ");
    printf("\nInserir novo cliente: 1");
    printf("\nGerar e exibir relat�rio de contatos: 2");
    printf("\nGerar e exibir relat�rio com busca por c�digo: 3");
    printf("\nGerar e exibir relat�rio com busca por nome: 4");
    printf("\nEdi��o de dados do contato: 5");
    printf("\nRemover contato: 6");
    printf("\nSair e encerrar o programa: 0\n\n--------------------------------------------------\n\n");

    scanf("%d", &valor);

switch (valor){

    case 1 :
      //----- Inser��o de dados na lista ---------
    {


    int opcao;



    do{


        printf("\nDigite o c�digo do cliente: ");
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
        // ------ Busca na lista pelo c�digo do cadastro

    int option;

    do{
    int codigo;
    printf("Digite o C�digo do cliente: ");
    scanf("%d",&codigo);
    x = consulta_lista_cod(li, codigo, &ctt);


    printf("\n\nPosi��o :%d", posicao);
    printf("\nC�digo :%d", ctt.codigo);
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

        printf("\n\nPosi��o :%d", posicao);
        printf("\nC�digo :%d", ctt.codigo);
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
    printf("Digite o c�digo do cliente a ser alterado: \n");
    scanf("%d", &codigo);
    x = consulta_lista_cod(li, codigo, &ctt);
    printf("\n\nPosi��o :%d", posicao);
    printf("\nC�digo :%d", ctt.codigo);
    printf("\nNome do cliente :%s", ctt.nome);
    printf("\nEmpresa :%s",ctt.empresa);
    printf("\nDepartamento :%s",ctt.depart);
    printf("\nTelefone :%s",ctt.tel);
    printf("\nCelular :%s",ctt.cel);
    printf("\nE-mail :%s",ctt.email);
    novo_cod = ctt.codigo;

    printf("Tem certeza que deseja fazer a edi��o?\n\n Digite 1 para sim e 2 para n�o.\n");
    scanf("%d", &resp);

    if(resp == 1){
       y = remove_lista(li, codigo);
    if(y){
        printf("Remo��o realizada com sucesso!");
    }else{
        printf("Remo��o n�o realizada!");
    }


    printf("Edite as informa��es do cliente: \n\n");
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

        printf("Edi��o realizada com sucesso! Pressione 0 para sair ou 1 para selecionar outro usu�rio para remo��o");
        scanf("%d", &opedit);
    }
    if(resp == 2){
        printf("Edi��o n�o realizada. Pressione 0 para sair ou 1 para selecionar outro usu�rio para remo��o");
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

    printf("Digite o c�digo do cliente para remo��o: \n");
    scanf("%d", &codigo);

    y = consulta_lista_cod(li, codigo, &ctt);

    printf("\n\nPosi��o :%d", posicao);
    printf("\nC�digo :%d", ctt.codigo);
    printf("\nNome do cliente :%s", ctt.nome);
    printf("\nEmpresa :%s",ctt.empresa);
    printf("\nDepartamento :%s",ctt.depart);
    printf("\nTelefone :%s",ctt.tel);
    printf("\nCelular :%s",ctt.cel);
    printf("\nE-mail :%s",ctt.email);


    printf("Voc� tem certeza que deseja remover esse cadastro?\nDigite '1' para sim e '0' para n�o:\n");
    scanf("%d", &resposta);


    if(resposta == 1){
        x = remove_lista(li, codigo);
        printf("Remo��o realizada com sucesso!\n\n");
        printf("Pressione 0 para sair ou 1 para selecionar outro usu�rio para remo��o: \n");
        scanf("%d", &opremove);
    }
    else if(resposta == 0){
        printf("Remo��o n�o realizada!\n\n");
        printf("Pressione 0 para sair ou 1 para selecionar outro usu�rio para remo��o: \n");
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
    printf ("Valor inv�lido!\n");
    system("pause");
  }
}



}
while(valor!=0);

}
