#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    Chunk chunk;
    chunk_init(&chunk);
    
    chunk_write_constant(&chunk, 9.5, 1);
    chunk_write(&chunk, OP_RETURN, 2);

    chunk_disassemble(&chunk, "test chunk");
    chunk_free(&chunk);

    return 0;
}