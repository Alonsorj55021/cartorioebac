#include <Stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //boblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Resposável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçao de variávis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o W (whrite) significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("Pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definido linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arqivo não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)  
	{
		printf("\nEssas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser removido: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não localizado!.\n");
		system("pause");
	}

}


int main()
	{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //definido linguagem 
	
		printf("==== Cartório da EBAC ====\n\n"); //início do menu
		printf("Selecione uma opção:\n\n");
		printf("\t1 - Registrar Nomes\n");	
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Digite a opção desejada: ");//final do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls"); //Limpa a tela
	
		switch(opcao)
		{
		
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
							
			default: 
			printf("Essa opção não está disponível!\n");
			system("pause");
			break; 
			//fim da seleção
		}	
	}		
}