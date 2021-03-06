void RemoveListaFS(listaS **epinicio, char chave){
  listaS *p1, *p2;
  int achou;
         
  if (*epinicio == NULL)
    printf("lista vazia \n");
  else {
    achou = 0;
    while ((*epinicio != NULL) && ((*epinicio)->dado == chave)) {
      if ((*epinicio)->prox == *epinicio) {
        free (*epinicio);
        *epinicio = NULL;
        achou = 1;
      }
      else {
        p1 = *epinicio;    
        *epinicio = (*epinicio)->prox;
        p2 = *epinicio;
        while (p2->prox != p1)
          p2 = p2->prox;
        p2->prox = p1->prox; 
        free (p1);
        p1 = p2;
        achou = 1;
      }
    }         
    if ((*epinicio != NULL) && ((*epinicio)->prox != NULL)) {
      p1 = (*epinicio)->prox;
      while (p1 != *epinicio){ 
        if (p1->dado == chave) {
          p2 = *epinicio;
          while (p2->prox != p1)
            p2 = p2->prox;
          p2->prox = p1->prox;
          free (p1);
          p1 = p2->prox;  
          achou = 1;
        }  
        else    
          p1 = p1->prox;
	  }
	}
  }       
}
