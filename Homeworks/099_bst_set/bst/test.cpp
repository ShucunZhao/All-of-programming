#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "bst.h"

int main() {
	Bst<int> bst1;
	bst1.add(60);
	bst1.add(70);
	bst1.add(15);
	bst1.add(20);
	bst1.add(75);
	bst1.add(65);
	bst1.add(18);
	bst1.add(20);
	bst1.printInorder();
	bst1.remove(20);
	bst1.printInorder();
	bst1.removeAll(20);
	bst1.printInorder();
}
