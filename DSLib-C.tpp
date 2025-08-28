#include "DSLib-C.h"
using namespace std;



//pilha

template<class Thing>
Stack<Thing>::Stack()
{
    Top = 0;
    N = 0;
}

template<class Thing>
int Stack<Thing>::size()
{
    return N;
}

template<class Thing>
bool Stack<Thing>::Empty()
{
    return !Top;
}

template<class Thing>
Thing Stack<Thing>::TOP ()
{
    return Top->D;
}

template<class Thing>
bool Stack<Thing>::Push(Thing T)
{
    Node<Thing>* P = new Node<Thing>;
    if(!P)
    {
        //P eh null -> Nao alocou (memoria cheia)
        return false;
    }
    P->D = T;
    P->Next=Top;
    Top=P;
    N++;
    return true;
}

template<class Thing>
void Stack<Thing>::Pop()
{
    Node<Thing>* P = Top;
    Top = Top->Next;
    delete P;
    N--;
}

template<class Thing>
void Stack<Thing>::Clear()
{
    Node<Thing>* P;
    while(Top)
    {
        P = Top;
        Top = Top->Next;
        delete P;
    }
    N = 0;
}

template<class Thing>
Stack<Thing>::~Stack()
{
    Clear();
}

//fila

template<class Thing>
Queue<Thing>::Queue()
{
    Head = Tail = nullptr;
    N = 0;
}

template<class Thing>
bool Queue<Thing>::Empty()
{
    return !Head;
}


template<class Thing>
int Queue<Thing>::Size()
{
    return N;
}

template<class Thing>
bool Queue<Thing>::Push(Thing T)
{
    Node<Thing>* P = new Node<Thing>;
    if (!P)
    {
        return false;
    }
    P->D = T;
    P->Next = 0;
    
    if(!Head)
    {
        Head = P;
    }
    else
    {
        Tail->Next = P;
    }
    Tail = P;
    N++;
    return true;
}

template<class Thing>
Thing Queue<Thing>::Front()
{
    return Head->D;
}

template<class Thing>
Thing Queue<Thing>::Back()
{
    return Tail->D;
}

template<class Thing>
void Queue<Thing>::Pop()
{
    Node<Thing>* P = Head;
    Head = Head->Next;
    delete P;
    if(!Head)
    {
        Tail = Head;
    }
    N--;
}

template<class Thing>
void Queue<Thing>::Clear()
{
    Node<Thing>* P;
    while (Head)
    {
        P = Head;
        Head = Head -> Next;
        delete P;
    }
    Tail = nullptr;
    N = 0;
}

template<class Thing>
Queue<Thing>::~Queue()
{
    Clear();
}

// Lista duplamente encadeada circular

template<class Thing>
List<Thing>::List() // Construtor
{
    Head = Tail = It = nullptr;
    N = 0;
}

template<class Thing>
void List<Thing>::Itbegin() // It vai para o início da lista
{
    It = Head;
}

template<class Thing>
void List<Thing>::Itend() // It vai para o fim da lista
{
    It = Tail;
}

template<class Thing>
bool List<Thing>::Itout() // O It está fora da lista? (aponta para NULL?) se sim = TRUE
{
    return !It;
};

template<class Thing>
bool List<Thing>::PushaIt(Thing T) // Insere depois do node apontado por It (after)
{
    if (Itout())
    {
        cout<<"It n aponta para nada"<<endl;
        return false;
    }
    
    Node<Thing> *P = new Node<Thing>;
    if (!P) return false;
    P->D = T;
    
    P->Prev = It; //2
    P->Next = It->Next; //3
    (It->Next)->Prev = P; //4
    It->Next = P; //5
    
    if (It == Tail) Tail = P;
    N++;
    return true;
}

template<class Thing>
bool List<Thing>::PushbIt(Thing T) // Insere antes do node apontado por It (before)
{
    if (Itout())
    {
        cout<<"It n aponta para nada"<<endl;
        return false;
    }
    
    Node<Thing> *P = new Node<Thing>;
    if (!P) return false;
    P->D = T;
    
    P->Next = It; //2
    P->Prev = It->Prev; //3
    (It->Prev)->Next = P; //4
    It->Prev = P; //5
    
    if (It == Head) Head = P;
    
    N++;
    return true;
}

