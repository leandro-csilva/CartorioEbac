#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Definindo fun��o de cadastro
{
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s armazena a string
	
	strcpy(arquivo,cpf); //Respos�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo; "w" significa write ou escrever
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" � usado para adicionar ao arquivo
	fprintf(file, ","); //adiciona a virgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" � usado para ler o conte�do do arquivo
	
	if(file == NULL) //se o arquivo estiver vazio
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver conte�do no arquivo, o programa ir� ler
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //retorna o conte�do presente no arquivo
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //remove o arquivo selecionado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo n�o estiver presente
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
} //Definido fun��es

int main()
{
	int opcao=0; 
	int laco=1; //Definindo vari�veis
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1: // In�cio da sele��o
				registro(); //chamada de fun��es
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Op��o n�o dispon�vel!\n");
				system("pause");
				break; //Fim da sele��o
		}
	}
}
