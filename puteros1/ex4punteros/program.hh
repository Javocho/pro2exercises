void arb_sumes(Arbre<int> &asum) const {
	asum.primer_node = aux_suma(primer_node);
}

static node_arbre *aux_suma(node_arbre *m) {
	node_arbre *n;
	if (m == NULL) n = NULL;
	else {
		n = new node_arbre;
		n->segE = aux_suma(m->segE);
		n->info = m->info;
		if (n->segE != NULL) n->info += (n->segE)->info;
		n->segD = aux_suma(m->segD);
		if (n->segD != NULL) n->info += (n->segD)->info;
	}
	return n;
}