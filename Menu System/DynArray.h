#pragma once

using namespace std;

template<class T>
class DynArray
{
private:
	T * array;
	unsigned int Size, Capacity;

public:
	/////////////////////////////////////////////////////////////////////////////
	// Function :	Constructor
	// Notes : Constructs an empty array (Size 0 Capacity 0)
	/////////////////////////////////////////////////////////////////////////////
	DynArray()
	{
		array = nullptr;
		Size = 0;
		Capacity = 0;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function :	Destructor
	// Notes : cleans up any dynamic memory
	/////////////////////////////////////////////////////////////////////////////
	~DynArray()
	{
		delete[] array;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function :	Copy Constructor
	/////////////////////////////////////////////////////////////////////////////
	DynArray(const DynArray<T>& that)
	{
		Size = that.Size;
		Capacity = that.capacity();
		array = new T[Capacity];

		for (unsigned int i = 0; i < size(); ++i)
		{
			array[i] = that[i];
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function :	Assignment Operator
	/////////////////////////////////////////////////////////////////////////////
	DynArray<T>& operator=(const DynArray<T>& that)
	{
		if (&array != &that.array)
		{
			Size = that.Size;
			Capacity = that.capacity();
			delete[] array;
			array = new T[Capacity];
			for (unsigned int i = 0; i < size(); ++i)
			{
				array[i] = that[i];
			}
		}
		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : operator[]
	// Parameters : index - the index to access
	// Return : Type & - returns the array element at [index]
	// Notes : performs no error checking. user should ensure index is 
	//		valid with the size() method
	/////////////////////////////////////////////////////////////////////////////
	T& operator[](const unsigned int index)
	{
		return array[index];
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : operator[]
	// Parameters : index - the index to access
	// Return : const Type & - returns the array element at [index]
	// Notes : performs no error checking. user should ensure index is 
	//		valid with the size() method
	/////////////////////////////////////////////////////////////////////////////
	const T& operator[](const unsigned int index) const
	{
		return array[index];
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function :	size
	// Returns : int - returns the number of items being stored
	// Notes : this function returns the number of items being stored, 
	/////////////////////////////////////////////////////////////////////////////
	unsigned int size() const
	{
		return Size;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : capacity
	// Returns : int - returns the number of items the array can store before 
	//		the next resize
	// Notes : this function returns the number of items the array can store, 
	//		not the number of bytes
	/////////////////////////////////////////////////////////////////////////////
	unsigned int capacity() const
	{
		return Capacity;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function :	clear
	// Notes : cleans up any dynamic memory and resets size and capacity to 0
	/////////////////////////////////////////////////////////////////////////////
	void clear()
	{
		delete[] array;
		array = nullptr;
		Size = 0;
		Capacity = 0;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : append
	// Parameters : item - the item to be appended to the next open spot
	// Notes : this function will append the item to the next open spot. if 
	//		no room exists, the array's capacity will be doubled and then 
	//		the item will be added
	/////////////////////////////////////////////////////////////////////////////
	void append(const T& item)
	{
		if (size() == capacity())
		{
			reserve();
		}
		array[Size] = item;
		Size++;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : reserve
	// Parameters : newCap - the new capacity
	// Notes : 	- default parameter - reserve more space in the array, based on
	//		the expansion rate (100%, 1 minimum).
	//		- non-default parameter, expand to the specified capacity
	//		- if newCap is LESS than the current capacity, do nothing. 
	//		This function should NOT make the array smaller.
	/////////////////////////////////////////////////////////////////////////////
	void reserve(const unsigned int & newCap = 0)
	{
		if (newCap == 0)
		{
			if (capacity() == 0)
			{
				Capacity += 1;
			}
			else
			{
				Capacity *= 2;
			}
		}
		else if (newCap > capacity())
		{
			Capacity = newCap;
		}
		else
			return;

		T *temp = new T[Capacity];

		for (unsigned int i = 0; i < size(); ++i)
		{
			temp[i] = array[i];
		}

		delete[] array;

		array = temp;

	}
	/////////////////////////////////////////////////////////////////////////////
	// Function :	insert
	// Parameters : val - the value to insert
	//		   index - the index to insert at
	// Notes : if the array is full, this function should expand the array at 
	//		the default expansion rate (double the capacity, 1 minimum)
	/////////////////////////////////////////////////////////////////////////////
	void insert(const T val, const unsigned int index)
	{
		if (size() == capacity())
			reserve();
		else
			array[index] = val;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function :	insert
	// Parameters : val - the items to insert
	//		   n - the number of items to insert
	//		   index - the index to insert at
	// Notes : if the array is full, this function should expand the array at 
	//		the default expansion rate (double the capacity, 1 minimum) 
	//		before inserting
	/////////////////////////////////////////////////////////////////////////////
	void insert(const T * val, const unsigned int n, const unsigned int index)
	{
		if (size() == capacity())
			reserve(n);
		else
			array[index] = *val;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function :	remove
	// Parameters : index - the index to remove from
	// Notes : this function removes one item from the specified index
	/////////////////////////////////////////////////////////////////////////////
	void remove(const unsigned int index)
	{
		for (unsigned int i = index + 1; i < size(); ++i)
		{
			array[i - 1] = array[i];
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function :	remove
	// Parameters : index - the index to remove from
	//		   n - the number of items to remove
	// Notes : this function removes multiple items from the specified index
	/////////////////////////////////////////////////////////////////////////////
	void remove(const unsigned int index, const unsigned int n)
	{
		unsigned int counter = 0;
		while (counter != n)
		{
			for (unsigned int i = index + 1; i < size(); ++i)
			{
				array[i - 1] = array[i];
			}
			counter++;
		}
	}
};

