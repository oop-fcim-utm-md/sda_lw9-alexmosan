#include "header.h"

#include "string.h"
#include "malloc.h"

void clear(node_t *node)
{
    node_t *temp = node;
    while (temp)
    {
        node = temp;
        temp = node->next_;
        delete node;
        node = NULL;
    }
    delete temp;
    temp = NULL;
}

node_t *tail(node_t *node)
{
    while (node->next_)
    {
        node = node->next_;
    }
    return node;
}

unsigned int length(node_t *node)
{

    while (node->next_)
    {
        node = node->next_;
    }
    return node->data_.id_;
}

void push_front(node_t **node, const char *data)
{
    if (!*node)
    {
        (*node) = new node_t;
        strcpy((*node)->data_.name_, data);
        (*node)->data_.id_ = 1;
        (*node)->next_ = NULL;
    }
    else
    {
        node_t *head = new node_t;
        head->data_ = (*node)->data_;
        head->next_ = (*node)->next_;

        (*node)->data_.id_ = 1;
        strcpy((*node)->data_.name_, data);

        (*node)->next_ = head;
        head = (*node);

        while ((*node))
        {
            (*node)->data_.id_++;
            (*node) = (*node)->next_;
        }
        (*node) = head;
    }
}

void push_back(node_t **node, const char *data)
{
    if (!*node)
    {
        (*node) = new node_t;
        strcpy((*node)->data_.name_, data);
        (*node)->data_.id_ = 1;
        (*node)->next_ = NULL;
    }
    else
    {
        node_t *head = (*node);
        while ((*node)->next_)
        {
            (*node) = (*node)->next_;
        }

        node_t *temp = new node_t;
        temp->data_.id_ = (*node)->data_.id_ + 1;
        strcpy(temp->data_.name_, data);
        temp->next_ = NULL;

        (*node)->next_ = temp;
        (*node) = head;
    }
}

data_t pop_front(node_t **node)
{
    data_t res = (*node)->data_;
    (*node) = (*node)->next_;
    return res;
}

data_t pop_back(node_t **node)
{
    node_t *head = (*node);
    while ((*node)->next_->next_)
    {
        (*node) = (*node)->next_;
    }
    data_t res = (*node)->next_->data_;

    int len = strlen((*node)->next_->data_.name_);

    for (size_t i = 0; i < len; i++)
    {
        (*node)->next_->data_.name_[i] = 0;
    }

    (*node)->next_->data_.id_ = 0;
    (*node)->next_->next_ = NULL;
    (*node)->next_ = NULL;
    (*node) = head;

    return res;
}

void insert(node_t **node, const char *data)
{
    node_t *temp = new node_t;
    strcpy(temp->data_.name_, data);
    temp->data_.id_ = (*node)->data_.id_ + 1;

    temp->next_ = (*node)->next_;
    (*node)->next_ = temp;
}

void remove(node_t **node, const char *data)
{
    node_t *head = (*node);
    int flag = 0;
    for (size_t i = 0; i < strlen((*node)->next_->data_.name_); i++)
    {
        if ((*node)->next_->data_.name_[i] == data[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        (*node) = (*node)->next_;
    }
    else
    {
        flag = 0;
        while ((*node))
        {
            for (size_t i = 0; i < strlen((*node)->next_->data_.name_); i++)
            {
                if ((*node)->next_->data_.name_[i] == data[i])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag)
            {
                node_t *tmp = (*node)->next_;
                (*node)->next_ = tmp->next_;
                delete tmp;
            }
            (*node) = (*node)->next_;
        }
        (*node) = head;
    }
}
