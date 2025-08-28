#include <iostream>
#include "DSLib-C.h" // Incluindo a sua biblioteca
using namespace std;

int main() {
    // --- Teste Rápido da Pilha (Stack) ---
    cout << "### TESTE: PILHA (STACK) ###" << endl;
    Stack<int> pilha;
    pilha.Push(10);
    pilha.Push(20);
    pilha.Push(30);
    cout << "Pilha com " << pilha.size() << " elementos. Topo: " << pilha.TOP() << endl; // Saída: 3, 30
    pilha.Pop();
    cout << "Apos Pop(). Novo topo: " << pilha.TOP() << endl; // Saída: 20
    cout << "------------------------------------\n" << endl;

    // --- Teste Rápido da Fila (Queue) ---
    cout << "### TESTE: FILA (QUEUE) ###" << endl;
    Queue<string> fila;
    fila.Push("A");
    fila.Push("B");
    fila.Push("C");
    cout << "Fila com " << fila.Size() << " elementos. Frente: " << fila.Front() << " | Fundo: " << fila.Back() << endl; // Saída: 3, A, C
    fila.Pop();
    cout << "Apos Pop(). Nova frente: " << fila.Front() << endl; // Saída: B
    cout << "------------------------------------\n" << endl;

    // --- Teste Rápido da Lista (List) ---
    cout << "### TESTE: LISTA (LIST) ###" << endl;
    List<int> lista;
    lista.PushFront(10); // Lista: 10
    lista.PushBack(30);  // Lista: 10, 30
    lista.Itbegin();     // Iterador aponta para 10
    lista.PushaIt(20);   // Insere 20 depois do iterador. Lista: 10, 20, 30
    
    cout << "Lista inicial (" << lista.Size() << " elementos): ";
    lista.Itbegin();
    for (int i = 0; i < lista.Size(); ++i) {
        cout << lista.getIt() << " ";
        lista.ItMM();
    }
    cout << endl;

    lista.PopFront(); // Remove o 10
    lista.PopBack();  // Remove o 30
    cout << "Apos PopFront() e PopBack(). Elemento restante: " << lista.getFront() << endl; // Saída: 20
    cout << "------------------------------------\n" << endl;

    return 0;
}