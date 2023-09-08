Llista  reorganitzar_out(const T& x) const {
	Llista l; //para los grandes pilla simplemente ultimnode de cada vez
	node_llista *big = NULL; //donde comienzan grandes
	node_llista *p_lista = primer_node;
	l.longitud = longitud;
	l.primer_node = l.ultim_node = l.act = NULL;
	while (p_lista != NULL) {
		if (x >= p_lista->info) {
			if (l.primer_node == NULL) {
				l.primer_node = new node_llista;
				l.primer_node->ant = NULL;
				big = l.primer_node;
			}
			else {
				big->seg = new node_llista;
				(big->seg)->ant = big; //el anterior del siguiente que se tiene que definir, será el big de ahora
				big = big->seg;
			}
			big->info = p_lista->info;
		}
		else {
			if (l.ultim_node == NULL) {
				l.ultim_node = new node_llista;
				l.ultim_node->ant = big;
				big = l.ultim_node;
			}
			else {
				l.ultim_node->seg = new node_llista;
				(l.ultim_node->seg)->ant = l.ultim_node;
				l.ultim_node = l.ultim_node->seg;
			}
			l.ultim_node->info = p_lista->info;
		}
		p_lista = p_lista->seg;
	}
	if (l.primer_node == NULL) {
		l.primer_node = big;
	}
	if (l.ultim_node == NULL) {
		l.ultim_node = big;
	}
	l.act = big;
	return l;
}