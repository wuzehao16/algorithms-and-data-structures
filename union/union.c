void unionL(List *La, list Lb) {
  int La_len, Lb_len, i;
  ElemType e;
  La_len = ListLength(La);
  Lb_len = ListLength(Lb);
  for ( i = 0; i <= Lb_len; i++) {
    GetElem(Lb, i, &e);
    if (!LocateElem(*La, e)) {
      ListInsert(La, ++La.len, e)
    }
  }
}
