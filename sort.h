void bubbleSort(int array[], int length);
void quickSort(int array[], int length);

#ifdef SORT_IMPL
void swapElemsByIndexes(int array[],int index1, int index2) {
    if (index1 == index2) return;
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void bubbleSort(int array[], int length) {
    bool sorted;
    do {
        sorted = true;
        for(int i = 1; i <= length; ++i) {
            if(array[i-1] > array[i]) {
                sorted = false;
                swapElemsByIndexes(array, i-1, i);
            }
        }
    } while(!sorted);
}

void quickSortImp(int array[], int begin, int end) {
    if (begin >= end) return;
    const int medVal= array[end];
    int i = begin;
    int j = end;
    while(i < j) {
        if (medVal >= array[i]){
            ++i;
        } else {
            swapElemsByIndexes(array,i,j-1);
            swapElemsByIndexes(array,j,j-1);
            --j;
        }
    }
    quickSortImp(array,begin, j - 1);
    quickSortImp(array, j, end);
}

void quickSort(int array[], int length) {
    quickSortImp(array,0,length - 1);
}
#endif
