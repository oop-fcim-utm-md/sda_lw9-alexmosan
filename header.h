
struct data_t 
{
    unsigned int id_;
    char name_ [50];
};

struct node_t
{
    node_t * next_;
    data_t data_;
};

void clear(node_t *);
node_t * tail(node_t *);
unsigned int length(node_t *);
void push_front(node_t **, const char *);
void push_back(node_t **, const char *);
data_t pop_front(node_t **);
data_t pop_back(node_t **);
void insert(node_t **, const char *);
void remove(node_t **, const char *);
