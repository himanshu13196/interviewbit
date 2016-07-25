/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) – Push element x onto stack.
 * pop() – Removes the element on top of the stack.
 * top() – Get the top element.
 * getMin() – Retrieve the minimum element in the stack.
 * Note that all the operations have to be constant time operations.
 */

stack<int> minstk;
stack<int> mins;

MinStack::MinStack() {
	while (!minstk.empty()) {
		minstk.pop();
	}

	while (!mins.empty()) {
		mins.pop();
	}
}

void MinStack::push(int x) {
	if (minstk.empty()) {
		mins.push(x);
	} else if (x <= mins.top()) {
		mins.push(x);
	}
	minstk.push(x);
}

void MinStack::pop() {
	if (!minstk.empty()) {
		if (minstk.top() == mins.top()) {
			mins.pop();
		}
		minstk.pop();
	}
}

int MinStack::top() {
	if (minstk.empty()) {
		return -1;
	} else {
		return minstk.top();
	}
}

int MinStack::getMin() {
	if (minstk.empty()) {
		return -1;
	} else {
		return mins.top();
	}
}

