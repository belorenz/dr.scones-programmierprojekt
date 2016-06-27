#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *file_pointer;

	if (argc != 2){
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}

	if ((file_pointer = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file %s!\n", argv[1]);
		return 1;
	}

	int anzahl_plattformen = 0;
	char read_char = getc(file_pointer);
	char read_char_next;

	do{
		if (read_char < '0' || read_char > '9') {
			printf("Ungueltiges Eingabeformat\n");
			fclose(file_pointer);
			return 1;
		}
		anzahl_plattformen = anzahl_plattformen * 10 + (int)read_char - 48;
		read_char = getc(file_pointer);
	} while(read_char != '\n');

	int p2 = 0;
	int p1 = 0;
	read_char = getc(file_pointer);
	if (read_char < '0' || read_char > '9') {
		printf("Ungueltiges Eingabeformat\n");
				fclose(file_pointer);
				return 1;
	}

	while (read_char != EOF) {
		do {
			read_char_next = getc(file_pointer);

			if ((read_char < '0' || read_char > '9') || ((read_char_next < '0' || read_char_next > '9') && (read_char_next != ' '))) {
				printf("Ungueltiges Eingabeformat\n");
				fclose(file_pointer);
				return 1;
			}
			p1++;
			read_char = read_char_next;

		} while (read_char != ' ');

		read_char = getc(file_pointer);
		do {
			if (read_char < '0' || read_char > '9') {
				 printf("Ungueltiges Eingabeformat\n");
				 fclose(file_pointer);
				 return 1;
			}
			p2++;
			read_char = getc(file_pointer);
		} while (read_char != '\n');

		read_char = getc(file_pointer);
	}
	printf("anzahl plattformen %d\n", anzahl_plattformen);
	printf("p1 %d\n", p1);
	printf("p2 %d\n", p2);
}
