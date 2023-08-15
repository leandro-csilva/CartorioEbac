#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Definindo função de cadastro
{
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informações do usuário
	scanf("%s", cpf); //%s armazena a string
	
	strcpy(arquivo,cpf); //Resposável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo; "w" significa write ou escrever
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" é usado para adicionar ao arquivo
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
	file = fopen(cpf,"r"); //"r" é usado para ler o conteúdo do arquivo
	
	if(file == NULL) //se o arquivo estiver vazio
	{
		printf("Arquivo não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver conteúdo no arquivo, o programa irá ler
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //retorna o conteúdo presente no arquivo
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //remove o arquivo selecionado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo não estiver presente
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
} //Definido funções

int main()
{
	int opcao=0; 
	int laco=1; //Definindo variáveis
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1: // Início da seleção
				registro(); //chamada de funções
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Opção não disponível!\n");
				system("pause");
				break; //Fim da seleção
		}
	}
}
