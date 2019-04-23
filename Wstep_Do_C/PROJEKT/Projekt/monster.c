#include "monster.h"

void create_skel(){

    srand();

    skeleton = malloc(sizeof(Skeleton_str));

    skeleton->hp = 99;
    skeleton->pow = rand()%30;
}

