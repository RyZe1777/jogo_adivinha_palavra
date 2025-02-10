#include <iostream>
#include <string>
using namespace std;

// Função que substitui todas as letras da frase por "_" mantendo os espaços
string esconderFrase(const string& frase) {
    string escondido = ""; // Armazena a versão oculta da frase
    for (char f : frase) { // Percorre cada caractere da string original
        if (f == ' ') {
            escondido += ' '; // Mantém espaços inalterados
        } else {
            escondido += "_"; // Substitui as letras por "_"
        }
    }
    return escondido; // Retorna a frase ocultada
}

// Função que revela letras na frase oculta conforme o jogador acerta
string atualizarFrase(const string& frase, string& escondido, char tentativa) {
    for (size_t x = 0; x < frase.length(); x++) { // Percorre a frase original
        if (frase[x] == tentativa) { 
            escondido[x] = tentativa; // Revela a letra se houver correspondência
        }
    }
    return escondido; // Retorna a versão atualizada da frase oculta
}

// Função que pede ao usuário para inserir a frase secreta
string inserirFrase() {
    string frase;
    cout << "Digite uma frase: "; 
    getline(cin, frase); // Captura a frase completa, incluindo espaços
    return frase; // Retorna a frase digitada pelo usuário
}

int main() {
    // Captura a frase secreta do usuário
    string fraseSecreta = inserirFrase();
    // Cria a versão oculta da frase para o jogo
    string fraseOculta = esconderFrase(fraseSecreta);

    cout << "Bem-vindo ao jogo de adivinhação da frase!" << endl;
    cout << "Aqui está a frase secreta: " << fraseOculta << endl;

    string tentativa;
    bool venceu = false; // Indica se o jogador já venceu o jogo

    // Loop principal do jogo que continua até o jogador adivinhar a frase
    while (!venceu) {
        cout << "Digite uma letra para adivinhar: ";
        cin >> tentativa;

        // Valida se o usuário inseriu apenas uma letra
        if (tentativa.length() != 1) {
            cout << "Por favor, digite apenas uma letra!" << endl;
            continue; // Retorna ao início do loop se a entrada for inválida
        }

        char letraTentada = tentativa[0]; // Obtém o caractere tentado
        fraseOculta = atualizarFrase(fraseSecreta, fraseOculta, letraTentada);

        cout << "A frase agora é: " << fraseOculta << endl;

        // Verifica se o jogador já adivinhou toda a frase
        if (fraseOculta == fraseSecreta) {
            venceu = true; // Atualiza o estado do jogo para finalizado
            cout << "Parabéns! Você adivinhou a frase!" << endl;
        }
    }

    return 0; // Fim do programa
