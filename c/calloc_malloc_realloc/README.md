# calloc、malloc、realloc函数的区别及用法！
三者都是分配内存，都是stdlib.h库里的函数，但是也存在一些差异。

1. malloc函数。其原型void *malloc(unsigned int num_bytes)；
num_byte为要申请的空间大小，需要我们手动的去计算，如int *p = (int *)malloc(20*sizeof(int)),如果编译器默认int为4字节存储的话，那么计算结果是80Byte，一次申请一个80Byte的连续空间，并将空间基地址强制转换为int类型，赋值给指针p,此时申请的内存值是不确定的。

2. calloc函数，其原型void *calloc(size_t n, size_t size)；
其比malloc函数多一个参数，并不需要人为的计算空间的大小，比如如果他要申请20个int类型空间，会int *p = (int *)calloc(20, sizeof(int)）,这样就省去了人为空间计算的麻烦。但这并不是他们之间最重要的区别，malloc申请后空间的值是随机的，并没有进行初始化，而calloc却在申请后，对空间逐一进行初始化，并设置值为0;

实例：
```c
    int *p = (int *)malloc(20 * sizeof(int));
    int *pp = (int *)calloc(20, sizeof(int));
    int i;
    
    printf("malloc申请的空间值:\n\n");
    for ( i=0 ; i < 20; i++) {
        printf("%d ", *p++);
    }
    printf("\n\n");
    printf("calloc申请的空间的值:\n\n");
    for ( i=0 ; i < 20; i++) {
        printf("%d ", *pp++);
    }
    printf("\n");
```
3. realloc函数和上面两个有本质的区别，其原型void realloc(void *ptr, size_t new_Size)
用于对动态内存进行扩容(及已申请的动态空间不够使用，需要进行空间扩容操作)，ptr为指向原来空间基址的指针， new_size为接下来需要扩充容量的大小。
实例：
```c
const int size = 20000;
int *p = (int *)malloc(20*sizeof(int));
int *pp = (int *)realloc(p, size*sizeof(int));
printf("原来的p_Address:%x   扩容后的pp_Address:%x \n\n", p, pp);
```
realloc函数返回的指针所有向的地址空间可能会变化；
如果size较小，原来申请的动态内存后面还有空余内存，系统将直接在原内存空间后面扩容，并返回原动态空间基地址；如果size较大，原来申请的空间后面没有足够大的空间扩容，系统将重新申请一块(20+size)*sizeof(int)的内存，并把原来空间的内容拷贝过去，原来空间free;如果size非常大，系统内存申请失败，返回NULL,原来的内存不会释放。注意：如果扩容后的内存空间较原空间小，将会出现数据丢失，如果直接realloc(p, 0);相当于free(p).