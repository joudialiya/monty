
#define LIFO 0
#define FIFO 0
typedef struct state_s
{
	FILE *stream;
	int i_line;
	int mode;
	char *opcode;
	char *arg;
} state_t

extern state_t state;

state_t *init_state(const char *);
void free_state(state_t *);
