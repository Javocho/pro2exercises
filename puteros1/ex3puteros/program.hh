/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
 //mis cosas chachis
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
	node_llista *result, *primer, *auxant;
	primer = new node_llista;
	result = primer;
	if (m == NULL) {
		u = a = primer = NULL;
	}
	a = NULL;
	auxant = NULL;
	while (m != NULL) {
		result->ant = auxant;
		result->info = m->info;
		if (oact == m) a = result; 
		m = m->seg;
		if (m != NULL) {
			result->seg = new node_llista;
			auxant = result;
			result = result->seg;
		}
	}
	result->seg = NULL;
	u = result;
	return primer;
}


 /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) {
	if (&original != this) {
		esborra_node_llista_it(primer_node);
		primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
		longitud = original.longitud;
	}
	return *this;
}