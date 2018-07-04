Status GetMidNode(LinkList L, ElemType *e) {
  LinkList search, mid;
  while (search-> next != NULL) {
    if (search->next->next != NULL) {
      search = search->next->next
      mid = mid->next;
    }else{
      search = search->next;
    }
  }
  *e =mid->data;
  return OK;
}
