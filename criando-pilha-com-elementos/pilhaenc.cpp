#include <assert.h> /**< Necessário para uso da macro "assert". */
#include <cstdlib> /**< Necessário para uso do NULL. */
#include "pilhaenc.hpp"

using namespace std;

struct Noh {
	int item; /**< Representa a informação a ser armazenada em cada nó da pilha. */
	Noh* prox; /**< É um ponteiro para o próximo nó da pilha. */
};

struct PilhaEnc {
    Noh* topo; /**< É um ponteiro para o todo da pilha. */
};

PilhaEnc* criar_pilha() {
    /* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	PilhaEnc* pilha = new PilhaEnc;    
    
    pilha->topo = NULL;
    return pilha;
}

PilhaEnc* criar_pilha(int dados[], int n) {
	PilhaEnc* p = criar_pilha();
	for(int i = 0; i < n; i++) {
		empilhar(p, dados[i]);
	}	
	return p;
}

void liberar_pilha(PilhaEnc* pilha) {
    /* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	 */
	assert(pilha != NULL);
	
	// Libera a memória alocada para cada nó da pilha individualmente.
	while(pilha->topo != NULL) {
		desempilhar(pilha);
	}	
	delete pilha;
}

bool estah_vazia(PilhaEnc* pilha) {
    assert(pilha != NULL);	
	
	return (pilha->topo == NULL);
}

Noh* criar_noh(int item, Noh* prox) {
	Noh* novoNoh = new Noh;
	novoNoh->item = item;
	novoNoh->prox = prox;
	return novoNoh;
}

void empilhar(PilhaEnc* pilha, int item) {
    assert(pilha != NULL);
	
	Noh* novo_noh = criar_noh(item, pilha->topo); 
	pilha->topo = novo_noh;
}

int desempilhar(PilhaEnc* pilha) {
    assert(pilha != NULL);
	assert(pilha->topo != NULL);    
    
    int item = pilha->topo->item;    
    Noh* aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    delete aux;
        
    return item;    
}

int obter_topo(PilhaEnc* pilha) {
    assert(pilha != NULL);
	assert(pilha->topo != NULL);    
    
    return pilha->topo->item;
}
