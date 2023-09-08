int freq(const T& x) const {
		return aux_freq(primer_node, x);
	}

	static int aux_freq(node_arbreGen *m, const T& x) {
		int result = 0;
		if (m != NULL) {
			int nfills = m->seg.size();
			int i = 0;
			while (i < nfills) {
				result += aux_freq(m->seg[i], x);
				++i;
			}
			if (m->info == x) ++result;
		}
		return result;
	}