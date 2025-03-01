#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca resposavel por cuidas das string


void fecharPrograma() //fun��o para fechar o programa
{
	printf("Encerrano programa.\n");
	exit(0);
}

int registro() //fun��o responsavel por cadastrar usuarios no sistema
{
	//inicio cria��o de variaveis/ string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int resposta =0;
	//final das variaveis/ string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��es dos usuarios
	scanf("%s", cpf); //%s refere-se a string
	
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores das string
	
	FILE *file; //FILE fun��o existente na biblioteca  //criar o arquivo no banco de dados
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
	
	file = fopen(arquivo, "a"); //"a" atualiza��o
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	system("cls");
	
	printf("\tRealizar novo cadastro?\n");
	printf("Digite 1 para sim, 2 para n�o: ");
	
	scanf("%d",&resposta); //%d variavel do tipo inteiro
	
	system("cls");
	
	switch (resposta)
	{
		case 1:
		registro(); //chamada de fun��es
		break;
			
		case 2:
		return 0;
		break;
				
     }
		
	 system("pause");
	
}

int consulta() //fun��o de consulta dos arquivos
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado. \n");
		
	}
	while(fgets(conteudo, 200, file) != NULL) //while enquanto
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
	system("cls");
	
	printf("Realizar nova colsulta?\n");
	printf("Digite 1 para sim, 2 para n�o: \n");
	
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


int deletar() //fun��o de deletar os arquivos
{
	char cpf[40];
	int resposta =0;
	
	while (1) 
	{ // Loop principal //Use o while quando voc� n�o sabe quantas vezes o loop precisa ser executado
        printf("Digite o CPF a ser deletado: ");
        scanf("%s", cpf);
        
        // Tenta abrir o arquivo para verificar se ele existe
        FILE *file = fopen(cpf, "r");
        if (file == NULL) 
		{
            printf("Usu�rio n�o se encontra no sistema! \n");
            
        }
		 else 
		 {
            fclose(file); // Fecha o arquivo antes de deletar
            if (remove(cpf) == 0) { // Tenta deletar o arquivo
                printf("Usu�rio deletado com sucesso.\n");
            } 
			else 
			{
                printf("Erro ao deletar o usu�rio.\n");
            }
        }
		system("pause");
		system("cls");
		// Pergunta se o usu�rio deseja deletar outro arquivo
        printf("Deseja deletar mais algum usu�rio?\n");
        printf("Tecle 1 para SIM ou 2 para N�O: ");
        scanf("%d", &resposta);
        system("cls");

        if (resposta != 1) 
		{
            break; // Sai do loop se a resposta n�o for 1
        }
    }

    return 0; // Retorna 0 ao finalizar
	
	
}  
int main()
{
	int opcao=0; //1= atribui��o
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //idioma do programa
	
	
	
		printf("\t\tCart�rio da EBAC\n\n"); //inicio do menu
	
		printf("\tEscolha a op��o desejada do menu:\n\n"); //inicio do menu
	
		printf("\t1- Registrar nomes:\n"); //menu de op��es
		printf("\t2- Consultar nomes:\n");
		printf("\t3- Deletar nomes:\n");
		printf("\t4 Fechar programa:\n");
		printf("\t\tOp��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a resposta do usuario  //escanear o que o usuario coloca   //%d variavel do tipo inteiro
	
		system("cls"); //fun��o de limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
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
			printf("Est� op��o n�o esta disponivel!\n");    //fim da sele��o
			system("pause");
			break;
				
				
			
			
		}
	
	
	
	
	}
	}
