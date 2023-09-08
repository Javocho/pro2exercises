T max_suma_cami() const {
	T maxsuma, suma;
	maxsuma = suma = 0;
	aux_max_suma(primer_node, maxsuma, suma);
	return maxsuma;
}

static void aux_max_suma(node_arbreGen *m, T& maxsuma, T suma) {
	suma += m->info;
	if (suma > maxsuma) maxsuma = suma;
	for (int i = 0; i < m->seg.size(); ++i) {
		aux_max_suma(m->seg[i], maxsuma, suma);
	}
}