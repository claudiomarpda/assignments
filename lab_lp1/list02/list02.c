#include <stdio.h>

/**
    Converts 24 hours to 12 hours.
*/
void ex01(int hour, int minute) {

    if(hour > 12){
        printf("%d:", hour-12);// %s\n", hour-12, minute, "PM");
        if(minute < 10){
            putchar('0');
        }
        printf("%d %s\n", minute, "PM");
    }
    else{
        printf("%d:", hour);
        if(minute < 10){
            putchar('0');
        }
        printf("%d %s\n", minute, "AM");  
    }    
}

/**
    Shows numbers in cascade accoding to n.
*/
void ex02(int n) {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("%2d ", i);
        }
        putchar('\n');
    }
}

/**
    Shows numbers in cascade accoding to n.
*/
void ex03(int n) {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("%2d ", j);
        }
        putchar('\n');
    }
}


/**
    Checks if dividend is divisible by divisor.
*/
int is_divisible(int dividend, int divisor) {
    if((dividend % divisor) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

/**
    Checks if a number is prime.
*/
int is_prime(int n){
    for(int divisor = 2; divisor < n; divisor++){
        if(is_divisible(n, divisor)){
            return 0;
        }
    }
    return 1;
}

int max_height_position(float height[], int size){
    int i, higher;
    higher = 0;
    for(i = 1; i < size; i++){
        if(height[i] > height[higher]){
            higher = i;
        }
    }
    return higher;
}

int min_height_position(float height[], int size){
    int i, smaller;
    smaller = 0;
    for(i = 1; i < size; i++){
        if(height[i] < height[smaller]){
            smaller = i;
        }
    }
    return smaller;
}

float male_average_height(float height[], char gender[], int size){
    int i, number_of_male = 0;
    float total = 0;
    for(i = 0; i < size; i++){
        if(gender[i] == 'M'){
            number_of_male++;
            total += height[i];
        }
    }
    return total/number_of_male;
}

float female_average_height(float height[], char gender[], int size){
    int i, number_of_female = 0;
    float total = 0;
    for(i = 0; i < size; i++){
        if(gender[i] == 'F'){
            number_of_female++;
            total += height[i];
        }
    }
    return total/number_of_female;
}

int number_of_male(char gender[], int size){
    int i, male = 0;
    for(i = 0; i < size; i++){
        if(gender[i] == 'M'){
            male++;
        }
    }
    return male;
}

int number_of_female(char gender[], int size){
    int i, female = 0;
    for(i = 0; i < size; i++){
        if(gender[i] == 'F'){
            female++;
        }
    }
    return female;
}

/**
    Makes some calculus with the height of people
    
    Input example:

    1.50 F
    1.55 F
    1.60 F
    1.65 M
    1.70 F
    1.70 M
    1.75 M
    1.80 M
    1.90 M
    2.00 M

*/
void ex05(){
    const int NUMBER_OF_PEOPLE = 10;
    char gender[NUMBER_OF_PEOPLE];
    float height[NUMBER_OF_PEOPLE];

    printf("Enter people height and gender:\n");

    int i;
    for(i = 0; i < NUMBER_OF_PEOPLE; i++){
        scanf("%f %c", &height[i], &gender[i]);
    }

    int highest = max_height_position(height, NUMBER_OF_PEOPLE);
    int smallest = min_height_position(height, NUMBER_OF_PEOPLE);
    printf("Higher height: %.2f; Gender: %c\n", height[highest], gender[highest]);
    printf("Smaller height: %.2f; Gender: %c\n", height[smallest], gender[smallest]);

    printf("Male average height: %.2f\n", male_average_height(height, gender, NUMBER_OF_PEOPLE));
    printf("Female average height: %.2f\n", female_average_height(height, gender, NUMBER_OF_PEOPLE));

    printf("Number of men: %d\n", number_of_male(gender, NUMBER_OF_PEOPLE));
    printf("Number of women: %d\n", number_of_female(gender, NUMBER_OF_PEOPLE));
}

/**
    Handles characters of a phone number.
*/
void ex06(){
    const int size = 9;
    char phone[size-1];
    char new_phone[size+1];
    int number_of_digits = 0;

    printf("Enter phone number: ");
    fgets(phone, size+1, stdin);

    for(int i = 0; i < size; i++){
        if(phone[i] >= 48 && phone[i] <= 57){
            number_of_digits++;
        }
    }

    int j = 0; // new_vector index
    int hifen_position = 4; // 3999[-]9999 (hifen position)

    if(number_of_digits == 7){ // has no hifen
        new_phone[j++] = '3'; // adds digit 3 at the first hifen_position
        hifen_position = 3; // hifen position is index 3 (999[-]9999)
    }

    if(phone[hifen_position] != '-'){ // there is no hifen lile 999-9999
        new_phone[4] = '-';
        for(int i = 0; i < size; i++, j++){
            if(j == 4){
                j++;
            }
            new_phone[j] = phone[i];
        }        
    }
    else{ // there is hifen, so we just copy values
        for(int i = 0; i < size; i++, j++){
            new_phone[j] = phone[i];
        }    
    }

    printf("Phone number after verification: ");
    for(int i = 0; i < size; i++){
        putchar(new_phone[i]);
    }
    putchar('\n');
}