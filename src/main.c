#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    Chunk chunk;
    chunk_init(&chunk);
    
    int constant = chunk_add_constant(&chunk, 1.2);
    chunk_write(&chunk, OP_CONSTANT, 12);
    chunk_write(&chunk, constant, 12);
    chunk_write(&chunk, OP_RETURN, 15);

    chunk_disassemble(&chunk, "test chunk");
    chunk_free(&chunk);

    return 0;
}