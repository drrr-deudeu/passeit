#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

void print_line(unsigned char v)
{
	if (v & 0x08)printf("%c",SHAPE);
	else printf("%c",EMPTY);
	if (v & 0x04)printf("%c",SHAPE);
	else printf("%c",EMPTY);
	if (v & 0x02)printf("%c",SHAPE);
	else printf("%c",EMPTY);
	if (v & 0x01)printf("%c\n",SHAPE);
	else printf("%c\n",EMPTY);
}

void print_tetrix(unsigned short int val)
{
	print_line(val >> 12);
	print_line(val >> 8);
	print_line(val >> 4);
	print_line(val);
}

int main(void)
{
	/* basic get_single_row_val */
	printf(".... = %d\n", get_single_row_val("...."));
	printf("...# = %d\n", get_single_row_val("...#"));
	printf("#..# = %d\n", get_single_row_val("#..#"));

	/* add_tetrix_line */
	unsigned short int max = 0;
	for (int i = 0; i < 4 ; i++)
		max = add_tetrix_line(max, "####");
	printf("4 * #### = %#4X \n",max);

	/* make tetrix */
	printf("4 * ###. = %#8X\n", make_tetrix("###.","###.","###.","###."));

	/* move tetrix */
	unsigned short int a_tetrix_to_move = make_tetrix("....","....","....","#...");
	printf("to move: .... ##.. #... #... = <%04X>\n", a_tetrix_to_move);

	printf("moving\n");
	print_tetrix(a_tetrix_to_move);
	a_tetrix_to_move = move_to_top(a_tetrix_to_move);
	printf("result\n");
	print_tetrix(a_tetrix_to_move);
	printf("\nmoving\n");
	a_tetrix_to_move = make_tetrix("...#","...#","...#","...#");
	print_tetrix(a_tetrix_to_move);
	printf("result\n");
	print_tetrix(move_to_top(a_tetrix_to_move));
	a_tetrix_to_move = make_tetrix("....","....","....","....");
	printf("\nmoving\n");
	print_tetrix(a_tetrix_to_move);
	printf("result\n");
	print_tetrix(move_to_top(a_tetrix_to_move));

	t_tetrix *p = make_s_tetrix(a_tetrix_to_move);
	if (p) printf("%x  %d %d %d %d\n", (unsigned int)p, p->index[0],p->index[1], p->index[2], p->index[3]);
	else printf("no valid <%04X>\n",a_tetrix_to_move);
	p = make_s_tetrix(0xF001);
	if (p) printf("%x  %d %d %d %d\n", (unsigned int)p, p->index[0],p->index[1], p->index[2], p->index[3]);
	else printf("no valid <%04X>\n",0xF001);

	p = make_s_tetrix(0x1101);
	if (p) printf("%x  %d %d %d %d\n", (unsigned int)p, p->index[0],p->index[1], p->index[2], p->index[3]);
	else printf("no valid <%04X>\n",0x1101);
	p = make_s_tetrix(0x1301);
	if (p) printf("%x  %d %d %d %d\n", (unsigned int)p, p->index[0],p->index[1], p->index[2], p->index[3]);
	else printf("no valid <%04X>\n",0x1301);
	p = make_s_tetrix(0x1312);
	if (p) printf("%x  %d %d %d %d\n", (unsigned int)p, p->index[0],p->index[1], p->index[2], p->index[3]);
	else printf("no valid <%04X>\n",0x1311);
}
