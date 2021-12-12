#include <stdio.h>
#include <stdlib.h>
#include<time.h>

const char arr[3] = {'r', 'p', 's'};

int machine_rand(void) {
    srand(time(0));
    int machine_chose = rand() % 3;
    return machine_chose;
}

// Rock vs Paper -> Paper wins.
// Rock vs Scissor -> Rock wins.
// Paper vs Scissor -> Scissor wins.

// 0 - machine_wins
// 1 - user_wins

int start_game(char input_user, char *machine_choice){
    int machine_chose  = machine_rand();
    *machine_choice = arr[machine_chose];
    int result;
    if(input_user == arr[machine_chose])
    {
        result = -1;
    }
    else if (input_user == 'r' && arr[machine_chose] == 's')
    {
        result = 1;
    }
    else if (arr[machine_chose] == 'r' && input_user == 's')
    {
        result = 0;
    }
    else if (input_user == 'p' && arr[machine_chose] == 'r')
    {
        result = 1;
    }
    else if (arr[machine_chose] == 'p' && input_user == 'r')
    {
        result = 0;
    }
    else if (input_user == 's' && arr[machine_chose] == 'p')
    {
        result =  1;
    }
    else if (arr[machine_chose] == 's' && input_user == 'p')
    {
        result =  0;
    }

    return result;
}


int main () {
    char input_from_user, machine_chose;
    int result;
    printf("Please choose: rock (r) - paper (p) - scissors (s)\n");
    scanf("%c", &input_from_user);
    result = start_game(input_from_user, &machine_chose);
    // printf("THE machine_choice = %c", machine_chose);
    if(result == -1)
    {
        printf("\nthe Friendship wins !! \n");
    }
    else if (result == 0)
    {
        printf("\nYou chose %c and I choose %c, HAHAHAH Machine wins \n\n", input_from_user, machine_chose);
    }
    else
    {
        printf("\nYou chose %c and I choose %c, You wins \n\n", input_from_user, machine_chose);
    }
}