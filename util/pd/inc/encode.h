#ifndef __ENCODE_H__
#define __ENCODE_H__

#include "game.h"
#include "state.h"
#include <map>
#include <string>

using ll = long long;

ll encode(struct State&, struct Game&);
void decode(ll, struct State&, struct Game&);

#endif
