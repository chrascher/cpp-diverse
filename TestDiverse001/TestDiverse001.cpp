// TestDiverse001.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>


using namespace std; 

struct bits {
  unsigned bit0 : 1,
           bit1 : 1,
           bit2 : 1,
           bit3 : 1,
           bit4 : 1,
           bit5 : 1,
           bit6 : 1,
           bit7 : 1,
           bit8 : 1,
           bit9 : 1,
           bit10 : 1,
           bit11 : 1,
           bit12 : 1,
           bit13 : 1,
           bit14 : 1,
		   bit15 : 1;
};

struct mehrerBits {

	unsigned schriftart : 4;	// 16 Schriftarten
	unsigned variableb : 4;	// 16 Schriftarten
	unsigned vielebits : 32;	// 33 is not poissbile becouase size woud be greater then unsinged int 
}; 


union intorbit {
	 unsigned int a;
	 bits b; 
};



enum DataType { 
	INTEGER, 
	FLOAT_POINT, 
	STRING 
};



union DataValue {

    int v_int;
    float v_float;
    char v_string;
} ;



struct DataNode {

    DataType type;
    DataValue value;
}; 

DataType read_some_input(long long * temp) {

	*temp = 4711; 

	return DataType::STRING; 

}


void printDataNode(DataNode* ptr)
{
   printf("I am a ");
   switch(ptr->type){
	   case DataType::INTEGER: 
		   printf("Integer with value %d", ptr->value.v_int); 
			break;
	   case DataType::FLOAT_POINT: 
		   printf("Float with value %f", ptr->value.v_float); 
			break;
	   case DataType::STRING: 
		   printf("String with value %s", ptr->value.v_string); 
		   break;
   }
}

void myfunct() {

    long long temp;       // at least 64 bit
    DataNode inputData;

    inputData.type= read_some_input(&temp);

    switch(inputData.type) {

		case DataType::INTEGER: 
				inputData.value.v_int = (int)temp; 
				break;
		case DataType::FLOAT_POINT: 
				inputData.value.v_float = (float)temp; 
				break;
		case DataType::STRING: 
				inputData.value.v_string = (char)temp; 
				break;
    }

	printDataNode( &inputData); 

}

void main() {


	DataValue unionExample; 

	unionExample.v_int = 4707;
	unionExample.v_string = 'c'; 

	std::cout << "value string: " << unionExample.v_string << std::endl; 

	int a = unionExample.v_int; 
	std::cout << "value int: " <<  a << std::endl; 

	float asFloat = unionExample.v_float; 
	std::cout << "value as float: " <<  asFloat << std::endl; 


	// 
	// Beispiel 2 union mit int oder bit feld 
	// 
	intorbit dd; 

	dd.a = 4;
	dd.b.bit1 = 1 ; 
	cout << dd.b.bit0 << dd.b.bit1 << dd.b.bit2 << endl; 

	cout << dd.a << endl; 

	// overflow example 
	
	mehrerBits mbits;

	mbits.variableb = 0; 
	mbits.schriftart = 18 ; 

	std::cout << "value schriftart: " <<  mbits.schriftart << std::endl; 

	mehrerBits * pMbits = &mbits; 


	// call examples :: 

	myfunct(); 


	return;
}















/*

	a = unionExample.v_int = 4711;
	std::cout << "value int: " <<  a << std::endl; 


*/