void  reorganitzar_in(const T& x) {
	node_llista *aux, *primer_gran, *actual;
	aux = new node_llista;
	actual = new node_llista;
	actual = primer_node;
	act = NULL;
	while (actual != NULL) {
		if (actual->info <= x) {
			if (aux == NULL) {
				aux->info = actual->info;
				aux->ant = NULL;
				primer_node = aux;
			}
			else {
				aux->seg = new node_llista;
				aux = aux->seg;
				aux->info =actual->info;
			}
		}
		else {
			if (act == NULL) {
				primer_gran = new node_llista;
				primer_gran->info = actual->info;
				act = primer_gran;
			}
			else {
				act->seg = new node_llista;
				act = act->seg;
				act->info = actual->info;
			}
		}
		actual = actual->seg;
	}
	ultim_node = act;
	if (primer_node == NULL) primer_node = act;
	else if (ultim_node == NULL) ultim_node = aux;
	else {
		aux->seg = act;
		act->ant = aux;
	}
}