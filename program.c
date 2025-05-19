#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

struct car {
    char brand[20];
    int number;
    char color[20];
    int price;
};

int main(){
    system ("chcp 65001");
    struct car array[N] = {
        {"Audi", 4, "dark-gray", 32300},
        {"BMW", 1, "blue", 28500},
        {"Ford", 5, "red", 6731},
        {"Lexus", 8, "white", 14312},
        {"Infiniti", 6, "silver", 23861},
        {"Chery", 2, "black", 2606},
        {"Mercedes-Benz", 3, "dark-purple", 44900},
        {"Mitsubishi", 7, "dark-blue", 16500},
    };

    printf("Введіть марку автомобіля для детальної характеристики (Audi / BMW / Ford / Lexus / Infiniti / Chery / Mercedes-Benz / Mitsubishi): ");
    char brand_input [20];
    scanf("%s", &brand_input);

    FILE *information = fopen ("Car.txt", "w");
    int i;
    int count = 0;
    for(i=0;i<N;i+=1){
        if((strcmp(array[i].brand, brand_input)) == 0){
            fprintf(information, "Марка = %s\nНомер = %d\nКолір = %s\nВартість = %d$", array[i].brand, array[i].number, array[i].color, array[i].price);
            printf("Марка = %s\nНомер = %d\nКолір = %s\nВартість = %d$", array[i].brand, array[i].number, array[i].color, array[i].price);
            count +=1;
        }
    }
    if(count == 0){
        fprintf(information, "Ваша марка відсутня у програмі, вибачте за незручності!");
        printf("Ваша марка відсутня у програмі, вибачте за незручності!");
    }
    fclose(information);
    return 0;
}
