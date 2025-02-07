#include <iostream>
#include <string>
using namespace std;

string esconderFrase(const string& frase) {
    string escondido = "";
    for (char f : frase) {
        if (f == ' ') {
            escondido += ' '; // Mantém espaços
        } else {
            escondido += "_"; // Esconde letras
        }
    }
    return escondido;
}

string atualizarFrase(const string& frase, string& escondido, char tentativa) {
    for (size_t x = 0; x < frase.length(); x++) {
        if (frase[x] == tentativa) {
            escondido[x] = tentativa; // Revela a letra correta
        }
    }
    return escondido;
}

string inserirFrase() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);
    return frase;
}

int main() {
    string fraseSecreta = inserirFrase();
    string fraseOculta = esconderFrase(fraseSecreta);

    cout << "Bem-vindo ao jogo de adivinhação da frase!" << endl;
    cout << "Aqui está a frase secreta: " << fraseOculta << endl;

    string tentativa;
    bool venceu = false;

    while (!venceu) {
        cout << "Digite uma letra para adivinhar: ";
        cin >> tentativa;

        if (tentativa.length() != 1) {
            cout << "Por favor, digite apenas uma letra!" << endl;
            continue;
        }

        char letraTentada = tentativa[0];
        fraseOculta = atualizarFrase(fraseSecreta, fraseOculta, letraTentada);

        cout << "A frase agora é: " << fraseOculta << endl;

        if (fraseOculta == fraseSecreta) {
            venceu = true;
            cout << "Parabéns! Você adivinhou a frase!" << endl;
        }
    }

    return 0;
}
