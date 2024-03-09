#include<stdio.h>
#define NR_30 30
#define NR_29 29
#define NR_28 28

int main() {
    unsigned int inst = 0, aux = 0;
    unsigned int last_bit = -1, N = 0, Op = 0, Dim = 0;
    scanf("%u", &inst);
    // printf("first bit %u\n", first_bit);
    N = (inst >> NR_29) +1;     // iau doar primii 3 biti
    printf("%u", N);
    Op = inst << 3;             // scot primii 3 biti
    aux = Op;
    // printf("aux %u\n", aux);
    // creez cate o masca cu codul operatiei aflat pe primii 2 biti
    unsigned int add_musk = 0, subs_musk = 1 << NR_30, mult_musk = 2 << NR_30, div_musk = 3 << NR_30;
    unsigned int valid_mask = 3 << NR_30;
    // verific daca primii 2 biti corespund operatiei
    // valid_mask reduce verificare la primii 2 biti
    for (int i = 1; i <= N; i++) {
        // operation =  Op >> 2*(i-1);
        if (((aux ^ add_musk) & valid_mask) == 0) {
            printf(" +");
        } else if (((aux ^ subs_musk) & valid_mask) == 0) {
            printf(" -");
        } else if (((aux ^ mult_musk) & valid_mask) == 0) {
            printf(" *");
        } else {
            printf(" /");
        }
        aux <<= 2;
        // printf("aux %u\n", aux);
    }
    // primii 4 bitii ramasi in aux corespund dimensiunii, asa ca-i duc la pe primele 4 pozitii pentru ai interpreta
    Dim = (aux >> NR_28) + 1;
    printf(" %u\n", Dim);
    return 0;
}
// 0110 0011 1101 1110 0000 0000 0000 0000
// 0001 1110 1111 0000 0000 0000 0000 0000
