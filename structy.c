#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct college; 

struct college {
	char *name;
	char *location;
	int ncaa_div;
	int student_population;
};

int main();
struct college *generate_college();
void print_college(struct college *uni);

int main() {
	
	struct college *uc = generate_college("University of Chicago","Chicago, IL",6989,3);
	struct college *michtech = generate_college("Michigan Technological University","Houghton, MI",5642,2);
	struct college *dartmouth = generate_college("Dartmouth College","Hanover, NH",4170,1);
	print_college(uc);
	printf("\n");
	print_college(michtech);
	printf("\n");
	print_college(dartmouth);
	
	return 0;
}
struct college *generate_college(char *n, char *place,int body, int div) {
	struct college *u = malloc(sizeof(struct college));
	u->name = malloc(strlen(n));
	strcpy(u->name,n);
	u->location = malloc(strlen(place));
	strcpy(u->location,place);
	u->student_population = body; 
	u->ncaa_div = div; 
	return u;
}
void free_college(struct college *c) {
	free(c->name);
	free(c->location);
	free(c);
}
void print_college(struct college *uni) {
	printf("%s:\n\tLocation: %s\n\tStudent Body: %d\nNCAA Division: %d\n",uni->name,uni->location,uni->student_population,uni->ncaa_div);
}