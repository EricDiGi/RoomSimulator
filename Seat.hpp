#ifndef Seat_H
#define Seat_H

class Seat{
	private:
		bool status;
	
	public:
		Seat();
		Seat(bool status);
		bool GetStatus();
		bool Book();
		bool Free();
	
};

#endif
