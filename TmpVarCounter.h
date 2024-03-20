#pragma once
#include <unordered_map>
#include <string>

#define __USE_FUNCDNAME__
#ifndef __USE_FUNCDNAME__
#define __CLASS_INFO \
inline static char* __this() { \
	int Len = sizeof(__FUNCDNAME__) - sizeof("__this_4@@SAPEADFv"); \
	char* p = new char[Len + 1]; \
	char* rp = p; \
	int i = 0; \
	while (i < Len) { *(p++) = __FUNCDNAME__[sizeof("__this_") + i]; i++; }; \
		* p = '\0'; \
		return rp; \
		return (char*)__FUNCDNAME__; \
}\
struct __class {\
	\
		char* pName = __this(); \
		~__class() { delete[]pName; }\
}__class;
#else
#define __CLASS_INFO \
inline static char* __this() {\
	return (char*)__FUNCDNAME__; \
}\
struct __class {\
				char* pName = __this(); \
		}__class;
#endif
#define __CLASS_NAME __class.pName

#define Counter __CLASS_INFO \
TmpVarCounter __TmpVarCounter = TmpVarCounter(__CLASS_NAME);
#define Counter_Get __TmpVarCounter.getcount()
#define Counter_GetAccumulator __TmpVarCounter.getaccumulator()


class TmpVarCounter
{
	static std::unordered_map <void*, char*> __TmpVarCounter_ptrs;
	static std::unordered_map <std::string, size_t> __TmpVarCounter_class_count;
	static std::unordered_map <std::string, size_t> __TmpVarCounter_class_accumulator;
	char* class_name;
	public:
		TmpVarCounter(char* class_) {
			__TmpVarCounter_ptrs[(void*)this] = class_;
			if (__TmpVarCounter_class_count.find((std::string)class_) == __TmpVarCounter_class_count.end()) {
				__TmpVarCounter_class_count[(std::string)class_] = 1;
				__TmpVarCounter_class_accumulator[(std::string)class_] = 1;
			}
			else {
				__TmpVarCounter_class_count[(std::string)class_]++;
				__TmpVarCounter_class_accumulator[(std::string)class_]++;
			}
			class_name = class_;
		}
		~TmpVarCounter() {
			__TmpVarCounter_ptrs.erase((void*)this);size_t c = __TmpVarCounter_class_count[(std::string)class_name]--;
			if (c <= 1) __TmpVarCounter_class_count.erase((std::string)class_name);
		}
		size_t getcount() { 
			if(__TmpVarCounter_class_count.find((std::string)class_name) == __TmpVarCounter_class_count.end()) return 0;
			return __TmpVarCounter_class_count[(std::string)class_name];
		}
		size_t getaccumulator() {
			if (__TmpVarCounter_class_accumulator.find((std::string)class_name) == __TmpVarCounter_class_accumulator.end()) return 0;
			return __TmpVarCounter_class_accumulator[(std::string)class_name];
		}
		static size_t getcount(char* class_) {
			if (__TmpVarCounter_class_count.find((std::string)class_) == __TmpVarCounter_class_count.end()) return 0;
			return __TmpVarCounter_class_count[(std::string)class_];
		}
		static size_t getaccumulator(char* class_) {
			if (__TmpVarCounter_class_accumulator.find((std::string)class_) == __TmpVarCounter_class_accumulator.end()) return 0;
			return __TmpVarCounter_class_accumulator[(std::string)class_];
		}

};
#ifndef __TmpVarCounter__
#define __TmpVarCounter__
std::unordered_map <void*, char*> TmpVarCounter::__TmpVarCounter_ptrs{};
std::unordered_map <std::string, size_t> TmpVarCounter::__TmpVarCounter_class_count{};
std::unordered_map <std::string, size_t> TmpVarCounter::__TmpVarCounter_class_accumulator{};
#else
extern std::unordered_map <void*, char*> TmpVarCounter::__TmpVarCounter_ptrs{};
extern std::unordered_map <std::string, size_t> TmpVarCounter::__TmpVarCounter_class_count{};
extern std::unordered_map <std::string, size_t> TmpVarCounter::__TmpVarCounter_class_accumulator{};
#endif // !__TmpVarCounter__

