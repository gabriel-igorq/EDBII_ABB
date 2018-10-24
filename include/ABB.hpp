#ifndef INCLUDE_ABB_HPP
#define INCLUDE_ABB_HPP

using namespace std;

typedef int tipo;

struct Node {
	public:

	// Nó pai
	Node* pai;

	// Nó à esquerda
	Node* esq;

	// Nó à direita
	Node* dir;

	// Qntd de nós na subárvore esquerda
	unsigned int esq_cnt;

	// Qntd de nós na subárvore direita
	unsigned int dir_cnt;

	// Valor armazenado no nó
	tipo dado;

	// Nível
	unsigned int nivel;

	public:

	Node(tipo valor = tipo(), int nivel = 0, Node* pai = nullptr,
	    Node* esq = nullptr, Node* dir = nullptr);

};


class ABB {
    private:
	// Nó raiz
	Node* raiz;

	// Qntd de nós na árvore
	unsigned int size;

	// Altura da árvore
	unsigned int height;


	bool inserir(Node* node, const tipo valor);
	bool remover(Node* node, const tipo valor);

    public:

	int getSize();
	int getHeight();
	Node* getRaiz();

	ABB(Node* raiz = nullptr);
	~ABB();

	void destruir(Node* node);
	Node* busca(const tipo valor);
	bool inserir(const tipo valor);
	bool remover(const tipo valor);
};


#endif
