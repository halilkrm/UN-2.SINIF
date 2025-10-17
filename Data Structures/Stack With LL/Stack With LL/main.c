
typedef struct s{
   int item;
   struct s *next;
}STACK;

STACK *sp = NULL;

int push(int item){
   STACK *p;
   p = (STACK *)malloc(sizeof(STACK));
   if (p == NULL){
      printf("Error, not enough memory\n");
      return -1;
   }
   else{
      p->item = item;
      p->next = sp;  // mevcut yıgının eski başını gösterir
      sp = p;
      return 0;
   }
}
int pop(){
   STACK *p;
   int i;
   if (sp == NULL){
      printf("Stack is empty\n");
      return -1;
   }
   else {
      p = sp; // çıkarılacak öge(en üstteki) p işaretçisine atanır
      i = sp->item;  // Bu öğenin değeri i'ye aktarılır.
      sp = sp->next; // Yığının başı güncellenir. tepeden bir önceki artık tepede olur

      free(p);// Eski baş öğesi bellekten serbest bırakılır.

      return i; // çıkarılan öge döndürülür
   }
}
void reset(){
   STACK *p;
   while (sp != NULL){
      p = sp; // geçiçi işaretçi p yıgının basını tutar
      sp = sp->next; // Bu satırda, yığının başı (stack pointer) bir sonraki öğeye (sp->next) yönlendirilir. Yani, yığının başı bir öğe ilerler.
      free(p); // p işaretçisi eski yığın başını tutuyor. Bu satırda, eski yığın başının belleği serbest bırakılır. Bu, malloc ile ayrılmış olan belleği geri almak için yapılır.
   }
}

STACK *top(){  //returns the address of the top element Özet: top fonksiyonu, yığının başındaki öğenin adresini döndürür. Eğer yığın boşsa, NULL döner.
    

   return sp;
}
int size(){   // returns the # of elements in the stack Özet: Bu fonksiyon, yığındaki öğeleri tek tek sayarak, yığının toplam eleman sayısını döndürür.
    

   STACK *p;
   int i = 0;
   p = sp;
   while (p){
      i++;
      p = p->next;
   }
   return i;
}

STACK *isEmpty(){ // indicates whether no elements
                  // are stored or not. Bu fonksiyon, yığının boş olup olmadığını kontrol eder. Yığın boşsa NULL döner, boş değilse yığının başını (sp) döndürür.
   return sp;
}
