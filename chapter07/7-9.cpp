// 7.9 Explain the data structures and algorithms that you would use to design 
//     an in-meomry file system. Illustrate with an example in code where 
//     possbile.


// Solution

// For data block allocation, we can use bitmask vector and linear search ( see
// "Practical File System Design") or B+ trees (see Wikipedia).

// You should definitely check those out!
// 

struct DataBlock { char data[DATA_BLOCK_SIZE]; };
DataBlock data_blocks[NUM_DATA_BLOCKS];
struct INode { std::vector<int> data_blocks_vec; };
struct MetaData
{
	int size;
	Date last_modified;
	Date created;
	char extra_attributes;
};
std::vector<bool> data_block_used(NUM_DATA_BLOCKS);
std::map<string, INode*> map_from_name;
struct FSBase;
struct File : pulic FSBase
{
private:
	std::vector<INode> * nodes;
	MetaData meta_data;
};

struct Directory : public FSBase
{
	std::<vector<FSBase*> content;
};

struct FileSystem
{
	init();
	mount(FileSystem*);
	unmount(FileSystem*);
	File create_file(const char* name) { /* ... */ }
	Directory create_directory(const char* name) { /* ... */ }
	// map_from_name to find the INode corresponding to file
	void open_file(File* file, FileMode mode) { /* ... */ }
	void close_file(File* file) { /* ... */ }
	void write_to_file(File* file, void* data, int num) { /* ... */ }
	void read_from_file(File* file, void* res, int numbytes, int position) 
		{ /* ... */ }
};



































