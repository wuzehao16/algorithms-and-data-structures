// 头插法建立单链表
void CreateListHead(LinkList *L,int n) {
  LinkList p;
  int i;
  srand(time(0));
  *L = (LinkList)malloc(sizeof(Node));
  (*L) ->next = null;
  for ( i = 0; i < n; i++) {
    p = (LinkList)malloc(sizeof(Node));
    p->data = rand()%100 +1;
    p->next = (*L)->next;
    (*L) ->next = p;
  }
}
