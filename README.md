# Árvore Binária de Busca Extendida

Este repositório contém os arquivos correspondentes ao trabalho da segunda unidade da disciplina DIM0117 - Estruturas de Dados Básicas II, ofertada para o Bacheralado em Tecnlogia de Informação(BTI) na Universidade Federal do Rio Grande do Norte(UFRN).

## Descrição

Implementar uma árvore binária de busca(ABB) aumentada para suportar as operações convencionais de busca, inserção e remoção, além dos seguintes métodos:

- enésimo(int n): Retorna o n-ésimo elemento(contando a partir de 1) do percurso de ordem simétrica da ABB.
- position(Type key): Retorna a posição ocupada pelo elemento "key" em um percurso de ordem simétrica da ABB(contando a partir de 1).
- median(): Retorna o elemento que contém a mediana da ABB.
- isFull(): Retorna "true" se a ABB for uma árvore cheia e "false", caso contrário.
- isComplete(): Retorna "true" se a ABB for uma árvore completa e "false", caso contrário.
- toString(): Retorna uma string que contém a sequência de percorrimento da ABB por nível.

## Instruções

1. Clone o repositório abrindo o terminal e digitando: 
```bash
$ git clone https://github.com/gabriel-igorq/EDBII_ABB
```

2. Entre no diretório digitando: 
```bash
$ cd EDBII_ABB
```

3. Para compilar digite: 
```bash
$ make build
```

4. Para executar digite: 
```bash
$ ./bin/BinarySearchTree <nome-do-arquivo> <nome-do-arquivo>
# ex: ./bin/BinarySearchTree entradas comandos
```
Note que os arquivos de entrada devem estar na pasta [data](./data), e deve ser passado APENAS o nome do arquivo e não o diretório.

## Autores

Projeto desenvolvido por [_Gabriel Igor_]( https://github.com/gabriel-igorq) e [_Giordano Rodrigues_](https://github.com/giordanorn).

