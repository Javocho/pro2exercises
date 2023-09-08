T maxim() const {
	return i_max(primer_node);
}

static T i_max(node_arbreNari *m) {
	T maxnode = m->info;
	int tree_size = m->seg.size(); //número de hijos
	for (int i = 0; i < tree_size; ++i) {
		if (m->seg[i] != NULL) {
			T max_dels_fills = i_max(m->seg[i]);
			maxnode = max(max_dels_fills, maxnode);
		}
	}
	return maxnode;
} 
