#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100



typedef struct{
	int matricula;
	char nome[100];
	int idade;
}t_lista;

typedef int boolean;
#define true 1
#define false 0

// Pŕototipo de funções

// retirada para ordenação pela matricula
int leituraArquivo(t_lista alunos[], int qtnd_alunos);
// quicksort
void quickSort(t_lista alunos[], int inicio, int fim);
// imprimir os elementos
void imprimirAlunos(t_lista alunos[], int qtnd_alunos);



int qtnd_alunos(){

	FILE *arq;
	char string_temp[100] = " ";
	char *abrir_arquivo;
	int qtd_alunos = 0;

	arq = fopen("alunos.txt", "r");
	if(arq != NULL){
			while(true){
					abrir_arquivo = fgets(string_temp, 100, arq);
					if(abrir_arquivo != NULL)
						qtd_alunos++;
			else
				break;

		}
		fclose(arq);
 }
	return qtd_alunos;



}

boolean leituraArquivo(t_lista alunos[], int qtnd_alunos){
	FILE *arq;
	char string_temp[100] = " ";
	arq = fopen("alunos.txt", "r");
	if(arq != NULL){
			for (int i = 0; i < qtnd_alunos; i++){
				fgets(string_temp, MAX, arq);
				alunos[i].matricula =  atoi(strtok(string_temp, ","));
				strcpy(alunos[i].nome, strtok(NULL, ","));
				alunos[i].idade = atoi(strtok(NULL, ","));

				}
		}
		else {
			return true;
		}

		return false;

}

void quickSort(t_lista alunos[], int inicio, int fim){
	int i = inicio;
	int j = fim;
	t_lista pivo = alunos[(i + j) / 2];
	t_lista aluno_aux;

	while(i < j){

		while(alunos[i].matricula < pivo.matricula) i++;
		while(alunos[j].matricula > pivo.matricula) j--;

		if(i <= j){
			aluno_aux = alunos[i];
			alunos[i] = alunos[j];
			alunos[j] = aluno_aux;
			i++;
			j--;
		}

	}

	if(inicio < j) quickSort(alunos, inicio, j);
	if (i < fim) quickSort(alunos, i, fim);

}

void imprimirAlunos(t_lista alunos[], int qtnd){
		for (int i = 0; i < qtnd; i++){
		printf("************--Aluno %d--********************* \n", i+1);
		printf("Matricula: %d\n", alunos[i].matricula);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Idade: %d\n", alunos[i].idade);

		}

	 }


int main(void){
		int qtnd = qtnd_alunos();


		if(qtnd > 0){
			t_lista alunos[qtnd];
			if (leituraArquivo(alunos, qtnd) == false) {
				quickSort(alunos, 0, qtnd-1);
				imprimirAlunos(alunos, qtnd);
			}
			else{
				printf("arquivo com erro");
			}
			return 0;

		}


}
