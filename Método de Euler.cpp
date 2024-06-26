#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Essa � uma fun��o para calcular a EDO
double minha_edo(double y, double t){
	double resultado = 0.2 * y * (1 - y/500);
	return resultado;
}

int main() {
	int iteracoes; //Essa � uma vari�vel para definir a quantidade de itera��es que o usu�rio deseja fazer
	double passo = 0.2; //Essa � uma vari�vel para receber o valor do passo dado na quest�o
	int anterior; //Essa � uma vari�vel para usar o valor anterior de y e t no m�todo
	
	printf("Quantas iteracoes deseja fazer? "); //Aqui o programa pergunta a quantidade de itera��es ao usu�rio
	scanf("%i", &iteracoes); //Espera o usu�rio digitar a quantidade de itera��es
	printf("\n\n");
	
	double t[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de t das novas itera��es utilizando o m�todo
	double y[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de y das novas itera��es utilizando o m�todo
	
	t[0] = 0;  //Aqui atribui-se o PVI dado na quest�o, sendo o t0 igual a 0
	y[0] = 10; //Aqui atribui-se o PVI dado na quest�o, sendo o y(t0) igual a 10
	
	//La�o de repeti��o para calcular as itera��es utilizando o m�todo de Euler
	for(int rep = 1; rep <= iteracoes+1; rep++){
		anterior = rep-1; //Atribui��o do yn a vari�vel anterior
		t[rep] = t[anterior] + passo; //Atribui��o ao tn+1 = tn + valor do passo
		y[rep] = y[anterior] + (passo * minha_edo(y[anterior], t[anterior])); //Atribui��o ao yn+1 = yn + valor do passo*EDO nos pontos anteriores. Aqui chamamos a fun��o da EDO passando como par�metros os valores de yn e tn
	}
	
	//La�o de repeti��o para imprimir os resultados das itera��es
	for(int rep = 0; rep < iteracoes+1; rep++){
		printf("===== Iterecao %d =====\n\n", rep);
		printf("t%d = %lf\n", rep, t[rep]); //Imprimir os valores de t
		printf("y(t%d) = %lf\n\n", rep, y[rep]); //Imprimir os valores de y
	}
}
