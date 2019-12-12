/*
 * Made by Hadron Collider
 * Thu 12 Dec 16:50
 *
 * tAras
 * Afdpro trass file to excel table parser
 * Licensed with GPLv3
 *
 * https://github.com/hadrizi/tAras
 */

#include "xlsxwriter.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Function that writes header of EXCEL table
void write_header(lxw_worksheet*, lxw_format**);
void parse_file(char*, int, lxw_workbook*, lxw_worksheet*, lxw_format*);
void fill_data(int, int, int, const char*, lxw_worksheet*, lxw_format*);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("taras [filename]");
		exit(-1);
	}

	lxw_workbook  *workbook  = workbook_new("tArass.xlsx");
	lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
	lxw_format    *format    = workbook_add_format(workbook);

    	write_header(worksheet, &format);
	parse_file(argv[1], 81, workbook, worksheet, format);
    	
    	return workbook_close(workbook);
}

void fill_data(int line, int idx, int row, const char* token, lxw_worksheet *worksheet, lxw_format *format)
{	
//----------------------------------------------------------------------------------
	if(line == 2 && idx == 0)
		worksheet_write_string(worksheet, row, 0, token, format);

	if(line == 2 && idx == 0) 
		worksheet_write_string(worksheet, row, 6, token, format);
//----------------------------------------------------------------------------------
	if(line == 2 && idx == 1)
		worksheet_write_string(worksheet, row, 1, token, format);
//----------------------------------------------------------------------------------
	if(line == 2 && idx == 4)
		worksheet_write_string(worksheet, row, 2, token, format);
//----------------------------------------------------------------------------------
	if(line == 2 && idx == 10) 
		worksheet_write_string(worksheet, row, 16, token, format);
//----------------------------------------------------------------------------------
	if(line == 4 && idx == 1) 
		worksheet_write_string(worksheet, row, 3, token, format);
//----------------------------------------------------------------------------------
	if(line == 6 && idx == 9)
		worksheet_write_string(worksheet, row, 4, token, format);
//----------------------------------------------------------------------------------
	if(line == 8 && idx == 9) 
		worksheet_write_string(worksheet, row, 5, token, format);
//----------------------------------------------------------------------------------
	if(line == 8 && idx == 0)
		worksheet_write_string(worksheet, row, 7, token, format);
	if(line == 8 && idx == 1)
		worksheet_write_string(worksheet, row, 8, token, format);
	if(line == 8 && idx == 2)
		worksheet_write_string(worksheet, row, 9, token, format);
	if(line == 8 && idx == 3)
		worksheet_write_string(worksheet, row, 10, token, format);
	if(line == 8 && idx == 4)
		worksheet_write_string(worksheet, row, 11, token, format);
	if(line == 8 && idx == 5)
		worksheet_write_string(worksheet, row, 12, token, format);
	if(line == 8 && idx == 6)
		worksheet_write_string(worksheet, row, 13, token, format);
	if(line == 8 && idx == 7)
		worksheet_write_string(worksheet, row, 14, token, format);
//----------------------------------------------------------------------------------
	worksheet_write_string(worksheet, row, 15, "", format);
}

void parse_file(char* filename, int offset, lxw_workbook* workbook,lxw_worksheet* worksheet, lxw_format* format)
{
	FILE *f;
	char line[256];
	int line_index = 1, i = 0, row = 2;

	if((f = fopen(filename, "r")) == NULL)
	{
		printf("Error opening file(invalid way or file doesn't exist)\n");
		exit(-1);
	}
	
	fseek(f, 76, SEEK_SET);

	while( !feof(f) )
	{	
		fgets(line, offset, f);
		char *token;
		token = strtok(line, " =\n\r");
		do
		{ 
			//printf("%s[%i %i] ", token, line_index, i);
			if(token > 0)
				fill_data(line_index, i, row, token, worksheet, format);
			i++;

		}while((token = strtok(NULL, " =\n\r")) != NULL);
		//printf("%i %i\n\r", i, line_index);
		line_index++;
		if(line_index % 9 == 0)
		{
			line_index = 1;
			i = 0;
			row++;
		}
		i = 0;
	}
	
	lxw_format *_format    = workbook_add_format(workbook);
	//format_set_border(_format, LXW_BORDER_THIN);

	worksheet_write_string(worksheet, row, 0, "", _format);
	worksheet_write_string(worksheet, row, 6, "", _format);
	worksheet_write_string(worksheet, row, 15, "", _format);

	fclose(f);
}

void write_header(lxw_worksheet* worksheet, lxw_format** format)
{
    	format_set_border(*format, LXW_BORDER_MEDIUM);
    	format_set_align(*format,  LXW_ALIGN_CENTER);
    	format_set_align(*format,  LXW_ALIGN_VERTICAL_CENTER);

    	format_set_text_wrap(*format);
	format_set_font_size(*format, 8);

    	worksheet_merge_range(worksheet, 0, 0, 0, 1, "Выполняемая команда", *format);
    	worksheet_set_row(worksheet, 0, 80, NULL);
	worksheet_set_column(worksheet, 1,1, 6, NULL);

	worksheet_merge_range(worksheet, 0, 2, 0, 6, "Содержимое регистров процессора после выполнения команды", *format);
	worksheet_set_column(worksheet, 2,6, 5, NULL);

	worksheet_merge_range(worksheet, 0, 7, 0, 14, "Содержимое регистра флагов после выполнения команды", *format);
	worksheet_set_column(worksheet, 7,14, 2, NULL);

	worksheet_write_string(worksheet, 0, 15, "Адрес памяти", *format);

	worksheet_write_string(worksheet, 0, 16, "Состояние стека", *format);
	worksheet_set_column(worksheet, 16,16, 7, NULL);

	worksheet_write_string(worksheet, 1, 0, "Адрес", *format);
	worksheet_write_string(worksheet, 1, 1, "Команда", *format);

	worksheet_write_string(worksheet, 1, 2, "AX", *format);
	worksheet_write_string(worksheet, 1, 3, "BX", *format);
	worksheet_write_string(worksheet, 1, 4, "CX", *format);
	worksheet_write_string(worksheet, 1, 5, "DX", *format);
	worksheet_write_string(worksheet, 1, 6, "IP", *format);
	
	worksheet_write_string(worksheet, 1, 7,  "OF", *format);
	worksheet_write_string(worksheet, 1, 8,  "DF", *format);
	worksheet_write_string(worksheet, 1, 9,  "IF", *format);
	worksheet_write_string(worksheet, 1, 10, "SF", *format);
	worksheet_write_string(worksheet, 1, 11, "ZF", *format);
	worksheet_write_string(worksheet, 1, 12, "AF", *format);
	worksheet_write_string(worksheet, 1, 13, "PF", *format);
	worksheet_write_string(worksheet, 1, 14, "CF", *format);

	worksheet_write_string(worksheet, 1, 15, "Адрес", *format);

	worksheet_write_string(worksheet, 1, 16, "Значение", *format);
}
