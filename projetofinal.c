/*      __________________________________________________________
----   |                                                          |
----   | Projeto: SISTEMA DE CHAMADOS DA ALANA CORPORATION        |
----   | 2º período do curso Sistemas de Informação - IESP 2019.2 |
----   | Desenvolvido por: David Robert e Antônio Marcos.         |
----   | Matéria: Linguagem de Programação 1                      |
----   | Professora: Alana Morais <3                              |
----   |__________________________________________________________|
*/

/*-------------------- incluindo Bibliotecas: --------------------*/

#include <stdio.h> // biblioteca padrão para usar printf, scanf etc...
#include <stdlib.h> // biblioteca padrão
#include <string.h> // biblioteca que permite acesso a manipulação de strings e uso de structs
#include <locale.h> // biblioteca para permitir suporte a língua portuguesa
#include <windows.h> // biblioteca


/* -------------------- Estruturas: -------------------- */

typedef struct{ // Estrutura dos clientes:

    char nome[50]; // nome[limite de caracteres]
    char cpf[11];
    char rua[50];
    char cep[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char numero[50];
    char descricao[500];
    char tipo[50];
    char data[50];
    int  status_chamada;
    char status[50];
    char msg_cliente[300];
    char feedback[300];
} cliente; cliente c[200]; // nome da estrutura cliente atribuida a "c" e limite de clientes atribuido a [].


typedef struct { // Estrutura do gerente:

   char nome[30]; // nome[limite de caracteres]
   char login[30];
   char senha[30];
   char msg_gerente[300];
} gerente; gerente g[2]; // nome da estrutura gerente atribuida a "g" e limite de clientes atribuido a [].



/* -------------------- Variáveis globais e funções definidas: -------------------- */

// variável com valor quantidade de clientes que será mudado pelo cliente em breve
int quantidade = 0;

// definindo funções que foram criadas abaixo do main:
void menu_gerente();
void login_gerente();
void menu_cliente();
void login_cliente();
void cadastro_cliente();

/* ---------------- funções: -------------------- */

int main() // função main | função principal
{
	setlocale(LC_ALL, "Portuguese"); // permitindo caracteres especiais do teclado PT-BR.
    system("cls"); // função do prompt de comando usado para limpar cmd // serve para limpar terminal no linux

	char op; // variável opção.
	printf("------------------ Alana Corporation - Área de Suporte 1.0 ------------------\n");
	printf("\n1 - Área do cliente\n");
	printf("\n2 - Área do Gerente\n");
	printf("\n3 - fechar\n\n: ");
	scanf("%c", &op);

	switch(op){ // examinando variável opção que contém valor inserido pelo usuário. // analisando a opção inserida pelo usuário.
		case '1':
            system("cls"); // função do prompt de comando usado para limpar cmd // limpar prompt
		    menu_cliente(); // < volta para a função
		    break;
		case '2':
		    system("cls"); // função do prompt de comando usado para limpar cmd
		    login_gerente(); // < volta para a função // executando função do gerente
		    break;
		case '3':
		    system("cls"); // função do prompt de comando usado para limpar cmd // serve para limpar terminal no linux
		    printf("\nVocê fechou o sistema.");
		    exit(0);
		    break;
		default:
		    printf("Opção não válida.");
            Sleep(500);
            return main(); // < volta para a função
		    break;
	}
	return 0;
}

void menu_cliente(){

    int op = 0;
    system("cls"); // função do prompt de comando usado para limpar cmd // limpar prompt
    printf("------------------ Alana Corporation - Área do cliente ------------------\n");
    printf("\n1 - Entrar\n");
    printf("\n2 - Cadastrar-se\n");
    printf("\n3 - Voltar\n\n:");
    scanf("%d", &op);

    switch(op){ // examinando variável opção que contém valor inserido pelo usuário.
        case 1:
            login_cliente(); // < volta para a função
            break;
        case 2:
            cadastro_cliente(); // < volta para a função
            break;
        case 3:
            main(); // < volta para a função
            break;
        default:
            return menu_cliente(); // < volta para a função
            break;
    }
}

void login_cliente(){

    int op;
    char cpf[11];

    system("cls"); // função do prompt de comando usado para limpar cmd
    printf("------------------ Alana Corporation - Área do Login ------------------\n");
    printf("\n\t\tDigite seu cpf: ");
    scanf(" %[^\n]s", cpf);// scanf para escanear e atribuir valor inserido pelo usuário para a variável / %[^\n]s serve para limpar buffer do teclado e ler caracteres até o próximo [enter]

    for(int i = 0; i < quantidade; i++){ // criando contador e atribuindo variavel contador para espaço do vetor ex: v[i]
        if(strcmp(cpf,c[i].cpf)==0){ // comparando variavel cpf com vetor struct cpf
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("\n\t\t\tBem vindo %s...\n",c[i].nome);
            printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
            printf("\n1 - Relatar problema");
            printf("\n2 - Alterar chamados");
            printf("\n3 - Verificar status do chamado");
            printf("\n4 - Enviar Feedback");
            printf("\n5 - Sair\n\n: ");
            scanf("%d", &op);
            switch(op){ // examinando variável opção que contém valor inserido pelo usuário.
                case 1:
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
                    printf("\nDigite o tipo de problema:\n");
                    printf("\n[Internet] - Problemas com a Internet, relacionadas à problemas de conexão e acesso, etc.");
                    printf("\n[Redes] - Problemas relacionados à serviços de rede: dispositivos de rede, problemas em serviço de segurança, etc.\n\n");
                    scanf(" %[^\n]s", c[i].tipo);

                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
                    printf("Descrição:");
                    printf("\nNos explique com mais detalhes o que está ocorrendo: ");
                    printf("\n\n");
                    scanf(" %[^\n]s", c[i].descricao);

                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("\nDigite a data atual por favor: ");

                    printf("\n\n");
                    scanf(" %[^\n]s", c[i].data);

                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("\nSeu chamado foi armazenado no nosso banco de dados, por favor aguarde.");
                    printf("\nVoce será retornado ao menu daqui a alguns segundos....");
                    Sleep(500);
                    main(); // < volta para a função
                    break;
                case 2:
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
                    printf("Tipo de chamado: %s | Descrição: %s \n", c[i].tipo, c[i].descricao);
                    printf("Digite o novo tipo de chamado: ");
                    scanf(" %[^\n]s", c[i].tipo);
                    printf("\nDigite a nova descrição: \n");
                    scanf(" %[^\n]s", c[i].descricao);
                    printf("\n\nChamado alterado com sucesso...\n");
                    system("Sleep 03");
                    login_cliente(); // < volta para a função
                    break;
                case 3:
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
                    printf("Status do chamado: %s\nTipo do chamado: %s\nDescrição : %s\nMensagem do gerente de ti:%s",c[i].status, c[i].tipo, c[i].descricao, g[0].msg_gerente);
                    Sleep(500);
                    break;
                case 4:
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área do Cliente ------------------\n");
                    printf("\nEnvie seu Feedback: ");
                    scanf(" %[^\n]s",  c[i].feedback);
                    printf("Obrigado pelo seu Feedback!\n Voltando a página principal...");
                    system("Sleep 03");
                    return login_cliente(); // < volta para a função
                    break;
                case 5:
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("Alana Corporation - %s Saindo da sua conta...", c[i].nome);
                    system("Sleep 04");
                    main(); // < volta para a função
            }
    }
    }
}
void cadastro_cliente(){

    system("cls"); // função do prompt de comando usado para limpar cmd
    char op; // variável opção
    printf("------------------ Alana Corporation - Área do cadastro ------------------\n");
    printf("\nQuantas pessoas quer cadastrar?: ");
    scanf("%i", &quantidade);
    system("cls"); // função do prompt de comando usado para limpar cmd

    for(int i = 0; i < quantidade; i++){ // criando um contador "i" e criando uma condição, se "i" for maior que a variável quantidade, loop mais uma vez.

        printf("------------------ Alana Corporation - Área do cadastro ------------------\n");
        printf("Quantidade de cadastros: %i\n", quantidade);
        // dependendo da quantidade de cadastros fornecida pelo usuário, o loop só fechará o laço for quando o contador for maior que a quantidade.

        printf("\nNome completo:");
        scanf(" %[^\n]s", c[i].nome);

        printf("CPF:");
        scanf(" %[^\n]s", c[i].cpf);

        printf("Rua:");
        scanf(" %[^\n]s", c[i].rua);

        printf("Bairro:");
        scanf(" %[^\n]s", c[i].bairro);

        printf("CEP:");
        scanf(" %[^\n]s", c[i].cep);

        printf("Cidade:");
        scanf(" %[^\n]s", c[i].cidade);

        printf("Estado:");
        scanf(" %[^\n]s", c[i].estado);

        system("cls"); // função do prompt de comando usado para limpar cmd
    }
    printf("\nCadastro concluido com sucesso\n");
    printf("\nDeseja fazer o login? S/N : ");
    scanf("%s", &op);
    switch(op){ // examinando variável opção que contém valor inserido pelo usuário.
        case 's':
        case 'S':
            system("cls"); // função do prompt de comando usado para limpar cmd
            login_cliente(); // < volta para a função
            break;
        case 'n':
        case 'N':
            system("cls"); // função do prompt de comando usado para limpar cmd
            menu_cliente(); // < volta para a função
            break;
        default:
            system("cls"); // função do prompt de comando usado para limpar cmd
            menu_cliente(); // < volta para a função
            break;
    }

}


void login_gerente(){

    setlocale(LC_ALL,"Portuguese");

	strcpy(g[0].nome, "Marcos");
	strcpy(g[1].nome, "David"); // armazenando strings na variavel da struct
	strcpy(g[0].login, "admin"); // esse é o login armazenado na struct
	strcpy(g[0].senha, "admin"); // esse é a senha armazenada na struct

	char login[10], senha[10], nome[10], cpf[11]; // criando variável com [limite de tamanho]

    system("cls"); // função do prompt de comando usado para limpar cmd // limpar prompt

	printf("\n\tLogin: ");
	scanf(" %s", login); // scanf para escanear e atribuir valor inserido pelo usuário para a variável login
	printf("\n\tSenha: ");
	scanf(" %s", senha); // scanf para escanear e atribuir valor inserido pelo usuário para a variável senha

	if ((strcmp(login,g[0].login)==0) || (strcmp(senha,g[0].senha)==0)){ // se as variaveis senha e login forem iguais a g.login e g.senha irá logar.

		system("cls"); // função do prompt de comando usado para limpar cmd

		printf("\n\tGerente: ");
		scanf(" %s", nome);

		if(strcmp(nome,g[0].nome)==0){ // se o nome do gerente coincidir com o nome inserido, logará. caso contrário fechará o sistema por motivos de segurança.
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("\t\tLogin efetuado com sucesso.\tBem vindo %s.\n",g[0].nome);
            menu_gerente(); // < volta para a função
		}
        else if(strcmp(nome,g[1].nome)==0){ // se o nome do gerente coincidir com o nome inserido, logará. caso contrário fechará o sistema por motivos de segurança.
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("\t\t\tLogin efetuado com sucesso.\tBem vindo %s.\n",g[1].nome);
            menu_gerente(); // < volta para a função
        }
        else{ // se o nome inserido pelo usuário não for igual ao nome do gerente do sistema, fechará o sistema por motivos de segurança.
            printf("\t\tNome inválido ou incorreto\n\t\tPor motivos de segurança, o sistema será fechado...\n\n");
            exit(1);
        }
    }
}

void menu_gerente(){

    system("cls"); // função do prompt de comando usado para limpar cmd // limpar prompt
    int op = 0;
    char cpf[50];
    char zero[50];
    char op2;
    strcpy(zero, "0");
    printf("------------------ Alana Corporation - Área de Gerenciamento 1.0 ------------------\n");
    printf("\n1 - Consultar clientes");
    printf("\n2 - Gerenciar chamados");
    printf("\n3 - Feedbacks");
    printf("\n4 - Sair\n\n :");
    scanf("%d", &op);
    switch(op){ // examinando variável opção que contém valor inserido pelo usuário.
        case 1:
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("------------------ Alana Corporation - Área de Gerenciamento 1.0 ------------------\n");
            printf("Clientes cadastrados: %d\n", quantidade);
            for(int b = 0; b < quantidade; b++){
                printf("Cadastro : %d | Nome: %s | CPF: %s\n", b, c[b].nome, c[b].cpf);
            }
            printf("\nDigite o CPF do cliente para ver as informações\nDigite 0 para voltar...\n: ");
            scanf(" %s", cpf);
            if(strcmp(cpf,zero) == 0){
                menu_gerente(); // < volta para a função
            }
            for(int i = 0; i < quantidade; i++){ // criando contador e atribuindo variavel contador para espaço do vetor ex: v[i]
                if(strcmp(cpf,c[i].cpf)==0){ // comparando variavel cpf com vetor struct cpf
                    system("cls"); // função do prompt de comando usado para limpar cmd
                    printf("------------------ Alana Corporation - Área de Gerenciamento 1.0 ------------------\n");
                    printf("\nTodos os dados do cliente abaixo:\n\n");
                    printf("Nome: %s\n", c[i].nome);
                    printf("Cpf: %s\n", c[i].cpf);
                    printf("Telefone/Celular: %s\n", c[i].nome);
                    printf("Estado: %s\n Cidade: %s\n Bairro: %s\n Rua: %s\n CEP: %s\n", c[i].estado, c[i].cidade, c[i].bairro, c[i].rua, c[i].cep);
                    printf("Data do primeiro acesso: %s\n", c[i].data);
                    printf("\nDigite qualquer tecla para voltar...");
                    scanf(" %s", &op2);
                    switch(op2){
                        case '\n':
                            menu_gerente(); // < volta para a função
                            break;
                        default:
                            menu_gerente(); // < volta para a função
                            break;
                    }
                }
            }
            break;
        case 2:
            system("cls"); // função do prompt de comando usado para limpar cmd
            if (quantidade == 0){ // se a quantidade de clientes for igual a 0 significa que ainda não existem registros de chamados.
                system ("cls");
                printf("------------------ Alana Corporation - Área de Gerenciamento 1.0 ------------------\n");
                printf("\nNenhum registro de chamado foi criado.\n");
                printf("\n\npressione [ENTER] para voltar...");
                scanf("%s", &op2); // variável opção
                switch(op2){
                    case '\n':
                        menu_gerente(); // < volta para a função
                        break;
                    default:
                        menu_gerente(); // < volta para a função
                        break;
                }
            }
            else{
                printf("------------------ Alana Corporation - Área de Gerenciamento 1.0 ------------------\n");
                printf("\nTodos os registros de chamados:\n\n");

                for (int e = 0; e < quantidade; e++){
                printf("Cliente: %s | CPF: %s | Status: %s | tipo: %s | Descrição: '%s' |\n",c[e].nome, c[e].cpf, c[e].status, c[e].tipo, c[e].descricao);
                }
                printf("\n\\ndigite o CPF do cliente para acessar o chamado: ");
                scanf(" %[^\n]s", cpf);// scanf para escanear e atribuir valor inserido pelo usuário para a variável cpf
                for(int d = 0; d < quantidade; d++){ // criando contador e atribuindo variavel contador para espaço do vetor ex: v[i]

                    if(strcmp(cpf,c[d].cpf)==0){// comparando vetor local com vetor da estrutura do cliente, se forem iguais estará logado.

                        system("cls"); // função do prompt de comando usado para limpar cmd
                        printf("------------------ Alana Corporation - Área de Gerenciamento ------------------\n");
                        printf("\nCliente: %s", c[d].nome);
                        printf("\n1 - Responder cliente");
                        printf("\n2 - alterar status do chamado");
                        printf("\n3 - Sair\n\n: ");
                        scanf("%i", &op);
                        switch(op){ // examinando variável opção que contém valor inserido pelo usuário.
                            case 1:
                                system("cls"); // função do prompt de comando usado para limpar cmd
                                printf("------------------ Alana Corporation - Área de Gerenciamento ------------------\n");
                                printf("\nEnviar mensagem ao cliente: ");
                                scanf(" %[^\n]s", g[0].msg_gerente);
                                printf("Mensagem enviada...");
                                c[d].status_chamada = 1;
                                Sleep(200);
                                menu_gerente(); // < volta para a função
                                break;
                            case 2:
                                system("cls"); // função do prompt de comando usado para limpar cmd

                                printf("------------------ Alana Corporation - Área de Gerenciamento ------------------\n");
                                printf("\n Chamado do cliente: %s\n", c[d].nome);
                                printf("\n0 - Em aberto");
                                printf("\n1 - Em andamento");
                                printf("\n2 - Em atendimento - visita técnica");
                                printf("\n3 - Não resolvido");
                                printf("\n4 - Finalizado\n\n :");
                                scanf("%i", c[d].status);

                                if (c[d].status_chamada == 0){ // se o vetor status estiver com o valor padrão que é 0, o status do cliente será [Em aberto]
                                    strcpy(c[d].status, "Em aberto");
                                }
                                else if (c[d].status_chamada == 1){ // se o vetor status estiver com o valor 1, o status do cliente será [Em andamento]
                                    strcpy(c[d].status, "Em andamento");
                                }
                                else if (c[d].status_chamada == 2){ // se  status estiver com o valor 2, o status do cliente será [Visita técnica]
                                    strcpy(c[d].status, "Em atendimento - visita técnica");
                                }
                                else if (c[d].status_chamada == 3){
                                    strcpy(c[d].status, "Não resolvido");
                                }
                                else if (c[d].status_chamada == 4){
                                    strcpy(c[d].status, "Resolvido");
                                }
                                else{
                                    printf("\n\nVocê digitou uma opção inexistente...\n");
                                    Sleep(200);
                                    menu_gerente(); // < volta para a função
                                }
                                system("cls"); // função do prompt de comando usado para limpar cmd
                                printf("\n\nChamado alterado com sucesso...");
                                system("Sleep 03");
                                if (c[d].status == 2){ // se o vetor status for igual a 2, o vetor msg_gerente receberá o valor em string abaixo.
                                    strcpy(g[0].msg_gerente, "O técnico irá visitar você em breve...");
                                }
                                else if((c[d].status == 3)){
                                    strcpy(g[0].msg_gerente, "Relatório: O seu chamado não foi resolvido, compareça a uma de nossas centrais.");
                                }
                                menu_gerente(); // < volta para a função
                                break;
                            default:
                                system("cls"); // função do prompt de comando usado para limpar cmd
                                printf("\nErro, digite uma opção válida...");
                                Sleep(200); // serve para dar um delay de milisegundos
                                menu_gerente(); // < volta para a função
                                break;
                        }
                    }
                }
            }
        case 3:
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("------------------ Alana Corporation - Feedbacks ------------------\n");
            printf("\nFeedBacks: \n\n");
            for(int f = 0; f < quantidade; f++){
                printf(" Nome: %s | Texto: s%\n", c[f].nome, c[f].feedback);
            }
            Sleep(600); // serve para dar um delay de milisegundos
            menu_gerente(); // < volta para a função
            break;
        case 4:
            system("cls"); // função do prompt de comando usado para limpar cmd
            printf("\n\t\t\tSaindo...");
            Sleep(500); // serve para dar um delay de milisegundos
            main();
        default:
            printf("\n\nDigite uma opção válida... :");
            Sleep(200); // serve para dar um delay de milisegundos
            menu_gerente(); // < volta para a função

    }
}


