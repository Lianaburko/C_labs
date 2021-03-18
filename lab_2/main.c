#include <stdio.h>
#include <math.h>
#include "main.h"

int Checking_input(int day, int month, int year){
    if (year < 0 || day <= 0 || month <= 0) {
        printf("Years, days, monthes can't be negative\n");
        return 0;
    }
    if (month > 12){
        printf("Wrong month\n");
        return 0;  
    }
    if (month == 2){ 
        if (year % 4 == 0){
            if (day <=29){
                return 1;
            }
            else {
                printf("Wrong amout of days in your data\n");
                return 0;
            }
        }
        else {
            if (day <=28) {
                return 1;
            }
            else {
                printf("Wrong amout of days in your data\n");
                return 0;
            }
        }
    }         
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if (day <= 31) {
            return 1;
        }
        else {
            printf("Wrong amout of days in your data\n");
            return 0;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day <= 30) {
            return 1;
        }
        else {
            printf("Wrong amout of days in your data\n");
            return 0;
        }
    }          
}

void Data_in_the_format_DDMMYY(int day, int month, int year){
    int year_yy = year%100;
    if (year_yy < 10) {
        if (month < 10 && day < 10){
            printf("input is 0%d.0%d.0%d.\n", day, month, year_yy);
        }
        if (month < 10 && day >= 10){
            printf("input is %d.0%d.0%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day >= 10){
            printf("input is %d.%d.0%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day < 10){
            printf("input is 0%d.%d.0%d.\n", day, month, year_yy);
        }
    }
    else {
        if (month < 10 && day < 10){
            printf("input is 0%d.0%d.%d.\n", day, month, year_yy);
        }
        if (month < 10 && day >= 10){
            printf("input is %d.0%d.%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day >= 10){
            printf("input is %d.%d.%d.\n", day, month, year_yy);
        }
        if (month >= 10 && day < 10){
            printf("input is 0%d.%d.%d.\n", day, month, year_yy);
        }
    }
}

void Data_by_words(int day, int month, int year){
    switch (month){
        case 1: 
            printf ("input is %d january %d y.\n", day, year); 
            break;
        case 2:  
            printf ("input is %d february %d y.\n", day, year); 
            break;
        case 3:  
            printf ("input is %d march %d y.\n", day, year); 
            break;
        case 4:  
            printf ("input is %d april %d y.\n", day, year); 
            break;
        case 5:  
            printf ("input is %d may %d y.\n", day, year); 
            break;
        case 6:  
            printf ("input is %d june %d y.\n", day, year); 
            break;
        case 7:  
            printf ("input is %d july %d y.\n", day, year);
            break;
        case 8:  
            printf ("input is %d augast %d y.\n", day, year); 
            break;
        case 9:  
            printf ("input is %d september %d y.\n", day, year);
            break;
        case 10:  
            printf ("input is %d october %d y.\n", day, year); 
            break;
        case 11:  
            printf ("input is %d november %d y.\n", day, year); 
            break;
        case 12:  
            printf ("input is %d december %d y.\n", day, year); 
            break;
    }
}

int Amount_of_days_after_Criest(int day, int month, int year){
    int total_sum;
    total_sum = year/4 * 366 + (year-year/4)*365;
    int i;
    for (i = 0; i < month; i++){
        if (i == 2){
            if (year%4==0){
                total_sum+=29;
            }
            else{
                total_sum+=28;
            }     
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            total_sum+=31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) {
          total_sum+=30;
        }
    }   

    total_sum += day;
    return total_sum;
}

int Ordinal_number_in_the_year(int day, int month, int year){
    int sum = 0;
    int i;
    for (i = 0; i < month; i++){
        if (i == 2){
            if (year % 4==0){
               sum += 29;
            }
            else {
                sum += 28;
            }     
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            sum += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            sum += 30;
        }
    }   
    sum+=day;
    return sum;
}

void Day_of_the_week(int day, int month, int year){
    int date1 = Amount_of_days_after_Criest(15, 3, 2021); /*Monday*/
    int date2 = Amount_of_days_after_Criest(day, month, year);
    int difference = (date1 - date2);
    difference = (difference % 7 + 7) % 7;
    switch(difference){
        case 0: 
            printf("Monday\n");
            break;   
        case 1: 
            printf("Sunday\n");
            break;
        case 2: 
            printf("Sutarday\n");
            break;
        case 3: 
            printf("Friday\n");
            break;
        case 4: 
            printf("Thursday\n");
            break;
        case 5: 
            printf("Wednesday\n");
            break;
        case 6: 
            printf("Tuesday\n");
            break;
        default:
            printf("Something goes wrong :(((\n");
            break;
    }

}

int main(void) {
    printf("Enter a number of operation, that you want to execute");
    printf("\n1 - to enter a data");
    printf("\n2 - get the data in the format DD.MM.YY.");
    printf("\n3 - get the data in the format 1 january 2010 y.");
    printf("\n4 - the ordinal number in the year and the day of the week");
    printf("\n5 - days, that had passed before Christ");
    printf("\n6 - get information about the auther");
    printf("\n7 - to leave a programm\n");

    int my_case;
    int day = 0, month = 0, year = 0;
    int bool_check = 1;
    while(bool_check == 1){
        scanf("%d", &my_case);
        switch (my_case) {
            case 1: 
                printf("Enter a day, a month, a year, use format DD,MM,YYYY\n");
                while (scanf("%d,%d,%d", &day, &month, &year) != 3 || Checking_input(day, month, year) == 0) {
                    printf ("incorrect input\n");
                    while (getchar()!= '\n'){
                    }
                }
                printf("Input is correct, choose the other operation\n");
                break;  
            case 2: 
                if (day > 0){
                    Data_in_the_format_DDMMYY(day, month, year);
                }
                else{
                    printf("firstly, you must do point 1\n");
                }      
                break;  
            case 3: 
                if (day > 0){
                    Data_by_words(day, month, year);
                }
                else{
                    printf("firstly, you must do point 1\n");
                }  
                break;  
            case 4: 
                if (day > 0){
                    int sum = Ordinal_number_in_the_year(day, month, year);
                    printf("The ordinal number of the day is %d\nthe day of the week is ", sum);
                    Day_of_the_week(day, month, year);
                }
                else{
                    printf("firstly, you must do point 1\n");
                }     
                break; 
            case 5: 
                if (day > 0){
                    int sum = Amount_of_days_after_Criest(day, month, year);
                    printf("Amount of the days, that passed after Criest is %d days\n", sum);
                }
                else{
                    printf("firstly, you must do point 1\n");
                }    
                break;  
            case 6: 
                printf("Program was created by Liana Burko, student of group 053501\n");
                break;  
            case 7: 
                bool_check = 0;
                break;  
            default: 
                printf("Choose another input");
                rewind(stdin);
                break;
        }
    }
    return 0;
}