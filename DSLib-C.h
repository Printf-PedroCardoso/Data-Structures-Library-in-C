#ifndef DSLIB_C_H
#define DSLIB_C_H

//nó

template<class Thing>
class Node
{
public:
    Thing D;
    Node<Thing>* Next;
    Node<Thing>* Prev;
};

//pilha

template<class Thing>
class Stack
{
    Node<Thing>* Top;
    int N;
    
public:
    Stack();
    int size();
    bool Empty();
    Thing TOP();
    bool Push (Thing T);
    void Pop();
    void Clear();
    ~Stack();
};

// fila

template<class Thing>
class Queue
{
private:
    Node<Thing>* Head;
    Node<Thing>* Tail;
    int N;
    
public:
    Queue();
    bool Empty();
    int Size();
    bool Push(Thing T);
    Thing Front();
    Thing Back();
    void Pop();
    void Clear();
    ~Queue();
};

// Lista duplamente encadeada circular

template <class Thing>
class List 
{
private:
    Node<Thing> *Head;
    Node<Thing> *Tail;
    Node<Thing> *It;
    int N;
    
public:
    List(); //Yes
    void Itbegin();  //Yes
    void Itend(); //Yes
    bool Itout(); //Yes  // O It está fora da lista? (aponta para NULL?) se sim = TRUE
    bool PushaIt(Thing T); //Yes  // Insere após o node apontado por It (after)
    bool PushbIt(Thing T); //Yes  // Insere antes do node apontado por It (before)
    bool PushFront (Thing T); //Yes // Insere antes do Head (e vira Head)
    //não implementado
    bool PushBack(Thing T); // Insere depois do Tail (e vira Tail)
    void PopIt(); // Remove o apontado por It 
    void PopFront(); // Remove o apontado por Head
    void PopBack(); // Remove o apontado por Tail
    bool Empty(); // Verifica se a lista esta vazia
    int Size(); // Retorna o tamanho da Lista
    void ItMM(); // Faz It avançar um node
    void Itmm(); // Faz o It voltar um node
    Thing getIt(); // Retorna o conteúdo do node apontado por It
    Thing getFront(); // Retorna o conteúdo do node apontado por Head
    Thing getBack(); // Retorna o conteúdo do node apontado por Tail
    void Clear(); // Limpa a Lista
    ~List(); // Destrutor
};

#include "DSLib-C.tpp"
#endif // DSLIB-C_H