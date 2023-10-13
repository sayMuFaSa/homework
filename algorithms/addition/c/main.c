#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct number{
	unsigned char digits[MAX_LENGTH];
	int length;
} number ;


void add(number* num1, number* num2, number* the_sum);


void assign_to(number* target, const char* my_number);

void stringify(number* target, char* buffer);

int main(void){
	number first_number, second_number, our_sum;
	char buffer[MAX_LENGTH];

	assign_to(&first_number, "2000000");
	assign_to(&second_number, "9000000");

	add(&first_number, &second_number, &our_sum);

	stringify(&our_sum, buffer);

	printf("Sum is equal to %s", buffer);


}

void assign_to(number* target, const char* my_num){

	memset(target->digits, 0, MAX_LENGTH);
	target->length = strlen(my_num);

	for(int i = 0; i < target->length; i++){
		target->digits[target->length - 1 - i] = my_num[i] - 48;
	}
}

void 
stringify(number* target, char* buffer)
{
	for (int i = 0; i < target->length; i++){
		buffer[i] = target->digits[target->length - i - 1] + 48;
	}
}



void add(number* num1, number* num2, number* the_sum){
	uint8_t carry = 0;
	int most = (num1->length > num2->length) ? num1->length : num2->length;

	for (int i = 0; i < most; i++){
		the_sum->digits[i] = carry + (num1->digits[i] + num2->digits[i]);
		carry = the_sum->digits[i] / 10;
		the_sum->digits[i] %= 10;
	}

	if(carry == 1){
		the_sum->digits[most] = 1;
		the_sum->length = most + 1;
		return;
	}

	the_sum->length = most;

}
