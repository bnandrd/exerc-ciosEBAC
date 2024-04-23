#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pela l�gica das string

int novonome() //fun��o respons�vel pelo cadastro de novos nomes no sistema
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunica��o com o usu�rio possa conter acentua��es do nosso idioma
	
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Para come�ar, insira o CPF da pessoa a ser cadastrada (apenas n�meros, sem espa�os, pontos ou tra�os: "); //coletando a informa��o principal sobre o usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo,cpf); //comando respons�vel por copiar os valores das string. neste caso, o cpf corresponder� ao nome do arquivo txt criado
	
	FILE *file; //iniciando a fun��o sobre arquivos
	file = fopen(arquivo, "w"); //escrevendo no arquivo, ou seja, registrando
	fprintf(file,cpf);//registrando o valor da vari�vel cpf no txt
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo,"a"); //iniciando a atualiza��o do arquivo
	fprintf(file,","); //uma vez coletado o cpf, este trecho adiciona uma v�rgula ap�s o dado, para que n�o fique tudo misturado
	fclose(file); //fechando ap�s a atualiza��o do arquivo
	
	printf("Insira o primeiro nome da pessoa que deseja cadastrar no nosso sistema: "); //coletando a informa��o do char nome
	scanf("%s", nome); //%s refere-se � string, scanf registrar� a resposta digitada no espa�o previamente alocado
	
	file = fopen(arquivo, "a"); //mais uma vez, atualizando o arquivo
	fprintf(file,nome); //uma vez coletado o nome, este trecho adiciona o nome ao arquivo txt
	fclose(file); //e depois fecha o arquivo
	
    file = fopen(arquivo,"a"); //mais uma vez, atualizando o arquivo
	fprintf(file,","); //ap�s coletar o nome, este trecho adiciona mais uma v�rgula para organizar os dados no txt
	fclose(file); //e depois fecha
	
	printf("Insira o �ltimo sobrenome da pessoa a ser cadastrada no sistema: "); //coletando a informa��o do char sobrenome
	scanf("%s", sobrenome); //%s refere-se � string, scanf registrar� a resposta digitada no espa�o previamente alocado
	
	file = fopen(arquivo, "a"); //mais uma vez, atualizando o arquivo
	fprintf(file,sobrenome); //uma vez coletado o sobrenome, este trecho adiciona este sobrenome ao arquivo txt
	fclose(file); //e depois fecha o arquivo
	
	file = fopen(arquivo,"a"); //mais uma vez, atualizando o arquivo
	fprintf(file,","); //ap�s coletar o sobrenome, este trecho adiciona mais uma v�rgula para organizar os dados no txt
	fclose(file); //e depois fecha
	
	printf("Insira o cargo EBAC da pessoa a ser cadastrada no sistema: "); //coletando a informa��o do char cargo
	scanf("%s", cargo); //%s refere-se � string, scanf registrar� a resposta digitada no espa�o previamente alocado
	
	file = fopen(arquivo,"a"); //atualizando o arquivo (pela �ltima vez nessa fun��o!)
	fprintf(file,cargo); //uma vez coletado o cargo que a pessoa ocupa na comunidade EBAC, este trecho adiciona este cargo ao arquivo txt
	fclose(file); //e depois fecha
	
	system("pause"); //para ent�o pausar
	
	}

int consultarnome () //fun��o para consultar nomes j� inseridos previamente
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunica��o com o usu�rio possa conter acentua��es do nosso idioma
	
	//in�cio da cria��o das vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das vari�veis/string
	
	printf("Insira o CPF a ser consultado em sistema:  "); //coletando a informa��o principal (cpf) que norteia a busca no banco de dados
	scanf("%s",cpf); //%s refere-se � string, scanf registrar� a resposta digitada no espa�o previamente alocado
	
	FILE *file; //iniciando a fun��o sobre arquivos
	file = fopen(cpf,"r"); //abrindo o arquivo para ler nele, ou seja, buscar nele, a vari�vel cpf
	
	if(file == NULL) //ao realizar a consulta, se o resultado n�o trouxer correspond�ncias:
	{
		printf("N�o foi poss�vel localizar este registro! Tente novamente\n\n"); //alerta ao usu�rio que o cpf consultado n�o est� no banco
	}
		
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver correspond�ncias, ou seja, enquanto a busca achar ocorr�ncias diferentes de nulo:
	{
		printf("\nEsses s�o os dados at� agora registrados em nosso sistema: "); //comunica o usu�rio o conte�do do txt outrora criado
		printf("%s",conteudo); //em uma �nica linha, dados separados por v�rgula conforme montamos
		printf("\n\n"); //e pula duas linhas (pra ficar mais amig�vel esteticamente)
	}
	
	fclose(file); //fechando ap�s a atualiza��o do arquivo
	system("pause");
}

int deletarnome () //fun��o para gerenciamento de banco atrav�s da op��o de deletar registros anteriores
{
	setlocale(LC_ALL, "Portuguese"); //para que minha comunica��o com o usu�rio possa conter acentua��es do nosso idioma
	
	char cpf[40]; //criando a vari�vel (neste caso s� precisaremos do cpf, que � o dado principal de refer�ncia)
	
	printf("Insira o CPF da pessoa que voc� deseja deletar do nosso cadastro: "); //comunica��o para coletar o cpf a deletar
	scanf("%s",cpf); //salvando o cpf inserido pelo usu�rio, para ent�o:
	
	remove(cpf); //fun��o de deletar o arquivo correspondente, sendo esta j� inserida na biblioteca
	
	//etapa de valida��o:
	FILE *file; //iniciando a fun��o sobre arquivos
	file = fopen(cpf,"r"); //lendo ("reading") o cpf no arquivo txt
	
	if(file == NULL)//caso n�o encontre uma correspond�ncia,
	{
		printf("Este CPF n�o est� mais cadastrado em nosso sistema!\n\n"); //comunica ao usu�rio que o cpf n�o consta!
		system("pause");
	}
	
	fclose(file); //fechando ap�s a atualiza��o do arquivo
}

int main()
{
	int opcao=0; //Definindo, primeiramente, as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo o idioma utilizado para que o printf acerte nos acentos
	
		printf("~~~~~ CART�RIO DA EBAC ~~~~~\n\n");
		printf("Selecione a a��o desejada no menu:\n\n");
		printf("\t1. Inserir um novo nome\n");
		printf("\t2. Consultar um nome j� registrado\n");
		printf("\t3. Deletar um nome j� registrado\n\n"); //Fim do menu
		printf("Op��o:  \n\n");
		
		scanf("%d", &opcao); //Separando mem�ria para armazenar as escolhas do usu�rio durante o uso
	
		system("cls"); //respons�vel por limpar a tela
	
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
			printf("Instru��o indispon�vel\n\n");
			system("pause");
			break;
				}
	
	    }
    
}
