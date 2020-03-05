/**
 * Altere e complete o programa de maneira que ele seja capaz de
 * calcular a serie de Fibonacci ate 10^19 ou 10000000000000000000.
 */

#include <iostream>
#include <vector>

using namespace::std;


//-------------------------------------------------------------------------------
//! Imprime um vetor de inteiros longos sem sinal.
/*! Esta funcao imprime na saida padrao um vetor de inteiros.
 *  @param _A O vetor a ser impresso na saida padrao.
 */
void printArray( vector<int> &_A )
{
    // Imprimir o vetor.
    cout << ">>> [ ";
    for ( int i(1) ; i < _A.size() ; ++i ){   // Exclui o primeiro elemento(0) da sequência e imprime todos os seguintes
        cout << _A[ i ] << " ";
    }
    cout << "]" << endl;
}

//-------------------------------------------------------------------------------
//! Gera a sequencia de Fibonacci em um vetor ate um limite informado.
/*! Esta funcao gera em um vetor alocado dinamicamente a serie de Fibonacci ate
 *  antes de atingir um limite inteiro passado por parametro.
 *  Por exemplo, se limite = 15, o vetor gerado deve ser [ 1 1 2 3 5 8 13 ],
 *  visto que o ultimo elemento da serie e 13 < limite (=15).
 *
 *  @param _limit O limite inteiro que determina o fim da serie.
 *  @param _A Referencia ao vetor com a serie.
 */
void fib( int _limit, vector<int> &_A )
{

    int fib0 = 0;
    int fib1 = 1;   // fib1 é o segundo elemento(contando-se com o 0), logo deve ser 1
    int fib2 = 0;

    // o loop so vale a partir do terceiro termo
    while ( fib2 < _limit ){

        _A.push_back(fib2);
        fib2 = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib2;
        

    }
    cout << endl; // Indica o encerramento da operção e quebra linha para organizar

}

int main () {
    int L; // Valor limite da serie, cujo valor maximo deve ser inferior.
    vector<int> A;  // Vetor que irá guardar a sequência

    cout << ">>> Indique o limite para a serie de Fibonacci (n > 0): ";
    cin >> L; // Ler valor do terminal.

    if ( L >= 0 ) {
        fib( L, A ); // Gerar a Fibonacci em vetor.
        cout << ">>> The Fibonacci series up to " << L << " is: " << endl;
        printArray( A ); // Imprimir vetor na saida padrao.

        cout << endl << ">>> Normal exiting..." << endl;

    }else{
        cout << ">>> Sorry, only positive integers accepted. Aborting..." << endl;
    }
}
