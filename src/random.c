#include "global.h"
#include "random.h"
#include "moves.h"

// The number 1103515245 comes from the example implementation
// of rand and srand in the ISO C standard.

u32 gRngValue;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
}

u16 RandomPokemon(void)
{
    u16 pkmn = Random() % NATIONAL_DEX_DEOXYS;
    if (pkmn > NATIONAL_DEX_CELEBI)
    {
        pkmn += 25;
    }
    return pkmn;
}

u16 RandomMove(void)
{
    return (Random() % (MOVES_COUNT-1)) + 1;
}

u16 RandomAbility(u32 personality)
{
    return (personality % 77) + 1;
}