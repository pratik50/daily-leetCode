// -------- Max Heap Structure --------
typedef struct {
    int arr[MAXN];
    int sz;
} maxHeap;

void push(maxHeap *h, int x) {
    // code here
    
    h->sz++;
    int idx = h->sz;
    h->arr[idx] = x;
    
    while(idx > 1){
        
        int parent = idx/2;
        
        if(h->arr[parent] < h->arr[idx]){
            int temp = h->arr[parent];
            h->arr[parent] = h->arr[idx];
            h->arr[idx] = temp;
            
            idx = parent;
        }else{
            return;
        }
    }
    
}

void pop(maxHeap *h) {
    
    // code here
     if (h->sz == 0) return;

    h->arr[1] = h->arr[h->sz];
    h->sz--;

    int i = 1;

    // heapify down
    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= h->sz && h->arr[left] > h->arr[largest])
            largest = left;

        if (right <= h->sz && h->arr[right] > h->arr[largest])
            largest = right;

        if (largest != i) {
            int temp = h->arr[i];
            h->arr[i] = h->arr[largest];
            h->arr[largest] = temp;

            i = largest;
        } else {
            return;
        }
    }
}

    
int peek(maxHeap *h) {
    // code here
    if(h->sz == 0)  return -1;
    return h->arr[1];
}
    

int size(maxHeap *h) {
    // code here
    
    return h->sz;
}