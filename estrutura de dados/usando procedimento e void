#include <iostream>
#include <cmath>

bool ehPrimo(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}


void mostraResultado(int n) {
    if (ehPrimo(n)) {
        std::cout << "É primo o número: " << n << std::endl;
    } else {
        std::cout << "Não é primo o número: " << n << std::endl;
    }
}

int main() {
    int numero;

    std::cout << "Digite um número: ";
    std::cin >> numero;

    mostraResultado(numero);  

    return 0;
}
