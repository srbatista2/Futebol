#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


typedef struct _jogador{
    char nome[20];
    int idade;
    char posicao[20];
    int idJogador;

}Jogador;

typedef struct _clube{
    char nome[20];
    char local[20];
    int fundacao;
    int idclube;
    Jogador jogador[20];
    int numJ;
}Clube;

typedef struct _campeonato{
    int id;
    char nome[20];
    char pais[20];
    char modalidade[20];
    Clube clubes[10];
    int numClubes;

}Campeonato;

Jogador inserirjogador(int numJ){
    Jogador novojogador;
    novojogador.idJogador=numJ;
    system("cls");
    printf("Nome do jogador: ");
    scanf(" %[^\n]s", novojogador.nome);
    printf("Idade do jogador: ");
    scanf("%i", &novojogador.idade);
    printf("posição do jogador: ");
    scanf(" %[^\n]s", novojogador.posicao);
    return novojogador;
   }

Clube inserirclube(int numClubes){
    Clube novoclube;
    novoclube.idclube=numClubes;
    printf("NOME DO CLUBE: ");
    scanf(" %[^\n]s", novoclube.nome);
    printf("LOCAL DO CLUBE: ");
    scanf(" %[^\n]s", novoclube.local);
    printf("ANO DE FUNDAÇÃO DO CLUBE: ");
    scanf("%i", &novoclube.fundacao);
    novoclube.numJ = 0;
    puts("");
    return novoclube;
    }

Campeonato inserircampeonato(int numCamp){
    Campeonato novocampeonato;
    novocampeonato.id=numCamp;
    system("cls");
    printf("NOME DO CAMPEONATO: ");
    scanf(" %[^\n]s", novocampeonato.nome);
    printf("PAIS DO CAMPEONATO: ");
    scanf(" %[^\n]s", novocampeonato.pais);
    printf("MODALIDADE DO CAMPEONATO: ");
    scanf(" %[^\n]s", novocampeonato.modalidade);
    novocampeonato.numClubes = 0;
    return novocampeonato;
}

void listarjogador(int numJ, Jogador jogador[]){
    int i;
    system("cls");
    for(i=0;i<numJ;i++){
        printf("NOME: %s\n", jogador[i].nome);
        printf("ID: %i\n", i);
        printf("IDADE: %i\n", jogador[i].idade);
        printf("POSIÇÃO: %s\n\n", jogador[i].posicao);
}
}

void listarclubes(int numClubes, Clube clubes[]){
    int i;
    system("cls");
    for(i=0;i<numClubes;i++){
        printf("NOME: %s\n", clubes[i].nome);
        printf("ID: %i\n", i);
        printf("CIDADE: %s\n", clubes[i].local);
        printf("FUNDAÇÃO: %i\n\n", clubes[i].fundacao);
}
}
Campeonato listarcampeonato(int numCamp, Campeonato campeonatos[]){
    int i;
    system("cls");
    for(i=0;i<numCamp
;i++){
    printf("NOME: %s\n", campeonatos[i].nome);
    printf("ID: %i\n", i);
    printf("PAÍS: %s\n", campeonatos[i].pais);
    printf("MODALIDADE: %s\n\n",campeonatos[i].modalidade);
}
}






int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    system ("COLOR A");


    int op,a=1,numCamp=0,idCamp,idClube,id;
    Campeonato campeonatos[5];


    while(a==1){
    system("cls");

    puts("BEM VINDO AO PAINEL DE FUTEBOL 2022\n");
    puts("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");

    puts("      OQUE DESEJA FAZER?\n");
    puts("  1-INSERIR CAMPEONATO\n");
    puts("  2-LISTAR CAMPEONATOS CADASTRADOS\n");
    puts("  3-INSERIR CLUBES\n");
    puts("  4-LISTAR CLUBES CADASTRADOS\n");
    puts("  5-INSERIR JOGADOR\n");
    puts("  6-LISTAR JOGADORES CADASTRADOS\n");

    puts("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");


   op=getch();
    switch(op)
{
        case '1':
            campeonatos[numCamp]=inserircampeonato(numCamp);
            numCamp++;
            printf("CAMPEONATO ADICIONADO!\n");
            system("pause");
            break;

        case '2':
            listarcampeonato(numCamp,campeonatos);
            system("pause");
            break;

        case '3':
            listarcampeonato(numCamp,campeonatos);
            printf("DIGITE O ID DO CAMPEONATO, CASO NÃO ESTEJE LISTADO DIGITE UM ID NÃO CADASTRADO: ");
            scanf("%i", &idCamp);
            if(idCamp<numCamp&& idCamp>=0){
                int numClubes = campeonatos[idCamp].numClubes;
                campeonatos[idCamp].clubes[numClubes]=inserirclube(numClubes);
                campeonatos[idCamp].numClubes++;
                break;
            }else{
                puts("RETORNANDO AO INICIO");
                system("pause");
                }
                system("cls");
                break;
                case '4':
            listarcampeonato(numCamp,campeonatos);
            printf("ID DO CAMPEONATO: ");
            scanf("%i", &idCamp);
            int numClubes = campeonatos[idCamp].numClubes;
            listarclubes(numClubes, campeonatos[idCamp].clubes);
            system("pause");
            break;

        case '5':
            listarcampeonato(numCamp,campeonatos);
            printf("DIGITE O ID DO CAMPEONATO, CASO NÃO ESTEJE LISTADO DIGITE UM ID NÃO CADASTRADO: ");
            scanf("%i", &idCamp);
            if(idCamp<numCamp&&idCamp>=0){
                int numClubes = campeonatos[idCamp].numClubes;
                listarclubes(numClubes, campeonatos[idCamp].clubes);
                printf("DIGITE O ID DO CLUBE, CASO NÃO ESTEJE LISTADO DIGITE UM ID NÃO CADASTRADO: ");
                scanf("%i", &idClube);
                if(idClube<numClubes&&idClube>=0){
                    int numJ = campeonatos[idCamp].clubes[idClube].numJ;
                    campeonatos[idCamp].clubes[idClube].jogador[numJ]=inserirjogador(numJ);
                    campeonatos[idCamp].clubes[idClube].numJ++;
                    puts("JOGADOR ADICIONADO");
                    system("pause");
                    break;
                    }
            }else{
                puts("RETORNANDO AO INICIO");
                system("pause");}
                system("cls");
                break;

        case '6':
            listarcampeonato(numCamp,campeonatos);
            printf("DIGITE O ID DO CAMPEONATO, CASO NÃO ESTEJE LISTADO DIGITE UM ID NÃO CADASTRADO: ");
            scanf("%i", &idCamp);
            if(idCamp<numCamp&&idCamp>=0){
                listarclubes(numClubes, campeonatos[idCamp].clubes);
                printf("DIGITE O ID DO CLUBE, CASO NÃO ESTEJE LISTADO DIGITE UM ID NÃO CADASTRADO: ");
                scanf("%i", &idClube);
                if(idCamp<numClubes&&idCamp>=0){
                    int numJ = campeonatos[idCamp].clubes[idClube].numJ;
                    listarjogador(numJ, campeonatos[idCamp].clubes[idClube].jogador);
                    system("pause");}
            }else{
                puts("RETORNANDO AO INICIO");
                system("pause");}
                system("cls");
                break;}
    }


return 0;

}
