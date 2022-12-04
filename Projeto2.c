#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#define max 15

typedef struct {
        int Dia;
        int Mes;
        int Ano;
}DATA_Projeto;

typedef struct {
        float Salario_DEVS;
        float HORA_EXTRAS_Valor;
        float DESLOCAMENTO_Reunioes;
        float OUTROS_Gastos;
}DESPESAS_Projeto;

struct INFO_Projetos {
    DESPESAS_Projeto desp_Projeto;
    DATA_Projeto data_Projeto;
        int COD_Projeto;
        char GERENTE_Projeto[50];
        char Cliente[50];
        float RECEITA_Projeto;
};

int main () {

setlocale(LC_ALL,"portuguese");

int i=0, PJ=0, N=0, A=0, aux=0, vet[max], Maior=0;
float Resp=0, TOTAL_Gasto=0;
char op=NULL, CHResp[50];

struct INFO_Projetos projeto[max];

do {

    printf("\n\n\t/----Lista de Comandos----/\n\n\tCriar NOVO Projeto [1]\n\tExibir LUCRO Total [2]\n\tExibir Projetos ATRASADOS [3]\n\tExibir Projeto com mais gastos EXTRAS [4]\n\tExibir Projeto mais CARO [5]\n\tPesquisar GERENTE [6]\n\tPesquisar CLIENTE [7]\n\tEXIT [8]\n\n\t\tDigite o número da AÇÃO que deseja ser executada:\n\t\t\t\t: ");
    scanf("%d",&A);

    switch(A){

        case 1 :

        if(A==1){

            do {
                i++;
                printf("\n\tDigite as informações para o PROJETO %d",i);

                printf("\n\n\t\tDigite o CÓDIGO do projeto:\n\t\t\t");
                scanf("%d", &projeto[i].COD_Projeto);

                printf("\n\n\t\tDigite o NOME do CLIENTE:\n\t\t\t");
                scanf("%s", &projeto[i].Cliente);

                printf("\n\n\t\tDigite o NOME do GERENTE responsável pelo projeto:\n\t\t\t");
                scanf("%s", &projeto[i].GERENTE_Projeto);

                printf("\n\n\t\tDigite a DATA de ENTREGA PREVISTA do projeto no formato [dd mm aaaa]:\n\t\t\t");
                scanf("%d%d%d", &projeto[i].data_Projeto.Dia, &projeto[i].data_Projeto.Mes, &projeto[i].data_Projeto.Ano);

                printf("\n\n\t\tDigite o SALÁRIO dos DEVS:\n\t\t\tR$:");
                scanf("%f", &projeto[i].desp_Projeto.Salario_DEVS);

                printf("\n\n\t\tDigite o VALOR das horas extras:\n\t\t\tR$:");
                scanf("%f", &projeto[i].desp_Projeto.HORA_EXTRAS_Valor);

                printf("\n\n\t\tDigite o VALOR das Deslocações de Reuniões:\n\t\t\tR$:");
                scanf("%f", &projeto[i].desp_Projeto.DESLOCAMENTO_Reunioes);

                printf("\n\n\t\tDigite os OUTROS gastos:\n\t\t\tR$:");
                scanf("%f", &projeto[i].desp_Projeto.OUTROS_Gastos);

                printf("\n\n\t\tDigite a RECEITA do projeto:\n\t\t\tR$:");
                scanf("%f", &projeto[i].RECEITA_Projeto);

        //------------------------------------------------------------------------------------//

                printf("\n\n///------PROJETO-%d------///\n\n",i);

                printf("Codigo do Projeto : %d\n",projeto[i].COD_Projeto);
                printf("------------------\n");

                printf("Cliente : %s\n",projeto[i].Cliente);
                printf("------------------\n");

                printf("Gerente : %s\n",projeto[i].GERENTE_Projeto);
                printf("------------------\n");

                printf("Data de Entrega Prevista do Projeto: %d/%d/%d\n",projeto[i].data_Projeto.Dia, projeto[i].data_Projeto.Mes, projeto[i].data_Projeto.Ano);
                printf("------------------\n");

                printf("Salário : R$:%.2f\n",projeto[i].desp_Projeto.Salario_DEVS);
                printf("------------------\n");

                printf("Horas Extras : R$:%.2f\n",projeto[i].desp_Projeto.HORA_EXTRAS_Valor);
                printf("------------------\n");

                printf("Deslocação de Reuniões : R$:%.2f\n",projeto[i].desp_Projeto.DESLOCAMENTO_Reunioes);
                printf("------------------\n");

                printf("Outros Gastos : R$:%.2f\n",projeto[i].desp_Projeto.OUTROS_Gastos);
                printf("------------------\n");

                printf("Receita do Projeto : R$:%.2f\n",projeto[i].RECEITA_Projeto);
                printf("------------------\n\n\n");

                PJ=i;

                printf("\tDeseja criar outro PROJETO [S/N] ?\n\t\t\t: ");
                scanf("%s", &op);

                if (op == 'N' || op == 'n') {
                    break;
                }

            }while(op == 'S' || op == 's');

        }


        case 2 :

        if(A==2){

            for (i=1;i<=PJ;i++){

                Resp=Resp+projeto[i].RECEITA_Projeto;
            }

            printf("\n\n\LUCRO TOTAL dos Projetos : R$:%.2f\n",Resp);
            printf("------------------\n\n\n");
            Resp=0;
            }

            break;


        case 3 :

            break;


        case 4 :

            Maior=0;
            aux=0;
            for (i=1;i<=PJ;i++){


                if(projeto[i].desp_Projeto.HORA_EXTRAS_Valor>Maior){

                    Maior=projeto[i].desp_Projeto.HORA_EXTRAS_Valor;
                    aux=i;
                }
            }

            printf("\n\n///------PROJETO-%d------///\n\n",aux);

            printf("Codigo do Projeto : %d\n",projeto[aux].COD_Projeto);
            printf("------------------\n");

            printf("Gerente : %s\n",projeto[aux].GERENTE_Projeto);
            printf("------------------\n");

            printf("Gastos Extras : %.2f\n",projeto[aux].desp_Projeto.HORA_EXTRAS_Valor);
            printf("------------------\n");

            break;

        case 5 :

            TOTAL_Gasto=0;
            Maior=0;
            aux=0;
            for (i=1;i<=PJ;i++){

                TOTAL_Gasto=projeto[i].desp_Projeto.Salario_DEVS+projeto[i].desp_Projeto.HORA_EXTRAS_Valor+projeto[i].desp_Projeto.DESLOCAMENTO_Reunioes+projeto[i].desp_Projeto.OUTROS_Gastos;

                if(TOTAL_Gasto>Maior){

                    aux=i;
                }
            }

            printf("\n\n///------PROJETO-%d------///\n\n",aux);

            printf("Codigo do Projeto : %d\n",projeto[aux].COD_Projeto);
            printf("------------------\n");

            printf("Gerente : %s\n",projeto[aux].GERENTE_Projeto);
            printf("------------------\n");

            printf("Gastos Totais : %.2f\n",TOTAL_Gasto);
            printf("------------------\n");

            break;



        case 6 :

        if(A==6){

            printf("\n\n\tDigite o NOME do GERENTE ?\n\t\t\t: ");
            scanf("%s", &CHResp);

            aux=NULL;
            N=9;
            for (i=1;i<=PJ;i++){

            N=strcmp(projeto[i].GERENTE_Projeto, CHResp);

            if(N==0) {
                aux=i;

                printf("\n\n///------PROJETO-%d------///\n\n",aux);

                printf("Codigo do Projeto : %d\n",projeto[aux].COD_Projeto);
                printf("------------------\n");

                printf("Cliente : %s\n",projeto[aux].Cliente);
                printf("------------------\n");

                printf("Data de Entrega Prevista do Projeto: %d/%d/%d\n",projeto[i].data_Projeto.Dia, projeto[i].data_Projeto.Mes, projeto[i].data_Projeto.Ano);
                printf("------------------\n");

                printf("Receita do Projeto : R$:%.2f\n",projeto[i].RECEITA_Projeto);
                printf("------------------\n\n\n");
                }
            }
        }
            break;

        case 7 :

            if(A==7){

            printf("\n\n\tDigite o NOME do CLIENTES ?\n\t\t\t: ");
            scanf("%s", &CHResp);

            aux=NULL;
            N=9;
            for (i=1;i<=PJ;i++){

            N=strcmp(projeto[i].Cliente, CHResp);

            if(N==0) {
                aux=i;

                printf("\n\n///------PROJETO-%d------///\n\n",aux);

                printf("Codigo do Projeto : %d\n",projeto[aux].COD_Projeto);
                printf("------------------\n");

                printf("Gerente : %s\n",projeto[i].GERENTE_Projeto);
                printf("------------------\n");

                printf("Data de Entrega Prevista do Projeto: %d/%d/%d\n",projeto[i].data_Projeto.Dia, projeto[i].data_Projeto.Mes, projeto[i].data_Projeto.Ano);
                printf("------------------\n");

                printf("Custo do Projeto : R$:%.2f\n",projeto[i].RECEITA_Projeto);
                printf("------------------\n\n\n");
                }
            }
        }

            break;
        }

    }while (A!=8);





return 0;
}


