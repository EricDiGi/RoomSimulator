#include <iostream>
#include "Room.hpp"
#include "Seat.hpp"

using namespace std;

Room::Room(){
	rows = 3;
	cols = 3;
	this->seats = new Seat*[rows];
	for(int h = 0; h < rows; h++){
		this->seats[h] = new Seat[cols];
		for(int w = 0; w < cols; w++)
			this->seats[h][w] = Seat(false);
	}
}

Room::Room(int n, int m){
	this->rows = n;
	this->cols = m;
	this->seats = new Seat*[m];
	for(int h = 0; h < n; h++){
		this->seats[h] = new Seat[n];
		for(int w = 0; w < m; w++)
			this->seats[h][w] = Seat(false);
	}
	//cout << this->seats[0][0].GetStatus() << endl;
} 

Room::~Room(){
	//cout << "Room destructor activated" << endl;
	for(int h = 0; h < this->rows; h++)
		delete[] this->seats[h];
	delete [] this->seats;
	//cout << "deleted" << endl;
}

bool Room::BookSeat(int i, int j){
	if((i >= this->rows || j >= this->cols) || (i < 0 || j < 0))
		return false;
	return this->seats[i][j].Book(); //Should return same vals as Book
}

bool Room::FreeSeat(int i, int j){
	if((i >= this->rows || j >= this->cols) || (i < 0 || j < 0))
		return false;
	return this->seats[i][j].Free();
}

bool Room::ShrinkRoom(int n, int m){
	bool W = n <= this->rows && n > 0;
	bool H = m <= this->cols && m > 0;
	bool cont = H && W;
	bool v;
	if(cont){
		Seat** temp = new Seat*[n];
		for(int y = 0; y < n; y++){
			temp[y] = new Seat[m];
			for(int x = 0; x < m; x++){
				v = this->seats[y][x].GetStatus();
				temp[y][x] = Seat(v);
			}
		}
		for(int h = 0; h < this->rows; h++)
			delete[] this->seats[h];
		delete [] this->seats;
		this->rows = n;
		this->cols = m;
		this->seats = temp;
		return true;
	}
	return false;
}

double Room::Occupancy(){
	double n = 0.0;
	double mass = this->rows * this->cols;
	for(int h = 0; h < this->rows; h++){
		for(int w = 0; w < this->cols; w++)
			n +=  double(this->seats[h][w].GetStatus());
	}
	return n/mass;
}
