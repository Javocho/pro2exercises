void sub_arrel(Arbre& asub, const T& x) {
		int profactual, mejorprof;
		profactual = 0;
		mejorprof = -1;
		asub.primer_node = NULL;
		asub.primer_node = copia_node_arbre(aux_sub_arrel(primer_node, x, profactual, mejorprof));
		//no puedo asignar directamente nodos diferentes, para eso está copia_node_arbre
}

static node_arbre *aux_sub_arrel(node_arbre *a, const T& x, int profactual, int& mejorprof) {
		node_arbre *aux = NULL;
		node_arbre *mejoraux = NULL;
		if (a != NULL) {
			if ((a->info == x) and ((profactual < mejorprof) or (mejorprof == -1))) {
				mejorprof = profactual;
				return a;
			}
			aux = copia_node_arbre(aux_sub_arrel(a->segE, x, profactual + 1, mejorprof));
			if (aux != NULL) mejoraux =  copia_node_arbre(aux);
			if (aux == NULL) aux = copia_node_arbre(aux_sub_arrel(a->segD, x, profactual + 1, mejorprof));
			if (aux != NULL) mejoraux =  copia_node_arbre(aux);
		}
		
		return mejoraux;
}

//sería más óptimo hacerla void y simplemente con la condición ir asignando el mejor nodo a un nodo pasado por referencia y si no es igual ir llamando a la función con izquierda y derecha
