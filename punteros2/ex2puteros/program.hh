void arbsuma(ArbreNari& asum) const {
	asum.N = N;
	asum.primer_node = i_arbsuma(primer_node);
}

static node_arbreNari *i_arbsuma(node_arbreNari *m) {
	if (m == NULL) return NULL;
	node_arbreNari *n = new node_arbreNari;
	int s = m->info;
	int nhijos = m->seg.size(); //o se puede usar parámetro N si no fuera static la función
	n->info = m->info;
	for (int i = 0; i < nhijos; ++i) {
		n->seg[i] = new node_arbreNari;
		n->seg[i] = i_arbsuma(m->seg[i]);
		if (n->seg[i] != NULL) s += (n->seg[i])->info;
	}
	n->info = s;
	return n;
}