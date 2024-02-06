#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "vector.h"

using namespace std;

bool vector_find(vector<string> vec, string value) {
	return std::find(vec.begin(), vec.end(), value) != vec.end();
}