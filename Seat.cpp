#include <iostream>
#include <iomanip>

#include "Seat.hpp"

/*Seat passes Test Cases*/

using namespace std;


Seat::Seat(){
	this->status = false;
}

Seat::Seat(bool stat){
	this->status = stat;
}

bool Seat::GetStatus(){
	return this->status;
}

bool Seat::Book(){
	if(this->status == false){
		this->status = true;
		return true;
	}
	return false;
}

bool Seat::Free(){
	if(this->status == false){
		return false;
	}
	else{
		this->status = false;
		return true;
	}
}
