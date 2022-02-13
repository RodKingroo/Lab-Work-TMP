#pragma once
class Pet {

public:
	virtual char* getName() const = 0;
	virtual void setName(const char* name) = 0; 
	virtual void play() = 0;

};

