/*
	Header file containing all the enums of the game status
*/

#pragma once


enum class EWordStatus
{
	OK,
	Not_Isogram,
	Not_Lowercase,
	To_Short,
	To_Long
};

enum class EResetStatus
{
	OK,
	No_Hidden_Word
};