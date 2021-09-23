#ifndef _UTILS_H
#define _UTILS_H
#include "doublylinked.cpp"
bool binarySearch(const List<int> &list, const int searchTerm);
bool sequentialSearch(const List<int> &list, const int searchTerm);
void loadSortedList(List<int> &list);
void loadRandomList(List<int> &list);

#endif
