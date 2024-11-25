#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX_DATA 100
#define MAX_ROWS 100

typedef struct Address{
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
}Address;

typedef struct Database{
	Address address[MAX_ROWS];
}Database;

typedef struct Connection{
	FILE *file;
	Database *data;
}Connection;


void Database_loader(Database *data, FILE *file);
void die(const char* message)
{
	if (errno) {
		perror("systeme error111");
	}else {
		puts(message);		
	}	
	exit(1);
}
Connection* Database_open(char *filename, char action)
{
	Connection *conn = malloc(sizeof(Connection));
	if(!conn) die("conn cannot malloc"); 
	if(action == 'c') {
		conn->file = fopen(filename, "w");
	}else {
		conn->file = fopen(filename, "r+");
	}
	if(!conn->file) {
		die("the file dose not exist");
	}
	conn->data = malloc(sizeof(Database));
	if (!conn->data) {
		die("conn->data cannot malloc");
	}
	Database_loader(conn->data, conn->file);
	return conn;
} 
void Database_loader(Database *data, FILE *file)
{
	rewind(file);
	int res = fread(data, sizeof(Database), 1, file);
	if (res == -1) {
		die("Database_loader fread error");
	}
}

void Address_print(Address *info, int id)
{
	printf("id: %d\tname: %s\temail: %s\n\r", id, info->name, info->email);
}
Address* Database_get(Connection * conn, int id)
{
	int i = 0;
	Address *the_find = malloc(sizeof(Address));
	if (conn->data->address[id].set == 1) {
		the_find = &conn->data->address[id];
		return the_find;
	}
	free(the_find);
	return NULL;
}
void Database_write(Connection *conn)
{
	rewind(conn->file);
	int res = fwrite(conn->data, sizeof(Database), 1, conn->file);
	if (res != 1) {
		die("wirte data to file error!");
	}
	res = fflush(conn->file);
	if (res == EOF) {
		die("fflush file error!");
	}
}

void Database_set(Connection *conn, int id, char *name, char *email)
{
	if (Database_get(conn, id)) {
		die("this address data have existed! please try another one to set!");
	}
	strcpy(conn->data->address[id].name, name);
	strcpy(conn->data->address[id].email, email);
	conn->data->address[id].set = 1;
	Database_write(conn);
	printf("set %d successful!\n\r", id);
}

void Database_list(Connection *conn)
{
	int count = 0; 
	for (int i = 0; i < MAX_ROWS; ++ i)
	{
		if (conn->data->address[i].set == 1) {
			Address_print(&conn->data->address[i], i);
			count++;
		}
	}
	if (count == 0) {
		printf("sorry there is no data existed~\n\r");
	}
}
void Database_delete(Connection * conn, int id)
{
	if (!Database_get(conn, id)) {
		die("this address data didnt existet! please try another one to delete!");
	}else {
		conn->data->address[id].set = 0;
		printf("delete %d successful!\n\r", id);
	}
	Database_write(conn);
}

//for init the address array of conn->data
void Database_create(Connection *conn)
{
	for (int i = 0; i < MAX_ROWS; ++ i)
	{
		Address address = {.set = 0};
		conn->data->address[i] = address;
	}
}

void Database_close(Connection *conn)
{
	if (conn->file) {
		free(conn->file);
	}
	if (conn->data) {
		free(conn->data);
	}
	free(conn);
}
int main(int argc, char* argv[])
{
	if (argc < 3) {
		die("lack args!");	
	}
	char* filename = argv[1];
	char action = argv[2][0];
	Connection *conn = Database_open(filename, action); 
	int id = 0;
	if (argc > 3) {
		id =  atoi(argv[3]);
	}	
	switch (action){
	case 'c':
		Database_create(conn);
		Database_write(conn);
		break;
	case 'g':
		if (argc < 4) {
			die("lack the arg of id!");
		}
		Address * find_one = Database_get(conn, id);
		if (find_one) {
			Address_print(find_one, id);
		}else {
			die("didnt find this data");
		} 
		break;
	case 's':
		if (argc < 6) {
			die("lack the arg of the address data to insert!");
		}
		Database_set(conn, id, argv[4], argv[5]);
		break;
	case 'd':
		Database_delete(conn, id);
		break;
	case 'l':
		Database_list(conn);
		break;
	default:
		die("please input the operation!");
	}	
	Database_close(conn);
	return 0;
}
