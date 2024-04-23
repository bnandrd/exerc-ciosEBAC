#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela lógica das string

int novonome() //função responsável pelo cadastro de novos nomes no sistema
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunicação com o usuário possa conter acentuações do nosso idioma
	
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf("Para começar, insira o CPF da pessoa a ser cadastrada (apenas números, sem espaços, pontos ou traços: "); //coletando a informação principal sobre o usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo,cpf); //comando responsável por copiar os valores das string. neste caso, o cpf corresponderá ao nome do arquivo txt criado
	
	FILE *file; //iniciando a função sobre arquivos
	file = fopen(arquivo, "w"); //escrevendo no arquivo, ou seja, registrando
	fprintf(file,cpf);//registrando o valor da variável cpf no txt
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo,"a"); //iniciando a atualização do arquivo
	fprintf(file,","); //uma vez coletado o cpf, este trecho adiciona uma vírgula após o dado, para que não fique tudo misturado
	fclose(file); //fechando após a atualização do arquivo
	
	printf("Insira o primeiro nome da pessoa que deseja cadastrar no nosso sistema: "); //coletando a informação do char nome
	scanf("%s", nome); //%s refere-se à string, scanf registrará a resposta digitada no espaço previamente alocado
	
	file = fopen(arquivo, "a"); //mais uma vez, atualizando o arquivo
	fprintf(file,nome); //uma vez coletado o nome, este trecho adiciona o nome ao arquivo txt
	fclose(file); //e depois fecha o arquivo
	
    file = fopen(arquivo,"a"); //mais uma vez, atualizando o arquivo
	fprintf(file,","); //após coletar o nome, este trecho adiciona mais uma vírgula para organizar os dados no txt
	fclose(file); //e depois fecha
	
	printf("Insira o último sobrenome da pessoa a ser cadastrada no sistema: "); //coletando a informação do char sobrenome
	scanf("%s", sobrenome); //%s refere-se à string, scanf registrará a resposta digitada no espaço previamente alocado
	
	file = fopen(arquivo, "a"); //mais uma vez, atualizando o arquivo
	fprintf(file,sobrenome); //uma vez coletado o sobrenome, este trecho adiciona este sobrenome ao arquivo txt
	fclose(file); //e depois fecha o arquivo
	
	file = fopen(arquivo,"a"); //mais uma vez, atualizando o arquivo
	fprintf(file,","); //após coletar o sobrenome, este trecho adiciona mais uma vírgula para organizar os dados no txt
	fclose(file); //e depois fecha
	
	printf("Insira o cargo EBAC da pessoa a ser cadastrada no sistema: "); //coletando a informação do char cargo
	scanf("%s", cargo); //%s refere-se à string, scanf registrará a resposta digitada no espaço previamente alocado
	
	file = fopen(arquivo,"a"); //atualizando o arquivo (pela última vez nessa função!)
	fprintf(file,cargo); //uma vez coletado o cargo que a pessoa ocupa na comunidade EBAC, este trecho adiciona este cargo ao arquivo txt
	fclose(file); //e depois fecha
	
	system("pause"); //para então pausar
	
	}

int consultarnome () //função para consultar nomes já inseridos previamente
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunicação com o usuário possa conter acentuações do nosso idioma
	
	//início da criação das variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação das variáveis/string
	
	printf("Insira o CPF a ser consultado em sistema:  "); //coletando a informação principal (cpf) que norteia a busca no banco de dados
	scanf("%s",cpf); //%s refere-se à string, scanf registrará a resposta digitada no espaço previamente alocado
	
	FILE *file; //iniciando a função sobre arquivos
	file = fopen(cpf,"r"); //abrindo o arquivo para ler nele, ou seja, buscar nele, a variável cpf
	
	if(file == NULL) //ao realizar a consulta, se o resultado não trouxer correspondências:
	{
		printf("Não foi possível localizar este registro! Tente novamente\n\n"); //alerta ao usuário que o cpf consultado não está no banco
	}
		
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver correspondências, ou seja, enquanto a busca achar ocorrências diferentes de nulo:
	{
		printf("\nEsses são os dados até agora registrados em nosso sistema: "); //comunica o usuário o conteúdo do txt outrora criado
		printf("%s",conteudo); //em uma única linha, dados separados por vírgula conforme montamos
		printf("\n\n"); //e pula duas linhas (pra ficar mais amigável esteticamente)
	}
	
	fclose(file); //fechando após a atualização do arquivo
	system("pause");
}

int deletarnome () //função para gerenciamento de banco através da opção de deletar registros anteriores
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunicação com o usuário possa conter acentuações do nosso idioma
	
	char cpf[40]; //criando a variável (neste caso só precisaremos do cpf, que é o dado principal de referência)
	
	printf("Insira o CPF da pessoa que você deseja deletar do nosso cadastro: "); //comunicação para coletar o cpf a deletar
	scanf("%s",cpf); //salvando o cpf inserido pelo usuário, para então:
	
	remove(cpf); //função de deletar o arquivo correspondente, sendo esta já inserida na biblioteca
	
	//etapa de validação:
	FILE *file; //iniciando a função sobre arquivos
	file = fopen(cpf,"r"); //lendo ("reading") o cpf no arquivo txt
	
	if(file == NULL)//caso não encontre uma correspondência,
	{
		printf("Este CPF não está mais cadastrado em nosso sistema!\n\n"); //comunica ao usuário que o cpf não consta!
		system("pause");
	}
	
	fclose(file); //fechando após a atualização do arquivo
}

int main()
{
	int opcao=0; //Definindo, primeiramente, as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo o idioma utilizado para que o printf acerte nos acentos
	
		printf("~~~~~ CARTÓRIO DA EBAC ~~~~~\n\n");
		printf("Selecione a ação desejada no menu:\n\n");
		printf("\t1. Inserir um novo nome\n");
		printf("\t2. Consultar um nome já registrado\n");
		printf("\t3. Deletar um nome já registrado\n\n"); //Fim do menu
		printf("Opção:  \n\n");
		
		scanf("%d", &opcao); //Separando memória para armazenar as escolhas do usuário durante o uso
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao)
		{
			case 1: 
			novonome();
			break;
			
			case 2:
			consultarnome();
			break;
			
			case 3:
			deletarnome();
			break;
			
			default:
			printf("Instrução indisponível\n\n");
			system("pause");
			break;
				}
	
	    }
    
}
