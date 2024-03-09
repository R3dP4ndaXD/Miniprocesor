#include<stdio.h>
#define NR_32 32
#define NR_30 30
#define NR_29 29
#define NR_28 28
#define NR_16 16
#define NR_15 15

int main() {
    unsigned int inst = 0, aux = 0, N = 0, Dim = 0;
    int i  = 1, res = 0;
    scanf("%u", &inst);
    N = (inst >> NR_29) +1;
    // printf("%u", N);
    aux = inst << 3;
    /* pentru a afla dimensiunea caut sa aduc bitii pentru dimensiune pe ultimele 4 pozitii;
    primii 2*(N+2) biti din aux contin operatiile si secventa;
    shiftez pe aux pentru a aduce acei 2*(N+2) biti pe ultimele pozitii
    si cu ultima masca citesc doar ultimi 4 biti (cei pentru dimensiune) */
    Dim = ((aux >> (NR_32 -2*(N+2))) & NR_15) + 1;
    // printf(" %u\n", Dim);
    unsigned int nr_oprd = ((N+1) * Dim) / NR_16;
    if (((N+1) * Dim) % NR_16) {
        nr_oprd++;
    }
    // printf("%u\n", nr_oprd);
    unsigned int add_musk = 0, subs_musk = 1 << NR_30, mult_musk = 2 << NR_30, div_musk = 3 << NR_30;
    unsigned int valid_mask = 3 << NR_30, oprd_mask = (1 << Dim) - 1;
    unsigned int nr2 = 0, count = 1, oprd_per_nr = NR_16 / Dim;
    unsigned int j = oprd_per_nr;
    unsigned short oprd = 0;

    scanf("%hu", &oprd);
    res = (int)(oprd >> ((j-1) * Dim));     // primul operand din short(oprd)
    // printf("primul nr %i \n", res);
    j--;
    if (oprd_per_nr == 1) {
        j++;
        scanf("%hu", &oprd);
        count++;
        // printf("%i \n", res);
    }

    while (count <= nr_oprd) {
        /* fiecare short il interpretez operand cu operand si ma opresc daca am citit am atins numarul de operanzi
        (asta pentru cand ultimul sort e incomplet); 
        daca Dim == 16, interpretez short cu short */
        while (j > 0 && i <= N) {
            if (oprd_per_nr > 1) {
                nr2 = (oprd >> ((j-1) * Dim) ) & oprd_mask;
                // printf(" numarul %u\n", nr2);
            } else {
                nr2 = oprd;
            }
            if (((aux ^ add_musk) & valid_mask) == 0) {
                res += (int)nr2;
            } else if (((aux ^ subs_musk) & valid_mask) == 0) {
                res -= (int)nr2;
            } else if (((aux ^ mult_musk) & valid_mask) == 0) {
                res *= (int)nr2;
            } else {
                res /= (int)nr2;
            }
            aux <<= 2;
            j-= 1;
            i++;
            // printf("rez part %i\n", res);
        }
        if (count < nr_oprd) {
            scanf("%hu", &oprd);
        }
        count++;
        j = oprd_per_nr;
    }
    printf("%i\n", res);
    return 0;
}
