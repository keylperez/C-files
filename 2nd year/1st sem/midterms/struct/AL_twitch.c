#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User
{
    char name[100];
    int age;
} user;

typedef struct UserList
{
    user arr[100];
    int last;
} userList;

typedef struct Followers
{
    userList arr[50];
    int last;
} follows;

typedef struct Subscribers
{
    user arr[10];
    int last;
} subs;

typedef struct Vips
{
    user arr[20];
    int last;
} vips;

typedef struct Moderators
{
    user arr[10];
    int last;
} mods;

typedef struct Channel
{
    char name[50];
    follows *followers;
    subs *subscribers;
    vips *importants;
    mods *moderators;
} channel;

void initStructs(userList *u, follows *f, subs *s, vips *v, mods *m);
void populateUsers(userList *list);
void populateUsersList(userList *list, user node);
void populateFollowers(follows *list, userList *node);
void populateSubs(subs *list, userList *node);
void populateVIPS(vips *list, userList *node);
void popoulateMods(mods *list, userList *node);
void displayChannel(channel *c);

int main(void)
{
    userList users;
    follows followers;
    subs subers;
    vips vip;
    mods mod;
    channel ch;
    initStructs(&users, &followers, &subers, &vip, &mod);
    populateUsers(&users);
    populateFollowers(&followers, &users);
    populateSubs(&subers, &users);
    populateVIPS(&vip, &users);
    popoulateMods(&mod, &users);
    displayChannel(&ch);
    return 0;
}

void initStructs(userList *u, follows *f, subs *s, vips *v, mods *m)
{
    u->last = 0;
    f->last = 0;
    s->last = 0;
    v->last = 0;
    m->last = 0;
}

void populateUsers(userList *list)
{
    user user1 = {"DarkGoesYolo", 1};
    user user2 = {"Sherwin", 2};
    user user3 = {"cyistooshort", 3};
    user user4 = {"jenggaaa", 4};
    user user5 = {"dtannn", 5};
    user user6 = {"isFalse", 6};
    user user7 = {"carouselboy", 7};
    user user8 = {"yukinonii", 8};
    user user9 = {"98toki", 9};
    user user10 = {"endoupie", 10};
    addUsers(list, user1);
    addUsers(list, user2);
    addUsers(list, user3);
    addUsers(list, user4);
    addUsers(list, user5);
    addUsers(list, user6);
    addUsers(list, user7);
    addUsers(list, user8);
    addUsers(list, user9);
    addUsers(list, user10);
}

void populateUsersList(userList *list, user node)
{
    list->arr[list->last] = node;
    list->last++;
}

void populateFollowers(follows *list, userList *node)
{
    list->arr[list->last] = node[list->last];
    list->last++;
}

void populateSubs(subs *list, userList *node)
{
    list->arr[list->last] = node[list->last];
    list->last++;
}

void populateVIPS(vips *list, userList *node)
{
    list->arr[list->last] = node[list->last];
    list->last++;
}

void popoulateMods(mods *list, userList *node)
{
    list->arr[list->last] = node[list->last];
    list->last++;
}

void displayChannel(channel *c)
{
    char buffer[255];
    c->name = "keyl_perez" sprintf(buffer, "Channel name: %s", c->name);
    puts(buffer);
    printf("\nFollower List:");
    displayUser(c);
}

void displayuser(channel *list)
{
    char buffer[100];
    int i;
    for (i = 0; i < list->followers->last, i++)
    {

        sprintf(buffer, "\nName: %s\t%s", list->followers.arr[i]->name, subCheck(list->followers.arr[i].age));
    }
}

char *subCheck(user *node)
{
    subs *age;
    char result[30];
    if (strcmp(node, age) == 0)
    {
        strcpy(result, "Subscriber");
    }

    char *retStr = (char *)malloc(strlen(result) + 1);
    strcpy(retStr, result);
    return retStr;
}
