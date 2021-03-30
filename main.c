#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo (Calcular calc);
int soma(int resposta, Calcular calc);
int subtracao(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main()
{
    srand(time(NULL)); //deve ser chamado apenas 1 vez
    jogar();
    return 0;
}

void jogar(){
    Calcular calc;

    printf("----------VAMOS JOGAR-----------\n\n");
    printf("Informe o nivel de dificuldade que voce deseja [1,2,3 ou 4]\n");
    scanf("%d", &calc.dificuldade);

    calc.operacao = rand() % 3; //gera um int randomico entre 0 e 2

    if (calc.dificuldade == 1){
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }
    else if (calc.dificuldade == 2){
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3){
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4){
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    }
    else{
        calc.valor1 = rand() % 1000001;
        calc.valor2 = rand() % 1000001;
    }

    int resposta;
    printf("Informe o resultado para a seguinte operacao:\n");

    if (calc.operacao == 0){
        printf("%d + %d\n", calc.valor1,calc.valor2);
        scanf("%d", &resposta);

        if (soma(resposta,calc)){
            pontos += 1;
            printf("Voce esta com %d ponto(s).\n", pontos);
        }
    }
    else if (calc.operacao == 1){
        printf("%d - %d\n", calc.valor1,calc.valor2);
        scanf("%d", &resposta);

        if (subtracao(resposta,calc)){
            pontos += 1;
            printf("Voce esta com %d ponto(s).\n", pontos);
        }
    }
    else if (calc.operacao == 2){
        printf("%d x %d\n", calc.valor1,calc.valor2);
        scanf("%d", &resposta);

        if (multiplicar(resposta,calc)){
            pontos += 1;
            printf("Voce esta com %d ponto(s).\n", pontos);
        }
    }
    else {
        printf("A operaçao e desconhecida =(", calc.operacao);
    }

    //mostrarInfo(calc);

    printf("Deseja continuar jogando? [1 - Sim ou 0 - Nao]\n");
    int continuar;
    scanf("%d", &continuar);

    if (continuar){
        jogar();
    }else{
        printf("Voce finalizou com %d ponto(s).\n", pontos);
        printf("Ate a proxima!");
        exit (0);
    }
}

void mostrarInfo (Calcular calc){
    char opcao[25];

    if (calc.operacao == 0){ //0 = somar
        sprintf(opcao, "Somar");
    }
    else if (calc.operacao == 1){
        sprintf(opcao, "Subtrair");
    }
    else if (calc.operacao == 2){
        sprintf(opcao, "Multiplicar");
    }
    else{
        sprintf(opcao, "Operacao desconhecida");
    }

    printf ("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperacao: %s\n\n", calc.valor1, calc.valor2, calc.dificuldade, opcao);
}

int soma(int resposta, Calcular calc){
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 = errado

    if (resposta == calc.resultado){
        printf("Resposta correta =D\n");
        certo = 1;
    } else{
        printf("Resposta incorreta D=\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int subtracao(int resposta, Calcular calc){
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 = errado

    if (resposta == calc.resultado){
        printf("Resposta correta =D\n");
        certo = 1;
    } else{
        printf("Resposta incorreta D=\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, Calcular calc){
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 = errado

    if (resposta == calc.resultado){
        printf("Resposta correta =D\n");
        certo = 1;
    } else{
        printf("Resposta incorreta D=\n");
    }
    printf("%d X %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}
