#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int price;
} Item;

int compare_desc(const void* a, const void* b) {
    return ((Item*)b)->price - ((Item*)a)->price;
}

int main() {
    int coffee, iced_tea, smoothie;
    int carrot, cheese, choco;

    printf("주문하고자 하는 음료(커피, 아이스티, 스무디)와 케이크(당근, 치즈, 초코)의 갯수를 각각 입력하세요:\n");
    scanf("%d %d %d %d %d %d", &coffee, &iced_tea, &smoothie, &carrot, &cheese, &choco);

    int drink_counts[3] = {coffee, iced_tea, smoothie};
    int drink_prices[3] = {3500, 3000, 5000};
    const char* drink_names[3] = {"커피", "아이스티", "스무디"};

    int cake_counts[3] = {carrot, cheese, choco};
    int cake_prices[3] = {7000, 6000, 5500};
    const char* cake_names[3] = {"당근 케이크", "치즈 케이크", "초코 케이크"};

    int total_drinks = coffee + iced_tea + smoothie;
    int total_cakes = carrot + cheese + choco;

    if (total_drinks > 10 || total_cakes > 10) {
        printf("음료 또는 케이크 갯수가 10개를 넘었습니다. 다시 주문하세요.\n");
        return 0;
    }

    Item sorted_drinks[3], sorted_cakes[3];
    for (int i = 0; i < 3; i++) {
        sorted_drinks[i].index = i;
        sorted_drinks[i].price = drink_prices[i];
        sorted_cakes[i].index = i;
        sorted_cakes[i].price = cake_prices[i];
    }
    qsort(sorted_drinks, 3, sizeof(Item), compare_desc);
    qsort(sorted_cakes, 3, sizeof(Item), compare_desc);

    int set1 = 0, set2 = 0;
    int set1_price = 0, set2_price = 0;

    // 세트1 구성 (음료 2 + 케이크 2)
    while (1) {
        int d_used[2] = {-1, -1}, c_used[2] = {-1, -1};
        int d_cnt = 0, c_cnt = 0;
        int temp_price = 0;

        for (int i = 0; i < 3 && d_cnt < 2; i++) {
            int idx = sorted_drinks[i].index;
            while (drink_counts[idx] > 0 && d_cnt < 2) {
                temp_price += drink_prices[idx];
                drink_counts[idx]--;
                d_used[d_cnt++] = idx;
            }
        }

        for (int i = 0; i < 3 && c_cnt < 2; i++) {
            int idx = sorted_cakes[i].index;
            while (cake_counts[idx] > 0 && c_cnt < 2) {
                temp_price += cake_prices[idx];
                cake_counts[idx]--;
                c_used[c_cnt++] = idx;
            }
        }

        if (d_cnt == 2 && c_cnt == 2) {
            set1++;
            set1_price += (int)(temp_price * 0.8); // 20% 할인
        } else {
            for (int i = 0; i < d_cnt; i++) drink_counts[d_used[i]]++;
            for (int i = 0; i < c_cnt; i++) cake_counts[c_used[i]]++;
            break;
        }
    }

    // 세트2 구성 (음료 2 + 케이크 1)
    while (1) {
        int d_used[2] = {-1, -1}, c_used = -1;
        int d_cnt = 0, c_cnt = 0;
        int temp_price = 0;

        for (int i = 0; i < 3 && d_cnt < 2; i++) {
            int idx = sorted_drinks[i].index;
            while (drink_counts[idx] > 0 && d_cnt < 2) {
                temp_price += drink_prices[idx];
                drink_counts[idx]--;
                d_used[d_cnt++] = idx;
            }
        }

        for (int i = 0; i < 3 && c_cnt < 1; i++) {
            int idx = sorted_cakes[i].index;
            if (cake_counts[idx] > 0) {
                temp_price += cake_prices[idx];
                cake_counts[idx]--;
                c_used = idx;
                c_cnt++;
            }
        }

        if (d_cnt == 2 && c_cnt == 1) {
            set2++;
            set2_price += (int)(temp_price * 0.9); // 10% 할인
        } else {
            for (int i = 0; i < d_cnt; i++) drink_counts[d_used[i]]++;
            if (c_cnt == 1) cake_counts[c_used]++;
            break;
        }
    }

    // 단품 계산
    int single_drink_price = 0;
    int single_cake_price = 0;

    printf("\n품목        갯수      금액\n");
    printf("세트1       %d         %d\n", set1, set1_price);
    printf("세트2       %d         %d\n", set2, set2_price);

    for (int i = 0; i < 3; i++) {
        if (drink_counts[i] > 0) {
            int p = drink_counts[i] * drink_prices[i];
            printf("%s    %d         %d\n", drink_names[i], drink_counts[i], p);
            single_drink_price += p;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (cake_counts[i] > 0) {
            int p = cake_counts[i] * cake_prices[i];
            printf("%s     %d          %d\n", cake_names[i], cake_counts[i], p);
            single_cake_price += p;
        }
    }

    printf("---------------------------------\n");
    int total = set1_price + set2_price + single_drink_price + single_cake_price;
    printf("총 지불 금액          %d\n", total);

    return 0;
}