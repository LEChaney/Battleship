#pragma once

#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "BoardSquare.h"

class CShip
{
public:
	enum EORIENTATION
	{
		HORIZONTAL,
		VERTICAL,
		NOT_PLACED
	};

	enum ETYPE
	{
		PATROL_BOAT,
		SUBMARINE,
		DESTROYER,
		BATTLESHIP,
		AIRCRAFT_CARRIER
	};

	CShip(ETYPE);
	~CShip();

	void AddOccupiedSquare(CBoardSquare * const);
	size_t GetLength() const;
	ETYPE GetType() const;
	EORIENTATION GetOrientation() const;
	void SetOrientation(EORIENTATION);

	// Check if all parts of the ship have been hit
	bool IsDestroyed() const;

	// Return the vector of board square pointers occupied by the ship
	std::vector<CBoardSquare * const> GetOccupiedSquares() const;

private:
	std::vector<CBoardSquare * const> m_vecpOccupiedSquares;
	size_t m_szLength;
	mutable bool m_bIsDestroyed; // Cache variable
	EORIENTATION m_eOrientation;
	const ETYPE m_keTYPE;
};

#endif // SHIP_H