template<class Thing>
bool List<Thing>::PushFront(Thing T) // Insere antes do Head (e vira Head)
{
    Node<Thing> *P = new Node<Thing>;
    if (!P) return false;
    P->D = T;
    
    if (Head)
    {
        P->Next = Head;
        P->Prev = Head->Prev; 
        (Head->Prev)->Next = P;
        Head->Prev = P;
        Head = P;
    }
    else 
    {
        Head = Tail = P;
        P->Next = P;
        P->Prev = P;
    }
    N++;
    return true;
}

template<class Thing>
bool List<Thing>::PushBack(Thing T) // Insere depois do Tail (e vira Tail)
{
    Node<Thing> *P = new Node<Thing>;
    if (!P) return false;
    P->D = T;
    
    if (Tail)
    {
        P->Next = Tail->Next; //1
        P->Prev = Tail; //2
        (Tail->Next)->Prev = P; //3
        Tail->Next = P; //4
        Tail = P; //5
    }
    else 
    {
        Head = Tail = P;
        P->Next = P;
        P->Prev = P;
    }
    N++;
    return true;
}

template<class Thing>
void List<Thing>::PopIt() // Remove o apontado por It e move It para node anterior 
{
    if (Itout())
    {
        cout<<"It n aponta para nada"<<endl;
        return;
    }
    if (Empty())
    {
        cout<<"Nada na lista para remover"<<endl;
        return;
    }
    
    Node<Thing> *P = It;
    
    if (!(Head == Tail))
    {
        (It->Next)->Prev = It->Prev;
        (It->Prev)->Next = It->Next;
        It = It->Prev;
    }
    else
    {
        Head = Tail = nullptr;
    }
    if (P == Head) Head = P->Next;
    if (P == Tail) Tail = P->Prev;
    
    delete P;
    N--;
}

template<class Thing>
void List<Thing>::PopFront() // Remove o apontado por Head
{
    if (Empty())
    {
        cout<<"Nada na lista para remover"<<endl;
        return;
    }
    
    Node<Thing> *P = Head;
    
    if (!(Head == Tail))
    {
        (Head->Next)->Prev = Head->Prev;
        (Head->Prev)->Next = Head->Next;
        Head = Head->Next;
    }
    else
    {
        Head = Tail = nullptr;
    }
    
    delete P;
    N--; 
}

template<class Thing>
void List<Thing>::PopBack() // Remove o apontado por Tail
{
    if (Empty())
    {
        cout<<"Nada na lista para remover"<<endl;
        return;
    }
    
    Node<Thing> *P = Tail;
    
    if (!(Head == Tail))
    {
        (Tail->Next)->Prev = Tail->Prev;
        (Tail->Prev)->Next = Tail->Next;
        Tail = Tail->Prev;
    }
    else
    {
        Head = Tail = nullptr;
    }
    
    delete P;
    N--;
}

template<class Thing>
bool List<Thing>::Empty() // Verifica se a lista esta vazia
{
    return (Head == nullptr);
}

template<class Thing>
int List<Thing>::Size()  // Retorna o tamanho da Lista
{
    return N;
}

template<class Thing>
void List<Thing>::ItMM() // Faz It avançar um node
{
    It = It->Next;
}

template<class Thing>
void List<Thing>::Itmm() // Faz o It voltar um node
{
    It = It->Prev;
}

template<class Thing>
Thing List<Thing>::getIt() // Retorna o conteúdo do node apontado por It
{
    return It->D;
}

template<class Thing>
Thing List<Thing>::getFront() // Retorna o conteúdo do node apontado por Head
{
    return Head->D;
}

template<class Thing>
Thing List<Thing>::getBack() // Retorna o conteúdo do node apontado por Tail
{
    return Tail->D;
}

template<class Thing>
void List<Thing>::Clear() // Limpa a Lista
{
    while (Head)
    {
        Node<Thing> *P = Head;
        
        if (!(Head == Tail))
        {
            (Head->Next)->Prev = Head->Prev;
            (Head->Prev)->Next = Head->Next;
            Head = Head->Next;
        }
        else
        {
            Head = Tail = nullptr;
        }
        
        delete P;
        N--; 
    }
}

template<class Thing>
List<Thing>::~List() // Destrutor
{
    Clear();
}
