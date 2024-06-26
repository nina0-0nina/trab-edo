#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Essa é uma função para calcular a EDO
double minha_edo(double y, double t){
	double resultado = 0.2 * y * (1 - y/500);
	return resultado;
}

int main() {
	int iteracoes; //Essa é uma variável para definir a quantidade de iterações que o usuário deseja fazer
	double passo = 0.2; //Essa é uma variável para receber o valor do passo dado na questão
	int anterior; //Essa é uma variável para usar o valor anterior de y e t no método
	
	printf("Quantas iteracoes deseja fazer? "); //Aqui o programa pergunta a quantidade de iterações ao usuário
	scanf("%i", &iteracoes); //Espera o usuário digitar a quantidade de iterações
	printf("\n\n");
	
	double t[iteracoes + 1]; //Essa é uma variável para receber o valor de t das novas iterações utilizando o método
	double y[iteracoes + 1]; //Essa é uma variável para receber o valor de y das novas iterações utilizando o método
	
	t[0] = 0;  //Aqui atribui-se o PVI dado na questão, sendo o t0 igual a 0
	y[0] = 10; //Aqui atribui-se o PVI dado na questão, sendo o y(t0) igual a 10
	
	//Laço de repetição para calcular as iterações utilizando o método de Euler
	for(int rep = 1; rep <= iteracoes+1; rep++){
		anterior = rep-1; //Atribuição do yn a variável anterior
		t[rep] = t[anterior] + passo; //Atribuição ao tn+1 = tn + valor do passo
		y[rep] = y[anterior] + (passo * minha_edo(y[anterior], t[anterior])); //Atribuição ao yn+1 = yn + valor do passo*EDO nos pontos anteriores. Aqui chamamos a função da EDO passando como parâmetros os valores de yn e tn
	}
	
	//Laço de repetição para imprimir os resultados das iterações
	for(int rep = 0; rep < iteracoes+1; rep++){
		printf("===== Iterecao %d =====\n\n", rep);
		printf("t%d = %lf\n", rep, t[rep]); //Imprimir os valores de t
		printf("y(t%d) = %lf\n\n", rep, y[rep]); //Imprimir os valores de y
	}
}
