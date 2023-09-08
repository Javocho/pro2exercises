bool buscar(const T& x) const {
	return buscar_arbre_aux(primer_node, x);
}

static bool buscar_arbre_aux(node_arbreGen *m, const T& x) {
	int i = 0;
	bool found = false;
	if (m != NULL) {
		int nfills = m->seg.size();
		while(i < nfills and not found) {
			found = buscar_arbre_aux(m->seg[i], x);
			++i;
		}
		if (m->info == x) return true;
	}
	return found;
}