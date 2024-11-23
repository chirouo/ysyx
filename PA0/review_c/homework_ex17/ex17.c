#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX_DATA 100
#define MAX_ROWS 100

typedef struct Address{
	int id;
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
	if (errno){
		perror("systeme error111");
	}else{
		puts(message);		
	}	
	exit(1);
}
Connection* Database_open(char *filename, char *action)
{
	Connection *conn = malloc(sizeof(Connection));
	if(!conn) die("conn cannot malloc");
	if(action == "c")
	{
		conn->file = fopen(filename, "w");
		if(!conn->file) die("the file dose not exist");
	}
	else{
		conn->file = fopen(filename, "r");
		if(!conn->file) die("the file dose not exist");
	}
	conn->data = malloc(sizeof(Database));
	if (!conn->data) die("conn->data cannot malloc");
	Database_loader(conn->data, conn->file);
	return conn;
} 
void Database_loader(Database *data, FILE *file)
{
	rewind(file);
	int res = fread(data, sizeof(Database), 1, file);
	if (res == -1) die("Database_loader fread error");
}
void Database_create(Connection *conn)
{
}
void Address_print(Address *info)
{
	printf(info->
int main(int argc, char* argv[])
{
	if (argc < 3) die("lack args!");	
	char* filename = argv[1];
	char action = argv[2][0];
	Connection *conn = Database_open(filename, action); 
	if (argc > 3){
		int id =  atoi(argv[3]);
	}	
	switch (action){
	case 'c':
		Database_create(conn);
		printf("c\n");
		break;
	case 'g':
		printf("g\n");
		break;
	case 's':
		printf("s\n");
		break;
	case 'd':
		printf("d\n");
		break;
	case 'l':
		printf("l\n");
		break;
	}	
	return 0;

