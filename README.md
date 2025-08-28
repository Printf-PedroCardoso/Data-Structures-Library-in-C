# DSLib-C: Biblioteca de Estruturas de Dados em C++

Este repositório contém uma implementação simples e didática de estruturas de dados clássicas em C++, utilizando templates para permitir o uso com qualquer tipo de dado. O objetivo principal deste projeto é fornecer um material de estudo claro e funcional sobre Pilhas, Filas e Listas Duplamente Encadeadas Circulares.

## Estruturas Implementadas

* **`Stack<T>` (Pilha)**: Estrutura de dados LIFO (Last-In, First-Out).
* **`Queue<T>` (Fila)**: Estrutura de dados FIFO (First-In, First-Out).
* **`List<T>` (Lista Duplamente Encadeada Circular)**: Lista com um iterador (`It`) para navegação e manipulação de elementos em qualquer posição.

## Estrutura dos Arquivos

* `DSLib-C.h`: O arquivo de cabeçalho. Contém as declarações das classes `Node`, `Stack`, `Queue` e `List`. **Inclua este arquivo no seu projeto para usar a biblioteca.**
* `DSLib-C.tpp`: O arquivo de implementação dos templates. Contém o código-fonte dos métodos das classes e é incluído automaticamente pelo `DSLib-C.h`.
* `main.cpp`: Um arquivo de exemplo que demonstra o uso básico de cada uma das estruturas de dados implementadas.

## Como Compilar e Executar o Exemplo

Para compilar e executar o arquivo de demonstração (`main.cpp`) em um ambiente Linux ou com g++, siga os passos:

1.  **Clone o repositório:**
    ```sh
    git clone <URL_DO_SEU_REPOSITORIO>
    ```

2.  **Navegue até a pasta do projeto:**
    ```sh
    cd <NOME_DA_PASTA>
    ```

3.  **Compile os arquivos:**
    ```sh
    g++ main.cpp -o programa_teste
    ```

4.  **Execute o programa:**
    ```sh
    ./programa_teste
    ```

## Como Usar em Seu Projeto

1.  Copie os arquivos `DSLib-C.h` e `DSLib-C.tpp` para o diretório do seu projeto.
2.  Inclua o cabeçalho no seu código-fonte:
    ```cpp
    #include "DSLib-C.h"
    ```
3.  Instancie e utilize as estruturas de dados conforme necessário:
    ```cpp
    #include <iostream>
    #include "DSLib-C.h"

    int main() {
        Stack<int> minhaPilha;
        minhaPilha.Push(100);
        std::cout << "Topo da pilha: " << minhaPilha.TOP() << std::endl;
        return 0;
    }
    ```

## API de Métodos

Aqui está um resumo dos métodos públicos disponíveis para cada classe.

### Stack<T>

* `int size()`: Retorna o número de elementos.
* `bool Empty()`: Verifica se a pilha está vazia.
* `Thing TOP()`: Retorna o elemento do topo sem removê-lo.
* `bool Push(Thing T)`: Adiciona um elemento no topo.
* `void Pop()`: Remove o elemento do topo.
* `void Clear()`: Remove todos os elementos.

### Queue<T>

* `int Size()`: Retorna o número de elementos.
* `bool Empty()`: Verifica se a fila está vazia.
* `bool Push(Thing T)`: Adiciona um elemento no final da fila.
* `Thing Front()`: Retorna o primeiro elemento sem removê-lo.
* `Thing Back()`: Retorna o último elemento sem removê-lo.
* `void Pop()`: Remove o primeiro elemento.
* `void Clear()`: Remove todos os elementos.

### List<T>

* **Tamanho e Status:**
    * `int Size()`: Retorna o número de elementos.
    * `bool Empty()`: Verifica se a lista está vazia.
* **Inserção:**
    * `bool PushFront(Thing T)`: Insere no início da lista.
    * `bool PushBack(Thing T)`: Insere no final da lista.
    * `bool PushaIt(Thing T)`: Insere um elemento *após* a posição do iterador.
    * `bool PushbIt(Thing T)`: Insere um elemento *antes* da posição do iterador.
* **Remoção:**
    * `void PopFront()`: Remove o primeiro elemento.
    * `void PopBack()`: Remove o último elemento.
    * `void PopIt()`: Remove o elemento na posição do iterador.
* **Acesso:**
    * `Thing getFront()`: Retorna o primeiro elemento.
    * `Thing getBack()`: Retorna o último elemento.
    * `Thing getIt()`: Retorna o elemento na posição do iterador.
* **Iterador (`It`):**
    * `void Itbegin()`: Move o iterador para o início da lista (`Head`).
    * `void Itend()`: Move o iterador para o final da lista (`Tail`).
    * `void ItMM()`: Avança o iterador para o próximo elemento.
    * `void Itmm()`: Recua o iterador para o elemento anterior.
    * `bool Itout()`: Verifica se o iterador aponta para `nullptr`.
* **Geral:**
    * `void Clear()`: Remove todos os elementos da lista.
