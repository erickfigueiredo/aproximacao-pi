//Matricula: 98898 | Aluno: Erick Lima Figueiredo.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Prototipa��o dos procedimentos

void leibniz(long long int num);
void wallis(long long int num);
void euler(long long int num);
void viete(long long int num);
void brouncker(long long int num);

//M�todo Principal

int main(){
	int escolha = -1;
	do{
		cout <<"CALCULO APROXIMADO DO VALOR DE PI\n\n\n";
		cout << "1-Leibniz\n2-Wallis\n3-Euler\n4-Viete\n5-Brouncker\n6-Executar todos\n0-Sair\n\nOpcao: ";
		cin >> escolha;
		
		//Verifica se o usu�rio digitou 0, caso verdadeiro o loop finaliza
		
		if(escolha == 0)
			break;
		
		//Verifica se a escolha � uma op��o v�lida
		
		else if((escolha >=1) &&(escolha <=6))
			cout << "Informe o numero de elementos da sequencia (quanto maior, maior a precisao): ";
		else
			cout << "\n\n\nOpcao indisponivel!!!\n\n\n";
		switch(escolha){
			long long int num;
			
			case 1:
				cin >> num;
				leibniz(num);
				break;
			case 2:
				cin >> num;
				wallis(num);
				break;
			case 3:
				cin >> num;
				euler(num);
				break;
			case 4:
				cin >> num;
				viete(num);
				break;
			case 5: 
				cin >> num;
				brouncker(num);
				break;
			case 6: 
				cin >> num;
				cout<<"Isso pode demorar um pouco...\n";
				leibniz(num);
				wallis(num);
				euler(num);
				viete(num);
				brouncker(num);
				break;
			
		}
		cout<<"\n\n\n"<<endl;
		
	// Sempre executa at� que haja um break
	
	}while(true);
	return 0;
}

void leibniz(long long int num){
	
	//Iniciamos o valor do denominador
	
	long long int cont = 1;
	
	//Iniciamos o resultado com o elemento neutro da adi��o/subtra��o
	
	long double result = 0;
	
	//la�o para realizar a sequ�ncia a� o n�mero escolhido pelo usu�rio
	
	for(int i = 0; i < num; i++){
		if(i%2 == 0){
			
			//caso o n�mero ocupe uma posi��o par ele � positivo
			
			result += (1.0/cont);
		}else{
			
			//caso contr�rio � negativo
			
			result += -(1.0/cont);
		}
		
		//A cada execu��o o denominador recebe +2 em seu valor
		
		cont += 2;
	}
	
	/*Utilizamos o precision com 30 casas decimais depois da v�rgula e multipli
	camos o resultado da opera��o por 4, pois a formula d� o resultado da quarta 
	parte de pi*/
	
	cout <<"Na sequencia de "<< num <<" numeros pelo metodo de Leibniz, temos pi como: "<<fixed<<setprecision(30)<< result*4 << endl;
}

void wallis(long long int num){
	
	/*Iniciamos o numerador com 0 pois desse modo ao receber +2 em seu valor conti
	nuar� par, j� o denominador foi iniciado com 1, pois sempre ser� impar e, 
	assim como o n�merador, tem diferenca de 2 com o pr�ximo denominador. J� o 
	resultado recebe 1, por ser o elemento neutro da multiplica��o e n�o afetar 
	na acumula��o*/
	
	long double numerador = 0.0, denominador = 1.0, result = 1;
	
	//la�o para realizar a sequ�ncia a� o n�mero escolhido pelo usu�rio
	
	for(int i = 0; i < num; i++){
		if(i%2 == 0){
			
			//caso o n�mero ocupe uma posi��o par o numerador recebe +2 em seu valor
			
			numerador += 2;
			result *= (numerador/denominador);
		}else{
			
			//caso contr�rio o denominador recebe +2 em seu valor
			
			denominador += 2;
			result *= (numerador/denominador);
		}
	}
	
	/*Utilizamos o precision com 30 casas decimais depois da v�rgula e multipli
	camos o resultado da opera��o por 2, pois a formula d� o resultado da metade
 	de pi*/
 	
	cout <<"Na sequencia de "<< num <<" numeros pelo metodo de Wallis, temos pi como: "<<fixed<<setprecision(30)<< result*2 << endl;
}

