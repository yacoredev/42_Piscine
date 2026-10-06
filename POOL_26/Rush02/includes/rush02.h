#ifndef RUSH02_H
#define RUSH02_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_DICT 300
#define MAX_LINE 500
#define MAX_FILE 65536

typedef struct s_dict
{
	char *key;
	char *value;
}	t_dict;

int is_digit(char c);
int is_number(char *s);
char *decimal_number(char *s);

char *read_file(char *filename);

int find_colon(char *line);
char *trim(char *s);
int is_blank(char *s);
int process_line(char *line, t_dict *dict, int *count);
int handle_line_end(char *line, t_dict *dict, int *count);
int parse_dict(char *buf, t_dict *dict);

int str_eq(char *a, char *b);
int find_index(t_dict *dict, int count, char *key);
int update_entry(t_dict *dict, int index, char *value);
int insert_entry(t_dict *dict, int *count, char *key, char *value);
int add_entry(t_dict *dict, int *count, char *key, char *value);
int check_base_keys(t_dict *dict, int count);
int check_scale_keys(t_dict *dict, int count);
int check_keys(t_dict *dict, int count);

char *find_value(t_dict *dict, int count, char *key);

char *convert(char *number, t_dict *dict, int count, int *error);
char *convert_group(int value, t_dict *dict, int count, int *error);
char *convert_units(int value, t_dict *dict, int count, int *error);
char *convert_tens(int value, t_dict *dict, int count, int *error);
char *convert_hundreds(int value, t_dict *dict, int count, int *error);
int extract_group(char *number, int start, int length);
int group_bounds(int i, int first_len, int *length);
char *handle_group(char *result, char *number, int i, int groups,
	int first_len, t_dict *dict, int count, int *error);
char *add_scale(char *words, int power, t_dict *dict, int count, int *error);

int str_len(char *s);
char *my_strdup(char *s);
int copy_at(char *dest, int pos, char *src);
char *my_join(char *s1, char *sep, char *s2);
char *int_to_str(int n);
char *build_scale_key(int zeros);

void free_dict(t_dict *dict, int count);

#endif
