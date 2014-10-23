// DB.h#pragma once/* The DB object encapsulates the idea of a set of DBRecords. The DB handles memory management, reading, writing, iteration, and basic selection and deletion operations on its DBRecords. Uses the PowerPlant LArray and TArray to do most of the work. Please see the handout for the discussion of the abstraction presented by the DB class.*/#include <TArray.h>/* Avoid including .h's in other .h's if possible. This file refers directly to a TArray through our "records" instance variable, so the #include is unavoidable.*/class DBRecord;/* Trick: the code in this file only refers to DBRecord*'s, so we can get away with this stub declration instead of the full #include.*/#include <iostream.h>	// needed since we refer to istream and ostreamclass DB {	public:		// Default constructor builds a DB with zero records	DB();	~DB();		// Any records in the database which contain the criteria	// have their selected bit set. Records which do not match	// are unaffected.	void Select(const DBRecord* criteria, bool oneIsSufficient = false);		// The number of records in the database	// Guaranteed to work on constant time.	int Count() const;		// The number of selected records in the database	// May take O(number of records) time.	int SelectedCount() const;		// Delete either: all the records, the selected records, or the	// unselected records. All of the memory is reclaimed.	enum DeleteOption { delete_Selected, delete_Unselected, delete_All };	void Delete(DeleteOption option = DB::delete_Selected);		// Change all the records to be unselected.	void ClearSelection();		// Read all of the records out of the stream, adding them	// as unselected records to the database	void Read(istream& in);		// Write either all of the records, or only the selected	// records to the stream.	void Write(ostream& out, bool selectedOnly = true) const;		private:		// The following implementation keeps the TArray literally inside	// the DB. Alternately, we could allocate the TArray in the heap.#pragma warn_hidevirtual off	// bypass some warnings the TArray causes	TArray<DBRecord*> records;#pragma warn_hidevirtual reset};