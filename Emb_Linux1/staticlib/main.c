#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Includes/add.h"
#include "Includes/divide.h"
#include "Includes/modulus.h"
#include "Includes/multiply.h"
#include "Includes/subtract.h"

int modulo(int dividend, int divisor);
float multiply(float num1, float num2);
float subtract(float num1, float num2);
float divide(float n1,float n2);
float sum(float num1 , float num2);


int main() {

	float input1,input2,result=0.0;
	int num1,num2;
	int op;
	printf("choose the operation:\n1)sum \n2)sub \n3)multiply \n4)divide \n5)modulus");
	scanf("%d",&op);
	if(op==5){
	   scanf("%f %f",&num1,&num2);
	}
	else if(op<5)
	{
           scanf("%f %f",&input1,&input2);
	}
	else{
		printf("invalid input");
	}
	
	switch(op){
	case 1:
		result =sum(input1,input2);
		break;
	case 2:
		result =subtract(input1,input2);
		break;

	case 3:
		result =multiply(input1,input2);
		break;

	case 4:
		result =divide(input1,input2);
		break;

	case 5:
		result = modulo(num1,num2);
		break;

	default:
		printf("invalid input");
		break;
	}

	printf("%f",result);
    return 0;
}
