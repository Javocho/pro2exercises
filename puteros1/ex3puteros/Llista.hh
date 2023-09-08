#ifndef LLISTA
#define LLISTA

#include "utils.PRO2"

template <class T> class Llista {
private:
  struct node_llista {
    T info;
    node_llista* seg;
    node_llista* ant;
  }; 
  int longitud;
  node_llista* primer_node;
  node_llista* ultim_node;
  node_llista* act;
  // especificaci� operacions privades

static void esborra_node_llista_it(node_llista* m)
 /* Pre: cert */
 /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
    dels nodes de la cadena que t� el node apuntat per m com a primer */
  {
    while (m!=NULL){
      node_llista* n=m->seg;
      delete m;
      m=n;
    }
  }

public:
  //  operacions publiques

  // Constructora

  Llista() 
    /* Pre: cert */
    /* Post: el resultat es una llista buida */
  {
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }

  Llista(const Llista &original) 
    /* Pre: cert */
    /* Post: El resultat es una copia d'original */
  {
    longitud= original.longitud;
    primer_node = copia_node_llista_it(original.primer_node, original.act,
				       ultim_node, act);  
  }

  // Destructora

  ~Llista() 
    // Destructora: Esborra automaticament els objectes locals en
    // sortir d'un ambit de visibilitat
  {
    esborra_node_llista_it(primer_node);
  }

  // Redefinicio de la asignacio

  // Modificadores

  void l_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una llista sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_llista_it(primer_node);
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }
        
  void afegir (const T& x) 
    /* Pre: cert */
    /* Post: el p.i. es com el seu valor original, pero amb x
       afegit a l'esquerra del punt d'interes */
  {
    node_llista* aux;
    aux= new node_llista; // reserva espai pel nou element
    aux->info= x;
    aux->seg= act;
    if (longitud==0) {
      aux->ant= NULL;
      primer_node= aux;
      ultim_node= aux;
    }
    else if (act==NULL) {
      aux->ant= ultim_node;
      ultim_node->seg= aux;
      ultim_node= aux;
    }
    else if (act==primer_node) {
      aux->ant= NULL;
      act->ant= aux;
      primer_node= aux;
    }
    else {
      aux->ant= act->ant;
      (act->ant)->seg= aux;
      act->ant= aux;
    }
    ++longitud;
  }

  void eliminar()
    /* Pre: el p.i. es una llista no buida i el seu punt d'interes no esta a la dreta de tot */
    /* Post: El p.i. es com el p.i. original sense l'element on estava el punt d'interes
       i amb el nou punt d'interes avancat una posicio a la dreta */
  {
    node_llista* aux;
    aux= act; // conserva l'acces al node actual
    if (longitud==1) {
      primer_node= NULL;
      ultim_node= NULL;
    }
    else if (act==primer_node) {
      primer_node= act->seg;
      primer_node->ant= NULL;
    }
    else if (act==ultim_node) {
      ultim_node= act->ant;
      ultim_node->seg= NULL;
    }
    else {
      (act->ant)->seg= act->seg;
      (act->seg)->ant= act->ant;
    }
    act= act->seg; // avanca el punt d'interes
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) 
    /* Pre: l=L */
    /* Post: el p.i. te els seus elements originals seguits pels de
       L, l es buida i el punt d'interes del p.i. queda situat a l'inici */
  {
    if (l.longitud>0) {  // si la llista l es buida no cal fer res
      if (longitud==0) {
	primer_node= l.primer_node;
	ultim_node= l.ultim_node;
	longitud= l.longitud;
      }
      else {
	ultim_node->seg= l.primer_node;
	(l.primer_node)->ant= ultim_node;
	ultim_node= l.ultim_node;
	longitud+= l.longitud;
      }
      l.primer_node= NULL;
      l.ultim_node= NULL;
      l.act= NULL;
      l.longitud= 0;  
    }    
    act= primer_node;

  }

  // Consultores 

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. es una llista buida o no */
  {
    return primer_node==NULL and ultim_node==NULL and longitud==0;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat es el nombre d'elements de la llista p.i. */
  {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const
    /* Pre: el p.i. es una llista no buida i el seu punt d'interes no esta a la dreta de tot */
    /* Post: el resultat es l'element actual del p.i. */
  { 
    return act->info;// equival a consultar *it si it es un iterador a l'actual
  }

  void modifica_actual(const T &x) 
    /* Pre: el p.i. es una llista no buida i el seu punt d'interes no esta a la dreta de tot */
    /* Post: el p.i. es com el seu valor original, pero amb x reemplacant l'element actual */
  {
    act->info= x; // equival a fer *it=x; si it is un iterador
  }

  // Noves operacions per a moure el punt d'interes

  void inici()
    /* Pre: cert */
    /* Post: el punt d'inter�s del p.i. esta situat a sobre del primer element de la llista
       o a la dreta de tot si la llista es buida */
  {
    act= primer_node; // equival a fer it=l.begin(); si it es un iterador a l'actual
  }

  void fi()
    /* Pre: cert */
    /* Post: el punt d'interes del p.i. esta situat a la dreta del tot */
  {
    act= NULL;  // equival a fer it=l.end(); si it es un iterador a l'actual
  }

  void avanca() 
    /* Pre: el punt d'interes del p.i. no est� a la dreta de tot */
    /* Post: el punt d'interes del p.i. esta situat una posicio mes a la dreta que al
       valor original del p.i. */ 
  { 
    act= act->seg; // equival a fer ++it; si it es un iterador a l'actual
  }

  void retrocedeix() 
    /* Pre: el punt d'interes del p.i. no esta a sobre del primer element de la llista*/
    /* Post: el punt d'interes del p.i. esta situat una posicio mes a l'esquerra que
       al valor original del p.i. */ 
  {
    if (act==NULL) act=ultim_node;  
    else act= act->ant; // equival a fer --it; si it es un iterador a l'actual
  }

  bool dreta_de_tot() const
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'interes del p.i. esta a la dreta de tot */
  {
    return act==NULL; // equival a comparar it==l.end() si it es un iterador a l'actual
  }

  bool sobre_el_primer() const 
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'inter�s del p.i. esta a sobre del
       primer element del p.i. o esta a la dreta de tot si la llista es buida */
  {
    return act==primer_node; // equival a comparar it==l.begin() si it es un iterador a l'actual
  }

#include "program.hh"

};

#endif
