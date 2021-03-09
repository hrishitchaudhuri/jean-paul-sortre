int ARRAY_MAX_SIZE;
long int GLOBAL_COMP_COUNT;

int fwrite_out_time(char *, double);
int fwrite_out_comp(char *, long int);

void swap(int *, int, int);
void merge_inc(int *, int *, int *, int *);
void merge(int *, int, int, int, const int);

int qs_partition(int *, int, int, const int);

void sel_sort(int *, int);
void bub_sort(int *, int);
void mrg_sort(int *, int, int, const int);
void qck_sort(int *, int, int, const int);

void sort_with_time(char, int *, int *);
void arr_init(int *, int);