void euler(long long int num){
	long long int agregador  = 0;
	
	/*Denominador inicial recebe 1 e o valor do primeiro resultados dos elementos
	da sequ�ncia tamb�m*/
	
	long double denominador = 1.0, result = 1.0;
	
	//la�o para realizar a sequ�ncia a� o n�mero escolhido pelo usu�rio
	
	for(int i = 0; i < num; i++){
		if(i == 0){
			
			//Agregador ao denominador recebe 3 na primeira execu��o do la�o
			
			agregador += 3;
		}else{
			
			//Adiciona o agregador ao denominador
			
			denominador += agregador;
			
			//Realiza a divis�o e adiciona seu resultado � soma j� obtida at� ent�o
			
			result += (1/denominador);
			
			/*A partir da segunda execu��o do la�o o agregador vai recebendo mais
			dois em seu valor que na pr�xima execu��o vai ser agregada ao denominador*/
			
			agregador += 2;
		}
	}
	cout <<"Na sequencia de "<< num <<" numeros pelo metodo de Euler, temos pi como: "<<fixed<<setprecision(30)<< sqrt(result*6) << endl;
}

void viete(long long int num){
	
	/*vamos considerar o n�merador e o denominador invertidos. o denominador recebe
	0 e o resutado recebe o elemento neutro da multiplica��o*/
	
	long double denominador = 0.0, result = 1;
	
	//la�o para realizar a sequ�ncia a� o n�mero escolhido pelo usu�rio
	
	for(int i = 0; i < num; i++){
		if(i == 0){
			
			/*Denominador recebe raiz de dois e � feita a divis�o por dois e a
			multiplica��o pelo resultado acumulado j� na primeira execu��o do 
			la�o de repeti��o*/
			
			denominador = sqrt(2);
			result *= 2/denominador;
		}else{
			
			/*Denominador a partir do segundo la�o recebe a raiz de 2 mais ele mesmo*/
			
			denominador = sqrt(2+denominador);
			result *= 2/denominador;
		}
	}
	
	/*Como invertemos a equa��o, basta multiplicar o resultado por 2, para obter 
	uma aproxima��o de pi*/
	
	cout <<"Na sequencia de "<< num <<" numeros pelo metodo de Viete, temos pi como: "<< fixed << setprecision(30) << result*2 << endl;
}

void brouncker(long long int num){ 
	
	//Iniciamos o denominador com 0 e o resultado recebe o elemento neutro da adi��o
	
	long double den = 1, result = 0;
	for(int i = 0; i < num; i++){
		
		//Para fazer a opera��o precisamos do �ltimo de todos os denominadores
		
		den += 2;
	}
	for(int i = 0; i < num; i++){
		
		//Percebe-se que, a base de cada numerador � -2 a base do n�merador
		
		if(i == 0){
			
			/*No ultimo valor do denominador da sequ�ncia come�amos a opera��o,
			lembrando da rela��o numerador - denominador descrita anteriormente*/
			
			result = ((den-2)*(den-2))/(2+(den*den));
			
			//Feita a opera��o decrementamos 2 do valor ultimo do denominador
			
			den -= 2;
		}else{
			
			/*A partir daqui, a cada passo, pegamos o resultado anterior e com a
			rela��o numerador - denominador, obtemos um novo resultado */
			
			result = ((den-2)*(den-2))/(2+result);
			
			//Decrementamos 2 do valor do ultimo denominador
			den -= 2;
		}
	}
	
	//Feita a parte sequencial, somamos 1 ao resultado, dividimos o mesmo por 4
	
	result = (result+1)/4;
	
	/*Exibimos como 1/result, pois na formula o a rela��o deixa de ser 1/pi = result
	para ser pi = 1/result*/
	
	cout <<"Na sequencia de "<< num <<" numeros pelo metodo de Brouncker, temos pi como: "<< fixed << setprecision(30) << (1/result) << endl;
}