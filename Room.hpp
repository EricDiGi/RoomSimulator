#ifndef Room_H
#define Room_H
#include "Seat.hpp"

using namespace std;

class Room{
	private:
		Seat** seats;
		int rows;
		int cols;
	
	public:
		Room();
		Room(int n, int m);
		~Room();
		bool BookSeat(int i, int j);
		bool FreeSeat(int i, int j);
		bool ShrinkRoom(int n, int m);
		double Occupancy();
		
		friend ostream &operator<< (ostream &out, const Room &r){
			//cout << "{";
			bool op;
			for(int y = 0; y < r.rows; y++){
				//cout << "(";
				for(int x = 0; x < r.cols; x++){
					op = r.seats[y][x].GetStatus();
					char c = op ? 'x' : 'o';
					out << c << " ";
				}
				//if(y != r.rows - 1)
					out << endl;
			}
			return out;
		}
};

#endif
