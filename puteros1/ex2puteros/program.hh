node_pila* copia_node_pila_it(node_pila* m) {
	node_pila *primer;
	if (m == NULL) return NULL;
	else {
		node_pila *aux;
		primer = aux = new node_pila;
		while (m != NULL) {
			aux->info = m->info; //info es el propio elemento del nodo actual
			m = m->seguent; //m apuntará a seguent que es puntero que apunta al siguiente nodo
			if (m != NULL) {
				aux->seguent = new node_pila;
				aux = aux->seguent;
			}
		}
		aux->seguent = NULL;
	}
	return primer; //primer apunta al primer elemento aux
}

Pila& operator=(const Pila& original) {
	if (this != &original) { //this es la pila actual
		esborra_node_pila_it(primer_node);
		altura = original.altura;
		primer_node = copia_node_pila_it(original.primer_node); //accedo a elemento de pila, no al puntero directamente
	}
	return *this;
}

//-> lo mismo que (*).