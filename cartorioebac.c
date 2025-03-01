#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposavel por cuidas das string


void fecharPrograma() //função para fechar o programa
{
	printf("Encerrano programa.\n");
	exit(0);
}

int registro() //função responsavel por cadastrar usuarios no sistema
{
	//inicio criação de variaveis/ string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int resposta =0;
	//final das variaveis/ string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informações dos usuarios
	scanf("%s", cpf); //%s refere-se a string
	
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores das string
	
	FILE *file; //FILE função existente na biblioteca  //criar o arquivo no banco de dados
	file = fopen(arquivo, "w"); //abrir a variavel arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" atualização
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	system("cls");
	
	printf("\tRealizar novo cadastro?\n");
	printf("Digite 1 para sim, 2 para não: ");
	
	scanf("%d",&resposta); //%d variavel do tipo inteiro
	
	system("cls");
	
	switch (resposta)
	{
		case 1:
		registro(); //chamada de funções
		break;
			
		case 2:
		return 0;
		break;
				
     }
		
	 system("pause");
	
}

int consulta() //função de consulta dos arquivos
{
	setlocale(LC_ALL, "Portuguese"); //idioma do programa
	char cpf[40];
	char conteudo[200];
	int resposta =0;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" ler
	
	if(file == NULL) // NULL nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado. \n");
		
	}
	while(fgets(conteudo, 200, file) != NULL) //while enquanto
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
	system("cls");
	
	printf("Realizar nova colsulta?\n");
	printf("Digite 1 para sim, 2 para não: \n");
	
	scanf("%d", &resposta);
	
	system("cls");
	
	switch (resposta)
	{
		case 1:
		consulta();
		break;
		
		case 2:
		return 0;
		break;
	}
	
	system("pause");
		
}


int deletar() //função de deletar os arquivos
{
	char cpf[40];
	int resposta =0;
	
	while (1) 
	{ // Loop principal //Use o while quando você não sabe quantas vezes o loop precisa ser executado
        printf("Digite o CPF a ser deletado: ");
        scanf("%s", cpf);
        
        // Tenta abrir o arquivo para verificar se ele existe
        FILE *file = fopen(cpf, "r");
        if (file == NULL) 
		{
            printf("Usuário não se encontra no sistema! \n");
            
        }
		 else 
		 {
            fclose(file); // Fecha o arquivo antes de deletar
            if (remove(cpf) == 0) { // Tenta deletar o arquivo
                printf("Usuário deletado com sucesso.\n");
            } 
			else 
			{
                printf("Erro ao deletar o usuário.\n");
            }
        }
		system("pause");
		system("cls");
		// Pergunta se o usuário deseja deletar outro arquivo
        printf("Deseja deletar mais algum usuário?\n");
        printf("Tecle 1 para SIM ou 2 para NÃO: ");
        scanf("%d", &resposta);
        system("cls");

        if (resposta != 1) 
		{
            break; // Sai do loop se a resposta não for 1
        }
    }

    return 0; // Retorna 0 ao finalizar
	
	
}  
int main()
{
	int opcao=0; //1= atribuição
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //idioma do programa
	
	
	
		printf("\t\tCartório da EBAC\n\n"); //inicio do menu
	
		printf("\tEscolha a opção desejada do menu:\n\n"); //inicio do menu
	
		printf("\t1- Registrar nomes:\n"); //menu de opções
		printf("\t2- Consultar nomes:\n");
		printf("\t3- Deletar nomes:\n");
		printf("\t4 Fechar programa:\n");
		printf("\t\tOpção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a resposta do usuario  //escanear o que o usuario coloca   //%d variavel do tipo inteiro
	
		system("cls"); //função de limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			fecharPrograma();
			return(0);
			break;
			
			
			default:
			printf("Está opção não esta disponivel!\n");    //fim da seleção
			system("pause");
			break;
				
				
			
			
		}
	
	
	
	
	}
	}
