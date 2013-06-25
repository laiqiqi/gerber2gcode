/*
 * Cords.h
 *
 *  Created on: 25.06.2013
 *      Author: smeat
 */

#ifndef CORDS_H_
#define CORDS_H_

#include <cmath>

class Cords {
private:
	float _x, _y;
	bool _inInch;

public:
	Cords(float x, float y, bool inch);
	Cords();
	virtual ~Cords();

	//TODO: make gcode in inch
	void inchToMM();
	float getLength() const;
	float getDistance(const Cords& ob) const;
	
	float getX(){
		return _x;
	}
	
	float getY(){
		return _y;
	}











	//Operators

	bool operator==(const Cords& b) const{
		return ((_x == b._x) && (_y == b._y));
	}
	
	//Why do I need this function??
	bool operator!=(const Cords&b) const{
		return !(*this == b);
	}

	Cords& operator=(const Cords& b){
		_x = b._x;
		_y = b._y;
		return *this;
	}

	friend Cords operator+(const Cords& a, const Cords& b){
		Cords temp;
		temp._x = a._x + b._x;
		temp._y = a._y + b._y;

		return temp;
	}

	Cords& operator+=(const Cords&b){
		this->_x += b._x;
		this->_y += b._y;

		return *this;
	}

	Cords& operator-=(const Cords&b){
		this->_x -= b._x;
		this->_y -= b._y;

		return *this;
	}

	Cords& operator*=(const Cords&b){
		this->_x *= b._x;
		this->_y *= b._y;

		return *this;
	}

	Cords& operator*=(const float b){
		this->_x *= b;
		this->_y *= b;

		return *this;
	}

	friend Cords operator*(const Cords& a, const Cords& b){
		Cords temp;
		temp._x = a._x * b._x;
		temp._y = a._y * b._y;
		return temp;
	}
	
	friend Cords operator*(const Cords& a, const float b){
		Cords temp;
		temp._x = a._x * b;
		temp._y = a._y * b;
		return temp;
	}


	friend Cords operator-(const Cords& a, const Cords& b){
		Cords temp;
		temp._x = a._x - b._x;
		temp._y = a._y - b._y;
		return temp;
	}
};

#endif /* CORDS_H_ */
