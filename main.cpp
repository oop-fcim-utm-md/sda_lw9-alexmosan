#include "header.h"

#include <assert.h>
#include <string.h>

int main(int argc, char const *argv[], char *envp[])
{
    node_t *first = NULL;
    const char *data[3] = {"Alpha", "Bravo", "Charlie"};

    for (unsigned int i = 0; i < 3; i++)
    {
        push_back(&first, data[i]);
    }

    assert(3 == length(first));

    node_t *charlie_ref = tail(first);
    assert(!strcmp(charlie_ref->data_.name_, "Charlie"));

    push_front(&first, "Alice");
    assert(!strcmp(first->data_.name_, "Alice"));

    push_back(&first, "Delta");
    data_t delta = pop_back(&first);
    assert(!strcmp(delta.name_, "Delta"));

    data_t alice = pop_front(&first);
    assert(alice.name_);

    insert(&first, "Bob");
    assert(!strcmp(first->next_->data_.name_, "Bob"));

    charlie_ref = tail(first);
    insert(&charlie_ref, "Zulu");
    node_t *zulu_ref = tail(first);
    assert(!strcmp(zulu_ref->data_.name_, "Zulu"));

    remove(&first, "Zulu");
    charlie_ref = tail(first);
    assert(!strcmp(charlie_ref->data_.name_, "Charlie"));

    assert(4 == length(first));

    clear(first);
}
