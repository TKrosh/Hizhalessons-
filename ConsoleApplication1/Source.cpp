#include <stdio.h>
/*
struct List {
	char sym;
	List* next;
	List* prev;
};

void create_node(char c, List* n) {
	List* t = new List;
	t->sym = c;
	n->next = t;
	t->prev = n;
}

void output(List* head) {
	FILE* output_file;
	fopen_s(&output_file, "out.txt", "w");

	for (List* x = head->prev; x->prev->next != NULL; x = x->prev)
		fprintf(output_file, "%c", x->sym);

	fclose(output_file);
}

void clean(List* head) {
	List* l = head->next;
	for (; l != NULL; l = l->next) {
		delete head;
		head = l;
	}
	delete head;
}


int input(char* filename, List** head) {
	FILE* input_file;
	fopen_s(&input_file, filename, "r");
	List* n, * t;
	char c = ' ';

	if (!input_file) {
		printf("Невозможно открыть файл.");
		return 1;
	}
	c = fgetc(input_file);
	if (c == '.') 
	{
		return 1;
	}

	n = *head;
	

	while ((c != '.') and (c != EOF)) {
		create_node(c, n);
		n = n->next;
		c = fgetc(input_file);
	}

	n->next = NULL;
	(*head)->prev = n;

	fclose(input_file);
	return 0;
}


int main() {
	List* head;
	int c;
	char filename[] = "input.txt";

	c = input(filename, &head);
	if (c)
		head = new List;
		output(head);
		return 1;

	output(head);
	clean(head);

}
*/