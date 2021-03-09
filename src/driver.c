#include"utils.h"

int main() {
    for (ARRAY_MAX_SIZE = 800000; ARRAY_MAX_SIZE <= 1000000; ARRAY_MAX_SIZE = ARRAY_MAX_SIZE + 50000){
        int a[ARRAY_MAX_SIZE];

        int vargs_itr[1] = {ARRAY_MAX_SIZE};
        int vargs_rec[3] = {0, ARRAY_MAX_SIZE - 1, ARRAY_MAX_SIZE};
        
        arr_init(a, ARRAY_MAX_SIZE);
        sort_with_time('s', a, vargs_itr);
    
        arr_init(a, ARRAY_MAX_SIZE);
        sort_with_time('b', a, vargs_itr);

        arr_init(a, ARRAY_MAX_SIZE);
        sort_with_time('m', a, vargs_rec);

        arr_init(a, ARRAY_MAX_SIZE);
        sort_with_time('q', a, vargs_rec);
    }
    return 0;
}