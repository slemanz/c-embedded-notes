/**********************************************************************************
*                                                                                 *
*                                 STRUCTURES                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// structures is a data structure used to create user-defined data types in c (allow
// us to combine data of different types)


// example of a structure
struct CarModel
{
	unsigned int carNumber;
	uint32_t     carPrice;
	uint16_t     carMaxSpeed;
	float		 carWeight;
};
// WARNING: structure definition doesn't consume any memory. its just a description
// or a record.

struct DataSet
{
	char  data1;
	int   data2;
	char  data3;
	short data4;
};

void displayMemberElements(struct DataSet *pData);

int main()
{	
	// memory will be consumed when you create structure variables:
	struct CarModel CarBMW = {2021, 15000, 220, 1330}; // C89: order is important
	struct CarModel CarFord = {.carNumber=4031, .carPrice=35000, .carMaxSpeed=160, .carWeight=1900.90}; // C99: order is NOT important

	// accessing structure member elements:
	// use a .(dot) operator to access the member elements

	printf("Details of car BMW:\n");
	printf("Number: %u\n",CarBMW.carNumber);
	printf("Price: %u\n",CarBMW.carPrice);
	printf("Max speed: %u\n",CarBMW.carMaxSpeed);
	printf("Weight: %.2f\n\n",CarBMW.carWeight);


	CarFord.carNumber = 4200;
	printf("Details of car Ford:\n");
	printf("Number: %u\n",CarFord.carNumber);
	printf("Price: %u\n",CarFord.carPrice);
	printf("Max speed: %u\n",CarFord.carMaxSpeed);
	printf("Weight: %.2f\n\n",CarFord.carWeight);


	// the size of a structure
	// car model: 4 + 4 + 4 + 2 =14 bytes (in theory)
	printf("the size of structure is %d\n", (int)sizeof(struct CarModel)); // but gives 16 bytes
	// why 16 bytes? because of the struct padding, this occour because the alligned data store!

	// to understand better:
	struct DataSet data;

	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	uint8_t *ptr;
	ptr = (uint8_t*)&data;
	uint32_t totalSize = sizeof(struct DataSet);

	printf("Memory adresss        Content \n");
	printf("==============================\n");

	for(uint32_t i = 0; i < totalSize; i++)
	{
		printf("%p        %X\n",ptr,*ptr);
		ptr++;
	}

	printf("Total memory consumed by this struct: %d\n\n", totalSize);
	// you can avoid padding with "__atribute__(packed)" but its not recommended


	// TYPEDEF AND STRUCT
	// you can create an alias name to the struct 
	typedef struct
	{
		unsigned int carNumber;
		uint32_t     carPrice;
		uint16_t 	 carMaxSpeed;
		float		 carWeight;
	}CarModel_t; // the _t stands for typedef! always use to know that is a typedef/alias

	CarModel_t carTest;
	carTest.carNumber = 3140;
	printf("Car test number: %d\n\n", carTest.carNumber);



	// STRUCTURE AND POINTERS
	// using "data" example

	uint8_t *ptr2 = (uint8_t*)&data;
	// modify the first element
	*ptr2 = 0x55; // not the best method

	// best method to do that:
	// create a pointer variable of the type of your struct
	struct DataSet *pData;
	pData = &data;
	pData->data1 = 0x55; // best
	// WARNING:
	// use dot (.) operator when you use structure variable of non pointer type
	// use arrow (->) operator when you use structure variable of pointer type

	// function and struct pointer example:
	displayMemberElements(&data);


	return 0;
}

void displayMemberElements(struct DataSet *pData)
{

	printf("data1 = 0x%X\n", pData->data1);
	printf("data2 = 0x%X\n", pData->data2);
	printf("data3 = 0x%X\n", pData->data3);
	printf("data4 = 0x%X\n", pData->data4);
}