void bubble_sort(int array[], int length);
void quick_sort(int array[], int length);

#ifdef SORT_IMPL
void swap_elements_by_indexes(int array[],int index1, int index2) {
    if (index1 == index2) return;
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void bubble_sort(int array[], int length) {
    bool sorted;
    do {
        sorted = true;
        for(int i = 1; i <= length; ++i) {
            if(array[i-1] > array[i]) {
                sorted = false;
                swap_elements_by_indexes(array, i-1, i);
            }
        }
    } while(!sorted);
}

void quick_sort_imp(int array[], int begin, int end) {
    if (begin >= end) return;
    const int medVal= array[end];
    int i = begin;
    int j = end;
    while(i < j) {
        if (medVal >= array[i]){
            ++i;
        } else {
            swap_elements_by_indexes(array,i,j-1);
            swap_elements_by_indexes(array,j,j-1);
            --j;
        }
    }
    quick_sort_imp(array,begin, j - 1);
    quick_sort_imp(array, j, end);
}

void quick_sort(int array[], int length) {
    quick_sort_imp(array,0,length - 1);
}
#endif
