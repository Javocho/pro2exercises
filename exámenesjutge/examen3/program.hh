void trenat(Cua &c) {
	longitud += c.longitud;
	i_trenat(primer_node, c.primer_node);
	c.primer_node = NULL;
	c.ultim_node = NULL;
}

void i_trenat(node_cua *original, node_cua *c) {
	if (original != NULL and c != NULL) {
		node_cua *originalaux = original->seguent;
		node_cua *caux = c->seguent;
		original->seguent = c;
		if (originalaux != NULL) original->seguent->seguent = originalaux;
		if (original->seguent != NULL) i_trenat(original->seguent->seguent,caux);
	}
	else if (c == NULL) original = c;
	//si original es null no passa res
}
