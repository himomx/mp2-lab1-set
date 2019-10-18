// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП

//

// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001

// Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)

//

// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)

{

	if (mp > -1) {

		MaxPower = mp;

	}

	else throw - 1;

}

// конструктор копирования

TSet::TSet(const TSet &s) : BitField(s.BitField)

{

	if (s.MaxPower > -1) {

		MaxPower = s.MaxPower;

	}

	else throw - 1;

}

// конструктор преобразования типа

TSet::TSet(const TBitField &bf) : BitField(bf.GetLength())

{

	MaxPower = bf.GetLength();

	BitField = bf;

}

TSet::operator TBitField()

{

	return BitField;

}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов

{

	return MaxPower;

}

int TSet::IsMember(const int Elem) const // элемент множества? ELEM - НОМЕР БИТА

{

	if (BitField.GetBit(Elem) == 0) return 0;

	else return 1;

}

void TSet::InsElem(const int Elem) // включение элемента множества

{

	BitField.SetBit(Elem);

}

void TSet::DelElem(const int Elem) // исключение элемента множества

{

	BitField.ClrBit(Elem);

}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание

{

	if (this == &s) {

		return *this;

	}

	else {

		MaxPower = s.MaxPower;

		BitField = s.BitField;

		return *this;

	}

}

int TSet::operator==(const TSet &s) const // сравнение

{

	if (MaxPower != s.MaxPower) {

		return 0;

	}

	else if (BitField != s.BitField) {

		return 0;

	}

	else return 1;

}

int TSet::operator!=(const TSet &s) const // сравнение

{

	return !(*this == s);

}

TSet TSet::operator+(const TSet &s) // объединение

{

	if (s.MaxPower > MaxPower) MaxPower = s.MaxPower;

	TSet result(MaxPower);

	result.BitField = BitField | s.BitField;

	return result;

}

TSet TSet::operator+(const int Elem) // объединение с элементом

{

	TSet res(*this);

	res.BitField.SetBit(Elem);

	return res;

}

TSet TSet::operator-(const int Elem) // разность с элементом

{

	return *this;

}

TSet TSet::operator*(const TSet &s) // пересечение

{

	TSet result(BitField & s.BitField);

	return result;

}

TSet TSet::operator~(void) // дополнение

{

	TSet result(~BitField);

	return result;

}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод

{

	istr >> s.BitField;

	return istr;

}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод

{

	ostr << s.BitField;

	return ostr;

}