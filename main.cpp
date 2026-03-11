#include <cassert>
#include <iostream>
#include "linked_list.h"
using namespace std;

// ===== TESTES DA FUNÇÃO criaLista =====
void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "criaLista() passou em todos os testes!" << endl;
}

// ===== TESTES DA FUNÇÃO insere (inserção no início) =====
void teste_insere() {
    cout << "Testando insere()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere primeiro elemento
    insere(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Insere segundo elemento (deve ficar no início)
    insere(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    // Insere terceiro elemento
    insere(*lista, 30);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "insere() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO destroiLista =====
void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insere(*lista, 1);
    insere(*lista, 2);
    insere(*lista, 3);

    // Destrói a lista
    destroiLista(*lista);

    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "destroiLista() passou em todos os testes" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_insere();
        teste_destroiLista();

        cout << "\n=========================================" << endl;
        cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
        cout << "=========================================" << endl << endl;

        return 0;
    } catch (const exception& e) {
        cout << "\nErro durante os testes: " << e.what() << endl;
        return 1;
    } catch (const char* e) {
        cout << "\nErro durante os testes: " << e << endl;
        return 1;
    }
}
