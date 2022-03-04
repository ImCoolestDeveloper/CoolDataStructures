#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100

struct CoolStack {
	int vals[MAX_ELEMENTS];
	int top_idx;
};

struct CoolStack *createStack() {
	struct CoolStack *s = malloc(sizeof(struct CoolStack)*MAX_ELEMENTS);
	s->top_idx = -1;
	return s;
}

int isStackEmpty(struct CoolStack *s) {
	if (s->top_idx==-1) return 1;
	return 0;
}

int isStackFull(struct CoolStack *s) {
	if (s->top_idx==MAX_ELEMENTS-1) return 1;
	return 0;
}


void pushOnStack(struct CoolStack *s, int val) {
	if (!isStackFull(s)){
		s->top_idx++;
		s->vals[s->top_idx] = val;
	}
}

void popOnStack(struct CoolStack *s) {
	if (!isStackEmpty(s)){
		s->vals[s->top_idx] = -1;
		s->top_idx--;
	}
}

int getStackTop(struct CoolStack *s) {
	return s->vals[s->top_idx];
}

void deleteStack(struct CoolStack *s) {
	free(s);
}

void printStack(struct CoolStack *s) {
	printf("[ ");
	for (int i=0;i<=s->top_idx;i++) printf("%d ", s->vals[i]);
	printf("]\n");
}

int main(){
	struct CoolStack *s = createStack();
	printStack(s);
	pushOnStack(s,1);
	pushOnStack(s,2);
	pushOnStack(s,3);
	pushOnStack(s,4);
	pushOnStack(s,5);
	printf("Stack top: %d\n",getStackTop(s));
	printStack(s);
	popOnStack(s);
	popOnStack(s);
	printStack(s);
	popOnStack(s);
	popOnStack(s);
	printStack(s);

	return 0;
}