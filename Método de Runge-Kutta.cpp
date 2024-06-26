#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Essa � uma fun��o para calcular a EDO
double minha_edo(double y, double t){
	double resultado = 0.2 * y * (1 - y / 500);
	return resultado;
}

//Essa � uma fun��o para calcular o k1 do m�todo de Runge-Kutta de 4 ordem
double k1_runge_kutta(double h, double t, double y){
	double resultado = h * minha_edo(y, t);
	return resultado;
}

//Essa � uma fun��o para calcular o k2 e o k3 do m�todo de Runge-Kutta de 4 ordem
double k_runge_kutta(double h, double t, double y, double k){
	double resultado = h * minha_edo((y + k / 2), (t + h / 2));
	return resultado;
}

//Essa � uma fun��o para calcular o k4 do m�todo de Runge-Kutta de 4 ordem
double k4_runge_kutta(double h, double t, double y, double k){
	double resultado = h * minha_edo((y + k), (t + h));
	return resultado;
}

//Essa � uma fun��o para calcular o yn+1 do m�todo de Runge-Kutta de 4 ordem
double runge_kutta(double k1, double k2, double k3, double k4, double y){
	double resultado = y + ((k1 + 2 * k2 + 2 * k3 + k4) / 6);
	return resultado;
}

int main() {
	int iteracoes; //Essa � uma vari�vel para definir a quantidade de itera��es que o usu�rio deseja fazer
	float passo = 0.2; //Essa � uma vari�vel para receber o valor do passo dado na quest�o
	int anterior; //Essa � uma vari�vel para usar o valor anterior de y e t no m�todo
	
	printf("Quantas iteracoes deseja fazer? "); //Aqui o programa pergunta a quantidade de itera��es ao usu�rio
	scanf("%i", &iteracoes); //Espera o usu�rio digitar a quantidade de itera��es
	printf("\n\n");
	
	double t[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de t das novas itera��es utilizando o m�todo
	double y[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de y das novas itera��es utilizando o m�todo
	double k1[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de k1 das novas itera��es utilizando o m�todo
	double k2[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de k2 das novas itera��es utilizando o m�todo
	double k3[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de k3 das novas itera��es utilizando o m�todo
	double k4[iteracoes + 1]; //Essa � uma vari�vel para receber o valor de k4 das novas itera��es utilizando o m�todo
	
	t[0] = 0;  //Aqui atribui-se o PVI dado na quest�o, sendo o t0 igual a 0
	y[0] = 10; //Aqui atribui-se o PVI dado na quest�o, sendo o y(t0) igual a 10
	k1[0] = 0; //Aqui atribui-se o valor 0 para o vetor k1 na posi��o 0 para n�o ficar com lixo
	k2[0] = 0; //Aqui atribui-se o valor 0 para o vetor k2 na posi��o 0 para n�o ficar com lixo
	k3[0] = 0; //Aqui atribui-se o valor 0 para o vetor k3 na posi��o 0 para n�o ficar com lixo
	k4[0] = 0; //Aqui atribui-se o valor 0 para o vetor k4 na posi��o 0 para n�o ficar com lixo
	
	//La�o de repeti��o para calcular as itera��es utilizando o m�todo de Runge-Kutta de 4 ordem
	for(int rep = 1; rep < iteracoes + 1; rep++){
		anterior = rep - 1; //Atribui��o da vari�vel anterior utilizando os vetores
		t[rep] = t[anterior] + passo; //Atribui��o ao tn+1 = tn + valor do passo
		k1[rep] = k1_runge_kutta(passo, t[anterior], y[anterior]); //Calculo do k1 utilizando a fun��o criada
		k2[rep] = k_runge_kutta(passo, t[anterior], y[anterior], k1[rep]); //Calculo do k2 utilizando a fun��o criada
		k3[rep] = k_runge_kutta(passo, t[anterior], y[anterior], k2[rep]); //Calculo do k3 utilizando a fun��o criada
		k4[rep] = k4_runge_kutta(passo, t[anterior], y[anterior], k3[rep]); //Calculo do k4 utilizando a fun��o criada
		y[rep] = runge_kutta(k1[rep], k2[rep], k3[rep], k4[rep], y[anterior]); //Calculo do yn+1 utilizando a fun��o criada
	}
	
	//La�o de repeti��o para imprimir os resultados das itera��es
	for(int rep = 1; rep < iteracoes + 1; rep++){
	    printf("===== Iterecao %d =====\n\n", rep);
		printf("t%d = %lf\n", rep, t[rep]); //Imprimir os valores de t
		printf("k1 = %lf\n", k1[rep]); //Imprimir os valores de k1
		printf("k2 = %lf\n", k2[rep]); //Imprimir os valores de k2
		printf("k3 = %lf\n", k3[rep]); //Imprimir os valores de k3
		printf("k4 = %lf\n", k4[rep]); //Imprimir os valores de k4
		printf("y(t%d) = %lf\n\n", rep, y[rep]); //Imprimir os valores de y
	}
}
