#ifndef _HPM_ENTRIES_H_
#define _HPM_ENTRIES_H_ 1

enum MethodEntry
{
	HPM_Vec4Copy,
};
typedef struct hpm_callback_entry_t
{
	enum MethodEntry id;
	void *callback;
} HpmCallBackEntry;

#endif
