Status ClearList (LinkList *L) {
  LinkList p , q;
  p = (*L)->next;
  while (p) {
    q = p -> next;
    free(q);
    q = p;
  }
  (*L)->next = null;
  return OK;
}
